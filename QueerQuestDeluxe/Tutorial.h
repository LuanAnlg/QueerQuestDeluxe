#pragma once

#include "Robot.h"
#include "Enemigo.h"

namespace QueerQuestDeluxe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Tutorial : public System::Windows::Forms::Form {
	public:
		Tutorial(void) {
			InitializeComponent();
			// Configura colores de los componentes
			this->BackColor = formlib::P8AzulOscuro();
			lbl_movimiento->BackColor = formlib::P8Rojo();
			lbl_objetivo->BackColor = formlib::P8Azul();
			lbl_trivia->BackColor = formlib::P8Amarillo();
			lbl_desacoplar->BackColor = formlib::P8Verde();
			btn_continuar->BackColor = formlib::P8Naranja();
			btn_continuar->ForeColor = formlib::P8Blanco();

			// Inicialización de gráficos y buffer
			graphics = CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(graphics, ClientRectangle);

			// Carga los sprites necesarios
			spritePersonajes = gcnew Bitmap("Sprites\\Personajes.png");

			// Crea el robot y el enemigo en posiciones aleatorias
			robot = new Robot(nuevaPosicion(), spritePersonajes);
			enemigo = new Enemigo({448, 258}, spritePersonajes);

			// Dirección inicial del robot
			direccion = formlib::Direcciones::Ninguno;

		}

	protected:
		~Tutorial() {
			if (components) {
				delete components;
			}
		}

	private:
		// Variables y componentes de la interfaz de usuario
		System::Windows::Forms::Label^ lbl_movimiento;
		System::Windows::Forms::Label^ lbl_objetivo;
		System::Windows::Forms::Label^ lbl_trivia;
		System::Windows::Forms::Label^ lbl_desacoplar;
		System::Windows::Forms::Button^ btn_continuar;
		System::Windows::Forms::Timer^ tiempoDelta;
		System::ComponentModel::IContainer^ components;
		Graphics^ graphics;
		BufferedGraphics^ buffer;
		Bitmap^ spritePersonajes;
		Robot* robot;
		Enemigo* enemigo;
		formlib::Direcciones direccion;

		// Oculta la primera parte del tutorial
		void ocultarParte1() {
			lbl_movimiento->Visible = false;
			lbl_objetivo->Visible = false;
			btn_continuar->Visible = false;
		}

		// Muestra la segunda parte del tutorial
		void mostrarParte2() {
			lbl_trivia->Visible = true;
			lbl_desacoplar->Visible = true;
		}

		// Genera una nueva posición aleatoria dentro de los límites de la pantalla
		formlib::Vec2 nuevaPosicion() {
			return {
				static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Right - formlib::getCelda()))),
				static_cast<float>(formlib::getAleatorio(0, static_cast<int>(graphics->VisibleClipBounds.Bottom - formlib::getCelda())))
			};
		}

		// Genera una nueva dirección aleatoria
		formlib::Direcciones nuevaDireccion() {
			return static_cast<formlib::Direcciones>(formlib::getAleatorio(0, 3));
		}

#pragma region Windows Form Designer generated code

		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->lbl_movimiento = (gcnew System::Windows::Forms::Label());
			this->lbl_objetivo = (gcnew System::Windows::Forms::Label());
			this->lbl_trivia = (gcnew System::Windows::Forms::Label());
			this->lbl_desacoplar = (gcnew System::Windows::Forms::Label());
			this->btn_continuar = (gcnew System::Windows::Forms::Button());
			this->tiempoDelta = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// lbl_movimiento
			// 
			this->lbl_movimiento->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_movimiento->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_movimiento->Location = System::Drawing::Point(32, 288);
			this->lbl_movimiento->Name = L"lbl_movimiento";
			this->lbl_movimiento->Size = System::Drawing::Size(416, 192);
			this->lbl_movimiento->TabIndex = 0;
			this->lbl_movimiento->Text = L"Para moverte pude usar las tacas W, A, S, D, como las teclas direccionales.";
			this->lbl_movimiento->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_objetivo
			// 
			this->lbl_objetivo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_objetivo->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_objetivo->Location = System::Drawing::Point(512, 288);
			this->lbl_objetivo->Name = L"lbl_objetivo";
			this->lbl_objetivo->Size = System::Drawing::Size(416, 192);
			this->lbl_objetivo->TabIndex = 1;
			this->lbl_objetivo->Text = L"Tu objetivo sera transformar a tus \"enemigos\" en aliados a traves del dialogo y e"
				L"l buen trato. Para dialogar tienes que colicionar con ellos.";
			this->lbl_objetivo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_trivia
			// 
			this->lbl_trivia->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_trivia->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_trivia->Location = System::Drawing::Point(32, 32);
			this->lbl_trivia->Name = L"lbl_trivia";
			this->lbl_trivia->Size = System::Drawing::Size(416, 192);
			this->lbl_trivia->TabIndex = 2;
			this->lbl_trivia->Text = L"Cuando converses con un \"enemigo\" visualizaras una pequena trivia, si la constest"
				L"as bien tendras un nuevo aliado y si la constestas mal perderas una vida.";
			this->lbl_trivia->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lbl_trivia->Visible = false;
			// 
			// lbl_desacoplar
			// 
			this->lbl_desacoplar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_desacoplar->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_desacoplar->Location = System::Drawing::Point(512, 32);
			this->lbl_desacoplar->Name = L"lbl_desacoplar";
			this->lbl_desacoplar->Size = System::Drawing::Size(416, 192);
			this->lbl_desacoplar->TabIndex = 3;
			this->lbl_desacoplar->Text = L"Siempre puedes seleccionar la opcion D para desacoplar a un aliado de tu grupo y "
				L"saltar la pregunta.";
			this->lbl_desacoplar->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lbl_desacoplar->Visible = false;
			// 
			// btn_continuar
			// 
			this->btn_continuar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_continuar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_continuar->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_continuar->Location = System::Drawing::Point(736, 480);
			this->btn_continuar->Name = L"btn_continuar";
			this->btn_continuar->Size = System::Drawing::Size(192, 64);
			this->btn_continuar->TabIndex = 4;
			this->btn_continuar->Text = L"Continuar";
			this->btn_continuar->UseVisualStyleBackColor = true;
			this->btn_continuar->Click += gcnew System::EventHandler(this, &Tutorial::btn_continuar_Click);
			// 
			// tiempoDelta
			// 
			this->tiempoDelta->Enabled = true;
			this->tiempoDelta->Tick += gcnew System::EventHandler(this, &Tutorial::tiempoDelta_Tick);
			// 
			// Tutorial
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 576);
			this->Controls->Add(this->btn_continuar);
			this->Controls->Add(this->lbl_desacoplar);
			this->Controls->Add(this->lbl_trivia);
			this->Controls->Add(this->lbl_objetivo);
			this->Controls->Add(this->lbl_movimiento);
			this->Name = L"Tutorial";
			this->Text = L"Tutorial";
			this->ResumeLayout(false);

		}

#pragma endregion
	
	private:
		// Evento del botón Continuar
		System::Void btn_continuar_Click(System::Object^ sender, System::EventArgs^ e) {
			ocultarParte1();
			mostrarParte2();
		}

		// Evento del Timer, se ejecuta en cada tick
		System::Void tiempoDelta_Tick(System::Object^ sender, System::EventArgs^ e) {
			buffer->Graphics->Clear(formlib::P8AzulOscuro());
			if (formlib::getAleatorio(0, 2) == 0) {
				direccion = nuevaDireccion();
			}
			robot->actualizar(graphics, direccion);
			robot->dibujar(buffer->Graphics, spritePersonajes);
			enemigo->dibujar(buffer->Graphics, spritePersonajes);
			buffer->Render(graphics);
		}
	};
}
