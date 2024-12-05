#pragma once

#include "AdministratorManagementForm.h"
#include "CourseManagementForm.h"
#include "FacultyManagementForm.h"
#include "TranscriptGenerationForm.h"
#include "ProfileManagementForm.h"
#include "ReportForm.h"
#include "ManageFinancialsForm.h"

namespace project {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for AdminMenu
    /// </summary>
    public ref class AdminMenu : public System::Windows::Forms::Form
    {
    public:
        AdminMenu(void)
        {
            InitializeComponent();
        }

    protected:
        ~AdminMenu()
        {
            if (components)
            {
                delete components;
            }
        }










    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Button^ button6;
    private: System::Windows::Forms::Button^ button7;
    private: System::Windows::Forms::Label^ label1;

    protected:

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminMenu::typeid));
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(11, 213);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(180, 23);
            this->button2->TabIndex = 2;
            this->button2->Text = L"Manage Courses";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &AdminMenu::button2_Click);
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(12, 124);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(180, 23);
            this->button3->TabIndex = 3;
            this->button3->Text = L"Manage Faculty";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &AdminMenu::button3_Click);
            // 
            // button4
            // 
            this->button4->Location = System::Drawing::Point(11, 269);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(180, 23);
            this->button4->TabIndex = 4;
            this->button4->Text = L"Generate Transcripts";
            this->button4->UseVisualStyleBackColor = true;
            this->button4->Click += gcnew System::EventHandler(this, &AdminMenu::button4_Click);
            // 
            // button5
            // 
            this->button5->Location = System::Drawing::Point(12, 153);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(180, 23);
            this->button5->TabIndex = 5;
            this->button5->Text = L"Manage  profiles";
            this->button5->UseVisualStyleBackColor = true;
            this->button5->Click += gcnew System::EventHandler(this, &AdminMenu::button5_Click);
            // 
            // button6
            // 
            this->button6->Location = System::Drawing::Point(12, 182);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(180, 25);
            this->button6->TabIndex = 6;
            this->button6->Text = L"Manage reports forms";
            this->button6->UseVisualStyleBackColor = true;
            this->button6->Click += gcnew System::EventHandler(this, &AdminMenu::button6_Click);
            // 
            // button7
            // 
            this->button7->Location = System::Drawing::Point(11, 242);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(180, 23);
            this->button7->TabIndex = 7;
            this->button7->Text = L"Manage Financials";
            this->button7->UseVisualStyleBackColor = true;
            this->button7->Click += gcnew System::EventHandler(this, &AdminMenu::button7_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->ForeColor = System::Drawing::Color::DarkOrange;
            this->label1->Location = System::Drawing::Point(12, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(249, 39);
            this->label1->TabIndex = 8;
            this->label1->Text = L"WELCOME TO THE ADMIN WINDOW\r\n\r\nPLEASE SELECT ON OF THE OPTIONS BELOW:";
            // 
            // AdminMenu
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Maroon;
            this->ClientSize = System::Drawing::Size(484, 661);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button7);
            this->Controls->Add(this->button6);
            this->Controls->Add(this->button5);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"AdminMenu";
            this->Text = L"Administrator";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        // Button Click Event Handlers

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        // Open Administrator Management Form
        AdministratorManagementForm^ adminForm = gcnew AdministratorManagementForm();
        adminForm->Show();
    }

    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        // Open Course Management Form
        CourseManagementForm^ courseForm = gcnew CourseManagementForm();
        courseForm->Show();
    }

    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
        // Open Faculty Management Form
        FacultyManagementForm^ facultyForm = gcnew FacultyManagementForm();
        facultyForm->Show();
    }

    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
        // Open Transcript Generation Form
        TranscriptGenerationForm^ transcriptForm = gcnew TranscriptGenerationForm();
        transcriptForm->Show();
    }

    private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
        // Open Profile Management Form
        ProfileManagementForm^ profileForm = gcnew ProfileManagementForm();
        profileForm->Show();
    }
    private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            ReportForm^ reportForm = gcnew ReportForm();
            reportForm->Show();
        }
        catch (System::Exception^ ex) {
            MessageBox::Show("Error opening Report Form: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

    }
    private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            ManageFinancialsForm^ manageFinancialsForm = gcnew ManageFinancialsForm();
            manageFinancialsForm->Show(); 
        }
        catch (System::Exception^ ex) {
            MessageBox::Show("Error opening Manage Financials Form: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    };
}
