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
	/// Summary for FacultyManagementForm
	/// </summary>
	public ref class FacultyManagementForm : public System::Windows::Forms::Form
	{
	private:
		// Add MySQL-related variables
		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
		DataTable^ sqlDt;
		MySqlDataAdapter^ sqlDtA;
		MySqlDataReader^ sqlRd;

		String^ connectionString;

	public:
		FacultyManagementForm(void)
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
		~FacultyManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(197, 236);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FacultyManagementForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(28, 207);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Add ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FacultyManagementForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(131, 207);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(89, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Update ";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FacultyManagementForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Enter Faculty ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Enter First Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Enter Last Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(25, 144);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Enter Department";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 176);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(104, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Date of Appointment";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(152, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 11;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(152, 58);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 12;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(152, 99);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 13;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Computer Science", L"Mathematics", L"Physics" });
			this->comboBox1->Location = System::Drawing::Point(152, 136);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 21);
			this->comboBox1->TabIndex = 14;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(152, 170);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(100, 20);
			this->dateTimePicker1->TabIndex = 15;
			// 
			// FacultyManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"FacultyManagementForm";
			this->Text = L"Faculty Management Form";
			this->Load += gcnew System::EventHandler(this, &FacultyManagementForm::FacultyManagementForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Event for Add Faculty
		void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "INSERT INTO faculties(FacultyID, FirstName, LastName, Department, DateOfAppointment) VALUES('" + textBox1->Text + "', '" + textBox2->Text + "', '" + textBox3->Text + "', '" + comboBox1->SelectedItem + "', '" + dateTimePicker1->Value.ToString("yyyy-MM-dd") + "')";
				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Faculty Added Successfully!");
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message);
			}
			finally {
				sqlConn->Close();
			}
		}

		// Event for Update Faculty
		void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "UPDATE faculties SET FirstName='" + textBox2->Text + "', LastName='" + textBox3->Text + "', Department='" + comboBox1->SelectedItem + "', DateOfAppointment='" + dateTimePicker1->Value.ToString("yyyy-MM-dd") + "' WHERE FacultyID='" + textBox1->Text + "'";
				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Faculty Updated Successfully!");
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message);
			}
			finally {
				sqlConn->Close();
			}
		}

		// Event for Cancel
		void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	private: System::Void FacultyManagementForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
