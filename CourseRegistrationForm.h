#pragma once

namespace project {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class CourseRegistrationForm : public System::Windows::Forms::Form
    {
    private:
        MySqlConnection^ sqlConn;
        MySqlCommand^ sqlCmd;
        String^ connectionString;

        // UI components
    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::ComboBox^ comboBox1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::TextBox^ textBoxCourseID;
        System::Windows::Forms::Button^ buttonRegister;
    private: System::Windows::Forms::Label^ label3;
           System::Windows::Forms::Button^ buttonCancel;

    public:
        CourseRegistrationForm(void)
        {
            InitializeComponent();
            sqlConn = gcnew MySqlConnection();
            connectionString = "server=localhost;user id=root;password=;database=ashesii;";
            sqlConn->ConnectionString = connectionString;
        }

    protected:
        ~CourseRegistrationForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CourseRegistrationForm::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->textBoxCourseID = (gcnew System::Windows::Forms::TextBox());
            this->buttonRegister = (gcnew System::Windows::Forms::Button());
            this->buttonCancel = (gcnew System::Windows::Forms::Button());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(52, 118);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(79, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Enter Semester";
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Semester 1", L"Semester 2" });
            this->comboBox1->Location = System::Drawing::Point(193, 115);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(150, 21);
            this->comboBox1->TabIndex = 1;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(52, 78);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(82, 13);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Enter Course ID";
            // 
            // textBoxCourseID
            // 
            this->textBoxCourseID->Location = System::Drawing::Point(193, 71);
            this->textBoxCourseID->Name = L"textBoxCourseID";
            this->textBoxCourseID->Size = System::Drawing::Size(150, 20);
            this->textBoxCourseID->TabIndex = 3;
            // 
            // buttonRegister
            // 
            this->buttonRegister->Location = System::Drawing::Point(87, 158);
            this->buttonRegister->Name = L"buttonRegister";
            this->buttonRegister->Size = System::Drawing::Size(100, 30);
            this->buttonRegister->TabIndex = 4;
            this->buttonRegister->Text = L"Register";
            this->buttonRegister->UseVisualStyleBackColor = true;
            this->buttonRegister->Click += gcnew System::EventHandler(this, &CourseRegistrationForm::buttonRegister_Click);
            // 
            // buttonCancel
            // 
            this->buttonCancel->Location = System::Drawing::Point(269, 158);
            this->buttonCancel->Name = L"buttonCancel";
            this->buttonCancel->Size = System::Drawing::Size(100, 30);
            this->buttonCancel->TabIndex = 5;
            this->buttonCancel->Text = L"Cancel";
            this->buttonCancel->UseVisualStyleBackColor = true;
            this->buttonCancel->Click += gcnew System::EventHandler(this, &CourseRegistrationForm::buttonCancel_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(210, 31);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(136, 26);
            this->label3->TabIndex = 6;
            this->label3->Text = L"Welcome\r\nRegister your courses here:\r\n";
            this->label3->Click += gcnew System::EventHandler(this, &CourseRegistrationForm::label3_Click);
            // 
            // CourseRegistrationForm
            // 
            this->BackColor = System::Drawing::Color::Maroon;
            this->ClientSize = System::Drawing::Size(495, 200);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->buttonCancel);
            this->Controls->Add(this->buttonRegister);
            this->Controls->Add(this->textBoxCourseID);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->label1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"CourseRegistrationForm";
            this->Text = L"Regester  Courses";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void buttonRegister_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ courseID = textBoxCourseID->Text;
            String^ semester = comboBox1->Text;

            if (String::IsNullOrEmpty(courseID) || String::IsNullOrEmpty(semester)) {
                MessageBox::Show("Please fill all fields!");
                return;
            }

            try {
                sqlConn->Open();
                sqlCmd = gcnew MySqlCommand("SELECT COUNT(*) FROM courses WHERE CourseID = @courseID", sqlConn);
                sqlCmd->Parameters->AddWithValue("@courseID", courseID);
                int count = Convert::ToInt32(sqlCmd->ExecuteScalar());

                if (count == 0) {
                    MessageBox::Show("Course ID not found in courses table!");
                    sqlConn->Close();
                    return;
                }

                sqlCmd = gcnew MySqlCommand("INSERT INTO course_registration (CourseID, Semester) VALUES (@courseID, @semester)", sqlConn);
                sqlCmd->Parameters->AddWithValue("@courseID", courseID);
                sqlCmd->Parameters->AddWithValue("@semester", semester);

                sqlCmd->ExecuteNonQuery();
                sqlConn->Close();

                MessageBox::Show("Course registered successfully!");
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
                sqlConn->Close();
            }
        }

        System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
            textBoxCourseID->Clear();
            comboBox1->Text = "";
        }
    private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
