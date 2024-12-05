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
    /// Summary for CourseManagementForm
    /// </summary>
    public ref class CourseManagementForm : public System::Windows::Forms::Form
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
        CourseManagementForm(void)
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
        ~CourseManagementForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;

    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::TextBox^ textBox3;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::Button^ button1;

    private: System::Windows::Forms::Button^ button3;
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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CourseManagementForm::typeid));
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(21, 26);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(71, 13);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Course Name";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(21, 78);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(62, 13);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Prerequisite";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(30, 141);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(39, 13);
            this->label4->TabIndex = 3;
            this->label4->Text = L"Credits";
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(151, 19);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(121, 20);
            this->textBox2->TabIndex = 5;
            // 
            // textBox3
            // 
            this->textBox3->Location = System::Drawing::Point(151, 138);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(121, 20);
            this->textBox3->TabIndex = 6;
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
                L"Mathematics", L"Science", L"History", L"Geography",
                    L"English"
            });
            this->comboBox1->Location = System::Drawing::Point(151, 75);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(121, 21);
            this->comboBox1->TabIndex = 7;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(24, 190);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 8;
            this->button1->Text = L"Add Course";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &CourseManagementForm::button1_Click);
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(140, 190);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(86, 23);
            this->button3->TabIndex = 10;
            this->button3->Text = L"Update Course";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &CourseManagementForm::button3_Click);
            // 
            // CourseManagementForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"CourseManagementForm";
            this->Text = L"Manage courses";
            this->Load += gcnew System::EventHandler(this, &CourseManagementForm::CourseManagementForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        // Event handler for Add Course button
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            sqlConn->Open();
            sqlCmd->Connection = sqlConn;
            sqlCmd->CommandText = "INSERT INTO courses (CourseName, Prerequisite, Credits) VALUES (@CourseName, @Prerequisite, @Credits)";
            sqlCmd->Parameters->AddWithValue("@CourseName", textBox2->Text);
            sqlCmd->Parameters->AddWithValue("@Prerequisite", comboBox1->SelectedItem->ToString());
            sqlCmd->Parameters->AddWithValue("@Credits", textBox3->Text);

            sqlCmd->ExecuteNonQuery();
            MessageBox::Show("Course added successfully!");
            sqlConn->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
    }

           // Event handler for Cancel button
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }

           // Event handler for Update Course button
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            sqlConn->Open();
            sqlCmd->Connection = sqlConn;
            sqlCmd->CommandText = "UPDATE courses SET CourseName = @CourseName, Prerequisite = @Prerequisite, Credits = @Credits WHERE CourseID = @CourseID";
            sqlCmd->Parameters->AddWithValue("@CourseID", textBox2->Text); // Assuming CourseID is provided for updating
            sqlCmd->Parameters->AddWithValue("@CourseName", textBox2->Text);
            sqlCmd->Parameters->AddWithValue("@Prerequisite", comboBox1->SelectedItem->ToString());
            sqlCmd->Parameters->AddWithValue("@Credits", textBox3->Text);

            sqlCmd->ExecuteNonQuery();
            MessageBox::Show("Course updated successfully!");
            sqlConn->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
    }
    private: System::Void CourseManagementForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
