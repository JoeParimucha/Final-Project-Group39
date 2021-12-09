#include "MyForm.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <chrono>

using namespace System;
using namespace System::Windows::Forms;



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


class Graph {
public:
	int goodIndex;
	std::vector<std::vector<Job>> adjList;
	void insertJob(Job& newJob);
	std::vector<Job> search(bool BFS, float variance, int salary, int& timeTaken);
	std::vector<Job> BFS(float variance, int salary, int& timeTaken);
	std::vector<Job> DFS(float variance, int salary, int& timeTaken);
	void generate();
	Graph();
};


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

std::vector<Job> Graph::search(bool BFS, float variance, int salary, int& timeTaken) {
	std::vector<Job> result;
	if(BFS){
		//result = this->BFS(variance, salary, timeTaken);
	}else{
		//result = this->DFS(variance, salary, timeTaken);
	}
	return result;
}


std::vector<Job> Graph::BFS(float variance, int salary, int& timeTaken) {
	auto start = std::chrono::steady_clock::now();
	//Code BFS Here (return a vector of 10 jobs, that meet the variance factor, aka if its 70,000 and a variance of 10%, 
	//return the first 10 found within 63,000 and 77,000)
	//your code here
	std::vector<Job> result;
	int min = salary - (salary * variance);
	int max = salary + (salary * variance);
	for (int i = 0; i < adjList.size(); i++)
	{
		if (result.size() == 10)
		{
			break;
		}
		std::vector<Job>& tempVec = adjList[i];
		for (int j = 0; j < tempVec.size(); j++)
		{
			if (result.size() == 10)
			{
				break;
			}
			if (tempVec[j].salary >= min && tempVec[j].salary <= max)
			{
				result.push_back(tempVec[j]);
			}
		}
	}

	auto end = std::chrono::steady_clock::now();
	double finalTime = double(std::chrono::duration_cast <std::chrono::milliseconds> (end - start).count());
	int timeTook = int(finalTime);

	timeTaken = timeTook;

	return result;
}


std::vector<Job> Graph::DFS(float variance, int salary, int& timeTaken) {
	auto start = std::chrono::steady_clock::now();
	std::vector<Job> result;
	//Code DFS Here (return a vector of 10 jobs, that meet the variance factor, aka if its 70,000 and a variance of 10%, 
	//return the first 10 found within 63,000 and 77,000)
	int min = salary - (salary * variance);
	int max = salary + (salary * variance);

	std::map<std::vector<Job>, bool> vecMap;
	for (int i = 0; i < adjList.size(); i++)
	{
		if (result.size() == 10)
		{
			break;
		}
		if (vecMap.find(adjList[i]) == vecMap.end())
		{
			vecMap[adjList[i]] == true;
			for (auto j = adjList[i].begin(); j != adjList[i].end(); j++)
			{
				if (result.size() == 10)
				{
					break;
				}
				if ((*j).salary >= min && (*j).salary <= max)
				{
					result.push_back(*j);
				}

			}
		}
	}

	auto end = std::chrono::steady_clock::now();
	double finalTime = double(std::chrono::duration_cast <std::chrono::milliseconds> (end - start).count());
	int timeTook = int(finalTime);
	timeTaken = timeTook;

	return result;
}


void main(array<String^>^ args)
{

	Graph* jobGraph = new Graph();
	(*jobGraph).generate();
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TestFinalProject::MyForm form;
	Application::Run(% form);
}

