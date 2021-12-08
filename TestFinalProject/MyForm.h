#pragma once
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>


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
	private: System::Windows::Forms::TextBox^ textBox1;








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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Table_Jobs_Salary->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GoldenGateBridge))->BeginInit();
			this->SuspendLayout();
			// 
			// DesiredSalary
			// 
			this->DesiredSalary->AutoSize = true;
			this->DesiredSalary->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DesiredSalary->Location = System::Drawing::Point(134, 237);
			this->DesiredSalary->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DesiredSalary->Name = L"DesiredSalary";
			this->DesiredSalary->Size = System::Drawing::Size(243, 41);
			this->DesiredSalary->TabIndex = 1;
			this->DesiredSalary->Text = L"Desired Salary:";
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Gadugi", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(640, 63);
			this->Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(493, 49);
			this->Title->TabIndex = 2;
			this->Title->Text = L"San Francisco Job Finder";
			// 
			// BFSSearchTime
			// 
			this->BFSSearchTime->AutoSize = true;
			this->BFSSearchTime->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BFSSearchTime->Location = System::Drawing::Point(134, 474);
			this->BFSSearchTime->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->BFSSearchTime->Name = L"BFSSearchTime";
			this->BFSSearchTime->Size = System::Drawing::Size(276, 41);
			this->BFSSearchTime->TabIndex = 3;
			this->BFSSearchTime->Text = L"BFS Search Time:";
			// 
			// DFSSearchTime
			// 
			this->DFSSearchTime->AutoSize = true;
			this->DFSSearchTime->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DFSSearchTime->Location = System::Drawing::Point(134, 543);
			this->DFSSearchTime->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DFSSearchTime->Name = L"DFSSearchTime";
			this->DFSSearchTime->Size = System::Drawing::Size(280, 41);
			this->DFSSearchTime->TabIndex = 4;
			this->DFSSearchTime->Text = L"DFS Search Time:";
			// 
			// Instructions
			// 
			this->Instructions->AutoSize = true;
			this->Instructions->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Instructions->Location = System::Drawing::Point(204, 149);
			this->Instructions->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Instructions->Name = L"Instructions";
			this->Instructions->Size = System::Drawing::Size(1402, 31);
			this->Instructions->TabIndex = 5;
			this->Instructions->Text = L"Instructions: Enter your desired salary and the BFS Search and DFS search times w"
				L"ill be outputted along with a list of jobs.";
			// 
			// DesiredSalaryBox
			// 
			this->DesiredSalaryBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->DesiredSalaryBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->DesiredSalaryBox->Location = System::Drawing::Point(416, 249);
			this->DesiredSalaryBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->DesiredSalaryBox->Name = L"DesiredSalaryBox";
			this->DesiredSalaryBox->Size = System::Drawing::Size(402, 26);
			this->DesiredSalaryBox->TabIndex = 7;
			this->DesiredSalaryBox->TextChanged += gcnew System::EventHandler(this, &MyForm::DesiredSalaryBox_TextChanged);
			// 
			// BFSSearchBox
			// 
			this->BFSSearchBox->Location = System::Drawing::Point(414, 488);
			this->BFSSearchBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->BFSSearchBox->Name = L"BFSSearchBox";
			this->BFSSearchBox->Size = System::Drawing::Size(400, 26);
			this->BFSSearchBox->TabIndex = 8;
			// 
			// DFSSearchBox
			// 
			this->DFSSearchBox->Location = System::Drawing::Point(414, 557);
			this->DFSSearchBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->DFSSearchBox->Name = L"DFSSearchBox";
			this->DFSSearchBox->Size = System::Drawing::Size(402, 26);
			this->DFSSearchBox->TabIndex = 9;
			// 
			// SearchClickyBox
			// 
			this->SearchClickyBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SearchClickyBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchClickyBox->Location = System::Drawing::Point(281, 359);
			this->SearchClickyBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->SearchClickyBox->Name = L"SearchClickyBox";
			this->SearchClickyBox->Size = System::Drawing::Size(372, 97);
			this->SearchClickyBox->TabIndex = 11;
			this->SearchClickyBox->Text = L"Search";
			this->SearchClickyBox->UseVisualStyleBackColor = true;
			this->SearchClickyBox->Click += gcnew System::EventHandler(this, &MyForm::Search_Click);
			// 
			// Salary
			// 
			this->Salary->AutoSize = true;
			this->Salary->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Salary->Location = System::Drawing::Point(1359, 237);
			this->Salary->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Salary->Name = L"Salary";
			this->Salary->Size = System::Drawing::Size(110, 41);
			this->Salary->TabIndex = 13;
			this->Salary->Text = L"Salary";
			// 
			// JobTitle
			// 
			this->JobTitle->AutoSize = true;
			this->JobTitle->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->JobTitle->Location = System::Drawing::Point(1023, 237);
			this->JobTitle->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->JobTitle->Name = L"JobTitle";
			this->JobTitle->Size = System::Drawing::Size(146, 41);
			this->JobTitle->TabIndex = 12;
			this->JobTitle->Text = L"Job Title";
			// 
			// SanFranciscoJobWebsiteButton
			// 
			this->SanFranciscoJobWebsiteButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SanFranciscoJobWebsiteButton->Location = System::Drawing::Point(281, 1020);
			this->SanFranciscoJobWebsiteButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->SanFranciscoJobWebsiteButton->Name = L"SanFranciscoJobWebsiteButton";
			this->SanFranciscoJobWebsiteButton->Size = System::Drawing::Size(372, 102);
			this->SanFranciscoJobWebsiteButton->TabIndex = 14;
			this->SanFranciscoJobWebsiteButton->Text = L"San Francisco City Government Job Site";
			this->SanFranciscoJobWebsiteButton->UseVisualStyleBackColor = true;
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
			this->Table_Jobs_Salary->Location = System::Drawing::Point(938, 296);
			this->Table_Jobs_Salary->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
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
			this->Table_Jobs_Salary->Size = System::Drawing::Size(632, 775);
			this->Table_Jobs_Salary->TabIndex = 15;
			this->Table_Jobs_Salary->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Table_Jobs_Salary_Paint);
			// 
			// Salary10
			// 
			this->Salary10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary10->AutoSize = true;
			this->Salary10->Location = System::Drawing::Point(473, 718);
			this->Salary10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Salary10->Name = L"Salary10";
			this->Salary10->Size = System::Drawing::Size(0, 31);
			this->Salary10->TabIndex = 19;
			// 
			// JobTitle10
			// 
			this->JobTitle10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle10->AutoSize = true;
			this->JobTitle10->Location = System::Drawing::Point(158, 718);
			this->JobTitle10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->JobTitle10->Name = L"JobTitle10";
			this->JobTitle10->Size = System::Drawing::Size(0, 31);
			this->JobTitle10->TabIndex = 18;
			// 
			// Salary9
			// 
			this->Salary9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary9->AutoSize = true;
			this->Salary9->Location = System::Drawing::Point(473, 640);
			this->Salary9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Salary9->Name = L"Salary9";
			this->Salary9->Size = System::Drawing::Size(0, 31);
			this->Salary9->TabIndex = 17;
			// 
			// JobTitle9
			// 
			this->JobTitle9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle9->AutoSize = true;
			this->JobTitle9->Location = System::Drawing::Point(158, 640);
			this->JobTitle9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->JobTitle9->Name = L"JobTitle9";
			this->JobTitle9->Size = System::Drawing::Size(0, 31);
			this->JobTitle9->TabIndex = 16;
			// 
			// Salary8
			// 
			this->Salary8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary8->AutoSize = true;
			this->Salary8->Location = System::Drawing::Point(473, 563);
			this->Salary8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Salary8->Name = L"Salary8";
			this->Salary8->Size = System::Drawing::Size(0, 31);
			this->Salary8->TabIndex = 15;
			// 
			// JobTitle8
			// 
			this->JobTitle8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle8->AutoSize = true;
			this->JobTitle8->Location = System::Drawing::Point(158, 563);
			this->JobTitle8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->JobTitle8->Name = L"JobTitle8";
			this->JobTitle8->Size = System::Drawing::Size(0, 31);
			this->JobTitle8->TabIndex = 14;
			// 
			// Salary7
			// 
			this->Salary7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary7->AutoSize = true;
			this->Salary7->Location = System::Drawing::Point(473, 486);
			this->Salary7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Salary7->Name = L"Salary7";
			this->Salary7->Size = System::Drawing::Size(0, 31);
			this->Salary7->TabIndex = 13;
			// 
			// JobTitle7
			// 
			this->JobTitle7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle7->AutoSize = true;
			this->JobTitle7->Location = System::Drawing::Point(158, 486);
			this->JobTitle7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->JobTitle7->Name = L"JobTitle7";
			this->JobTitle7->Size = System::Drawing::Size(0, 31);
			this->JobTitle7->TabIndex = 12;
			// 
			// Salary6
			// 
			this->Salary6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary6->AutoSize = true;
			this->Salary6->Location = System::Drawing::Point(473, 409);
			this->Salary6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Salary6->Name = L"Salary6";
			this->Salary6->Size = System::Drawing::Size(0, 31);
			this->Salary6->TabIndex = 11;
			// 
			// JobTitle6
			// 
			this->JobTitle6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle6->AutoSize = true;
			this->JobTitle6->Location = System::Drawing::Point(158, 409);
			this->JobTitle6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->JobTitle6->Name = L"JobTitle6";
			this->JobTitle6->Size = System::Drawing::Size(0, 31);
			this->JobTitle6->TabIndex = 10;
			// 
			// Salary5
			// 
			this->Salary5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary5->AutoSize = true;
			this->Salary5->Location = System::Drawing::Point(473, 332);
			this->Salary5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Salary5->Name = L"Salary5";
			this->Salary5->Size = System::Drawing::Size(0, 31);
			this->Salary5->TabIndex = 9;
			// 
			// JobTitle5
			// 
			this->JobTitle5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle5->AutoSize = true;
			this->JobTitle5->Location = System::Drawing::Point(158, 332);
			this->JobTitle5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->JobTitle5->Name = L"JobTitle5";
			this->JobTitle5->Size = System::Drawing::Size(0, 31);
			this->JobTitle5->TabIndex = 8;
			// 
			// Salary4
			// 
			this->Salary4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary4->AutoSize = true;
			this->Salary4->Location = System::Drawing::Point(473, 255);
			this->Salary4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Salary4->Name = L"Salary4";
			this->Salary4->Size = System::Drawing::Size(0, 31);
			this->Salary4->TabIndex = 7;
			// 
			// JobTitle4
			// 
			this->JobTitle4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle4->AutoSize = true;
			this->JobTitle4->Location = System::Drawing::Point(158, 255);
			this->JobTitle4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->JobTitle4->Name = L"JobTitle4";
			this->JobTitle4->Size = System::Drawing::Size(0, 31);
			this->JobTitle4->TabIndex = 6;
			// 
			// Salary3
			// 
			this->Salary3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary3->AutoSize = true;
			this->Salary3->Location = System::Drawing::Point(473, 178);
			this->Salary3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Salary3->Name = L"Salary3";
			this->Salary3->Size = System::Drawing::Size(0, 31);
			this->Salary3->TabIndex = 5;
			// 
			// JobTitle3
			// 
			this->JobTitle3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle3->AutoSize = true;
			this->JobTitle3->Location = System::Drawing::Point(158, 178);
			this->JobTitle3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->JobTitle3->Name = L"JobTitle3";
			this->JobTitle3->Size = System::Drawing::Size(0, 31);
			this->JobTitle3->TabIndex = 4;
			// 
			// Salary2
			// 
			this->Salary2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary2->AutoSize = true;
			this->Salary2->Location = System::Drawing::Point(473, 101);
			this->Salary2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Salary2->Name = L"Salary2";
			this->Salary2->Size = System::Drawing::Size(0, 31);
			this->Salary2->TabIndex = 3;
			// 
			// JobTitle2
			// 
			this->JobTitle2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle2->AutoSize = true;
			this->JobTitle2->Location = System::Drawing::Point(158, 101);
			this->JobTitle2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->JobTitle2->Name = L"JobTitle2";
			this->JobTitle2->Size = System::Drawing::Size(0, 31);
			this->JobTitle2->TabIndex = 2;
			// 
			// Salary1
			// 
			this->Salary1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary1->AutoSize = true;
			this->Salary1->Location = System::Drawing::Point(473, 24);
			this->Salary1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Salary1->Name = L"Salary1";
			this->Salary1->Size = System::Drawing::Size(0, 31);
			this->Salary1->TabIndex = 1;
			// 
			// JobTitle1
			// 
			this->JobTitle1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle1->AutoSize = true;
			this->JobTitle1->Location = System::Drawing::Point(158, 24);
			this->JobTitle1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->JobTitle1->Name = L"JobTitle1";
			this->JobTitle1->Size = System::Drawing::Size(0, 31);
			this->JobTitle1->TabIndex = 0;
			// 
			// GoldenGateBridge
			// 
			this->GoldenGateBridge->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GoldenGateBridge.ErrorImage")));
			this->GoldenGateBridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GoldenGateBridge.Image")));
			this->GoldenGateBridge->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GoldenGateBridge.InitialImage")));
			this->GoldenGateBridge->Location = System::Drawing::Point(196, 612);
			this->GoldenGateBridge->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->GoldenGateBridge->Name = L"GoldenGateBridge";
			this->GoldenGateBridge->Size = System::Drawing::Size(568, 380);
			this->GoldenGateBridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->GoldenGateBridge->TabIndex = 16;
			this->GoldenGateBridge->TabStop = false;
			// 
			// BFS_CheckBox
			// 
			this->BFS_CheckBox->AutoSize = true;
			this->BFS_CheckBox->Location = System::Drawing::Point(104, 484);
			this->BFS_CheckBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->BFS_CheckBox->Name = L"BFS_CheckBox";
			this->BFS_CheckBox->Size = System::Drawing::Size(22, 21);
			this->BFS_CheckBox->TabIndex = 17;
			this->BFS_CheckBox->UseVisualStyleBackColor = true;
			this->BFS_CheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::BFS_CheckBox_CheckedChanged_1);
			// 
			// DFS_CheckBox
			// 
			this->DFS_CheckBox->AutoSize = true;
			this->DFS_CheckBox->Location = System::Drawing::Point(104, 557);
			this->DFS_CheckBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->DFS_CheckBox->Name = L"DFS_CheckBox";
			this->DFS_CheckBox->Size = System::Drawing::Size(22, 21);
			this->DFS_CheckBox->TabIndex = 18;
			this->DFS_CheckBox->UseVisualStyleBackColor = true;
			this->DFS_CheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::DFS_CheckBox_CheckedChanged);
			// 
			// PercentVariance
			// 
			this->PercentVariance->AutoSize = true;
			this->PercentVariance->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PercentVariance->Location = System::Drawing::Point(134, 296);
			this->PercentVariance->Name = L"PercentVariance";
			this->PercentVariance->Size = System::Drawing::Size(284, 41);
			this->PercentVariance->TabIndex = 19;
			this->PercentVariance->Text = L"Percent Variance:";
			//this->PercentVariance->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(418, 305);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(398, 26);
			this->textBox1->TabIndex = 20;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1788, 1169);
			this->Controls->Add(this->textBox1);
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
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Table_Jobs_Salary->ResumeLayout(false);
			this->Table_Jobs_Salary->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GoldenGateBridge))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		//Executed when the search button is clicked
private: System::Void Search_Click(System::Object^ sender, System::EventArgs^ e) {
	if (DesiredSalaryBox->Text == "") {
		MessageBox::Show("Please Enter A Value");
	}



	else if (DesiredSalary->Text != "") {
		msclr::interop::marshal_context change;
		std::string cleanString = change.marshal_as<std::string>(DesiredSalaryBox->Text);

		bool clean = true;
		for (int i = 0; i < cleanString.length(); i++) {
			if (isdigit(cleanString[i]) == false) {
				clean = false;
			}
		}

		msclr::interop::marshal_context checkPercentVariance;
		std::string cleanStringPercentVariance = change.marshal_as<std::string>(PercentVariance->Text);

		bool cleanPercentVariance = true;
		for (int i = 0; i < cleanStringPercentVariance.length(); i++) {
			if (isdigit(cleanStringPercentVariance[i]) == false) {
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
				//This sets the values for the BFS Time Taken
				std::string tempString = "1234567";
				String^ testString = gcnew String(tempString.data());
				BFSSearchBox->Text = testString;

				//This sets the values for the DFS Time Taken
				std::string tempString1 = "12345678910";
				String^ testString1 = gcnew String(tempString1.data());
				DFSSearchBox->Text = testString1;

			}

			else if (BFSChecked == true) {
				//This sets the values for the BFS Time Taken
				std::string tempString = "1234567";
				String^ testString = gcnew String(tempString.data());
				BFSSearchBox->Text = testString;
			}

			else if (DFSChecked == true) {
				//This sets the values for the DFS Time Taken
				std::string tempString1 = "12345678910";
				String^ testString1 = gcnew String(tempString1.data());
				DFSSearchBox->Text = testString1;
			}


			//Update The Table With Values Found (These are tempValues)


			JobTitle1->Text = "Hi";
			JobTitle2->Text = "My";
			JobTitle3->Text = "Name";
			JobTitle4->Text = "Is";
			JobTitle5->Text = "Pog";
			JobTitle6->Text = "I";
			JobTitle7->Text = "Hope";
			JobTitle8->Text = "This";
			JobTitle9->Text = "Really";
			JobTitle10->Text = "Works";

			Salary1->Text = "100000";
			Salary2->Text = "100001";
			Salary3->Text = "100002";
			Salary4->Text = "100003";
			Salary5->Text = "100004";
			Salary6->Text = "100005";
			Salary7->Text = "100006";
			Salary8->Text = "100007";
			Salary9->Text = "100008";
			Salary10->Text = "100009";

		}

		else {
			MessageBox::Show("Please Enter Numbers Only");
		}
	}

}


private: System::Void DesiredSalaryBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {

}

private: System::Void Clicked_Job_Button(System::Object^ sender, System::EventArgs^ e) {
	System::Diagnostics::Process::Start("https://sfdhr.org/job-seekers");
}

private: System::Void Table_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

}

private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void Table_Jobs_Salary_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
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

private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
