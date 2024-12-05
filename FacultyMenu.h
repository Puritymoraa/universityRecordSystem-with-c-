#pragma once
#include "GradeEntryForm.h"
#include "ProfileManagementForm.h"
#include "ViewClassRoster.h"
#include "CourseManagementForm.h"

namespace project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FacultyMenu
	/// </summary>
	public ref class FacultyMenu : public System::Windows::Forms::Form
	{
	public:
		FacultyMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FacultyMenu()
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
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FacultyMenu::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(133, 158);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(155, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Enter Grades";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FacultyMenu::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(133, 187);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(155, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Manage profiles";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FacultyMenu::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(133, 216);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(155, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"View Class Roster";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FacultyMenu::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(133, 129);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(155, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Manage Courses";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &FacultyMenu::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::DarkOrange;
			this->label1->Location = System::Drawing::Point(130, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 39);
			this->label1->TabIndex = 5;
			this->label1->Text = L"         Welcome Faculty\r\n\r\nSelect what you want to do here:";
			// 
			// FacultyMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(484, 661);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FacultyMenu";
			this->Text = L"Faculty Dashboard";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Button click event handlers
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Open Grade Entry Form
		GradeEntryForm^ gradeForm = gcnew GradeEntryForm();
		gradeForm->Show();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// Open Profile Management Form
		ProfileManagementForm^ profileForm = gcnew ProfileManagementForm();
		profileForm->Show();
	}

		   // Menu item click event handlers
	private: System::Void gradeEntryFormToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		// Open Grade Entry Form from Menu
		GradeEntryForm^ gradeForm = gcnew GradeEntryForm();
		gradeForm->Show();
	}

	private: System::Void profileManagementToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		// Open Profile Management Form from Menu
		ProfileManagementForm^ profileForm = gcnew ProfileManagementForm();
		profileForm->Show();
	}

		   // Form Load event handler (optional)
	private: System::Void FacultyMenu_Load(System::Object^ sender, System::EventArgs^ e) {
		// Additional initialization code (if needed)
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create an instance of the ViewClassRoster form
		ViewClassRoster^ viewClassRosterForm = gcnew ViewClassRoster();

		// Show the ViewClassRoster form
		viewClassRosterForm->Show();

		// Optionally, hide the current form if you want it to not be visible
		this->Hide();
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create an instance of the CourseManagementForm
		CourseManagementForm^ courseManagementForm = gcnew CourseManagementForm();

		// Show the CourseManagementForm
		courseManagementForm->Show();

		// Optionally, hide the current form if you want it to not be visible
		this->Hide();
	}
	};
}
