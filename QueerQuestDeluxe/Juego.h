#pragma once

#include "Grupo.h"
#include "Enemigo.h"
#include "Trivia.h"
#include "Preguntando.h"
#include "Puntaje.h"

namespace QueerQuestDeluxe {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Juego : public System::Windows::Forms::Form {

    public:
        Juego(formlib::Dificultades dificultad) {
            InitializeComponent();

            // Inicialización de gráficos y buffer
            graphics = this->CreateGraphics();
            buffer = BufferedGraphicsManager::Current->Allocate(graphics, this->ClientRectangle);

            // Cargar sprites
            spritePersonajes = gcnew Bitmap("Sprites\\Personajes.png");
            spriteInterfaz = gcnew Bitmap("Sprites\\Interfaz.png");

            // Crear grupo de personajes
            grupo = new Grupo({ static_cast<float>(6 * formlib::getCelda()), static_cast<float>(3 * formlib::getCelda()) }, spritePersonajes);

            if (dificultad == formlib::Dificultades::Facil) {
                spriteFondo = gcnew Bitmap("Sprites\\Fondo_Facil.png");
                cantidadVidas = 3;
                grupo->agregarAliado(spritePersonajes, formlib::Tipos::Chico);
                grupo->agregarAliado(spritePersonajes, formlib::Tipos::Chica);
                grupo->agregarAliado(spritePersonajes, formlib::Tipos::Chique);
            }
            else {
                spriteFondo = gcnew Bitmap("Sprites\\Fondo_Dificil.png");
                cantidadVidas = 1;
            }

            // Inicialización del enemigo
            formlib::Vec2 enemigoPosicion = { static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Right - formlib::getCelda()))),
                                              static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Bottom - formlib::getCelda()))) };
            enemigo = new Enemigo(enemigoPosicion, spritePersonajes);

            // Crear interfaz de vidas y aliados
            vidas = new Personaje({ static_cast<float>(1 * formlib::getCelda()), static_cast<float>(1 * (formlib::getCelda() / 2)) },
                spriteInterfaz, { 1, 2 }, { 0, 0 }, { 0, 0 }, 1, 1);
            aliados = new Personaje({ static_cast<float>(3 * formlib::getCelda()), static_cast<float>(1 * (formlib::getCelda() / 2)) },
                spriteInterfaz, { 1, 2 }, { 0, 0 }, { 0, 1 }, 1, 1);

            // Inicializar trivia
            trivia = new Trivia(dificultad);

            // Inicializar variables adicionales
            direccion = formlib::Direcciones::Ninguno;
            temporizador = 0;
        }

    protected:
        ~Juego() {
            if (components) {
                delete components;
            }
            delete graphics;
            delete buffer;
            delete spritePersonajes;
            delete spriteInterfaz;
            delete spriteFondo;
            delete grupo;
            delete enemigo;
            delete vidas;
            delete aliados;
            delete trivia;
        }

    private:
        // Componentes y variables de clase
        System::ComponentModel::IContainer^ components;
        System::Windows::Forms::Timer^ tiempoDelta;
        System::Windows::Forms::Label^ lbl_vidas;
        System::Windows::Forms::Label^ lbl_aliados;
        Graphics^ graphics;
        BufferedGraphics^ buffer;
        Bitmap^ spritePersonajes;
        Bitmap^ spriteInterfaz;
        Bitmap^ spriteFondo;
        Grupo* grupo;
        Enemigo* enemigo;
        Personaje* vidas;
        Personaje* aliados;
        Trivia* trivia;
        formlib::Direcciones direccion;
        int temporizador;
        int cantidadVidas;
        formlib::Dificultades dificultad;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->components = (gcnew System::ComponentModel::Container());
            this->tiempoDelta = (gcnew System::Windows::Forms::Timer(this->components));
            this->lbl_vidas = (gcnew System::Windows::Forms::Label());
            this->lbl_aliados = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // tiempoDelta
            // 
            this->tiempoDelta->Enabled = true;
            this->tiempoDelta->Interval = 16;
            this->tiempoDelta->Tick += gcnew System::EventHandler(this, &Juego::tiempoDelta_Tick);
            // 
            // lbl_vidas
            // 
            this->lbl_vidas->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->lbl_vidas->BackColor = System::Drawing::Color::Transparent;
            this->lbl_vidas->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_vidas->Location = System::Drawing::Point(96, 32);
            this->lbl_vidas->Name = L"lbl_vidas";
            this->lbl_vidas->Size = System::Drawing::Size(64, 32);
            this->lbl_vidas->TabIndex = 0;
            this->lbl_vidas->Text = L"X 3";
            // 
            // lbl_aliados
            // 
            this->lbl_aliados->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->lbl_aliados->BackColor = System::Drawing::Color::Transparent;
            this->lbl_aliados->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_aliados->Location = System::Drawing::Point(224, 32);
            this->lbl_aliados->Name = L"lbl_aliados";
            this->lbl_aliados->Size = System::Drawing::Size(64, 32);
            this->lbl_aliados->TabIndex = 1;
            this->lbl_aliados->Text = L"X 2";
            // 
            // Juego
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(960, 576);
            this->Controls->Add(this->lbl_aliados);
            this->Controls->Add(this->lbl_vidas);
            this->Name = L"Juego";
            this->Text = L"Juego";
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
            this->ResumeLayout(false);
        }
#pragma endregion

        // Método para el evento de actualización de tiempoDelta (aprox. 60 veces por segundo)
    private: System::Void tiempoDelta_Tick(System::Object^ sender, System::EventArgs^ e) {
        // Limpiar el buffer con un color de fondo
        buffer->Graphics->Clear(Color::Black);

        // Dibujar la imagen del fondo
        buffer->Graphics->DrawImage(spriteFondo, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);

        // Incrementar el temporizador
        temporizador++;

        // Actualizar el grupo de personajes si ha pasado suficiente tiempo y hay una dirección válida
        if (temporizador >= 15 && direccion != formlib::Direcciones::Ninguno) {
            grupo->actualizar(buffer->Graphics, direccion);
            temporizador = 0;
        }

        // Verificar si el grupo de personajes intersecta con el enemigo y hay preguntas disponibles
        if (grupo->getRobot().getRectanguloColision().IntersectsWith(enemigo->getRectanguloColision()) && trivia->getCantidadPreguntas() > 0) {
            //--------------------TRIVIA--------------------
            tiempoDelta->Stop();

            Preguntando^ preguntando = gcnew Preguntando();
            preguntando->setPreguntando(trivia->preguntar());
            preguntando->ShowDialog();

            switch ((preguntando->getResultado())) {
            case formlib::Resultado::gano:
                grupo->agregarAliado(spritePersonajes, enemigo->getTipo()); // Agregar nuevo aliado al grupo
                break;
            case formlib::Resultado::perdio:
                cantidadVidas--; // Reducir la cantidad de vidas
                break;
            case formlib::Resultado::sacrifico:
                if (grupo->getCantidadAliados() <= 0) {
                    cantidadVidas--;
                }
                else {
                    grupo->eliminarAliado();
                }
                break;
            default:  break;
            }

            delete preguntando;
            tiempoDelta->Start();
            //----------------------------------------------

           
            if (trivia->getCantidadPreguntas() <= 0 || cantidadVidas <= 0) {
                //------------------Puntaje------------------
                // Detener el tiempo
                tiempoDelta->Stop();

                // Crear y mostrar la ventana de puntaje
                Puntaje^ puntaje = gcnew Puntaje(cantidadVidas, grupo->getCantidadAliados());
                puntaje->ShowDialog();

                // Cerrar la ventana de puntaje después de que el usuario interactúe con ella
                delete puntaje;

                // Cerrar la ventana actual (Juego)
                this->Close();
            }
            //-----------------------------------------------
            

            // Eliminar el enemigo actual
            delete enemigo;

            // Crear un nuevo enemigo en una posición aleatoria dentro de los límites de la pantalla
            formlib::Vec2 enemigoPosicion = { static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Right - formlib::getCelda()))),
                                              static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Bottom - formlib::getCelda()))) };
            enemigo = new Enemigo(enemigoPosicion, spritePersonajes);
        }

        // Dibujar el grupo de personajes y el enemigo en el buffer
        grupo->dibujar(buffer->Graphics, spritePersonajes);
        enemigo->dibujar(buffer->Graphics, spritePersonajes);

        // Dibujar vidas y actualizar etiquetas
        vidas->dibujar(buffer->Graphics, spriteInterfaz);
        lbl_vidas->Text = "X " + cantidadVidas;

        // Dibujar aliados y actualizar etiquetas
        aliados->dibujar(buffer->Graphics, spriteInterfaz);
        lbl_aliados->Text = "X " + gcnew String(std::to_string(grupo->getCantidadAliados()).c_str());

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
    }
    };
}
