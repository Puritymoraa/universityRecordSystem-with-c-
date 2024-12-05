#pragma once

#include "AdminMenu.h"
#include "FacultyMenu.h"
#include "StudentMenu.h"

namespace project {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace MySql::Data::MySqlClient;

    public ref class LoginForm : public Form {
    private:
        
        MySqlConnection^ sqlConn;
        MySqlCommand^ sqlCmd;
        DataTable^ sqlDt;
        MySqlDataAdapter^ sqlDtA;
        MySqlDataReader^ sqlRd;
        String^ connectionString;
        System::ComponentModel::Container^ components;

       
        System::Windows::Forms::Label^ labelEmail;
        System::Windows::Forms::Label^ labelPassword;

        System::Windows::Forms::Button^ buttonLogin;
        System::Windows::Forms::Button^ buttonReset;

        
        System::Windows::Forms::TextBox^ textBoxEmail;  
        System::Windows::Forms::TextBox^ textBoxPassword;  

    public:
        LoginForm(void) {
            InitializeComponent();
            sqlConn = gcnew MySqlConnection();
            sqlCmd = gcnew MySqlCommand();
            sqlDt = gcnew DataTable();
            sqlDtA = gcnew MySqlDataAdapter();
            connectionString = "server=localhost;user id=root;password=;database=ashesii;";
            sqlConn->ConnectionString = connectionString;
        }

        void InitializeComponent(void) {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
            this->labelEmail = (gcnew System::Windows::Forms::Label());
            this->labelPassword = (gcnew System::Windows::Forms::Label());
            this->buttonLogin = (gcnew System::Windows::Forms::Button());
            this->buttonReset = (gcnew System::Windows::Forms::Button());
            this->textBoxEmail = (gcnew System::Windows::Forms::TextBox());
            this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // labelEmail
            // 
            this->labelEmail->Location = System::Drawing::Point(12, 20);
            this->labelEmail->Name = L"labelEmail";
            this->labelEmail->Size = System::Drawing::Size(100, 23);
            this->labelEmail->TabIndex = 0;
            this->labelEmail->Text = L"Enter your email:";
            // 
            // labelPassword
            // 
            this->labelPassword->Location = System::Drawing::Point(12, 60);
            this->labelPassword->Name = L"labelPassword";
            this->labelPassword->Size = System::Drawing::Size(100, 23);
            this->labelPassword->TabIndex = 2;
            this->labelPassword->Text = L"Enter your password:";
            // 
            // buttonLogin
            // 
            this->buttonLogin->Location = System::Drawing::Point(80, 113);
            this->buttonLogin->Name = L"buttonLogin";
            this->buttonLogin->Size = System::Drawing::Size(75, 23);
            this->buttonLogin->TabIndex = 5;
            this->buttonLogin->Text = L"LOGIN";
            this->buttonLogin->Click += gcnew System::EventHandler(this, &LoginForm::buttonLogin_Click);
            // 
            // buttonReset
            // 
            this->buttonReset->Location = System::Drawing::Point(206, 113);
            this->buttonReset->Name = L"buttonReset";
            this->buttonReset->Size = System::Drawing::Size(109, 23);
            this->buttonReset->TabIndex = 6;
            this->buttonReset->Text = L"Reset password";
            this->buttonReset->Click += gcnew System::EventHandler(this, &LoginForm::buttonReset_Click);
            // 
            // textBoxEmail
            // 
            this->textBoxEmail->Location = System::Drawing::Point(118, 23);
            this->textBoxEmail->Name = L"textBoxEmail";
            this->textBoxEmail->Size = System::Drawing::Size(166, 20);
            this->textBoxEmail->TabIndex = 8;
            // 
            // textBoxPassword
            // 
            this->textBoxPassword->AllowDrop = true;
            this->textBoxPassword->Location = System::Drawing::Point(118, 63);
            this->textBoxPassword->Name = L"textBoxPassword";
            this->textBoxPassword->Size = System::Drawing::Size(166, 20);
            this->textBoxPassword->TabIndex = 9;
            this->textBoxPassword->UseSystemPasswordChar = true;
            // 
            // LoginForm
            // 
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(380, 278);
            this->Controls->Add(this->textBoxPassword);
            this->Controls->Add(this->textBoxEmail);
            this->Controls->Add(this->labelEmail);
            this->Controls->Add(this->labelPassword);
            this->Controls->Add(this->buttonLogin);
            this->Controls->Add(this->buttonReset);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"LoginForm";
            this->Text = L"LOGIN OR LOGOUT";
            this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private: System::Void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            String^ query = "SELECT role FROM users WHERE Email = @Email AND Password = @Password";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, sqlConn);
            cmd->Parameters->AddWithValue("@Email", textBoxEmail->Text);
            cmd->Parameters->AddWithValue("@Password", textBoxPassword->Text);

            sqlConn->Open();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {
                int userRole = reader->GetInt32("role");
                sqlConn->Close();

                
                AdminMenu^ adminMenu = nullptr;
                FacultyMenu^ facultyMenu = nullptr;
                StudentMenu^ studentMenu = nullptr;

                switch (userRole) {
                case 1: 
                    adminMenu = gcnew AdminMenu();
                    adminMenu->Show();
                    break;
                case 2:
                    facultyMenu = gcnew FacultyMenu();
                    facultyMenu->Show();
                    break;
                case 3: 
                    studentMenu = gcnew StudentMenu();
                    studentMenu->Show();
                    break;
                default:
                    MessageBox::Show("Invalid user role.");
                    break;
                }
            }
            else {
                
                MessageBox::Show("Invalid email or password.");
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally {
            if (sqlConn->State == ConnectionState::Open) {
                sqlConn->Close();
            }
        }
    }

    private: System::Void buttonReset_Click(System::Object^ sender, System::EventArgs^ e) {
        
        textBoxEmail->Clear();
        textBoxPassword->Clear();
        
    }

    private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}