#include "MyForm.h"

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TestFinalProject::MyForm form;
	Application::Run(% form);
}