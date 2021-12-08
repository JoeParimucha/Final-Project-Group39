#include "MyForm.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>


using namespace System;
using namespace System::Windows::Forms;



class Job{
public:
	int ID;
	std::string title;
	int salary;
	Job(std::string _title, int _salary);
};

Job::Job(std::string _title, int _salary){
	title = _title;
	salary = _salary;
}

Job generateJob(std::string line){
	std::vector<std::string> temp;
	std::string title = "";
	std::string pay = "";
	bool readingTitle = false;
	int commaCount = 0;
	for(char c : line){
		if(commaCount == 2){ //reading title
			if(c == '\"'){
				readingTitle ? false : true;
			}
			if(readingTitle){
				title += c;
			}else if(c == ','){
				commaCount++;
			}
		}else if(commaCount == 3){
			if(c != ',' && c != '.'){
				pay += c;
			}else{
				break;
			}
		}
	}
	Job newJob(title, stoi(pay));
	return newJob;
}

class Graph{
public:
	std::vector<std::vector<Job>> adjList;
	void insertJob(Job& newJob);
	std::vector<Job> BFS(float variance);
	std::vector<Job> DFS(float variance);
	void generate();
	Graph();
};

Graph::Graph(){
	std::vector<Job> smallVec;
	std::vector<std::vector<Job>> bigVec(150000, smallVec);
}

void Graph::insertJob(Job& newJob){
	for (int i = 0; i < adjList.size(); i++) {
		std::vector<Job> v = adjList[i];
		if (v.size() < 5) {
			v.push_back(newJob);
			break;
		}
	}
}

void Graph::generate(){
	std::ifstream inFile;
	inFile.open("Salaries.csv");
	std::string header;
	std::getline(inFile, header);
	std::string line;
	int tempID = 0;
	while(getline(inFile, line)){
		Job tempJob = generateJob(line);
		tempJob.ID = tempID;
		tempID++;
		this->insertJob(tempJob);
	}
}

std::vector<Job> Graph::BFS(float variance){
	std::vector<Job> result;

	return result;
}

std::vector<Job> Graph::DFS(float variance){
	std::vector<Job> result;

	return result;
}

void main(array<String^>^ args)
{
	Graph* jobGraph = new Graph();
	(*jobGraph).generate();
	for(std::vector<Job> v : (*jobGraph).adjList){
		std::cout << v[0].title << std::endl;
	}
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TestFinalProject::MyForm form;
	Application::Run(% form);
	
	
	


}

