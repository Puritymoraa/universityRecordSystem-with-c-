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
	/// Summary for StudentEnrollment
	/// </summary>
	public ref class StudentEnrollment : public System::Windows::Forms::Form
	{
	private:
		// Add MySQL-related variables
		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
		DataTable^ sqlDt;
		MySqlDataAdapter^ sqlDtA;
		MySqlDataReader^ sqlRd;
	private: System::Windows::Forms::Label^ label7;

		String^ connectionString;

	public:
		StudentEnrollment(void)
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
		~StudentEnrollment()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;

	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 136);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Student ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 179);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Enter First Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 218);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Enter Last Name";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(0, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 23);
			this->label4->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 254);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(61, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Enter Major";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(25, 285);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(110, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Enter Enrollment Date";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(24, 319);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(99, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Enroll ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &StudentEnrollment::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(225, 319);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &StudentEnrollment::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(200, 129);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(200, 172);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(200, 215);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 10;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(200, 247);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 11;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(200, 285);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::Color::DarkOrange;
			this->label7->Location = System::Drawing::Point(97, 47);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(148, 52);
			this->label7->TabIndex = 13;
			this->label7->Text = L"      \r\n        Welcome Faculty\r\nEnroll the student here\r\nEnter the required deta"
				L"ils here";
			// 
			// StudentEnrollment
			// 
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(436, 363);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"StudentEnrollment";
			this->Text = L"Student Enrollment";
			this->Load += gcnew System::EventHandler(this, &StudentEnrollment::StudentEnrollment_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get data from TextBox controls
		String^ studentID = textBox1->Text;
		String^ firstName = textBox2->Text;
		String^ lastName = textBox3->Text;
		String^ major = textBox4->Text;
		String^ enrollmentDate = textBox5->Text;

		// Insert into database
		try {
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "INSERT INTO students (student_id, first_name, last_name, major, enrollment_date) "
				"VALUES ('" + studentID + "', '" + firstName + "', '" + lastName + "', '" + major + "', '" + enrollmentDate + "')";
			sqlCmd->ExecuteNonQuery();
			MessageBox::Show("Student enrolled successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			sqlConn->Close();
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close(); // Close the form
	}
	private: System::Void StudentEnrollment_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
