#pragma once

namespace project {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class TranscriptGenerationForm : public System::Windows::Forms::Form
    {
    private:
        MySqlConnection^ sqlConn;
        MySqlCommand^ sqlCmd;
        DataTable^ sqlDt;
        MySqlDataAdapter^ sqlDtA;
        MySqlDataReader^ sqlRd;
    private: System::Windows::Forms::Label^ label2;

        String^ connectionString;

    public:
        TranscriptGenerationForm(void)
        {
            InitializeComponent();
            sqlConn = gcnew MySqlConnection();
            sqlCmd = gcnew MySqlCommand();
            sqlDt = gcnew DataTable();
            sqlDtA = gcnew MySqlDataAdapter();
            connectionString = "server=localhost;user id=root;password=;database=ashesii;";
            sqlConn->ConnectionString = connectionString;
        }

    protected:
        ~TranscriptGenerationForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::TextBox^ textBox1;
        System::Windows::Forms::Button^ button1;

        System::Windows::Forms::Button^ button3;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TranscriptGenerationForm::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(62, 127);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(86, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Enter Student ID";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(148, 120);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(100, 20);
            this->textBox1->TabIndex = 1;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(12, 182);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 2;
            this->button1->Text = L"OK";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &TranscriptGenerationForm::button1_Click);
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(148, 182);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(75, 23);
            this->button3->TabIndex = 4;
            this->button3->Text = L"Back ";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &TranscriptGenerationForm::button3_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->ForeColor = System::Drawing::Color::DarkOrange;
            this->label2->Location = System::Drawing::Point(62, 68);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(185, 26);
            this->label2->TabIndex = 5;
            this->label2->Text = L"             Welcome student\r\nYou can generate your transcript here";
            // 
            // TranscriptGenerationForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Maroon;
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"TranscriptGenerationForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Generate Transcript";
            this->Load += gcnew System::EventHandler(this, &TranscriptGenerationForm::TranscriptGenerationForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void TranscriptGenerationForm_Load(System::Object^ sender, System::EventArgs^ e) {
        }

        // Generate Transcript Button Click
// Generate Transcript Button Click
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ studentID = textBox1->Text;

            if (String::IsNullOrWhiteSpace(studentID)) {
                MessageBox::Show("Please enter a valid Student ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            try {
                sqlConn->Open();
                sqlCmd->Connection = sqlConn;
                sqlCmd->CommandText = "SELECT FirstName, LastName, Major FROM students WHERE StudentID = @studentID";
                sqlCmd->Parameters->Clear();
                sqlCmd->Parameters->AddWithValue("@studentID", studentID);

                sqlRd = sqlCmd->ExecuteReader();

                if (sqlRd->Read()) {
                    String^ studentName = sqlRd["FirstName"]->ToString() + " " + sqlRd["LastName"]->ToString();
                    String^ major = sqlRd["Major"]->ToString();

                    MessageBox::Show("Generated Transcript for:\n" +
                        "Name: " + studentName + "\n" +
                        "Major: " + major, "Transcript", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
                else {
                    MessageBox::Show("Student not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally {
                sqlConn->Close();
            }
        }

        // Print Transcript Button Click
        System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ studentID = textBox1->Text;

            if (String::IsNullOrWhiteSpace(studentID)) {
                MessageBox::Show("Please enter a valid Student ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            try {
                sqlConn->Open();
                sqlCmd->Connection = sqlConn;
                sqlCmd->CommandText = "SELECT FirstName, LastName, Major, EnrollmentDate FROM students WHERE StudentID = @studentID";
                sqlCmd->Parameters->Clear();
                sqlCmd->Parameters->AddWithValue("@studentID", studentID);

                sqlRd = sqlCmd->ExecuteReader();

                if (sqlRd->Read()) {
                    String^ studentName = sqlRd["FirstName"]->ToString() + " " + sqlRd["LastName"]->ToString();
                    String^ major = sqlRd["Major"]->ToString();
                    String^ enrollmentDate = sqlRd["EnrollmentDate"]->ToString();

                    String^ transcript = "Student ID: " + studentID + "\n" +
                        "Name: " + studentName + "\n" +
                        "Major: " + major + "\n" +
                        "Enrollment Date: " + enrollmentDate;

                    MessageBox::Show(transcript, "Transcript", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
                else {
                    MessageBox::Show("Student not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally {
                sqlConn->Close();
            }
        }

        // Cancel Button Click
        System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }
    };
}
