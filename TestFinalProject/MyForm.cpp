#include "MyForm.h"

void main(array<String^>^ args)
{
	(*jobGraph).generate();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TestFinalProject::MyForm form;
	Application::Run(% form);
}