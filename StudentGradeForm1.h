#pragma once

namespace project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class StudentGradeForm : public System::Windows::Forms::Form
	{
	private:
		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
		MySqlDataAdapter^ sqlDtA;
		String^ connectionString;

	public:
		StudentGradeForm(void)
		{
			InitializeComponent();
			sqlConn = gcnew MySqlConnection();
			sqlCmd = gcnew MySqlCommand();
			sqlDtA = gcnew MySqlDataAdapter();
			connectionString = "server=localhost;user id=root;password=;database=universitymanagement;";
			sqlConn->ConnectionString = connectionString;
		}

	protected:
		~StudentGradeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(51, 171);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"View Grade";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &StudentGradeForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(168, 171);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &StudentGradeForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Student ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 95);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Course ID";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(143, 88);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 5;
			// 
			// StudentGradeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"StudentGradeForm1";
			this->Text = L"StudentGradeForm1";
			this->Load += gcnew System::EventHandler(this, &StudentGradeForm::StudentGradeForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void StudentGradeForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ studentId = textBox1->Text;
		String^ courseId = textBox2->Text;

		if (String::IsNullOrWhiteSpace(studentId) || String::IsNullOrWhiteSpace(courseId)) {
			MessageBox::Show("Please fill out both Student ID and Course ID fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try {
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT grade FROM grades WHERE StudentID = @StudentId AND CourseID = @CourseId";
			sqlCmd->Parameters->AddWithValue("@studentId", studentId);
			sqlCmd->Parameters->AddWithValue("@courseId", courseId);

			Object^ result = sqlCmd->ExecuteScalar();
			if (result != nullptr) {
				String^ grade = result->ToString();
				MessageBox::Show("Grade: " + grade, "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show("No grade found for the specified Student ID and Course ID.", "Not Found", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			sqlCmd->Parameters->Clear();
			sqlConn->Close();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
