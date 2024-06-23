#pragma once

#include "Juego.h"
#include "Creditos.h"

namespace QueerQuestDeluxe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuPrincipal : public System::Windows::Forms::Form {
	public:
		MenuPrincipal(void) {
			InitializeComponent();
			this->BackColor = formlib::P8AzulOscuro();
			lbl_queerQuest->BackColor = formlib::P8MoradoOscuro();
			lbl_queerQuest->ForeColor = formlib::P8Blanco();
			lbl_nuevaPartida->BackColor = formlib::P8Lavanda();
			btn_jugarFacil->BackColor = formlib::P8Rosa();
			btn_jugarDificil->BackColor = formlib::P8Azul();
			btn_creditos->BackColor = formlib::P8Amarillo();
			btn_tutorial->BackColor = formlib::P8Verde();
		}

	protected:
		~MenuPrincipal() {
			if (components) {
				delete components;
			}
		}
	private:
		System::Windows::Forms::Button^ btn_jugarFacil;
		System::Windows::Forms::Button^ btn_jugarDificil;
		System::Windows::Forms::Label^ lbl_nuevaPartida;
		System::Windows::Forms::Label^ lbl_queerQuest;
		System::Windows::Forms::Button^ btn_creditos;
		System::Windows::Forms::Button^ btn_tutorial;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void) {
			this->btn_jugarFacil = (gcnew System::Windows::Forms::Button());
			this->btn_jugarDificil = (gcnew System::Windows::Forms::Button());
			this->lbl_nuevaPartida = (gcnew System::Windows::Forms::Label());
			this->lbl_queerQuest = (gcnew System::Windows::Forms::Label());
			this->btn_creditos = (gcnew System::Windows::Forms::Button());
			this->btn_tutorial = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_jugarFacil
			// 
			this->btn_jugarFacil->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_jugarFacil->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_jugarFacil->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_jugarFacil->Location = System::Drawing::Point(304, 288);
			this->btn_jugarFacil->Name = L"btn_jugarFacil";
			this->btn_jugarFacil->Size = System::Drawing::Size(160, 64);
			this->btn_jugarFacil->TabIndex = 0;
			this->btn_jugarFacil->Text = L"Facil";
			this->btn_jugarFacil->UseVisualStyleBackColor = true;
			this->btn_jugarFacil->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_jugarFacil_Click);
			// 
			// btn_jugarDificil
			// 
			this->btn_jugarDificil->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_jugarDificil->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_jugarDificil->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_jugarDificil->Location = System::Drawing::Point(496, 288);
			this->btn_jugarDificil->Name = L"btn_jugarDificil";
			this->btn_jugarDificil->Size = System::Drawing::Size(160, 64);
			this->btn_jugarDificil->TabIndex = 1;
			this->btn_jugarDificil->Text = L"Dificil";
			this->btn_jugarDificil->UseVisualStyleBackColor = true;
			this->btn_jugarDificil->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_jugarDificil_Click);
			// 
			// lbl_nuevaPartida
			// 
			this->lbl_nuevaPartida->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_nuevaPartida->Font = (gcnew System::Drawing::Font(L"Consolas", 32.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nuevaPartida->Location = System::Drawing::Point(304, 224);
			this->lbl_nuevaPartida->Name = L"lbl_nuevaPartida";
			this->lbl_nuevaPartida->Size = System::Drawing::Size(352, 64);
			this->lbl_nuevaPartida->TabIndex = 2;
			this->lbl_nuevaPartida->Text = L"Nueva Partida";
			this->lbl_nuevaPartida->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_queerQuest
			// 
			this->lbl_queerQuest->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_queerQuest->Font = (gcnew System::Drawing::Font(L"Consolas", 96, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_queerQuest->Location = System::Drawing::Point(80, 32);
			this->lbl_queerQuest->Name = L"lbl_queerQuest";
			this->lbl_queerQuest->Size = System::Drawing::Size(800, 192);
			this->lbl_queerQuest->TabIndex = 3;
			this->lbl_queerQuest->Text = L"QueerQuest";
			this->lbl_queerQuest->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_creditos
			// 
			this->btn_creditos->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_creditos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_creditos->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_creditos->Location = System::Drawing::Point(304, 384);
			this->btn_creditos->Name = L"btn_creditos";
			this->btn_creditos->Size = System::Drawing::Size(352, 64);
			this->btn_creditos->TabIndex = 4;
			this->btn_creditos->Text = L"Creditos";
			this->btn_creditos->UseVisualStyleBackColor = true;
			this->btn_creditos->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_creditos_Click);
			// 
			// btn_tutorial
			// 
			this->btn_tutorial->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_tutorial->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_tutorial->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_tutorial->Location = System::Drawing::Point(304, 480);
			this->btn_tutorial->Name = L"btn_tutorial";
			this->btn_tutorial->Size = System::Drawing::Size(352, 64);
			this->btn_tutorial->TabIndex = 5;
			this->btn_tutorial->Text = L"Tutorial";
			this->btn_tutorial->UseVisualStyleBackColor = true;
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 576);
			this->Controls->Add(this->btn_tutorial);
			this->Controls->Add(this->btn_creditos);
			this->Controls->Add(this->lbl_queerQuest);
			this->Controls->Add(this->lbl_nuevaPartida);
			this->Controls->Add(this->btn_jugarDificil);
			this->Controls->Add(this->btn_jugarFacil);
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_jugarFacil_Click(System::Object^ sender, System::EventArgs^ e) {
		Juego^ juego = gcnew Juego(formlib::Dificultades::Facil);
		juego->ShowDialog();
		delete juego;
	}
	private: System::Void btn_jugarDificil_Click(System::Object^ sender, System::EventArgs^ e) {
		Juego^ juego = gcnew Juego(formlib::Dificultades::Dificil);
		juego->ShowDialog();
		delete juego;
	}
	private: System::Void btn_creditos_Click(System::Object^ sender, System::EventArgs^ e) {
		Creditos^ creditos = gcnew Creditos();
		creditos->ShowDialog();
		delete creditos;
	}
};
}
