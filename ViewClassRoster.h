#pragma once

namespace project {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class ViewClassRoster : public System::Windows::Forms::Form
    {
    private:
        MySqlConnection^ sqlConn;
        MySqlCommand^ sqlCmd;
        DataTable^ sqlDt;
        MySqlDataAdapter^ sqlDtA;
        MySqlDataReader^ sqlRd;
    private: System::Windows::Forms::Label^ label3;

        String^ connectionString;

    public:
        ViewClassRoster(void)
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
        ~ViewClassRoster()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ StudentID;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ StudentName;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Major;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ DaysPresent;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ DaysAbsent;
    private: System::Windows::Forms::Button^ button1;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->StudentID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->StudentName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Major = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->DaysPresent = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->DaysAbsent = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label3 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(296, 75);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(73, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Select Course";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(34, 79);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(90, 13);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Enter Department";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(279, 32);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(0, 13);
            this->label4->TabIndex = 3;
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
                L"Computer Science", L"Mathematics", L"Physics",
                    L"Chemistry", L"Biology", L"Literature", L"History", L"Philosophy", L"Sociology", L"Political Science"
            });
            this->comboBox1->Location = System::Drawing::Point(397, 67);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(104, 21);
            this->comboBox1->TabIndex = 9;
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(130, 72);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(104, 20);
            this->textBox1->TabIndex = 10;
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
                this->StudentID,
                    this->StudentName, this->Major, this->DaysPresent, this->DaysAbsent
            });
            this->dataGridView1->Location = System::Drawing::Point(12, 109);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(524, 173);
            this->dataGridView1->TabIndex = 11;
            // 
            // StudentID
            // 
            this->StudentID->HeaderText = L"Student ID";
            this->StudentID->Name = L"StudentID";
            // 
            // StudentName
            // 
            this->StudentName->HeaderText = L"Student Name";
            this->StudentName->Name = L"StudentName";
            // 
            // Major
            // 
            this->Major->HeaderText = L"Major";
            this->Major->Name = L"Major";
            // 
            // DaysPresent
            // 
            this->DaysPresent->HeaderText = L"Days Present";
            this->DaysPresent->Name = L"DaysPresent";
            // 
            // DaysAbsent
            // 
            this->DaysAbsent->HeaderText = L"Days Absent";
            this->DaysAbsent->Name = L"DaysAbsent";
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(12, 310);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(107, 23);
            this->button1->TabIndex = 12;
            this->button1->Text = L"OK";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &ViewClassRoster::button1_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(172, 19);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(175, 26);
            this->label3->TabIndex = 13;
            this->label3->Text = L"                    Welcome\r\nYou can view your class roster here";
            // 
            // ViewClassRoster
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Maroon;
            this->ClientSize = System::Drawing::Size(560, 365);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"ViewClassRoster";
            this->Text = L"View Class Roster";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            sqlConn->Open();
            String^ query = "SELECT s.StudentID, s.FirstName, s.LastName, s.Major, SUM(a.Present) AS DaysPresent, "
                "COUNT(a.Present) - SUM(a.Present) AS DaysAbsent "
                "FROM students s "
                "LEFT JOIN attendance a ON s.StudentID = a.StudentID "
                "GROUP BY s.StudentID";

            sqlCmd->CommandText = query;
            sqlCmd->Connection = sqlConn;
            sqlRd = sqlCmd->ExecuteReader();

            while (sqlRd->Read()) {
                dataGridView1->Rows->Add(sqlRd["StudentID"], sqlRd["FirstName"] + " " + sqlRd["LastName"],
                    sqlRd["Major"], sqlRd["DaysPresent"], sqlRd["DaysAbsent"]);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show(ex->Message);
        }
        finally {
            sqlConn->Close();
        }
    }
    };
}
