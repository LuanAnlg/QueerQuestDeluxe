#pragma once

#include "formlib.h"
#include "Personaje.h"

namespace QueerQuestDeluxe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Puntaje : public System::Windows::Forms::Form {
	public:
		Puntaje(int cantidadVidas, int cantidadAliados) {
			InitializeComponent();

			graphics = this->CreateGraphics();
			spriteInterfaz = gcnew Bitmap("Sprites\\Interfaz.png");

			// Crear interfaz de vidas y aliados
			vidas = new Personaje({ static_cast<float>(formlib::getCelda() / 2), static_cast<float>(formlib::getCelda()) },
				spriteInterfaz, { 1, 2 }, { 0, 0 }, { 0, 0 }, 1, 1);
			aliados = new Personaje({ static_cast<float>(3 * formlib::getCelda() - (formlib::getCelda() / 2)), static_cast<float>(formlib::getCelda()) },
				spriteInterfaz, { 1, 2 }, { 0, 0 }, { 0, 1 }, 1, 1);

			this->BackColor = formlib::P8AzulOscuro();
			puntaje = (cantidadVidas * 200) + (cantidadAliados * 100);

			lbl_vidas->Text = "X " + cantidadVidas;
			lbl_vidas->BackColor = formlib::P8Rosa();
			lbl_aliados->Text = "X " + cantidadAliados;
			lbl_aliados->BackColor = formlib::P8Azul();
			lbl_puntaje->Text = "Puntaje: " + puntaje;
			lbl_puntaje->BackColor = formlib::P8Amarillo();
			btn_terminar->BackColor = formlib::P8Verde();
		}
	protected:
		~Puntaje()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ lbl_aliados;
		System::Windows::Forms::Label^ lbl_vidas;
		System::Windows::Forms::Label^ lbl_puntaje;
	private: System::ComponentModel::IContainer^ components;

		System::Windows::Forms::Button^ btn_terminar;
		int puntaje;
		Graphics^ graphics;
		Bitmap^ spriteInterfaz;
		Personaje* vidas;
	private: System::Windows::Forms::Timer^ tiempoDelta;
		   Personaje* aliados;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->lbl_aliados = (gcnew System::Windows::Forms::Label());
			this->lbl_vidas = (gcnew System::Windows::Forms::Label());
			this->lbl_puntaje = (gcnew System::Windows::Forms::Label());
			this->btn_terminar = (gcnew System::Windows::Forms::Button());
			this->tiempoDelta = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// lbl_aliados
			// 
			this->lbl_aliados->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_aliados->BackColor = System::Drawing::Color::Transparent;
			this->lbl_aliados->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_aliados->Location = System::Drawing::Point(192, 64);
			this->lbl_aliados->Name = L"lbl_aliados";
			this->lbl_aliados->Size = System::Drawing::Size(96, 32);
			this->lbl_aliados->TabIndex = 3;
			this->lbl_aliados->Text = L"X 2";
			// 
			// lbl_vidas
			// 
			this->lbl_vidas->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_vidas->BackColor = System::Drawing::Color::Transparent;
			this->lbl_vidas->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_vidas->Location = System::Drawing::Point(64, 64);
			this->lbl_vidas->Name = L"lbl_vidas";
			this->lbl_vidas->Size = System::Drawing::Size(64, 32);
			this->lbl_vidas->TabIndex = 2;
			this->lbl_vidas->Text = L"X 3";
			// 
			// lbl_puntaje
			// 
			this->lbl_puntaje->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_puntaje->BackColor = System::Drawing::Color::Transparent;
			this->lbl_puntaje->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_puntaje->Location = System::Drawing::Point(32, 160);
			this->lbl_puntaje->Name = L"lbl_puntaje";
			this->lbl_puntaje->Size = System::Drawing::Size(256, 32);
			this->lbl_puntaje->TabIndex = 4;
			this->lbl_puntaje->Text = L"PUNTAJE: ";
			// 
			// btn_terminar
			// 
			this->btn_terminar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_terminar->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_terminar->Location = System::Drawing::Point(80, 224);
			this->btn_terminar->Name = L"btn_terminar";
			this->btn_terminar->Size = System::Drawing::Size(160, 64);
			this->btn_terminar->TabIndex = 5;
			this->btn_terminar->Text = L"Terminar";
			this->btn_terminar->UseVisualStyleBackColor = true;
			this->btn_terminar->Click += gcnew System::EventHandler(this, &Puntaje::btn_terminar_Click);
			// 
			// tiempoDelta
			// 
			this->tiempoDelta->Enabled = true;
			this->tiempoDelta->Tick += gcnew System::EventHandler(this, &Puntaje::tiempoDelta_Tick);
			// 
			// Puntaje
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(320, 320);
			this->Controls->Add(this->btn_terminar);
			this->Controls->Add(this->lbl_puntaje);
			this->Controls->Add(this->lbl_aliados);
			this->Controls->Add(this->lbl_vidas);
			this->Name = L"Puntaje";
			this->Text = L"Puntaje";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_terminar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void tiempoDelta_Tick(System::Object^ sender, System::EventArgs^ e) {
		// Dibujar los personajes
		vidas->dibujar(graphics, spriteInterfaz);
		aliados->dibujar(graphics, spriteInterfaz);
	}
};
}
