#pragma once

namespace project {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;
    using namespace System::IO;

    public ref class ProfileManagementForm : public System::Windows::Forms::Form
    {
    private:
        MySqlConnection^ sqlConn;
        MySqlCommand^ sqlCmd;
        String^ connectionString;
        String^ profilePicturePath;
        array<Byte>^ profilePictureData;

    private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

    public:
        ProfileManagementForm(void)
        {
            InitializeComponent();
            sqlConn = gcnew MySqlConnection();
            sqlCmd = gcnew MySqlCommand();
            connectionString = "server=localhost;user id=root;password=;database=ashesii;";
            sqlConn->ConnectionString = connectionString;
        }

    protected:
        ~ProfileManagementForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::TextBox^ textBox1;
        System::Windows::Forms::TextBox^ textBox2;
        System::Windows::Forms::TextBox^ textBox3;
        System::Windows::Forms::TextBox^ textBox4;
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::Button^ button2;



    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ProfileManagementForm::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->textBox4 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(65, 42);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(66, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Ener user ID";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(65, 96);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(85, 13);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Enter First Name";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(64, 145);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(86, 13);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Enter Last Name";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(64, 197);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(60, 13);
            this->label4->TabIndex = 3;
            this->label4->Text = L"Enter Email";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(152, 35);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(128, 20);
            this->textBox1->TabIndex = 4;
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(152, 89);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(128, 20);
            this->textBox2->TabIndex = 5;
            // 
            // textBox3
            // 
            this->textBox3->Location = System::Drawing::Point(152, 138);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(128, 20);
            this->textBox3->TabIndex = 6;
            // 
            // textBox4
            // 
            this->textBox4->Location = System::Drawing::Point(152, 190);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(128, 20);
            this->textBox4->TabIndex = 7;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(152, 268);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(85, 23);
            this->button1->TabIndex = 8;
            this->button1->Text = L"OK";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &ProfileManagementForm::button1_Click);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(268, 268);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(75, 23);
            this->button2->TabIndex = 9;
            this->button2->Text = L"Back";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &ProfileManagementForm::button2_Click);
            // 
            // openFileDialog1
            // 
            this->openFileDialog1->FileName = L"openFileDialog1";
            this->openFileDialog1->Filter = L"Image Files|*.jpg;*.jpeg;*.png;*.gif";
            // 
            // ProfileManagementForm
            // 
            this->BackColor = System::Drawing::Color::Maroon;
            this->ClientSize = System::Drawing::Size(663, 343);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox4);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"ProfileManagementForm";
            this->Text = L"Profile Management";
            this->Load += gcnew System::EventHandler(this, &ProfileManagementForm::ProfileManagementForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            sqlConn->Open();
            sqlCmd->Connection = sqlConn;
            sqlCmd->CommandText = "UPDATE users SET FirstName = @FirstName, LastName = @LastName, Email = @Email, ProfilePic = @ProfilePic WHERE UserID = @UserID";

            sqlCmd->Parameters->AddWithValue("@UserID", textBox1->Text);
            sqlCmd->Parameters->AddWithValue("@FirstName", textBox2->Text);
            sqlCmd->Parameters->AddWithValue("@LastName", textBox3->Text);
            sqlCmd->Parameters->AddWithValue("@Email", textBox4->Text);
            

            sqlCmd->ExecuteNonQuery();
            MessageBox::Show("Profile updated successfully!");

            sqlConn->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("An error occurred: " + ex->Message);
        }
    }

    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }

    
    private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void ProfileManagementForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
