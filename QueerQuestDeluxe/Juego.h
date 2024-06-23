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
        // Constructor que recibe la dificultad del juego
        Juego(formlib::Dificultades dificultad) {
            InitializeComponent(); // Inicializa los componentes visuales

            // Configuración de colores de los componentes
            lbl_vidas->BackColor = formlib::P8Rosa();
            lbl_vidas->ForeColor = formlib::P8Blanco();
            lbl_aliados->BackColor = formlib::P8Azul();
            lbl_aliados->ForeColor = formlib::P8Blanco();

            // Inicialización de gráficos y buffer
            graphics = CreateGraphics();
            buffer = BufferedGraphicsManager::Current->Allocate(graphics, ClientRectangle);

            // Carga de sprites
            spritePersonajes = gcnew Bitmap("Sprites\\Personajes.png");
            spriteInterfaz = gcnew Bitmap("Sprites\\Interfaz.png");

            // Creación del grupo de personajes
            grupo = new Grupo({ 6.0f * formlib::getCelda(), 3.0f * formlib::getCelda() }, spritePersonajes);

            // Configuración inicial según la dificultad seleccionada
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

            // Creación del enemigo en una posición aleatoria
            formlib::Vec2 enemigoPosicion = {
                static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Right - formlib::getCelda()))),
                static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Bottom - formlib::getCelda())))
            };
            enemigo = new Enemigo(enemigoPosicion, spritePersonajes);

            // Creación de la interfaz de vidas y aliados
            vidas = new Personaje({ 1.0f * formlib::getCelda(), 0.5f * formlib::getCelda() },
                spriteInterfaz, { 1, 2 }, { 0, 0 }, { 0, 0 }, 1, 1);
            aliados = new Personaje({ 3.0f * formlib::getCelda(), 0.5f * formlib::getCelda() },
                spriteInterfaz, { 1, 2 }, { 0, 0 }, { 0, 1 }, 1, 1);

            // Inicialización de la trivia
            trivia = new Trivia(dificultad);

            // Inicialización de variables adicionales
            direccion = formlib::Direcciones::Ninguno;
            temporizador = 0;
        }

    protected:
        // Destructor para liberar recursos
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
        // Variables y componentes de la interfaz de usuario
        System::Windows::Forms::Timer^ tiempoDelta;
        System::Windows::Forms::Label^ lbl_vidas;
        System::Windows::Forms::Label^ lbl_aliados;
        System::ComponentModel::IContainer^ components;
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

        // Método generado por el diseñador para inicializar los componentes visuales
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
            this->lbl_vidas->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
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
            this->lbl_aliados->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
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

    private:
        // Método que maneja el evento de actualización de tiempoDelta
        System::Void tiempoDelta_Tick(System::Object^ sender, System::EventArgs^ e) {
            buffer->Graphics->Clear(formlib::P8AzulOscuro()); // Limpia el buffer con un color de fondo azul oscuro
            buffer->Graphics->DrawImage(spriteFondo, 0, 0, ClientRectangle.Width, ClientRectangle.Height); // Dibuja el fondo en el buffer

            temporizador++; // Incrementa el temporizador

            // Actualiza el grupo de personajes si ha pasado suficiente tiempo y hay una dirección válida
            if (temporizador >= 15 && direccion != formlib::Direcciones::Ninguno) {
                grupo->actualizar(buffer->Graphics, direccion);
                temporizador = 0;
            }

            // Verifica la intersección entre el grupo de personajes y el enemigo, y si hay preguntas disponibles
            if (grupo->getRobot().getRectanguloColision().IntersectsWith(enemigo->getRectanguloColision()) && trivia->getCantidadPreguntas() > 0) {
                tiempoDelta->Stop(); // Detiene el temporizador

                // Muestra la ventana de preguntas
                Preguntando^ preguntando = gcnew Preguntando();
                preguntando->setPreguntando(trivia->preguntar());
                preguntando->ShowDialog();

                // Procesa la respuesta obtenida
                switch (preguntando->getResultado()) {
                case formlib::Resultado::gano:
                    grupo->agregarAliado(spritePersonajes, enemigo->getTipo()); // Agrega un aliado al grupo
                    break;
                case formlib::Resultado::perdio:
                    cantidadVidas--; // Reduce la cantidad de vidas
                    break;
                case formlib::Resultado::sacrifico:
                    if (grupo->getCantidadAliados() <= 0) {
                        cantidadVidas--; // Reduce vidas si no hay aliados para sacrificar
                    }
                    else {
                        grupo->eliminarAliado(); // Elimina un aliado del grupo
                    }
                    break;
                default:
                    break;
                }

                delete preguntando; // Libera la memoria de la ventana de preguntas
                tiempoDelta->Start(); // Reinicia el temporizador

                // Verifica si se acabaron las preguntas o las vidas para mostrar el puntaje final
                if (trivia->getCantidadPreguntas() <= 0 || cantidadVidas <= 0) {
                    tiempoDelta->Stop(); // Detiene el temporizador

                    // Muestra la ventana de puntaje final
                    Puntaje^ puntaje = gcnew Puntaje(cantidadVidas, grupo->getCantidadAliados());
                    puntaje->ShowDialog();
                    delete puntaje; // Libera la memoria de la ventana de puntaje

                    Close(); // Cierra la ventana del juego
                }

                delete enemigo; // Libera la memoria del enemigo actual

                // Genera una nueva posición aleatoria para el enemigo
                formlib::Vec2 enemigoPosicion = {
                    static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Right - formlib::getCelda()))),
                    static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Bottom - formlib::getCelda())))
                };
                enemigo = new Enemigo(enemigoPosicion, spritePersonajes); // Crea un nuevo enemigo en la nueva posición
            }

            // Dibuja el grupo de personajes y el enemigo en el buffer
            grupo->dibujar(buffer->Graphics, spritePersonajes);
            enemigo->dibujar(buffer->Graphics, spritePersonajes);

            // Dibuja la interfaz de vidas y actualiza el texto de vidas
            vidas->dibujar(buffer->Graphics, spriteInterfaz);
            lbl_vidas->Text = "X " + cantidadVidas;

            // Dibuja la interfaz de aliados y actualiza el texto de aliados
            aliados->dibujar(buffer->Graphics, spriteInterfaz);
            lbl_aliados->Text = "X " + gcnew String(std::to_string(grupo->getCantidadAliados()).c_str());

            buffer->Render(graphics); // Renderiza el buffer en la pantalla
        }

        // Método que maneja el evento KeyDown para controlar el movimiento del grupo de personajes
        System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
            if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left) {
                direccion = formlib::Direcciones::Izquierda; // Movimiento a la izquierda
            }
            else if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right) {
                direccion = formlib::Direcciones::Derecha; // Movimiento a la derecha
            }
            else if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up) {
                direccion = formlib::Direcciones::Arriba; // Movimiento hacia arriba
            }
            else if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down) {
                direccion = formlib::Direcciones::Abajo; // Movimiento hacia abajo
            }
        }
    };
}
