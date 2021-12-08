#include "MyForm.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>


using namespace System;
using namespace System::Windows::Forms;


/*
class Job {
public:
	int ID;
	std::string title;
	int salary;
	Job(std::string _title, int _salary);
};

Job::Job(std::string _title, int _salary) {
	title = _title;
	salary = _salary;
}

Job generateJob(std::string line) {
	std::vector<std::string> temp;
	std::string title = "";
	std::string pay = "";
	bool readingTitle = false;
	int commaCount = 0;
	for (char c : line) {
		if (commaCount == 2) { //reading title
			if (c == '\"') {
				readingTitle ? readingTitle = false : readingTitle = true;
			}
			if (readingTitle || c != ',') {
				title += c;
			}
			else if (c == ',') {
				commaCount++;
			}
		}
		else if (commaCount == 3) {
			if (c != ',' && c != '.') {
				pay += c;
			}
			else {
				break;
			}
		}
		else if (c == ',') {
			commaCount++;
		}
	}
	Job newJob(title, stoi(pay));
	return newJob;
}

class Graph {
public:
	int goodIndex;
	std::vector<std::vector<Job>> adjList;
	void insertJob(Job& newJob);
	std::vector<Job> search(bool BFS, float variance, int salary);
	std::vector<Job> BFS(float variance, int salary);
	std::vector<Job> DFS(float variance, int salary);
	void generate();
	Graph();
};

Graph::Graph() {
	goodIndex = 0;
	std::vector<Job> smallVec;
	std::vector<std::vector<Job>> bigVec(150000, smallVec);
	adjList = bigVec;
}

void Graph::insertJob(Job& newJob) {
	for (int i = goodIndex; i < adjList.size(); i++) {
		std::vector<Job> v = adjList[i];
		if (v.size() < 5) {
			v.push_back(newJob);
			adjList[i] = v;
			goodIndex = i;
			break;
		}
	}
	std::cout << newJob.ID << std::endl;
}

void Graph::generate() {
	std::ifstream inFile;
	inFile.open("Salaries.csv");
	if (inFile.is_open()) {
		std::cout << "File is open!" << std::endl;
	}
	else {
		std::cout << "File is NOT open!" << std::endl;
	}
	std::string header;
	std::getline(inFile, header);
	std::string line;
	int tempID = 0;
	while (getline(inFile, line)) {
		Job tempJob = generateJob(line);
		tempJob.ID = tempID;
		tempID++;
		this->insertJob(tempJob);
	}
}

std::vector<Job> Graph::search(bool BFS, float variance, int salary) {
	std::vector<Job> result;
	if(BFS){
		result = this->BFS(variance, salary);
	}else{
		result = this->DFS(variance, salary);
	}
	return result;
}

std::vector<Job> Graph::BFS(float variance) {
	std::vector<Job> result;
	//Code BFS Here
	//your code here
	return result;
}

std::vector<Job> Graph::DFS(float variance) {
	std::vector<Job> result;
	//Code DFS Here
	//your code here
	return result;
}
*/
void main(array<String^>^ args)
{
	/*
	Graph* jobGraph = new Graph();
	(*jobGraph).generate();
	*/
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TestFinalProject::MyForm form;
	Application::Run(% form);
}

