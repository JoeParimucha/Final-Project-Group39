#include "MyForm.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;



Job generateJobs(string fileName){
	ifstream inFile;
	inFile.open(fileName, ifstream::in);

}


class Job{
	std::string title;
	int salary;
	Job(std::string _title, int _salary);
};

Job::Job(std::string _title, int _salary){
	title = _title;
	salary = _salary;
}

class Graph{
	std::vector<std::vector<Job>> adjList;
	void insertJob(Job& newJob);

};

void Graph::insertJob(Job& newJob){
	if(adjList.size() == 0){
		vector<Job> tempVec;
		tempVec.push_back(newJob);
		adjList.push_back(tempVec);
	}else{
		for(vector<Job> v : adjList){
			if(v.size() < 5){
				v.push_back(newJob);
			}
		}
	}
}




void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TestFinalProject::MyForm form;
	Application::Run(% form);
	
}

