#pragma once
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <vector>
#include <fstream>
#include <map>
#include <chrono>
#include <stack>

using namespace System;
using namespace System::Windows::Forms;
bool firstSearch = true;


class Job {
public:
	int ID;
	std::string title;
	int salary;
	Job(std::string _title, int _salary);
	bool operator< (const Job& rhs) const noexcept {
		return this->salary < this->salary;
	}
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
		if (adjList[i].size() < 5) {
			adjList[i].push_back(newJob);
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
		insertJob(tempJob);
	}
}

std::vector<Job> Graph::BFS(float variance, int salary, int& timeTaken) {
	auto start = std::chrono::steady_clock::now();
	//Code BFS Here (return a vector of 10 jobs, that meet the variance factor, aka if its 70,000 and a variance of 10%, 
	//return the first 10 found within 63,000 and 77,000)
	//your code here
	std::vector<Job> result;
	int min = salary - (salary * (variance / 100));
	int max = salary + (salary * (variance / 100));
	for (int i = 0; i < adjList.size(); i++)
	{
		//std::cout << "Line at: " << i << std::endl;
		std::vector<Job>& tempVec = adjList[i];
		for (int j = 0; j < tempVec.size(); j++)
		{
			if (result.size() == 10)
			{
				break;
			}
			int jSal = tempVec[j].salary;
			if (jSal >= min && jSal <= max)
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
	//your code here
	int min = salary - (salary * (variance / 100));
	int max = salary + (salary * (variance / 100));

	std::stack<int> s;
	std::map<Job, bool> tempMap;
	int index = 0;

	s.push(adjList[0][0]);

	while (!s.empty())
	{
		if (result.size() == 10)
		{
			break;
		}

		Job front = s.top();
		s.pop();

		if (tempMap.find(front) != tempMap.end())
		{
			continue;
		}

		tempMap[front] = true;
		int jSal = front.salary;
		if (jSal >= min && jSal <= max)
		{
			result.push_back(front);
		}

		for (auto i = adjList[index].begin(); i != adjList[index].end(); i++)
		{
			Job temp = *i;
			if (tempMap.find(temp) == tempMap.end())
			{
				s.push(temp);
			}
		}

		index++;


	}


	auto end = std::chrono::steady_clock::now();
	double finalTime = double(std::chrono::duration_cast <std::chrono::milliseconds> (end - start).count());
	int timeTook = int(finalTime);
	timeTaken = timeTook;

	return result;
}


std::vector<Job> Graph::search(bool BFS, float variance, int salary, int& timeTaken) {
	std::vector<Job> result;

	
	if (BFS) {
		result = this->BFS(variance, salary, timeTaken);
	}
	else {
		result = this->DFS(variance, salary, timeTaken);
	}
	return result;
}

extern Graph* jobGraph = new Graph();



namespace TestFinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace std;
	bool BFSChecked = false;
	bool DFSChecked = false;
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
		}

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
	private: System::Windows::Forms::Label^ DesiredSalary;
	protected:


	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Label^ BFSSearchTime;
	private: System::Windows::Forms::Label^ DFSSearchTime;
	protected:




	private: System::Windows::Forms::Label^ Instructions;


	private: System::Windows::Forms::TextBox^ DesiredSalaryBox;
	private: System::Windows::Forms::TextBox^ BFSSearchBox;
	private: System::Windows::Forms::TextBox^ DFSSearchBox;





	private: System::Windows::Forms::Button^ SearchClickyBox;

	private: System::Windows::Forms::Label^ Salary;





	private: System::Windows::Forms::Label^ JobTitle;
	private: System::Windows::Forms::Button^ SanFranciscoJobWebsiteButton;
	private: System::Windows::Forms::TableLayoutPanel^ Table_Jobs_Salary;
	private: System::Windows::Forms::Label^ Salary10;
	private: System::Windows::Forms::Label^ JobTitle10;
	private: System::Windows::Forms::Label^ Salary9;
	private: System::Windows::Forms::Label^ JobTitle9;
	private: System::Windows::Forms::Label^ Salary8;
	private: System::Windows::Forms::Label^ JobTitle8;
	private: System::Windows::Forms::Label^ Salary7;
	private: System::Windows::Forms::Label^ JobTitle7;
	private: System::Windows::Forms::Label^ Salary6;
	private: System::Windows::Forms::Label^ JobTitle6;
	private: System::Windows::Forms::Label^ Salary5;
	private: System::Windows::Forms::Label^ JobTitle5;
	private: System::Windows::Forms::Label^ Salary4;
	private: System::Windows::Forms::Label^ JobTitle4;
	private: System::Windows::Forms::Label^ Salary3;
	private: System::Windows::Forms::Label^ JobTitle3;
	private: System::Windows::Forms::Label^ Salary2;
	private: System::Windows::Forms::Label^ JobTitle2;
	private: System::Windows::Forms::Label^ Salary1;
	private: System::Windows::Forms::Label^ JobTitle1;
	private: System::Windows::Forms::PictureBox^ GoldenGateBridge;
	private: System::Windows::Forms::CheckBox^ BFS_CheckBox;
	private: System::Windows::Forms::CheckBox^ DFS_CheckBox;
	private: System::Windows::Forms::Label^ PercentVariance;

	private: System::Windows::Forms::Label^ JobT;
	private: System::Windows::Forms::Label^ RealSalary;
	private: System::Windows::Forms::TextBox^ PercentVarianceBoxReal;
	private: System::Windows::Forms::TextBox^ DesiredSalaryBoxReal;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->DesiredSalary = (gcnew System::Windows::Forms::Label());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->BFSSearchTime = (gcnew System::Windows::Forms::Label());
			this->DFSSearchTime = (gcnew System::Windows::Forms::Label());
			this->Instructions = (gcnew System::Windows::Forms::Label());
			this->DesiredSalaryBox = (gcnew System::Windows::Forms::TextBox());
			this->BFSSearchBox = (gcnew System::Windows::Forms::TextBox());
			this->DFSSearchBox = (gcnew System::Windows::Forms::TextBox());
			this->SearchClickyBox = (gcnew System::Windows::Forms::Button());
			this->Salary = (gcnew System::Windows::Forms::Label());
			this->JobTitle = (gcnew System::Windows::Forms::Label());
			this->SanFranciscoJobWebsiteButton = (gcnew System::Windows::Forms::Button());
			this->Table_Jobs_Salary = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Salary10 = (gcnew System::Windows::Forms::Label());
			this->JobTitle10 = (gcnew System::Windows::Forms::Label());
			this->Salary9 = (gcnew System::Windows::Forms::Label());
			this->JobTitle9 = (gcnew System::Windows::Forms::Label());
			this->Salary8 = (gcnew System::Windows::Forms::Label());
			this->JobTitle8 = (gcnew System::Windows::Forms::Label());
			this->Salary7 = (gcnew System::Windows::Forms::Label());
			this->JobTitle7 = (gcnew System::Windows::Forms::Label());
			this->Salary6 = (gcnew System::Windows::Forms::Label());
			this->JobTitle6 = (gcnew System::Windows::Forms::Label());
			this->Salary5 = (gcnew System::Windows::Forms::Label());
			this->JobTitle5 = (gcnew System::Windows::Forms::Label());
			this->Salary4 = (gcnew System::Windows::Forms::Label());
			this->JobTitle4 = (gcnew System::Windows::Forms::Label());
			this->Salary3 = (gcnew System::Windows::Forms::Label());
			this->JobTitle3 = (gcnew System::Windows::Forms::Label());
			this->Salary2 = (gcnew System::Windows::Forms::Label());
			this->JobTitle2 = (gcnew System::Windows::Forms::Label());
			this->Salary1 = (gcnew System::Windows::Forms::Label());
			this->JobTitle1 = (gcnew System::Windows::Forms::Label());
			this->GoldenGateBridge = (gcnew System::Windows::Forms::PictureBox());
			this->BFS_CheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->DFS_CheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->PercentVariance = (gcnew System::Windows::Forms::Label());
			this->JobT = (gcnew System::Windows::Forms::Label());
			this->RealSalary = (gcnew System::Windows::Forms::Label());
			this->PercentVarianceBoxReal = (gcnew System::Windows::Forms::TextBox());
			this->DesiredSalaryBoxReal = (gcnew System::Windows::Forms::TextBox());
			this->Table_Jobs_Salary->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GoldenGateBridge))->BeginInit();
			this->SuspendLayout();
			// 
			// DesiredSalary
			// 
			this->DesiredSalary->AutoSize = true;
			this->DesiredSalary->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DesiredSalary->Location = System::Drawing::Point(89, 154);
			this->DesiredSalary->Name = L"DesiredSalary";
			this->DesiredSalary->Size = System::Drawing::Size(161, 28);
			this->DesiredSalary->TabIndex = 1;
			this->DesiredSalary->Text = L"Desired Salary:";
			this->DesiredSalary->UseWaitCursor = true;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Gadugi", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(342, 31);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(328, 32);
			this->Title->TabIndex = 2;
			this->Title->Text = L"San Francisco Job Finder";
			this->Title->UseWaitCursor = true;
			// 
			// BFSSearchTime
			// 
			this->BFSSearchTime->AutoSize = true;
			this->BFSSearchTime->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BFSSearchTime->Location = System::Drawing::Point(89, 308);
			this->BFSSearchTime->Name = L"BFSSearchTime";
			this->BFSSearchTime->Size = System::Drawing::Size(183, 28);
			this->BFSSearchTime->TabIndex = 3;
			this->BFSSearchTime->Text = L"BFS Search Time:";
			this->BFSSearchTime->UseWaitCursor = true;
			// 
			// DFSSearchTime
			// 
			this->DFSSearchTime->AutoSize = true;
			this->DFSSearchTime->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DFSSearchTime->Location = System::Drawing::Point(89, 353);
			this->DFSSearchTime->Name = L"DFSSearchTime";
			this->DFSSearchTime->Size = System::Drawing::Size(186, 28);
			this->DFSSearchTime->TabIndex = 4;
			this->DFSSearchTime->Text = L"DFS Search Time:";
			this->DFSSearchTime->UseWaitCursor = true;
			// 
			// Instructions
			// 
			this->Instructions->AutoSize = true;
			this->Instructions->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Instructions->Location = System::Drawing::Point(12, 86);
			this->Instructions->Name = L"Instructions";
			this->Instructions->Size = System::Drawing::Size(940, 21);
			this->Instructions->TabIndex = 5;
			this->Instructions->Text = L"Instructions: Enter your desired salary and the BFS Search and DFS search times w"
				L"ill be outputted along with a list of jobs.";
			this->Instructions->UseWaitCursor = true;
			// 
			// DesiredSalaryBox
			// 
			this->DesiredSalaryBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->DesiredSalaryBox->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->DesiredSalaryBox->Location = System::Drawing::Point(277, 162);
			this->DesiredSalaryBox->Name = L"DesiredSalaryBox";
			this->DesiredSalaryBox->Size = System::Drawing::Size(0, 20);
			this->DesiredSalaryBox->TabIndex = 7;
			this->DesiredSalaryBox->UseWaitCursor = true;
			//this->DesiredSalaryBox->TextChanged += gcnew System::EventHandler(this, &MyForm::DesiredSalaryBox_TextChanged);
			// 
			// BFSSearchBox
			// 
			this->BFSSearchBox->Location = System::Drawing::Point(277, 315);
			this->BFSSearchBox->Name = L"BFSSearchBox";
			this->BFSSearchBox->Size = System::Drawing::Size(179, 20);
			this->BFSSearchBox->TabIndex = 8;
			this->BFSSearchBox->UseWaitCursor = true;
			// 
			// DFSSearchBox
			// 
			this->DFSSearchBox->Location = System::Drawing::Point(277, 360);
			this->DFSSearchBox->Name = L"DFSSearchBox";
			this->DFSSearchBox->Size = System::Drawing::Size(179, 20);
			this->DFSSearchBox->TabIndex = 9;
			this->DFSSearchBox->UseWaitCursor = true;
			// 
			// SearchClickyBox
			// 
			this->SearchClickyBox->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->SearchClickyBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchClickyBox->Location = System::Drawing::Point(140, 226);
			this->SearchClickyBox->Name = L"SearchClickyBox";
			this->SearchClickyBox->Size = System::Drawing::Size(248, 63);
			this->SearchClickyBox->TabIndex = 11;
			this->SearchClickyBox->Text = L"Search";
			this->SearchClickyBox->UseVisualStyleBackColor = true;
			this->SearchClickyBox->UseWaitCursor = true;
			this->SearchClickyBox->Click += gcnew System::EventHandler(this, &MyForm::Search_Click);
			// 
			// Salary
			// 
			this->Salary->AutoSize = true;
			this->Salary->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Salary->Location = System::Drawing::Point(1552, 154);
			this->Salary->Name = L"Salary";
			this->Salary->Size = System::Drawing::Size(73, 28);
			this->Salary->TabIndex = 13;
			this->Salary->Text = L"Salary";
			this->Salary->UseWaitCursor = true;
			// 
			// JobTitle
			// 
			this->JobTitle->AutoSize = true;
			this->JobTitle->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->JobTitle->Location = System::Drawing::Point(604, 210);
			this->JobTitle->Name = L"JobTitle";
			this->JobTitle->Size = System::Drawing::Size(96, 28);
			this->JobTitle->TabIndex = 12;
			this->JobTitle->Text = L"Job Title";
			this->JobTitle->UseWaitCursor = true;
			// 
			// SanFranciscoJobWebsiteButton
			// 
			this->SanFranciscoJobWebsiteButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SanFranciscoJobWebsiteButton->Location = System::Drawing::Point(163, 681);
			this->SanFranciscoJobWebsiteButton->Name = L"SanFranciscoJobWebsiteButton";
			this->SanFranciscoJobWebsiteButton->Size = System::Drawing::Size(225, 68);
			this->SanFranciscoJobWebsiteButton->TabIndex = 14;
			this->SanFranciscoJobWebsiteButton->Text = L"San Francisco City Government Job Site";
			this->SanFranciscoJobWebsiteButton->UseVisualStyleBackColor = true;
			this->SanFranciscoJobWebsiteButton->UseWaitCursor = true;
			this->SanFranciscoJobWebsiteButton->Click += gcnew System::EventHandler(this, &MyForm::Clicked_Job_Button);
			// 
			// Table_Jobs_Salary
			// 
			this->Table_Jobs_Salary->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Table_Jobs_Salary->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Table_Jobs_Salary->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Inset;
			this->Table_Jobs_Salary->ColumnCount = 2;
			this->Table_Jobs_Salary->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->Table_Jobs_Salary->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->Table_Jobs_Salary->Controls->Add(this->Salary10, 1, 9);
			this->Table_Jobs_Salary->Controls->Add(this->JobTitle10, 0, 9);
			this->Table_Jobs_Salary->Controls->Add(this->Salary9, 1, 8);
			this->Table_Jobs_Salary->Controls->Add(this->JobTitle9, 0, 8);
			this->Table_Jobs_Salary->Controls->Add(this->Salary8, 1, 7);
			this->Table_Jobs_Salary->Controls->Add(this->JobTitle8, 0, 7);
			this->Table_Jobs_Salary->Controls->Add(this->Salary7, 1, 6);
			this->Table_Jobs_Salary->Controls->Add(this->JobTitle7, 0, 6);
			this->Table_Jobs_Salary->Controls->Add(this->Salary6, 1, 5);
			this->Table_Jobs_Salary->Controls->Add(this->JobTitle6, 0, 5);
			this->Table_Jobs_Salary->Controls->Add(this->Salary5, 1, 4);
			this->Table_Jobs_Salary->Controls->Add(this->JobTitle5, 0, 4);
			this->Table_Jobs_Salary->Controls->Add(this->Salary4, 1, 3);
			this->Table_Jobs_Salary->Controls->Add(this->JobTitle4, 0, 3);
			this->Table_Jobs_Salary->Controls->Add(this->Salary3, 1, 2);
			this->Table_Jobs_Salary->Controls->Add(this->JobTitle3, 0, 2);
			this->Table_Jobs_Salary->Controls->Add(this->Salary2, 1, 1);
			this->Table_Jobs_Salary->Controls->Add(this->JobTitle2, 0, 1);
			this->Table_Jobs_Salary->Controls->Add(this->Salary1, 1, 0);
			this->Table_Jobs_Salary->Controls->Add(this->JobTitle1, 0, 0);
			this->Table_Jobs_Salary->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Table_Jobs_Salary->GrowStyle = System::Windows::Forms::TableLayoutPanelGrowStyle::FixedSize;
			this->Table_Jobs_Salary->Location = System::Drawing::Point(550, 200);
			this->Table_Jobs_Salary->Name = L"Table_Jobs_Salary";
			this->Table_Jobs_Salary->RowCount = 10;
			this->Table_Jobs_Salary->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->Table_Jobs_Salary->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->Table_Jobs_Salary->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->Table_Jobs_Salary->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->Table_Jobs_Salary->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->Table_Jobs_Salary->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->Table_Jobs_Salary->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->Table_Jobs_Salary->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->Table_Jobs_Salary->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->Table_Jobs_Salary->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->Table_Jobs_Salary->Size = System::Drawing::Size(421, 504);
			this->Table_Jobs_Salary->TabIndex = 15;
			this->Table_Jobs_Salary->UseWaitCursor = true;
			//this->Table_Jobs_Salary->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Table_Jobs_Salary_Paint);
			// 
			// Salary10
			// 
			this->Salary10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary10->AutoSize = true;
			this->Salary10->Location = System::Drawing::Point(315, 466);
			this->Salary10->Name = L"Salary10";
			this->Salary10->Size = System::Drawing::Size(0, 21);
			this->Salary10->TabIndex = 19;
			this->Salary10->UseWaitCursor = true;
			// 
			// JobTitle10
			// 
			this->JobTitle10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle10->AutoSize = true;
			this->JobTitle10->Location = System::Drawing::Point(105, 466);
			this->JobTitle10->Name = L"JobTitle10";
			this->JobTitle10->Size = System::Drawing::Size(0, 21);
			this->JobTitle10->TabIndex = 18;
			this->JobTitle10->UseWaitCursor = true;
			// 
			// Salary9
			// 
			this->Salary9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary9->AutoSize = true;
			this->Salary9->Location = System::Drawing::Point(315, 415);
			this->Salary9->Name = L"Salary9";
			this->Salary9->Size = System::Drawing::Size(0, 21);
			this->Salary9->TabIndex = 17;
			this->Salary9->UseWaitCursor = true;
			// 
			// JobTitle9
			// 
			this->JobTitle9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle9->AutoSize = true;
			this->JobTitle9->Location = System::Drawing::Point(105, 415);
			this->JobTitle9->Name = L"JobTitle9";
			this->JobTitle9->Size = System::Drawing::Size(0, 21);
			this->JobTitle9->TabIndex = 16;
			this->JobTitle9->UseWaitCursor = true;
			// 
			// Salary8
			// 
			this->Salary8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary8->AutoSize = true;
			this->Salary8->Location = System::Drawing::Point(315, 365);
			this->Salary8->Name = L"Salary8";
			this->Salary8->Size = System::Drawing::Size(0, 21);
			this->Salary8->TabIndex = 15;
			this->Salary8->UseWaitCursor = true;
			// 
			// JobTitle8
			// 
			this->JobTitle8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle8->AutoSize = true;
			this->JobTitle8->Location = System::Drawing::Point(105, 365);
			this->JobTitle8->Name = L"JobTitle8";
			this->JobTitle8->Size = System::Drawing::Size(0, 21);
			this->JobTitle8->TabIndex = 14;
			this->JobTitle8->UseWaitCursor = true;
			// 
			// Salary7
			// 
			this->Salary7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary7->AutoSize = true;
			this->Salary7->Location = System::Drawing::Point(315, 315);
			this->Salary7->Name = L"Salary7";
			this->Salary7->Size = System::Drawing::Size(0, 21);
			this->Salary7->TabIndex = 13;
			this->Salary7->UseWaitCursor = true;
			// 
			// JobTitle7
			// 
			this->JobTitle7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle7->AutoSize = true;
			this->JobTitle7->Location = System::Drawing::Point(105, 315);
			this->JobTitle7->Name = L"JobTitle7";
			this->JobTitle7->Size = System::Drawing::Size(0, 21);
			this->JobTitle7->TabIndex = 12;
			this->JobTitle7->UseWaitCursor = true;
			// 
			// Salary6
			// 
			this->Salary6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary6->AutoSize = true;
			this->Salary6->Location = System::Drawing::Point(315, 265);
			this->Salary6->Name = L"Salary6";
			this->Salary6->Size = System::Drawing::Size(0, 21);
			this->Salary6->TabIndex = 11;
			this->Salary6->UseWaitCursor = true;
			// 
			// JobTitle6
			// 
			this->JobTitle6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle6->AutoSize = true;
			this->JobTitle6->Location = System::Drawing::Point(105, 265);
			this->JobTitle6->Name = L"JobTitle6";
			this->JobTitle6->Size = System::Drawing::Size(0, 21);
			this->JobTitle6->TabIndex = 10;
			this->JobTitle6->UseWaitCursor = true;
			// 
			// Salary5
			// 
			this->Salary5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary5->AutoSize = true;
			this->Salary5->Location = System::Drawing::Point(315, 215);
			this->Salary5->Name = L"Salary5";
			this->Salary5->Size = System::Drawing::Size(0, 21);
			this->Salary5->TabIndex = 9;
			this->Salary5->UseWaitCursor = true;
			// 
			// JobTitle5
			// 
			this->JobTitle5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle5->AutoSize = true;
			this->JobTitle5->Location = System::Drawing::Point(105, 215);
			this->JobTitle5->Name = L"JobTitle5";
			this->JobTitle5->Size = System::Drawing::Size(0, 21);
			this->JobTitle5->TabIndex = 8;
			this->JobTitle5->UseWaitCursor = true;
			// 
			// Salary4
			// 
			this->Salary4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary4->AutoSize = true;
			this->Salary4->Location = System::Drawing::Point(315, 165);
			this->Salary4->Name = L"Salary4";
			this->Salary4->Size = System::Drawing::Size(0, 21);
			this->Salary4->TabIndex = 7;
			this->Salary4->UseWaitCursor = true;
			// 
			// JobTitle4
			// 
			this->JobTitle4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle4->AutoSize = true;
			this->JobTitle4->Location = System::Drawing::Point(105, 165);
			this->JobTitle4->Name = L"JobTitle4";
			this->JobTitle4->Size = System::Drawing::Size(0, 21);
			this->JobTitle4->TabIndex = 6;
			this->JobTitle4->UseWaitCursor = true;
			// 
			// Salary3
			// 
			this->Salary3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary3->AutoSize = true;
			this->Salary3->Location = System::Drawing::Point(315, 115);
			this->Salary3->Name = L"Salary3";
			this->Salary3->Size = System::Drawing::Size(0, 21);
			this->Salary3->TabIndex = 5;
			this->Salary3->UseWaitCursor = true;
			// 
			// JobTitle3
			// 
			this->JobTitle3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle3->AutoSize = true;
			this->JobTitle3->Location = System::Drawing::Point(105, 115);
			this->JobTitle3->Name = L"JobTitle3";
			this->JobTitle3->Size = System::Drawing::Size(0, 21);
			this->JobTitle3->TabIndex = 4;
			this->JobTitle3->UseWaitCursor = true;
			// 
			// Salary2
			// 
			this->Salary2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary2->AutoSize = true;
			this->Salary2->Location = System::Drawing::Point(315, 65);
			this->Salary2->Name = L"Salary2";
			this->Salary2->Size = System::Drawing::Size(0, 21);
			this->Salary2->TabIndex = 3;
			this->Salary2->UseWaitCursor = true;
			// 
			// JobTitle2
			// 
			this->JobTitle2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle2->AutoSize = true;
			this->JobTitle2->Location = System::Drawing::Point(105, 65);
			this->JobTitle2->Name = L"JobTitle2";
			this->JobTitle2->Size = System::Drawing::Size(0, 21);
			this->JobTitle2->TabIndex = 2;
			this->JobTitle2->UseWaitCursor = true;
			// 
			// Salary1
			// 
			this->Salary1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary1->AutoSize = true;
			this->Salary1->Location = System::Drawing::Point(315, 15);
			this->Salary1->Name = L"Salary1";
			this->Salary1->Size = System::Drawing::Size(0, 21);
			this->Salary1->TabIndex = 1;
			this->Salary1->UseWaitCursor = true;
			// 
			// JobTitle1
			// 
			this->JobTitle1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle1->AutoSize = true;
			this->JobTitle1->Location = System::Drawing::Point(105, 15);
			this->JobTitle1->Name = L"JobTitle1";
			this->JobTitle1->Size = System::Drawing::Size(0, 21);
			this->JobTitle1->TabIndex = 0;
			this->JobTitle1->UseWaitCursor = true;
			// 
			// GoldenGateBridge
			// 
			this->GoldenGateBridge->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GoldenGateBridge.ErrorImage")));
			this->GoldenGateBridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GoldenGateBridge.Image")));
			this->GoldenGateBridge->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GoldenGateBridge.InitialImage")));
			this->GoldenGateBridge->Location = System::Drawing::Point(94, 424);
			this->GoldenGateBridge->Name = L"GoldenGateBridge";
			this->GoldenGateBridge->Size = System::Drawing::Size(379, 247);
			this->GoldenGateBridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->GoldenGateBridge->TabIndex = 16;
			this->GoldenGateBridge->TabStop = false;
			this->GoldenGateBridge->UseWaitCursor = true;
			// 
			// BFS_CheckBox
			// 
			this->BFS_CheckBox->AutoSize = true;
			this->BFS_CheckBox->Location = System::Drawing::Point(69, 315);
			this->BFS_CheckBox->Name = L"BFS_CheckBox";
			this->BFS_CheckBox->Size = System::Drawing::Size(15, 14);
			this->BFS_CheckBox->TabIndex = 17;
			this->BFS_CheckBox->UseVisualStyleBackColor = true;
			this->BFS_CheckBox->UseWaitCursor = true;
			this->BFS_CheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::BFS_CheckBox_CheckedChanged_1);
			// 
			// DFS_CheckBox
			// 
			this->DFS_CheckBox->AutoSize = true;
			this->DFS_CheckBox->Location = System::Drawing::Point(69, 363);
			this->DFS_CheckBox->Name = L"DFS_CheckBox";
			this->DFS_CheckBox->Size = System::Drawing::Size(15, 14);
			this->DFS_CheckBox->TabIndex = 18;
			this->DFS_CheckBox->UseVisualStyleBackColor = true;
			this->DFS_CheckBox->UseWaitCursor = true;
			this->DFS_CheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::DFS_CheckBox_CheckedChanged);
			// 
			// PercentVariance
			// 
			this->PercentVariance->AutoSize = true;
			this->PercentVariance->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PercentVariance->Location = System::Drawing::Point(89, 193);
			this->PercentVariance->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->PercentVariance->Name = L"PercentVariance";
			this->PercentVariance->Size = System::Drawing::Size(193, 30);
			this->PercentVariance->TabIndex = 19;
			this->PercentVariance->Text = L"Percent Variance:";
			this->PercentVariance->UseWaitCursor = true;
			// 
			// JobT
			// 
			this->JobT->AutoSize = true;
			this->JobT->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->JobT->Location = System::Drawing::Point(604, 162);
			this->JobT->Name = L"JobT";
			this->JobT->Size = System::Drawing::Size(96, 28);
			this->JobT->TabIndex = 21;
			this->JobT->Text = L"Job Title";
			this->JobT->UseWaitCursor = true;
			// 
			// RealSalary
			// 
			this->RealSalary->AutoSize = true;
			this->RealSalary->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RealSalary->Location = System::Drawing::Point(831, 162);
			this->RealSalary->Name = L"RealSalary";
			this->RealSalary->Size = System::Drawing::Size(73, 28);
			this->RealSalary->TabIndex = 22;
			this->RealSalary->Text = L"Salary";
			this->RealSalary->UseWaitCursor = true;
			// 
			// PercentVarianceBoxReal
			// 
			this->PercentVarianceBoxReal->Location = System::Drawing::Point(282, 198);
			this->PercentVarianceBoxReal->Name = L"PercentVarianceBoxReal";
			this->PercentVarianceBoxReal->Size = System::Drawing::Size(173, 20);
			this->PercentVarianceBoxReal->TabIndex = 23;
			this->PercentVarianceBoxReal->UseWaitCursor = true;
			// 
			// DesiredSalaryBoxReal
			// 
			this->DesiredSalaryBoxReal->Location = System::Drawing::Point(282, 162);
			this->DesiredSalaryBoxReal->Name = L"DesiredSalaryBoxReal";
			this->DesiredSalaryBoxReal->Size = System::Drawing::Size(173, 20);
			this->DesiredSalaryBoxReal->TabIndex = 24;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(984, 761);
			this->Controls->Add(this->DesiredSalaryBoxReal);
			this->Controls->Add(this->PercentVarianceBoxReal);
			this->Controls->Add(this->RealSalary);
			this->Controls->Add(this->JobT);
			this->Controls->Add(this->PercentVariance);
			this->Controls->Add(this->DFS_CheckBox);
			this->Controls->Add(this->BFS_CheckBox);
			this->Controls->Add(this->GoldenGateBridge);
			this->Controls->Add(this->Table_Jobs_Salary);
			this->Controls->Add(this->SanFranciscoJobWebsiteButton);
			this->Controls->Add(this->Salary);
			this->Controls->Add(this->JobTitle);
			this->Controls->Add(this->SearchClickyBox);
			this->Controls->Add(this->DFSSearchBox);
			this->Controls->Add(this->BFSSearchBox);
			this->Controls->Add(this->DesiredSalaryBox);
			this->Controls->Add(this->Instructions);
			this->Controls->Add(this->DFSSearchTime);
			this->Controls->Add(this->BFSSearchTime);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->DesiredSalary);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->UseWaitCursor = true;
			//this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Table_Jobs_Salary->ResumeLayout(false);
			this->Table_Jobs_Salary->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GoldenGateBridge))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		//Executed when the search button is clicked
private: System::Void Search_Click(System::Object^ sender, System::EventArgs^ e) {
	if (DesiredSalaryBoxReal->Text == "") {
		MessageBox::Show("Please Enter A Value");
	}


	else if (DesiredSalary->Text != "") {
		msclr::interop::marshal_context change;
		std::string cleanString = change.marshal_as<std::string>(DesiredSalaryBoxReal->Text);

		bool clean = true;
		for (int i = 0; i < cleanString.length(); i++) {
			if (isdigit(cleanString[i]) == false) {
				clean = false;
			}
		}

		msclr::interop::marshal_context checkPercentVariance;
		std::string cleanStringPercentVariance = checkPercentVariance.marshal_as<std::string>(PercentVarianceBoxReal->Text);

		bool cleanPercentVariance = true;
		for (int i = 0; i < cleanStringPercentVariance.length(); i++) {
			if (isdigit(cleanStringPercentVariance[i]) == false && cleanStringPercentVariance != "") {
				cleanPercentVariance = false;
			}
		}

		
		if (clean == false && cleanPercentVariance == false) {
			MessageBox::Show("Please Enter Numbers Only");
		}
		

		if (clean == true && cleanPercentVariance == true) {
			BFSSearchBox->Text = "";
			DFSSearchBox->Text = "";

			//Call to main function and search for the values
			if (BFSChecked == true && DFSChecked == true) {
				MessageBox::Show("Please Select BFS or DFS Only!");

			}

			else if (BFSChecked == true) {
				bool BFSCh = true;
				int timeTakenI = 0;
				int& timeTaken = timeTakenI;
				//This sets the values for the BFS Time Taken
				msclr::interop::marshal_context checkBFSSearchBox;
				std::string cleancheckBFSSearchBox = checkBFSSearchBox.marshal_as<std::string>(DesiredSalaryBoxReal->Text);

				if (std::stoi(cleancheckBFSSearchBox) < 0 || std::stoi(cleancheckBFSSearchBox) > 320000) {
					MessageBox::Show("Please enter a number between 0 and 320,000");
				}
				else {
					

					std::vector<Job> jobVectorNew;
					jobVectorNew = (*jobGraph).search(BFSCh, std::stof(cleanStringPercentVariance), std::stoi(cleancheckBFSSearchBox), timeTaken);

					switch(jobVectorNew.size()){
					case 10:
					{
						String^ tempString9 = gcnew String(jobVectorNew.at(9).title.c_str());
						JobTitle10->Text = tempString9;
						std::string tempS9 = std::to_string(jobVectorNew.at(9).salary);
						String^ tempSR9 = gcnew String(tempS9.c_str());
						Salary10->Text = tempSR9;
					}
					case 9:
					{
						String^ tempString8 = gcnew String(jobVectorNew.at(8).title.c_str());
						JobTitle9->Text = tempString8;
						std::string tempS8 = std::to_string(jobVectorNew.at(8).salary);
						String^ tempSR8 = gcnew String(tempS8.c_str());
						Salary9->Text = tempSR8;
					}
					case 8:
					{
						String^ tempString7 = gcnew String(jobVectorNew.at(7).title.c_str());
						JobTitle8->Text = tempString7;
						std::string tempS7 = std::to_string(jobVectorNew.at(7).salary);
						String^ tempSR7 = gcnew String(tempS7.c_str());
						Salary8->Text = tempSR7;
					}
					case 7:
					{
						String^ tempString6 = gcnew String(jobVectorNew.at(6).title.c_str());
						JobTitle7->Text = tempString6;
						std::string tempS6 = std::to_string(jobVectorNew.at(6).salary);
						String^ tempSR6 = gcnew String(tempS6.c_str());
						Salary7->Text = tempSR6;
					}
					case 6:
					{
						String ^ tempString5 = gcnew String(jobVectorNew.at(5).title.c_str());
						JobTitle6->Text = tempString5;
						std::string tempS5 = std::to_string(jobVectorNew.at(5).salary);
						String^ tempSR5 = gcnew String(tempS5.c_str());
						Salary6->Text = tempSR5;
						}
					case 5:
					{
						String^ tempString4 = gcnew String(jobVectorNew.at(4).title.c_str());
						JobTitle5->Text = tempString4;
						std::string tempS4 = std::to_string(jobVectorNew.at(4).salary);
						String^ tempSR4 = gcnew String(tempS4.c_str());
						Salary5->Text = tempSR4;
					}
					case 4:
					{
						String^ tempString3 = gcnew String(jobVectorNew.at(3).title.c_str());
						JobTitle4->Text = tempString3;
						std::string tempS3 = std::to_string(jobVectorNew.at(3).salary);
						String^ tempSR3 = gcnew String(tempS3.c_str());
						Salary4->Text = tempSR3;
					}
					case 3:
					{
						String ^ tempString2 = gcnew String(jobVectorNew.at(2).title.c_str());
						JobTitle3->Text = tempString2;
						std::string tempS2 = std::to_string(jobVectorNew.at(2).salary);
						String^ tempSR2 = gcnew String(tempS2.c_str());
						Salary3->Text = tempSR2;
					}
					case 2:
					{
						String ^ tempString1 = gcnew String(jobVectorNew.at(1).title.c_str());
						JobTitle2->Text = tempString1;
						std::string tempS1 = std::to_string(jobVectorNew.at(1).salary);
						String^ tempSR1 = gcnew String(tempS1.c_str());
						Salary2->Text = tempSR1;
					}
					case 1:
					{
						String^ tempString0 = gcnew String(jobVectorNew.at(0).title.c_str());
						JobTitle1->Text = tempString0;
						std::string tempS0 = std::to_string(jobVectorNew.at(0).salary);
						String^ tempSR0 = gcnew String(tempS0.c_str());
						Salary1->Text = tempSR0;
					}
					default:
						break;
					}

					//Converts the ints to strings to system strings
				}

				std::string tempString = std::to_string(timeTaken);
				String^ testString = gcnew String(tempString.data());
				BFSSearchBox->Text = testString;
			}

			else if (DFSChecked == true) {
				bool BFSCh = false;
				int timeTakenI = 0;
				int& timeTaken = timeTakenI;
				//This sets the values for the DFS Time Taken
				//This sets the values for the BFS Time Taken
				msclr::interop::marshal_context checkDFSSearchBox;
				std::string cleancheckDFSSearchBox = checkDFSSearchBox.marshal_as<std::string>(DesiredSalaryBoxReal->Text);

				if (std::stoi(cleancheckDFSSearchBox) < 0 || std::stoi(cleancheckDFSSearchBox) > 320000) {
					MessageBox::Show("Please enter a number between 0 and 320,000");
				}

				else {

					std::vector<Job> jobVectorNew;
					jobVectorNew = (*jobGraph).search(BFSCh, std::stof(cleanStringPercentVariance), std::stoi(cleancheckDFSSearchBox), timeTaken);

					switch (jobVectorNew.size()) {
					case 10:
					{
						String^ tempString9 = gcnew String(jobVectorNew.at(9).title.c_str());
						JobTitle10->Text = tempString9;
						std::string tempS9 = std::to_string(jobVectorNew.at(9).salary);
						String^ tempSR9 = gcnew String(tempS9.c_str());
						Salary10->Text = tempSR9;
					}
					case 9:
					{
						String^ tempString8 = gcnew String(jobVectorNew.at(8).title.c_str());
						JobTitle9->Text = tempString8;
						std::string tempS8 = std::to_string(jobVectorNew.at(8).salary);
						String^ tempSR8 = gcnew String(tempS8.c_str());
						Salary9->Text = tempSR8;
					}
					case 8:
					{
						String^ tempString7 = gcnew String(jobVectorNew.at(7).title.c_str());
						JobTitle8->Text = tempString7;
						std::string tempS7 = std::to_string(jobVectorNew.at(7).salary);
						String^ tempSR7 = gcnew String(tempS7.c_str());
						Salary8->Text = tempSR7;
					}
					case 7:
					{
						String^ tempString6 = gcnew String(jobVectorNew.at(6).title.c_str());
						JobTitle7->Text = tempString6;
						std::string tempS6 = std::to_string(jobVectorNew.at(6).salary);
						String^ tempSR6 = gcnew String(tempS6.c_str());
						Salary7->Text = tempSR6;
					}
					case 6:
					{
						String^ tempString5 = gcnew String(jobVectorNew.at(5).title.c_str());
						JobTitle6->Text = tempString5;
						std::string tempS5 = std::to_string(jobVectorNew.at(5).salary);
						String^ tempSR5 = gcnew String(tempS5.c_str());
						Salary6->Text = tempSR5;
					}
					case 5:
					{
						String^ tempString4 = gcnew String(jobVectorNew.at(4).title.c_str());
						JobTitle5->Text = tempString4;
						std::string tempS4 = std::to_string(jobVectorNew.at(4).salary);
						String^ tempSR4 = gcnew String(tempS4.c_str());
						Salary5->Text = tempSR4;
					}
					case 4:
					{
						String^ tempString3 = gcnew String(jobVectorNew.at(3).title.c_str());
						JobTitle4->Text = tempString3;
						std::string tempS3 = std::to_string(jobVectorNew.at(3).salary);
						String^ tempSR3 = gcnew String(tempS3.c_str());
						Salary4->Text = tempSR3;
					}
					case 3:
					{
						String^ tempString2 = gcnew String(jobVectorNew.at(2).title.c_str());
						JobTitle3->Text = tempString2;
						std::string tempS2 = std::to_string(jobVectorNew.at(2).salary);
						String^ tempSR2 = gcnew String(tempS2.c_str());
						Salary3->Text = tempSR2;
					}
					case 2:
					{
						String^ tempString1 = gcnew String(jobVectorNew.at(1).title.c_str());
						JobTitle2->Text = tempString1;
						std::string tempS1 = std::to_string(jobVectorNew.at(1).salary);
						String^ tempSR1 = gcnew String(tempS1.c_str());
						Salary2->Text = tempSR1;
					}
					case 1:
					{
						String^ tempString0 = gcnew String(jobVectorNew.at(0).title.c_str());
						JobTitle1->Text = tempString0;
						std::string tempS0 = std::to_string(jobVectorNew.at(0).salary);
						String^ tempSR0 = gcnew String(tempS0.c_str());
						Salary1->Text = tempSR0;
					}
					default:
						break;
					}
				}

					std::string tempString11 = std::to_string(timeTaken);
					String^ testString1 = gcnew String(tempString11.data());
					DFSSearchBox->Text = testString1;
				
			}

			else {
				//Defaults to BFS and does not return the time
				bool BFSCh = true;
				int timeTakenI = 0;
				int& timeTaken = timeTakenI;
				//This sets the values for the BFS Time Taken
				msclr::interop::marshal_context checkBFSSearchBox;
				std::string cleancheckBFSSearchBox = checkBFSSearchBox.marshal_as<std::string>(DesiredSalaryBoxReal->Text);

				if (std::stoi(cleancheckBFSSearchBox) < 0 || std::stoi(cleancheckBFSSearchBox) > 320000) {
					MessageBox::Show("Please enter a number between 0 and 320,000");
				}

				else {
					BFSCh = true;
					std::vector<Job> jobVectorNew;
					jobVectorNew = (*jobGraph).search(BFSCh, std::stof(cleanStringPercentVariance), std::stoi(cleancheckBFSSearchBox), timeTaken);

					String^ tempString0 = gcnew String(jobVectorNew.at(0).title.c_str());
					JobTitle1->Text = tempString0;

					String^ tempString1 = gcnew String(jobVectorNew.at(1).title.c_str());
					JobTitle2->Text = tempString1;

					String^ tempString2 = gcnew String(jobVectorNew.at(2).title.c_str());
					JobTitle3->Text = tempString2;

					String^ tempString3 = gcnew String(jobVectorNew.at(3).title.c_str());
					JobTitle4->Text = tempString3;

					String^ tempString4 = gcnew String(jobVectorNew.at(4).title.c_str());
					JobTitle5->Text = tempString4;

					String^ tempString5 = gcnew String(jobVectorNew.at(5).title.c_str());
					JobTitle6->Text = tempString5;

					String^ tempString6 = gcnew String(jobVectorNew.at(6).title.c_str());
					JobTitle7->Text = tempString6;

					String^ tempString7 = gcnew String(jobVectorNew.at(7).title.c_str());
					JobTitle8->Text = tempString7;

					String^ tempString8 = gcnew String(jobVectorNew.at(8).title.c_str());
					JobTitle9->Text = tempString8;

					String^ tempString9 = gcnew String(jobVectorNew.at(9).title.c_str());
					JobTitle10->Text = tempString9;


					//Converts the ints to strings to system strings
					std::string tempS0 = std::to_string(jobVectorNew.at(0).salary);
					String^ tempSR0 = gcnew String(tempS0.c_str());
					Salary1->Text = tempSR0;

					std::string tempS1 = std::to_string(jobVectorNew.at(1).salary);
					String^ tempSR1 = gcnew String(tempS1.c_str());
					Salary2->Text = tempSR1;

					std::string tempS2 = std::to_string(jobVectorNew.at(2).salary);
					String^ tempSR2 = gcnew String(tempS2.c_str());
					Salary3->Text = tempSR2;

					std::string tempS3 = std::to_string(jobVectorNew.at(3).salary);
					String^ tempSR3 = gcnew String(tempS3.c_str());
					Salary4->Text = tempSR3;

					std::string tempS4 = std::to_string(jobVectorNew.at(4).salary);
					String^ tempSR4 = gcnew String(tempS4.c_str());
					Salary5->Text = tempSR4;

					std::string tempS5 = std::to_string(jobVectorNew.at(5).salary);
					String^ tempSR5 = gcnew String(tempS5.c_str());
					Salary6->Text = tempSR5;

					std::string tempS6 = std::to_string(jobVectorNew.at(6).salary);
					String^ tempSR6 = gcnew String(tempS6.c_str());
					Salary7->Text = tempSR6;

					std::string tempS7 = std::to_string(jobVectorNew.at(7).salary);
					String^ tempSR7 = gcnew String(tempS7.c_str());
					Salary8->Text = tempSR7;

					std::string tempS8 = std::to_string(jobVectorNew.at(8).salary);
					String^ tempSR8 = gcnew String(tempS8.c_str());
					Salary9->Text = tempSR8;

					std::string tempS9 = std::to_string(jobVectorNew.at(9).salary);
					String^ tempSR9 = gcnew String(tempS9.c_str());
					Salary10->Text = tempSR9;
				}
			}
			

		}

		
		else {
			MessageBox::Show("Please Enter Positive Numbers Only");
		}
	}

}


private: System::Void Clicked_Job_Button(System::Object^ sender, System::EventArgs^ e) {
	System::Diagnostics::Process::Start("https://sfdhr.org/job-seekers");
}


//Check to see if the checkbox is checked for the DFS Search
private: System::Void DFS_CheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (DFS_CheckBox->Checked) {
		DFSChecked = true;
	}
	else {
		DFSChecked = false;
	}
}

//Check to see if the checkbox is checked for the BFS Search
private: System::Void BFS_CheckBox_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	if (BFS_CheckBox->Checked) {
		BFSChecked = true;
	}
	else {
		BFSChecked = false;
	}
}

};
}


