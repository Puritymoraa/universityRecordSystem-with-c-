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
	/// Summary for AdministratorManagementForm
	/// </summary>
	public ref class AdministratorManagementForm : public System::Windows::Forms::Form
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
		AdministratorManagementForm(void)
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
		~AdministratorManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
		   // ComboBox for role selection
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdministratorManagementForm::typeid));
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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Admin ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Enter Full Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Enter Email";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(25, 152);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Enter Password";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(127, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(127, 61);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(127, 108);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 6;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(127, 149);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(28, 210);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Add Admin";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdministratorManagementForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(138, 210);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Update Admin";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdministratorManagementForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(248, 210);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Delete Admin";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AdministratorManagementForm::button3_Click);
			// 
			// AdministratorManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(352, 253);
			this->Controls->Add(this->button3);
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
			this->Name = L"AdministratorManagementForm";
			this->Text = L"Administrator Management";
			this->Load += gcnew System::EventHandler(this, &AdministratorManagementForm::AdministratorManagementForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Add methods for the button clicks here
		void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "INSERT INTO administrators (AdminID, FullName, Email, Password) VALUES (@AdminID, @FullName, @Email, @Password)";

				// Add parameters for the Insert statement
				sqlCmd->Parameters->AddWithValue("@AdminID", textBox1->Text);
				sqlCmd->Parameters->AddWithValue("@FullName", textBox2->Text);
				sqlCmd->Parameters->AddWithValue("@Email", textBox3->Text);
				sqlCmd->Parameters->AddWithValue("@Password", textBox4->Text);
				//sqlCmd->Parameters->AddWithValue("@Role", comboBoxRole->SelectedItem->ToString());

				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Administrator added successfully!");
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message);
			}
		}

		void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "UPDATE administrators SET FullName = @FullName, Email = @Email, Password = @Password WHERE AdminID = @AdminID";

				// Add parameters for the Update statement
				sqlCmd->Parameters->AddWithValue("@AdminID", textBox1->Text); // Assuming AdminID is provided for updating
				sqlCmd->Parameters->AddWithValue("@FullName", textBox2->Text);
				sqlCmd->Parameters->AddWithValue("@Email", textBox3->Text);
				sqlCmd->Parameters->AddWithValue("@Password", textBox4->Text);
				//sqlCmd->Parameters->AddWithValue("@Role", comboBoxRole->SelectedItem->ToString());

				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Administrator updated successfully!");
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message);
			}
		}

		void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "DELETE FROM administrators WHERE AdminID = @AdminID";

				// Add parameter for the Delete statement
				sqlCmd->Parameters->AddWithValue("@AdminID", textBox1->Text); // Assuming AdminID is provided for deleting

				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Administrator deleted successfully!");
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message);
			}
		}
	private: System::Void AdministratorManagementForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
