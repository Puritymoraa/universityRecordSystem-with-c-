#pragma once

namespace project {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class ReportForm : public System::Windows::Forms::Form
    {
    private:
        MySqlConnection^ sqlConn;
        MySqlCommand^ sqlCmd;
        MySqlDataAdapter^ sqlDtA;
    private: System::Windows::Forms::Label^ label2;
           String^ connectionString;

    public:
        ReportForm(void)
        {
            InitializeComponent();
            sqlConn = gcnew MySqlConnection();
            sqlCmd = gcnew MySqlCommand();
            sqlDtA = gcnew MySqlDataAdapter();
            connectionString = "server=localhost;user id=root;password=;database=ashesii;";  // Update with actual database credentials
            sqlConn->ConnectionString = connectionString;
        }

    protected:
        ~ReportForm()
        {
            if (components)
            {
                delete components;
            }
            // Dispose MySQL objects
            if (sqlCmd != nullptr) delete sqlCmd;
            if (sqlConn != nullptr) delete sqlConn;
            if (sqlDtA != nullptr) delete sqlDtA;
        }

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->button2 = (gcnew System::Windows::Forms::Button());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->SuspendLayout();
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Location = System::Drawing::Point(38, 114);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(66, 13);
               this->label1->TabIndex = 0;
               this->label1->Text = L"Report Type";
               // 
               // comboBox1
               // 
               this->comboBox1->FormattingEnabled = true;
               this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Students", L"Courses", L"Grades" });
               this->comboBox1->Location = System::Drawing::Point(137, 111);
               this->comboBox1->Name = L"comboBox1";
               this->comboBox1->Size = System::Drawing::Size(121, 21);
               this->comboBox1->TabIndex = 1;
               this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &ReportForm::comboBox1_SelectedIndexChanged);
               // 
               // button1
               // 
               this->button1->Location = System::Drawing::Point(41, 182);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(100, 23);
               this->button1->TabIndex = 2;
               this->button1->Text = L"submit";
               this->button1->UseVisualStyleBackColor = true;
               this->button1->Click += gcnew System::EventHandler(this, &ReportForm::button1_Click);
               // 
               // button2
               // 
               this->button2->Location = System::Drawing::Point(169, 182);
               this->button2->Name = L"button2";
               this->button2->Size = System::Drawing::Size(75, 23);
               this->button2->TabIndex = 3;
               this->button2->Text = L"Back";
               this->button2->UseVisualStyleBackColor = true;
               this->button2->Click += gcnew System::EventHandler(this, &ReportForm::button2_Click);
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->ForeColor = System::Drawing::Color::DarkOrange;
               this->label2->Location = System::Drawing::Point(74, 48);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(149, 26);
               this->label2->TabIndex = 4;
               this->label2->Text = L"     Welcome Student \r\nReview your report form here!!";
               // 
               // ReportForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::Color::Maroon;
               this->ClientSize = System::Drawing::Size(284, 261);
               this->Controls->Add(this->label2);
               this->Controls->Add(this->button2);
               this->Controls->Add(this->button1);
               this->Controls->Add(this->comboBox1);
               this->Controls->Add(this->label1);
               this->Name = L"ReportForm";
               this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
               this->Text = L"ReportForm";
               this->Load += gcnew System::EventHandler(this, &ReportForm::ReportForm_Load);
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        // Check if a report type has been selected
        if (comboBox1->SelectedIndex == -1) {
            MessageBox::Show("Please select a report type.");
            return;
        }

        String^ reportType = comboBox1->SelectedItem->ToString();
        String^ query;

        // Set the query based on the selected report type
        if (reportType == "Students") {
            query = "SELECT StudentID, FirstName, LastName, Major FROM students";
        }
        else if (reportType == "Courses") {
            query = "SELECT CourseID, CourseName, Credits FROM courses";
        }
        else if (reportType == "Grades") {
            query = "SELECT StudentID, CourseID, Grade FROM grades";
        }
        else {
            MessageBox::Show("Invalid report type selected.");
            return;
        }

        try {
            sqlConn->Open();
            sqlCmd->Connection = sqlConn;
            sqlCmd->CommandText = query;

            // Create a data reader to execute the query and read the data
            MySqlDataReader^ reader = sqlCmd->ExecuteReader();

            // Prepare a report string
            String^ report = "Report for " + reportType + ":\n\n";
            while (reader->Read()) {
                if (reportType == "Students") {
                    report += "ID: " + reader["StudentID"] + " | Name: " + reader["FirstName"] + " " + reader["LastName"] + " | Major: " + reader["Major"] + "\n";
                }
                else if (reportType == "Courses") {
                    report += "Course ID: " + reader["CourseID"] + " | Course: " + reader["CourseName"] + " | Credits: " + reader["Credits"] + "\n";
                }
                else if (reportType == "Grades") {
                    report += "Student ID: " + reader["StudentID"] + " | Course ID: " + reader["CourseID"] + " | Grade: " + reader["Grade"] + "\n";
                }
            }

            // Close the reader and connection
            reader->Close();

            // Display the generated report in a message box
            MessageBox::Show(report, "Generated Report");

        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally {
            sqlConn->Close();
        }
    }

    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        // Close the form when Cancel is clicked
        this->Close();
    }

    private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        // Optional: You can handle additional actions here when the selection changes
    }

    private: System::Void ReportForm_Load(System::Object^ sender, System::EventArgs^ e) {
        // You can initialize things here if needed (e.g., set default values or load data)
    }
    };

}
