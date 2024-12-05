#pragma once

#include "LoginForm.h"
#include "AdminMenu.h"
#include "FacultyMenu.h"
#include "StudentMenu.h"
/*THIS IS THE FIRST PAGE THAT THE USER WILL INTERACT WITH. Be it a student, a faculty or an administrator */

namespace project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class MDIParentForm : public System::Windows::Forms::Form
	{
	public:
		MDIParentForm(void)
		{
			InitializeComponent();
			
		}

	protected:
		
		~MDIParentForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:





	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;


	private: System::ComponentModel::IContainer^ components;

	private:
		

#pragma region Windows Form Designer generated code
	
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MDIParentForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(167, 247);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Administrator";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MDIParentForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(168, 198);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Faculty";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MDIParentForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(169, 155);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(99, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Student";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MDIParentForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(151, 108);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 26);
			this->label1->TabIndex = 6;
			this->label1->Text = L"WELCOME USER\r\nSELECT YOUR ROLE BELOW ";
			// 
			// MDIParentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(573, 661);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->IsMdiContainer = true;
			this->Name = L"MDIParentForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"University students’ records management system";
			this->Load += gcnew System::EventHandler(this, &MDIParentForm::MDIParentForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void adminMenuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		LoginForm^ loginForm = gcnew LoginForm();

		
		if (loginForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			
			AdminMenu^ adminMenu = gcnew AdminMenu();
			adminMenu->Show(); 
		}
		
		this->Close(); 
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
		LoginForm^ loginForm = gcnew LoginForm();

		
		if (loginForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			
			FacultyMenu^ facultyMenu = gcnew FacultyMenu();
			facultyMenu->Show(); 
		}
		
		this->Close(); 
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		
		LoginForm^ loginForm = gcnew LoginForm();

		
		if (loginForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			
			StudentMenu^ studentMenu = gcnew StudentMenu();
			studentMenu->Show(); 
		}
		
		this->Close(); 
	}
	private: System::Void MDIParentForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
