#pragma once
#include "CourseRegistrationForm.h"
#include "ProfileManagementForm.h"
#include "StudentGradeForm1.h"
#include "PayFeeForm1.h"
#include "ViewSchedule.h"


namespace project {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for StudentMenu
    /// </summary>
    public ref class StudentMenu : public System::Windows::Forms::Form
    {
    public:
        StudentMenu(void)
        {
            InitializeComponent();
        }

    protected:
        ~StudentMenu()
        {
            if (components)
            {
                delete components;
            }
        }







    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Label^ label1;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StudentMenu::typeid));
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(136, 158);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(145, 23);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Register for courses";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &StudentMenu::button1_Click);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(136, 197);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(145, 23);
            this->button2->TabIndex = 2;
            this->button2->Text = L"View your Grades";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &StudentMenu::button2_Click);
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(136, 114);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(145, 23);
            this->button3->TabIndex = 3;
            this->button3->Text = L"Manage your profile";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &StudentMenu::button3_Click);
            // 
            // button4
            // 
            this->button4->Location = System::Drawing::Point(136, 255);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(145, 23);
            this->button4->TabIndex = 4;
            this->button4->Text = L"Pay Fees";
            this->button4->UseVisualStyleBackColor = true;
            this->button4->Click += gcnew System::EventHandler(this, &StudentMenu::button4_Click);
            // 
            // button5
            // 
            this->button5->Location = System::Drawing::Point(136, 226);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(145, 23);
            this->button5->TabIndex = 5;
            this->button5->Text = L"View your Schedule";
            this->button5->UseVisualStyleBackColor = true;
            this->button5->Click += gcnew System::EventHandler(this, &StudentMenu::button5_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->ForeColor = System::Drawing::Color::DarkOrange;
            this->label1->Location = System::Drawing::Point(133, 56);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(160, 26);
            this->label1->TabIndex = 6;
            this->label1->Text = L"          Welcome student\r\nSelect what you want to do here";
            // 
            // StudentMenu
            // 
            this->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Maroon;
            this->ClientSize = System::Drawing::Size(484, 661);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button5);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"StudentMenu";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Student Dashboard";
            this->Load += gcnew System::EventHandler(this, &StudentMenu::StudentMenu_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            CourseRegistrationForm^ courseForm = gcnew CourseRegistrationForm();
            courseForm->Show();
        }
        catch (System::Exception^ ex) {
            MessageBox::Show("Error opening Course Registration Form: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            StudentGradeForm^ gradeForm = gcnew StudentGradeForm();
            gradeForm->Show();
        }
        catch (System::Exception^ ex) {
            MessageBox::Show("Error opening Student Grade Form: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            ProfileManagementForm^ profileForm = gcnew ProfileManagementForm();
            profileForm->Show();
        }
        catch (System::Exception^ ex) {
            MessageBox::Show("Error opening Profile Management Form: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void courseRegistrationFormToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        button1_Click(sender, e);
    }

    private: System::Void reportFormToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        MessageBox::Show("Report Form clicked!");
    }

    private: System::Void profileManagementFormToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        button3_Click(sender, e);
    }
    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            PayFeeForm1^ payFeeForm = gcnew PayFeeForm1();  // Corrected to PayFeeForm1
            payFeeForm->Show();
        }
        catch (System::Exception^ ex) {
            MessageBox::Show("Error opening Pay Fee Form: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }


    }

    private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            ViewSchedule^ viewScheduleForm = gcnew ViewSchedule();  // Correct form name
            viewScheduleForm->Show();
        }
        catch (System::Exception^ ex) {
            MessageBox::Show("Error opening View Schedule Form: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }


    private: System::Void StudentMenu_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
