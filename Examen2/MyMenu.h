#pragma once
#include"MyForm.h"
namespace Examen2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyMenu
	/// </summary>
	public ref class MyMenu : public System::Windows::Forms::Form
	{
	public:
		MyMenu(void)
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
		~MyMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnIniciar;
	protected:
	private: System::Windows::Forms::Button^ btnSalir;

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
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnIniciar
			// 
			this->btnIniciar->Location = System::Drawing::Point(125, 96);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(199, 55);
			this->btnIniciar->TabIndex = 0;
			this->btnIniciar->Text = L"Iniciar Juego";
			this->btnIniciar->UseVisualStyleBackColor = true;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &MyMenu::btnIniciar_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->Location = System::Drawing::Point(125, 198);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(199, 60);
			this->btnSalir->TabIndex = 1;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &MyMenu::btnSalir_Click);
			// 
			// MyMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(493, 372);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnIniciar);
			this->Name = L"MyMenu";
			this->Text = L"MyMenu";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnIniciar_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ frm = gcnew MyForm();
		this->Visible = false;
		frm->ShowDialog();
		this->Visible = true;
		delete frm;

	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
