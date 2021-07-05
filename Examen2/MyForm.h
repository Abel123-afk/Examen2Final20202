#pragma once
#include"CControladora.h"
#include"CArchivoTexto.h"
namespace Examen2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			miarchivo = new CArchivoTexto();
			S = miarchivo->retornarNumero("configuracion.txt", 0);
			T = miarchivo->retornarNumero("configuracion.txt", 1);
			g = this->CreateGraphics();
			obj = new CControladora(S,T);
			imgJugador = gcnew Bitmap("imagenes\\ambulancia.png");
			imgPersonaje1= gcnew Bitmap("imagenes\\personaje1.png");
			imgPersonaje2= gcnew Bitmap("imagenes\\personaje2.png");
		}
	private:
		Graphics^ g;
		CControladora* obj;
		Bitmap^ imgJugador;
		Bitmap^ imgPersonaje1;
		Bitmap^ imgPersonaje2;
		CArchivoTexto* miarchivo;
		int S, T;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblPuntos;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblTime;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblPuntos = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(58, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Puntos:";
			// 
			// lblPuntos
			// 
			this->lblPuntos->AutoSize = true;
			this->lblPuntos->Location = System::Drawing::Point(137, 13);
			this->lblPuntos->Name = L"lblPuntos";
			this->lblPuntos->Size = System::Drawing::Size(16, 17);
			this->lblPuntos->TabIndex = 1;
			this->lblPuntos->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(447, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Time:";
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Location = System::Drawing::Point(514, 12);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(16, 17);
			this->lblTime->TabIndex = 3;
			this->lblTime->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(635, 489);
			this->Controls->Add(this->lblTime);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblPuntos);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(BackColor);
		obj->run(buffer->Graphics, imgJugador, imgPersonaje1, imgPersonaje2);
		lblTime->Text = "" + obj->getTime();
		lblPuntos->Text = "" + obj->getPuntos();
		if (obj->getTermino())
		{
			timer1->Enabled = false;
			MessageBox::Show("Perdiste");
			this->Close();
		}
		else if (obj->getGano())
		{
			timer1->Enabled = false;
			MessageBox::Show("Ganaste");
			this->Close();
		}
		else
		{
			buffer->Render(g);
		}
		delete buffer;

	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		switch (e->KeyData)
		{
		case Keys::Left:
			obj->tecla('A');
			break;
		case Keys::Right:
			obj->tecla('D');
			break;
		case Keys::Up:
			obj->tecla('W');
			break;
		case Keys::Down:
			obj->tecla('S');
			break;
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		obj->tecla('N');
	}
	};
}
