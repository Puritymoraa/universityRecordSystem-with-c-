#pragma once

namespace project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for GradeEntryForm
	/// </summary>
	public ref class GradeEntryForm : public System::Windows::Forms::Form
	{
	private:
		// Add MySQL-related variables
		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
		DataTable^ sqlDt;
		MySqlDataAdapter^ sqlDtA;
		MySqlDataReader^ sqlRd;
	private: System::Windows::Forms::Label^ label4;

		String^ connectionString;

	public:
		GradeEntryForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			sqlConn = gcnew MySqlConnection();
			sqlCmd = gcnew MySqlCommand();
			sqlDt = gcnew DataTable();
			sqlDtA = gcnew MySqlDataAdapter();
			connectionString = "server=localhost;user id=root;password=;database=ashesii;";
			sqlConn->ConnectionString = connectionString;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GradeEntryForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GradeEntryForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Course ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Enter Student ID";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 147);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(82, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Enter the Grade";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(37, 180);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GradeEntryForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(182, 203);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GradeEntryForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(121, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(121, 103);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(121, 140);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::DarkOrange;
			this->label4->Location = System::Drawing::Point(46, 18);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(175, 26);
			this->label4->TabIndex = 8;
			this->label4->Text = L"          Welcome Faculty\r\nEnter the details of the student here";
			// 
			// GradeEntryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GradeEntryForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Enter Grades";
			this->Load += gcnew System::EventHandler(this, &GradeEntryForm::GradeEntryForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void GradeEntryForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Grab input values from textboxes
		String^ courseID = textBox1->Text;
		String^ studentID = textBox2->Text;
		String^ grade = textBox3->Text;

		// Create the SQL query to insert the grade into the database
		String^ query = "INSERT INTO grades (CourseID, StudentID, Grade) VALUES (@CourseID, @StudentID, @Grade)";

		try {
			// Open connection
			sqlConn->Open();

			// Create the command
			sqlCmd = gcnew MySqlCommand(query, sqlConn);
			sqlCmd->Parameters->AddWithValue("@CourseID", courseID);
			sqlCmd->Parameters->AddWithValue("@StudentID", studentID);
			sqlCmd->Parameters->AddWithValue("@Grade", grade);

			// Execute the query
			sqlCmd->ExecuteNonQuery();
			MessageBox::Show("Grade Submitted Successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Clear the textboxes after submission
			textBox1->Clear();
			textBox2->Clear();
			textBox3->Clear();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			// Close the connection
			sqlConn->Close();
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close the form when cancel button is clicked
		this->Close();
	}
	};
}
