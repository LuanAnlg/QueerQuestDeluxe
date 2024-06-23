#pragma once

#include "formlib.h"

namespace QueerQuestDeluxe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Creditos : public System::Windows::Forms::Form
	{
	public:
		// Constructor de Creditos
		Creditos(void) {
			InitializeComponent();

			// Configurar apariencia del formulario
			this->BackColor = formlib::P8AzulOscuro();
			lbl_creditos->Text =
				" - Sean Bienvenidos a nuestro Trabajo Final - \n\n" +
				"Almeida Aguilar, Ivan Antonio: u20231b249\n" +
				"Montoya Torres, Alexander Gabriel: u20231b424\n" +
				"Rafael Sosa, Mariana Alexa: u202315231";
			lbl_creditos->ForeColor = formlib::P8Blanco();
		}

	protected:
		~Creditos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_creditos;
	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lbl_creditos = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_creditos
			// 
			this->lbl_creditos->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_creditos->BackColor = System::Drawing::Color::Transparent;
			this->lbl_creditos->Font = (gcnew System::Drawing::Font(L"Consolas", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_creditos->Location = System::Drawing::Point(0, 0);
			this->lbl_creditos->Name = L"lbl_creditos";
			this->lbl_creditos->Size = System::Drawing::Size(960, 580);
			this->lbl_creditos->TabIndex = 0;
			this->lbl_creditos->Text = L"CREDITOS";
			this->lbl_creditos->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Creditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 576);
			this->Controls->Add(this->lbl_creditos);
			this->Name = L"Creditos";
			this->Text = L"Creditos";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
