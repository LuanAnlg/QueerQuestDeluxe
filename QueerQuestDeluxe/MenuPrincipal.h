#pragma once

#include "Juego.h"

namespace QueerQuestDeluxe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_jugarFacil;
	private: System::Windows::Forms::Button^ btn_jugarDificil;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_jugarFacil = (gcnew System::Windows::Forms::Button());
			this->btn_jugarDificil = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_jugarFacil
			// 
			this->btn_jugarFacil->Location = System::Drawing::Point(366, 283);
			this->btn_jugarFacil->Name = L"btn_jugarFacil";
			this->btn_jugarFacil->Size = System::Drawing::Size(75, 23);
			this->btn_jugarFacil->TabIndex = 0;
			this->btn_jugarFacil->Text = L"Facil";
			this->btn_jugarFacil->UseVisualStyleBackColor = true;
			this->btn_jugarFacil->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_jugarFacil_Click);
			// 
			// btn_jugarDificil
			// 
			this->btn_jugarDificil->Location = System::Drawing::Point(532, 283);
			this->btn_jugarDificil->Name = L"btn_jugarDificil";
			this->btn_jugarDificil->Size = System::Drawing::Size(75, 23);
			this->btn_jugarDificil->TabIndex = 1;
			this->btn_jugarDificil->Text = L"Dificil";
			this->btn_jugarDificil->UseVisualStyleBackColor = true;
			this->btn_jugarDificil->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_jugarDificil_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 576);
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
	};
}
