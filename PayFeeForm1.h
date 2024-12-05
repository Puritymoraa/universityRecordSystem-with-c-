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
	/// Summary for PayFeeForm1
	/// </summary>
	public ref class PayFeeForm1 : public System::Windows::Forms::Form
	{
	private:
		// MySQL-related variables
		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label7;
		   String^ connectionString;

	public:
		PayFeeForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			sqlConn = gcnew MySqlConnection();
			sqlCmd = gcnew MySqlCommand();
			connectionString = "server=localhost;user id=root;password=;database=ashesii;";
			sqlConn->ConnectionString = connectionString;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PayFeeForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::TextBox^ textBox4;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(185, 350);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PayFeeForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(320, 380);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PayFeeForm1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Student ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 164);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Amount";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 191);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Status";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(26, 118);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(87, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Payment Method";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(26, 230);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Payment Date";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(29, 279);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(84, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Additional Notes";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(123, 71);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(121, 20);
			this->textBox1->TabIndex = 8;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(124, 157);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(120, 20);
			this->textBox3->TabIndex = 10;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Credit Card", L"Debit Card", L"Bank Transfer",
					L"Cash", L"Cheque"
			});
			this->comboBox1->Location = System::Drawing::Point(122, 115);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 11;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(122, 224);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 12;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(122, 272);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(200, 20);
			this->textBox4->TabIndex = 13;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Pending", L"Paid", L"Failed", L"Refunded" });
			this->comboBox2->Location = System::Drawing::Point(122, 183);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::Color::DarkOrange;
			this->label7->Location = System::Drawing::Point(105, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(139, 26);
			this->label7->TabIndex = 15;
			this->label7->Text = L"         Welcome student\r\nThis is the fee payment form";
			// 
			// PayFeeForm1
			// 
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(464, 415);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"PayFeeForm1";
			this->Text = L"Fee Payment Form";
			this->Load += gcnew System::EventHandler(this, &PayFeeForm1::PayFeeForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Validate input fields
		if (textBox1->Text == "" || textBox3->Text == "" || comboBox1->SelectedIndex == -1 || comboBox2->SelectedIndex == -1)
		{
			MessageBox::Show("Please fill in all fields.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try {
			// Open MySQL connection
			sqlConn->Open();

			// Prepare SQL query to insert data
			String^ query = "INSERT INTO payments (StudentID, Amount, PaymentMethod, PaymentDate, Status, Notes) VALUES (@StudentID, @Amount, @PaymentMethod, @PaymentDate, @Status, @Notes)";
			sqlCmd->CommandText = query;
			sqlCmd->Connection = sqlConn;

			// Add parameters
			sqlCmd->Parameters->AddWithValue("@StudentID", textBox1->Text);
			sqlCmd->Parameters->AddWithValue("@Amount", textBox3->Text);
			sqlCmd->Parameters->AddWithValue("@PaymentMethod", comboBox1->Text);
			sqlCmd->Parameters->AddWithValue("@PaymentDate", dateTimePicker1->Value);
			sqlCmd->Parameters->AddWithValue("@Status", comboBox2->Text);
			sqlCmd->Parameters->AddWithValue("@Notes", textBox4->Text);

			// Execute query
			sqlCmd->ExecuteNonQuery();
			MessageBox::Show("Payment recorded successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Close the connection
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			// Handle errors
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close the form without saving
		this->Close();
	}
	private: System::Void PayFeeForm1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
