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

class Graph{
	std::vector<std::vector<Job>> adjList;
	void insertJob(Job& newJob);
	vector<Job> BFS(float variance);
	vector<Job> DFS(float variance);
	void generate();
};

void Graph::insertJob(Job& newJob){
	if(adjList.size() == 0){
		vector<Job> tempVec;
		tempVec.push_back(newJob);
		adjList.push_back(tempVec);
	}else{
		for (int i = 0; i < adjList.size(); i++) {
			vector<Job> v = adjList[i];
			if(v.size() < 5){
				v.push_back(newJob);
			}
			int numVerts = 0;
			for(vector<Job> vert : adjList){
				numVerts += vert.size();
			}
		}
	}
}

void Graph::generate(){
	ifstream inFile;
	inFile.open(Salaries.csv);
	string header;
	getline(inFile, header);
	string line;
	int tempID = 0;
	while(getline(inFile, line)){
		Job tempJob = generateJob(line);

		this->insertJob(tempJob);
	}
}

Job generateJob(string line){
	vector<string> temp;
	string title = "";
	string pay = "";
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
		}else if(commaCount = 3){
			if(c != ',' && c != "."){
				pay += c;
			}else{
				break;
			}
		}
	}
	Job newJob(title, stoi(pay));
	return newJob;
}

void main(array<String^>^ args)
{


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TestFinalProject::MyForm form;
	Application::Run(% form);
	
	Graph* jobGraph = new Graph();
	(*jobGraph).generate();
	


}

