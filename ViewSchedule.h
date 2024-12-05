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
	/// Summary for ViewSchedule
	/// </summary>
	public ref class ViewSchedule : public System::Windows::Forms::Form
	{
	private:
		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
		DataTable^ sqlDt;
		MySqlDataAdapter^ sqlDtA;
		MySqlDataReader^ sqlRd;
	private: System::Windows::Forms::Label^ label2;

		String^ connectionString;

	public:
		ViewSchedule(void)
		{
			InitializeComponent();
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
		~ViewSchedule()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ViewSchedule::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 97);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Student ID";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(155, 90);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(123, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(397, 289);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Schedule";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ViewSchedule::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(72, 133);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(400, 150);
			this->dataGridView1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::DarkOrange;
			this->label2->Location = System::Drawing::Point(196, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(165, 26);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Welcome student \r\nYou can view your schedule here";
			// 
			// ViewSchedule
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(484, 348);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ViewSchedule";
			this->Text = L"Schedule";
			this->Load += gcnew System::EventHandler(this, &ViewSchedule::ViewSchedule_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Event when the button is clicked
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Ensure student ID is entered
		if (textBox1->Text->Length == 0) {
			MessageBox::Show("Please enter a Student ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Try to fetch and display the schedule
		try {
			sqlConn->Open();
			sqlCmd->CommandText = "SELECT * FROM schedule WHERE StudentID = @StudentID";
			sqlCmd->CommandType = CommandType::Text;
			sqlCmd->Connection = sqlConn;

			// Use parameters to avoid SQL injection
			sqlCmd->Parameters->AddWithValue("@StudentID", textBox1->Text);

			sqlDtA->SelectCommand = sqlCmd;
			sqlDtA->Fill(sqlDt);

			// Set the DataGridView to display the schedule
			dataGridView1->DataSource = sqlDt;

			sqlConn->Close();
		}
		catch (MySqlException^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

		   // Form load event, not necessary to modify but can be used for initial setup
	private: System::Void ViewSchedule_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
