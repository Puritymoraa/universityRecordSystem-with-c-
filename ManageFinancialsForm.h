#pragma once
#include "PayFeeForm1.h"

namespace project {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class ManageFinancialsForm : public System::Windows::Forms::Form
    {
    private:
        // MySQL-related variables
        MySqlConnection^ sqlConn;
        MySqlCommand^ sqlCmd;
        MySqlDataReader^ sqlRd;
        DataTable^ sqlDt;
    private: System::Windows::Forms::TextBox^ textBoxStudentID; // Corrected to match your description
    private: System::Windows::Forms::ComboBox^ comboBoxStatus;
    private: System::Windows::Forms::Label^ label3;
           String^ connectionString;

    public:
        ManageFinancialsForm(void)
        {
            InitializeComponent();
            sqlConn = gcnew MySqlConnection();
            sqlCmd = gcnew MySqlCommand();
            sqlDt = gcnew DataTable();
            connectionString = "server=localhost;user id=root;password=;database=ashesii;";
            sqlConn->ConnectionString = connectionString;
        }

    protected:
        ~ManageFinancialsForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::DataGridView^ dataGridViewPayments;
        System::Windows::Forms::Button^ button1; // View All Payments
        System::Windows::Forms::Button^ button2; // Add New Payment
        System::Windows::Forms::Button^ button3; // Cancel
        // View Payment

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ManageFinancialsForm::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->dataGridViewPayments = (gcnew System::Windows::Forms::DataGridView());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->textBoxStudentID = (gcnew System::Windows::Forms::TextBox());
            this->comboBoxStatus = (gcnew System::Windows::Forms::ComboBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPayments))->BeginInit();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->Location = System::Drawing::Point(81, 85);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(100, 23);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Student ID:";
            // 
            // label2
            // 
            this->label2->Location = System::Drawing::Point(81, 118);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(100, 23);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Status Filter:";
            // 
            // dataGridViewPayments
            // 
            this->dataGridViewPayments->Location = System::Drawing::Point(9, 170);
            this->dataGridViewPayments->Name = L"dataGridViewPayments";
            this->dataGridViewPayments->Size = System::Drawing::Size(424, 140);
            this->dataGridViewPayments->TabIndex = 4;
            this->dataGridViewPayments->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ManageFinancialsForm::dataGridViewPayments_CellContentClick);
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(55, 339);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(111, 23);
            this->button1->TabIndex = 5;
            this->button1->Text = L"View All Payments";
            this->button1->Click += gcnew System::EventHandler(this, &ManageFinancialsForm::button1_Click);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(225, 339);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(113, 23);
            this->button2->TabIndex = 6;
            this->button2->Text = L"Add New Payment";
            this->button2->Click += gcnew System::EventHandler(this, &ManageFinancialsForm::button2_Click);
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(370, 380);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(75, 23);
            this->button3->TabIndex = 7;
            this->button3->Text = L"Cancel";
            this->button3->Click += gcnew System::EventHandler(this, &ManageFinancialsForm::button3_Click);
            // 
            // textBoxStudentID
            // 
            this->textBoxStudentID->Location = System::Drawing::Point(204, 82);
            this->textBoxStudentID->Name = L"textBoxStudentID";
            this->textBoxStudentID->Size = System::Drawing::Size(152, 20);
            this->textBoxStudentID->TabIndex = 9;
            this->textBoxStudentID->TextChanged += gcnew System::EventHandler(this, &ManageFinancialsForm::textBoxStudentID_TextChanged);
            // 
            // comboBoxStatus
            // 
            this->comboBoxStatus->FormattingEnabled = true;
            this->comboBoxStatus->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Pending", L"Paid", L"Failed", L"Refunded" });
            this->comboBoxStatus->Location = System::Drawing::Point(204, 120);
            this->comboBoxStatus->Name = L"comboBoxStatus";
            this->comboBoxStatus->Size = System::Drawing::Size(152, 21);
            this->comboBoxStatus->TabIndex = 10;
            this->comboBoxStatus->SelectedIndexChanged += gcnew System::EventHandler(this, &ManageFinancialsForm::comboBoxStatus_SelectedIndexChanged);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->ForeColor = System::Drawing::Color::DarkOrange;
            this->label3->Location = System::Drawing::Point(145, 38);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(211, 13);
            this->label3->TabIndex = 11;
            this->label3->Text = L"Welcome to the financial management form";
            // 
            // ManageFinancialsForm
            // 
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(521, 415);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->comboBoxStatus);
            this->Controls->Add(this->textBoxStudentID);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->dataGridViewPayments);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button3);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"ManageFinancialsForm";
            this->Load += gcnew System::EventHandler(this, &ManageFinancialsForm::ManageFinancialsForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPayments))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
        {
            try {
                sqlConn->Open();
                sqlCmd->Connection = sqlConn;
                sqlCmd->CommandText = "SELECT * FROM payments";
                sqlRd = sqlCmd->ExecuteReader();
                sqlDt->Load(sqlRd);
                dataGridViewPayments->DataSource = sqlDt;
                sqlConn->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
            }
        }

        System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
        {
            PayFeeForm1^ newForm = gcnew PayFeeForm1();
            newForm->ShowDialog();
        }

        System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Close();
        }

        System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // View specific payment details logic
            if (dataGridViewPayments->SelectedRows->Count > 0) {
                int rowIndex = dataGridViewPayments->SelectedRows[0]->Index;
                // Use rowIndex to retrieve and view specific payment information
            }
        }

        System::Void textBoxStudentID_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            // Filter by Student ID
            String^ filterQuery = "SELECT * FROM payments WHERE StudentID LIKE '%" + textBoxStudentID->Text + "%'";
            ApplyFilter(filterQuery);
        }

        System::Void comboBoxStatus_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            // Filter by Status
            String^ filterQuery = "SELECT * FROM payments WHERE Status = '" + comboBoxStatus->SelectedItem->ToString() + "'";
            ApplyFilter(filterQuery);
        }

        void ApplyFilter(String^ filterQuery)
        {
            try {
                sqlConn->Open();
                sqlCmd->Connection = sqlConn;
                sqlCmd->CommandText = filterQuery;
                sqlRd = sqlCmd->ExecuteReader();
                sqlDt->Clear(); // Clear previous results
                sqlDt->Load(sqlRd); // Load new filtered data
                dataGridViewPayments->DataSource = sqlDt;
                sqlConn->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
            }
        }

        System::Void dataGridViewPayments_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
        {
            // Handle cell content click events if needed
        }
    private: System::Void ManageFinancialsForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
