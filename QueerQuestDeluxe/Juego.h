#pragma once

#include "Grupo.h"
#include "Enemigo.h"

namespace QueerQuestDeluxe {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Juego : public System::Windows::Forms::Form {

    public:
        Juego(void) {
            InitializeComponent();

            // Inicialización de gráficos y buffer
            graphics = this->CreateGraphics();
            buffer = BufferedGraphicsManager::Current->Allocate(graphics, this->ClientRectangle);

            // Cargar sprites
            spritePersonajes = gcnew Bitmap("Sprites\\Personajes.png");
            spriteFondo = gcnew Bitmap("Sprites\\Fondo_Facil.png");

            // Crear grupo de personajes
            grupo = new Grupo({ static_cast<float>(6 * formlib::getCelda()), static_cast<float>(3 * formlib::getCelda()) }, spritePersonajes);

            // Inicialización del enemigo
            formlib::Vec2 enemigoPosicion = { static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Right - formlib::getCelda()))),
                                              static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Bottom - formlib::getCelda()))) };
            enemigo = new Enemigo(enemigoPosicion, spritePersonajes);

            // Crear un personaje de prueba
            test = new Personaje({ static_cast<float>(8 * formlib::getCelda()), static_cast<float>(1 * formlib::getCelda()) },
                spritePersonajes, { 4, 5 }, { 0, 0 }, { 0, 4 }, 1, 1);

            // Inicializar variables adicionales
            direccion = formlib::Direcciones::Ninguno;
            temporizador = 0;
        }

    protected:
        ~Juego() {
            if (components) {
                delete components;
            }
        }

    private:
        // Componentes y variables de clase
        System::ComponentModel::IContainer^ components;
        System::Windows::Forms::Timer^ tiempoDelta;
        Graphics^ graphics;
        BufferedGraphics^ buffer;
        Bitmap^ spritePersonajes;
        Bitmap^ spriteFondo;
        Grupo* grupo;
        Enemigo* enemigo;
        Personaje* test;
        formlib::Direcciones direccion;
        int temporizador;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->components = (gcnew System::ComponentModel::Container());
            this->tiempoDelta = (gcnew System::Windows::Forms::Timer(this->components));
            this->SuspendLayout();
            // 
            // tiempoDelta
            // 
            this->tiempoDelta->Enabled = true;
            this->tiempoDelta->Interval = 16;
            this->tiempoDelta->Tick += gcnew System::EventHandler(this, &Juego::tiempoDelta_Tick);
            // 
            // Juego
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(960, 576);
            this->Name = L"Juego";
            this->Text = L"Juego";
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
            this->ResumeLayout(false);
        }
#pragma endregion

        // Método para el evento de actualización de tiempoDelta (aprox. 60 veces por segundo)
    private: System::Void tiempoDelta_Tick(System::Object^ sender, System::EventArgs^ e) {

        // Limpiar el buffer con un color de fondo
        buffer->Graphics->Clear(formlib::P8AzulOscuro());

        // Dibujar la imagen del fondo
        buffer->Graphics->DrawImage(spriteFondo, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);

        // Incrementar el temporizador
        temporizador++;

        // Actualizar el grupo de personajes si ha pasado suficiente tiempo y hay una dirección válida
        if (temporizador >= 15 && direccion != formlib::Direcciones::Ninguno) {
            grupo->actualizar(buffer->Graphics, direccion);
            temporizador = 0;
        }

        // Verificar si el grupo de personajes intersecta con el enemigo
        if (grupo->getRobot().getRectanguloColision().IntersectsWith(enemigo->getRectanguloColision())) {
            grupo->agregarAliado(spritePersonajes, enemigo->getTipo()); // Agregar nuevo aliado al grupo
            delete enemigo; // Eliminar el enemigo actual

            // Crear un nuevo enemigo en una posición aleatoria dentro de los límites de la pantalla
            formlib::Vec2 enemigoPosicion = { static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Right - formlib::getCelda()))),
                                              static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Bottom - formlib::getCelda()))) };
            enemigo = new Enemigo(enemigoPosicion, spritePersonajes);
        }

        // Dibujar el grupo de personajes y el enemigo en el buffer
        grupo->dibujar(buffer->Graphics, spritePersonajes);
        enemigo->dibujar(buffer->Graphics, spritePersonajes);
        test->dibujar(buffer->Graphics, spritePersonajes);

        // Renderizar el buffer en la pantalla
        buffer->Render(graphics);
    }

           // Método para el evento de tecla presionada
    private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
        // Asignar dirección basada en la tecla presionada
        if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left) {
            direccion = formlib::Direcciones::Izquierda;
        }
        else if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right) {
            direccion = formlib::Direcciones::Derecha;
        }
        else if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up) {
            direccion = formlib::Direcciones::Arriba;
        }
        else if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down) {
            direccion = formlib::Direcciones::Abajo;
        }
        else if (e->KeyCode == Keys::R) {
            grupo->eliminarAliado();
        }
    }
    };
}