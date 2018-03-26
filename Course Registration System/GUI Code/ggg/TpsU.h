#pragma once
namespace ggg {
			using namespace System;
			using namespace System::ComponentModel;
			using namespace System::Collections;
			using namespace System::Windows::Forms;
			using namespace System::Data;
			using namespace System::Drawing;
			using namespace System::Data::OracleClient;

			public ref class TpsU : public System::Windows::Forms::Form
			{
			public:
				TpsU(OracleConnection^ myConnection)
				{
					this -> oraConn = myConnection;
					InitializeComponent();
				}

			protected:
				~TpsU()
				{
					if (components)
					{
						delete components;
					}
				}
			private: System::Windows::Forms::Button^  button2;
			protected: 
			private: System::Windows::Forms::Button^  button1;
			private: System::Windows::Forms::TextBox^  textBox1;
			private: System::Windows::Forms::Label^  label2;
			private: System::Windows::Forms::DataGridView^  dataGridView1;
			private: System::Windows::Forms::Label^  label1;

			private:

			System::ComponentModel::Container ^components;
			private: System::Windows::Forms::DataGridViewTextBoxColumn^  SID;
			private: System::Windows::Forms::DataGridViewTextBoxColumn^  StudentName;
			private: System::Windows::Forms::DataGridViewTextBoxColumn^  Grade;
			private: System::Windows::Forms::DataGridViewTextBoxColumn^  Department;

#pragma region Windows Form Designer generated code
		static OracleConnection^ oraConn;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TpsU::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->SID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StudentName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Grade = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Department = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(26, 540);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 30);
			this->button2->TabIndex = 11;
			this->button2->Text = L"<<   Back";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TpsU::close);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(323, 72);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 30);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TpsU::searchTpsU);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox1->Location = System::Drawing::Point(197, 77);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 9;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(102, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 25);
			this->label2->TabIndex = 8;
			this->label2->Text = L"TopN";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->SID, this->StudentName, 
				this->Grade, this->Department});
			this->dataGridView1->Location = System::Drawing::Point(26, 125);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->Size = System::Drawing::Size(444, 388);
			this->dataGridView1->TabIndex = 7;
			// 
			// SID
			// 
			this->SID->HeaderText = L"SID";
			this->SID->Name = L"SID";
			this->SID->ReadOnly = true;
			// 
			// StudentName
			// 
			this->StudentName->HeaderText = L"StudentName";
			this->StudentName->Name = L"StudentName";
			this->StudentName->ReadOnly = true;
			this->StudentName->Width = 120;
			// 
			// Grade
			// 
			this->Grade->HeaderText = L"Grade";
			this->Grade->Name = L"Grade";
			this->Grade->ReadOnly = true;
			this->Grade->Width = 80;
			// 
			// Department
			// 
			this->Department->HeaderText = L"Department";
			this->Department->Name = L"Department";
			this->Department->ReadOnly = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(200, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 28);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Student";
			// 
			// TpsU
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(494, 582);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"TpsU";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Top N Students In The Campus";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		private: System::Void searchTpsU(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				bool isD = true;
				for(int i = 0; i < (this -> textBox1 -> Text -> Length); i++)
				{
					if(!Char::IsDigit(this -> textBox1 -> Text[i]))
					{
						isD = false;
					}
				}

			if(this -> textBox1 ->Text != "" && isD)
			{
				if(oraConn -> State == ConnectionState::Open) 
				{
					int totalRows = 0, n=0;
					OracleCommand^ command = oraConn -> CreateCommand();
					command -> CommandText = gcnew String("SELECT student_id, student_name, avggrade, department FROM students NATURAL JOIN (SELECT student_id, ROUND(AVG(grade), 2) avggrade FROM students NATURAL JOIN enrollment GROUP BY student_id) ORDER BY avggrade DESC");

					n = Convert::ToInt32(this -> textBox1 ->Text);

					OracleDataReader^ myReader = command -> ExecuteReader();
		
					while(n-- && myReader -> Read()) 
					{
							String^ student_id = myReader -> GetString(0);
							String^ student_name = myReader -> GetString(1);
							String^ grade = Convert::ToString(myReader -> GetDouble(2));
							String^ dept = myReader -> GetString(3);

							this->dataGridView1->Rows->Add();
							this->dataGridView1->Rows[totalRows]->Cells[0]->Value = student_id;
							this->dataGridView1->Rows[totalRows]->Cells[1]->Value = student_name;
							this->dataGridView1->Rows[totalRows]->Cells[2]->Value = grade;
							this->dataGridView1->Rows[totalRows]->Cells[3]->Value = dept;
							totalRows++;
					}

					myReader -> Close();
				}//end of if
			}
			else
			{
				MessageBox::Show("Please input the number of top students!");
				this -> textBox1 -> Text = "";
			}
		}

		private: System::Void close(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				this -> Close();
		}
};
}
