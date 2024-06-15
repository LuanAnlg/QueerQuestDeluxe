#pragma once

#include "Grupo.h"
#include "Enemigo.h"

#include <iostream>

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

            // Inicializaci�n de gr�ficos y buffer
            graphics = this->CreateGraphics();
            buffer = BufferedGraphicsManager::Current->Allocate(graphics, this->ClientRectangle);

            // Cargar sprites
            spritePersonajes = gcnew Bitmap("Sprites\\Personajes.png");

            // Crear grupo de personajes
            grupo = new Grupo({ static_cast<float>(6 * formlib::getCelda()), static_cast<float>(3 * formlib::getCelda()) }, spritePersonajes);

            // Inicializaci�n del enemigo
            formlib::Vec2 enemigoPosicion = { static_cast<float>(formlib::getAleatorio(0, graphics->VisibleClipBounds.Right - formlib::getCelda())),
                                              static_cast<float>(formlib::getAleatorio(0, graphics->VisibleClipBounds.Bottom - formlib::getCelda())) };
            enemigo = new Enemigo(enemigoPosicion, spritePersonajes);

            test = new Personaje({ static_cast<float>(8 * formlib::getCelda()), static_cast<float>(1 * formlib::getCelda()) },
                spritePersonajes, { 4, 5 }, { 0, 0 }, {0, 4}, 1, 1);
            std::cout << test->getRectanguloColision().Width;
            std::cout << "\n" << graphics->VisibleClipBounds.Width << "\n" << graphics->VisibleClipBounds.Height;
            // Inicializar variables adicionales
            direcion = formlib::Direcciones::Ninguno;
            temporizador = 0;
        }

    protected:

        ~Juego()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::IContainer^ components;
        System::Windows::Forms::Timer^ tiempoDelta;

        Graphics^ graphics;
        BufferedGraphics^ buffer;
        Bitmap^ spritePersonajes;
        Grupo* grupo;
        Enemigo* enemigo;
        Personaje* test;
        formlib::Direcciones direcion;
        int temporizador;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
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

        // M�todo para el evento de actualizaci�n de tiempoDelta (aprox. 60 veces por segundo)
    private: System::Void tiempoDelta_Tick(System::Object^ sender, System::EventArgs^ e) {

        // Limpiar el buffer con un color de fondo
        buffer->Graphics->Clear(formlib::P8AzulOscuro());

        // Incrementar el temporizador
        temporizador++;

        // Actualizar el grupo de personajes si ha pasado suficiente tiempo y hay una direcci�n v�lida
        if (temporizador >= 15 && direcion != formlib::Direcciones::Ninguno) {
            grupo->actualizar(buffer->Graphics, direcion);
            temporizador = 0;
        }

        // Verificar si el grupo de personajes intersecta con el enemigo
        if (grupo->getRobot().getRectanguloColision().IntersectsWith(enemigo->getRectanguloColision())) {
            grupo->agregar(spritePersonajes, enemigo->getTipo()); // Agregar nuevo aliado al grupo
            delete enemigo; // Eliminar el enemigo actual
            // Crear un nuevo enemigo en una posici�n aleatoria dentro de los l�mites de la pantalla
            formlib::Vec2 enemigoPosicion = { static_cast<float>(formlib::getAleatorio(0, graphics->VisibleClipBounds.Right - formlib::getCelda())),
                                              static_cast<float>(formlib::getAleatorio(0, graphics->VisibleClipBounds.Bottom - formlib::getCelda())) };
            enemigo = new Enemigo(enemigoPosicion, spritePersonajes);
        }

        // Dibujar el grupo de personajes y el enemigo en el buffer
        grupo->dibujar(buffer->Graphics, spritePersonajes);
        enemigo->dibujar(buffer->Graphics, spritePersonajes);
        test->dibujar(buffer->Graphics, spritePersonajes);
        // Renderizar el buffer en la pantalla
        buffer->Render(graphics);
    }

           // M�todo para el evento de tecla presionada
    private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
        // Asignar direcci�n basada en la tecla presionada
        if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left) {
            direcion = formlib::Direcciones::Izquierda;
        }
        else if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right) {
            direcion = formlib::Direcciones::Derecha;
        }
        else if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up) {
            direcion = formlib::Direcciones::Arriba;
        }
        else if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down) {
            direcion = formlib::Direcciones::Abajo;
        }
    }
    };
}
