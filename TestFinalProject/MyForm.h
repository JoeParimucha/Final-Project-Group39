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
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Gadugi", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(427, 41);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(328, 32);
			this->Title->TabIndex = 2;
			this->Title->Text = L"San Francisco Job Finder";
			// 
			// BFSSearchTime
			// 
			this->BFSSearchTime->AutoSize = true;
			this->BFSSearchTime->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BFSSearchTime->Location = System::Drawing::Point(89, 273);
			this->BFSSearchTime->Name = L"BFSSearchTime";
			this->BFSSearchTime->Size = System::Drawing::Size(183, 28);
			this->BFSSearchTime->TabIndex = 3;
			this->BFSSearchTime->Text = L"BFS Search Time:";
			// 
			// DFSSearchTime
			// 
			this->DFSSearchTime->AutoSize = true;
			this->DFSSearchTime->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DFSSearchTime->Location = System::Drawing::Point(89, 315);
			this->DFSSearchTime->Name = L"DFSSearchTime";
			this->DFSSearchTime->Size = System::Drawing::Size(186, 28);
			this->DFSSearchTime->TabIndex = 4;
			this->DFSSearchTime->Text = L"DFS Search Time:";
			// 
			// Instructions
			// 
			this->Instructions->AutoSize = true;
			this->Instructions->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Instructions->Location = System::Drawing::Point(136, 97);
			this->Instructions->Name = L"Instructions";
			this->Instructions->Size = System::Drawing::Size(940, 21);
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
			this->DesiredSalaryBox->Location = System::Drawing::Point(247, 162);
			this->DesiredSalaryBox->Name = L"DesiredSalaryBox";
			this->DesiredSalaryBox->Size = System::Drawing::Size(300, 20);
			this->DesiredSalaryBox->TabIndex = 7;
			this->DesiredSalaryBox->TextChanged += gcnew System::EventHandler(this, &MyForm::DesiredSalaryBox_TextChanged);
			// 
			// BFSSearchBox
			// 
			this->BFSSearchBox->Location = System::Drawing::Point(279, 281);
			this->BFSSearchBox->Name = L"BFSSearchBox";
			this->BFSSearchBox->Size = System::Drawing::Size(268, 20);
			this->BFSSearchBox->TabIndex = 8;
			// 
			// DFSSearchBox
			// 
			this->DFSSearchBox->Location = System::Drawing::Point(278, 323);
			this->DFSSearchBox->Name = L"DFSSearchBox";
			this->DFSSearchBox->Size = System::Drawing::Size(269, 20);
			this->DFSSearchBox->TabIndex = 9;
			// 
			// SearchClickyBox
			// 
			this->SearchClickyBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SearchClickyBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchClickyBox->Location = System::Drawing::Point(247, 200);
			this->SearchClickyBox->Name = L"SearchClickyBox";
			this->SearchClickyBox->Size = System::Drawing::Size(300, 63);
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
			this->Salary->Location = System::Drawing::Point(911, 154);
			this->Salary->Name = L"Salary";
			this->Salary->Size = System::Drawing::Size(73, 28);
			this->Salary->TabIndex = 13;
			this->Salary->Text = L"Salary";
			// 
			// JobTitle
			// 
			this->JobTitle->AutoSize = true;
			this->JobTitle->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->JobTitle->Location = System::Drawing::Point(687, 154);
			this->JobTitle->Name = L"JobTitle";
			this->JobTitle->Size = System::Drawing::Size(96, 28);
			this->JobTitle->TabIndex = 12;
			this->JobTitle->Text = L"Job Title";
			// 
			// SanFranciscoJobWebsiteButton
			// 
			this->SanFranciscoJobWebsiteButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SanFranciscoJobWebsiteButton->Location = System::Drawing::Point(156, 620);
			this->SanFranciscoJobWebsiteButton->Name = L"SanFranciscoJobWebsiteButton";
			this->SanFranciscoJobWebsiteButton->Size = System::Drawing::Size(248, 66);
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
			this->Table_Jobs_Salary->Location = System::Drawing::Point(627, 182);
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
			this->Table_Jobs_Salary->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Table_Jobs_Salary_Paint);
			// 
			// Salary10
			// 
			this->Salary10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary10->AutoSize = true;
			this->Salary10->Location = System::Drawing::Point(315, 466);
			this->Salary10->Name = L"Salary10";
			this->Salary10->Size = System::Drawing::Size(0, 21);
			this->Salary10->TabIndex = 19;
			// 
			// JobTitle10
			// 
			this->JobTitle10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle10->AutoSize = true;
			this->JobTitle10->Location = System::Drawing::Point(105, 466);
			this->JobTitle10->Name = L"JobTitle10";
			this->JobTitle10->Size = System::Drawing::Size(0, 21);
			this->JobTitle10->TabIndex = 18;
			// 
			// Salary9
			// 
			this->Salary9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary9->AutoSize = true;
			this->Salary9->Location = System::Drawing::Point(315, 415);
			this->Salary9->Name = L"Salary9";
			this->Salary9->Size = System::Drawing::Size(0, 21);
			this->Salary9->TabIndex = 17;
			// 
			// JobTitle9
			// 
			this->JobTitle9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle9->AutoSize = true;
			this->JobTitle9->Location = System::Drawing::Point(105, 415);
			this->JobTitle9->Name = L"JobTitle9";
			this->JobTitle9->Size = System::Drawing::Size(0, 21);
			this->JobTitle9->TabIndex = 16;
			// 
			// Salary8
			// 
			this->Salary8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary8->AutoSize = true;
			this->Salary8->Location = System::Drawing::Point(315, 365);
			this->Salary8->Name = L"Salary8";
			this->Salary8->Size = System::Drawing::Size(0, 21);
			this->Salary8->TabIndex = 15;
			// 
			// JobTitle8
			// 
			this->JobTitle8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle8->AutoSize = true;
			this->JobTitle8->Location = System::Drawing::Point(105, 365);
			this->JobTitle8->Name = L"JobTitle8";
			this->JobTitle8->Size = System::Drawing::Size(0, 21);
			this->JobTitle8->TabIndex = 14;
			// 
			// Salary7
			// 
			this->Salary7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary7->AutoSize = true;
			this->Salary7->Location = System::Drawing::Point(315, 315);
			this->Salary7->Name = L"Salary7";
			this->Salary7->Size = System::Drawing::Size(0, 21);
			this->Salary7->TabIndex = 13;
			// 
			// JobTitle7
			// 
			this->JobTitle7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle7->AutoSize = true;
			this->JobTitle7->Location = System::Drawing::Point(105, 315);
			this->JobTitle7->Name = L"JobTitle7";
			this->JobTitle7->Size = System::Drawing::Size(0, 21);
			this->JobTitle7->TabIndex = 12;
			// 
			// Salary6
			// 
			this->Salary6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary6->AutoSize = true;
			this->Salary6->Location = System::Drawing::Point(315, 265);
			this->Salary6->Name = L"Salary6";
			this->Salary6->Size = System::Drawing::Size(0, 21);
			this->Salary6->TabIndex = 11;
			// 
			// JobTitle6
			// 
			this->JobTitle6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle6->AutoSize = true;
			this->JobTitle6->Location = System::Drawing::Point(105, 265);
			this->JobTitle6->Name = L"JobTitle6";
			this->JobTitle6->Size = System::Drawing::Size(0, 21);
			this->JobTitle6->TabIndex = 10;
			// 
			// Salary5
			// 
			this->Salary5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary5->AutoSize = true;
			this->Salary5->Location = System::Drawing::Point(315, 215);
			this->Salary5->Name = L"Salary5";
			this->Salary5->Size = System::Drawing::Size(0, 21);
			this->Salary5->TabIndex = 9;
			// 
			// JobTitle5
			// 
			this->JobTitle5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle5->AutoSize = true;
			this->JobTitle5->Location = System::Drawing::Point(105, 215);
			this->JobTitle5->Name = L"JobTitle5";
			this->JobTitle5->Size = System::Drawing::Size(0, 21);
			this->JobTitle5->TabIndex = 8;
			// 
			// Salary4
			// 
			this->Salary4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary4->AutoSize = true;
			this->Salary4->Location = System::Drawing::Point(315, 165);
			this->Salary4->Name = L"Salary4";
			this->Salary4->Size = System::Drawing::Size(0, 21);
			this->Salary4->TabIndex = 7;
			// 
			// JobTitle4
			// 
			this->JobTitle4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle4->AutoSize = true;
			this->JobTitle4->Location = System::Drawing::Point(105, 165);
			this->JobTitle4->Name = L"JobTitle4";
			this->JobTitle4->Size = System::Drawing::Size(0, 21);
			this->JobTitle4->TabIndex = 6;
			// 
			// Salary3
			// 
			this->Salary3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary3->AutoSize = true;
			this->Salary3->Location = System::Drawing::Point(315, 115);
			this->Salary3->Name = L"Salary3";
			this->Salary3->Size = System::Drawing::Size(0, 21);
			this->Salary3->TabIndex = 5;
			// 
			// JobTitle3
			// 
			this->JobTitle3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle3->AutoSize = true;
			this->JobTitle3->Location = System::Drawing::Point(105, 115);
			this->JobTitle3->Name = L"JobTitle3";
			this->JobTitle3->Size = System::Drawing::Size(0, 21);
			this->JobTitle3->TabIndex = 4;
			// 
			// Salary2
			// 
			this->Salary2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary2->AutoSize = true;
			this->Salary2->Location = System::Drawing::Point(315, 65);
			this->Salary2->Name = L"Salary2";
			this->Salary2->Size = System::Drawing::Size(0, 21);
			this->Salary2->TabIndex = 3;
			// 
			// JobTitle2
			// 
			this->JobTitle2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle2->AutoSize = true;
			this->JobTitle2->Location = System::Drawing::Point(105, 65);
			this->JobTitle2->Name = L"JobTitle2";
			this->JobTitle2->Size = System::Drawing::Size(0, 21);
			this->JobTitle2->TabIndex = 2;
			// 
			// Salary1
			// 
			this->Salary1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salary1->AutoSize = true;
			this->Salary1->Location = System::Drawing::Point(315, 15);
			this->Salary1->Name = L"Salary1";
			this->Salary1->Size = System::Drawing::Size(0, 21);
			this->Salary1->TabIndex = 1;
			// 
			// JobTitle1
			// 
			this->JobTitle1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->JobTitle1->AutoSize = true;
			this->JobTitle1->Location = System::Drawing::Point(105, 15);
			this->JobTitle1->Name = L"JobTitle1";
			this->JobTitle1->Size = System::Drawing::Size(0, 21);
			this->JobTitle1->TabIndex = 0;
			// 
			// GoldenGateBridge
			// 
			this->GoldenGateBridge->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GoldenGateBridge.ErrorImage")));
			this->GoldenGateBridge->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GoldenGateBridge.Image")));
			this->GoldenGateBridge->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GoldenGateBridge.InitialImage")));
			this->GoldenGateBridge->Location = System::Drawing::Point(94, 366);
			this->GoldenGateBridge->Name = L"GoldenGateBridge";
			this->GoldenGateBridge->Size = System::Drawing::Size(379, 247);
			this->GoldenGateBridge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->GoldenGateBridge->TabIndex = 16;
			this->GoldenGateBridge->TabStop = false;
			// 
			// BFS_CheckBox
			// 
			this->BFS_CheckBox->AutoSize = true;
			this->BFS_CheckBox->Location = System::Drawing::Point(68, 281);
			this->BFS_CheckBox->Name = L"BFS_CheckBox";
			this->BFS_CheckBox->Size = System::Drawing::Size(15, 14);
			this->BFS_CheckBox->TabIndex = 17;
			this->BFS_CheckBox->UseVisualStyleBackColor = true;
			this->BFS_CheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::BFS_CheckBox_CheckedChanged_1);
			// 
			// DFS_CheckBox
			// 
			this->DFS_CheckBox->AutoSize = true;
			this->DFS_CheckBox->Location = System::Drawing::Point(68, 323);
			this->DFS_CheckBox->Name = L"DFS_CheckBox";
			this->DFS_CheckBox->Size = System::Drawing::Size(15, 14);
			this->DFS_CheckBox->TabIndex = 18;
			this->DFS_CheckBox->UseVisualStyleBackColor = true;
			this->DFS_CheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::DFS_CheckBox_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1192, 760);
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

		if (clean == false) {
			MessageBox::Show("Please Enter Numbers Only");
		}

		if (clean == true) {
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
};
}
