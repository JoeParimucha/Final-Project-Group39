#include "MyForm.h"


void main(array<String^>^ args)
{

	Graph* jobGraph = new Graph();
	(*jobGraph).generate();
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TestFinalProject::MyForm form;
	Application::Run(% form);
}



