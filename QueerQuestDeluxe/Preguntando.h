#pragma once

namespace QueerQuestDeluxe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Preguntando
	/// </summary>
	public ref class Preguntando : public System::Windows::Forms::Form
	{
	public:
		Preguntando(void)
		{
			InitializeComponent();
			

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Preguntando()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_pregunta;
	private: System::Windows::Forms::Button^ btn_opcionA;
	private: System::Windows::Forms::Button^ btn_opcionB;
	private: System::Windows::Forms::Button^ btn_opcionC;
	private: System::Windows::Forms::Button^ btn_opcionD;
	private: System::Windows::Forms::Label^ lbl_respuesta;
	private: System::Windows::Forms::Button^ btn_continuar;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		void quitarPregunta() {
			this->lbl_pregunta->Visible = false;
			this->btn_opcionA->Visible = false;
			this->btn_opcionB->Visible = false;
			this->btn_opcionC->Visible = false;
			this->btn_opcionD->Visible = false;
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbl_pregunta = (gcnew System::Windows::Forms::Label());
			this->btn_opcionB = (gcnew System::Windows::Forms::Button());
			this->btn_opcionC = (gcnew System::Windows::Forms::Button());
			this->btn_opcionD = (gcnew System::Windows::Forms::Button());
			this->btn_opcionA = (gcnew System::Windows::Forms::Button());
			this->lbl_respuesta = (gcnew System::Windows::Forms::Label());
			this->btn_continuar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbl_pregunta
			// 
			this->lbl_pregunta->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_pregunta->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_pregunta->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_pregunta->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lbl_pregunta->Location = System::Drawing::Point(12, 9);
			this->lbl_pregunta->Margin = System::Windows::Forms::Padding(10);
			this->lbl_pregunta->Name = L"lbl_pregunta";
			this->lbl_pregunta->Size = System::Drawing::Size(936, 229);
			this->lbl_pregunta->TabIndex = 0;
			this->lbl_pregunta->Text = L"PREGUNTA";
			this->lbl_pregunta->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// btn_opcionB
			// 
			this->btn_opcionB->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_opcionB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_opcionB->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_opcionB->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_opcionB->Location = System::Drawing::Point(492, 258);
			this->btn_opcionB->Margin = System::Windows::Forms::Padding(10);
			this->btn_opcionB->Name = L"btn_opcionB";
			this->btn_opcionB->Size = System::Drawing::Size(456, 150);
			this->btn_opcionB->TabIndex = 2;
			this->btn_opcionB->Text = L"OPCION B";
			this->btn_opcionB->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_opcionB->UseVisualStyleBackColor = true;
			this->btn_opcionB->Click += gcnew System::EventHandler(this, &Preguntando::btn_opcionB_Click);
			// 
			// btn_opcionC
			// 
			this->btn_opcionC->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_opcionC->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_opcionC->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_opcionC->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_opcionC->Location = System::Drawing::Point(12, 414);
			this->btn_opcionC->Margin = System::Windows::Forms::Padding(10);
			this->btn_opcionC->Name = L"btn_opcionC";
			this->btn_opcionC->Size = System::Drawing::Size(456, 150);
			this->btn_opcionC->TabIndex = 3;
			this->btn_opcionC->Text = L"OPCION C";
			this->btn_opcionC->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_opcionC->UseVisualStyleBackColor = true;
			this->btn_opcionC->Click += gcnew System::EventHandler(this, &Preguntando::btn_opcionC_Click);
			// 
			// btn_opcionD
			// 
			this->btn_opcionD->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_opcionD->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_opcionD->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_opcionD->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_opcionD->Location = System::Drawing::Point(492, 414);
			this->btn_opcionD->Margin = System::Windows::Forms::Padding(10);
			this->btn_opcionD->Name = L"btn_opcionD";
			this->btn_opcionD->Size = System::Drawing::Size(456, 150);
			this->btn_opcionD->TabIndex = 4;
			this->btn_opcionD->Text = L"D) Sacrificar a un aliado para saltar pregunta.";
			this->btn_opcionD->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_opcionD->UseVisualStyleBackColor = true;
			this->btn_opcionD->Click += gcnew System::EventHandler(this, &Preguntando::btn_opcionD_Click);
			// 
			// btn_opcionA
			// 
			this->btn_opcionA->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_opcionA->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_opcionA->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_opcionA->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_opcionA->Location = System::Drawing::Point(12, 258);
			this->btn_opcionA->Margin = System::Windows::Forms::Padding(10);
			this->btn_opcionA->Name = L"btn_opcionA";
			this->btn_opcionA->Size = System::Drawing::Size(456, 150);
			this->btn_opcionA->TabIndex = 1;
			this->btn_opcionA->Text = L"OPCION A";
			this->btn_opcionA->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_opcionA->UseVisualStyleBackColor = true;
			this->btn_opcionA->Click += gcnew System::EventHandler(this, &Preguntando::btn_opcionA_Click);
			// 
			// lbl_respuesta
			// 
			this->lbl_respuesta->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_respuesta->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_respuesta->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_respuesta->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lbl_respuesta->Location = System::Drawing::Point(7, 9);
			this->lbl_respuesta->Margin = System::Windows::Forms::Padding(10);
			this->lbl_respuesta->Name = L"lbl_respuesta";
			this->lbl_respuesta->Size = System::Drawing::Size(941, 450);
			this->lbl_respuesta->TabIndex = 5;
			this->lbl_respuesta->Text = L"RESPUESTA";
			this->lbl_respuesta->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lbl_respuesta->Visible = false;
			// 
			// btn_continuar
			// 
			this->btn_continuar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_continuar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_continuar->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_continuar->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_continuar->Location = System::Drawing::Point(703, 479);
			this->btn_continuar->Margin = System::Windows::Forms::Padding(10);
			this->btn_continuar->Name = L"btn_continuar";
			this->btn_continuar->Size = System::Drawing::Size(245, 85);
			this->btn_continuar->TabIndex = 6;
			this->btn_continuar->Text = L"Continuar";
			this->btn_continuar->UseVisualStyleBackColor = true;
			this->btn_continuar->Visible = false;
			this->btn_continuar->Click += gcnew System::EventHandler(this, &Preguntando::btn_continuar_Click);
			// 
			// Preguntando
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 576);
			this->Controls->Add(this->btn_continuar);
			this->Controls->Add(this->lbl_respuesta);
			this->Controls->Add(this->btn_opcionA);
			this->Controls->Add(this->btn_opcionD);
			this->Controls->Add(this->btn_opcionC);
			this->Controls->Add(this->btn_opcionB);
			this->Controls->Add(this->lbl_pregunta);
			this->Name = L"Preguntando";
			this->Text = L"Preguntando";
			this->Load += gcnew System::EventHandler(this, &Preguntando::Preguntando_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Preguntando_Load(System::Object^ sender, System::EventArgs^ e) {
		this->BackColor = Color::FromArgb(255, 29, 43, 83);
		this->lbl_pregunta->BackColor = Color::FromArgb(255, 255, 241, 232);
		this->btn_opcionA->BackColor = Color::FromArgb(255, 41, 173, 255);
		this->btn_opcionB->BackColor = Color::FromArgb(255, 255, 236, 39);
		this->btn_opcionC->BackColor = Color::FromArgb(255, 255, 0, 77);
		this->btn_opcionD->BackColor = Color::FromArgb(255, 0, 228, 54);
		this->lbl_respuesta->BackColor = Color::FromArgb(255, 255, 119, 168);
		this->btn_continuar->BackColor = Color::FromArgb(255, 255, 163, 0);
	}
	private: System::Void btn_opcionA_Click(System::Object^ sender, System::EventArgs^ e) {
		quitarPregunta();
		this->lbl_respuesta->Visible = true;
		this->btn_continuar->Visible = true;
	}
	private: System::Void btn_opcionB_Click(System::Object^ sender, System::EventArgs^ e) {
		quitarPregunta();
		this->lbl_respuesta->Visible = true;
		this->btn_continuar->Visible = true;
	}
	private: System::Void btn_opcionC_Click(System::Object^ sender, System::EventArgs^ e) {
		quitarPregunta();
		this->lbl_respuesta->Visible = true;
		this->btn_continuar->Visible = true;
	}
	private: System::Void btn_opcionD_Click(System::Object^ sender, System::EventArgs^ e) {
		quitarPregunta();
		this->lbl_respuesta->Visible = true;
		this->btn_continuar->Visible = true;
	}
private: System::Void btn_continuar_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}
