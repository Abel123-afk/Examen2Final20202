#include "MyForm.h"
#include"MyMenu.h"
using namespace System;
using namespace Windows::Forms;
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Examen2::MyMenu());
}
