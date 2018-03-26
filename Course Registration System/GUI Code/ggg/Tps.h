#pragma once
namespace ggg {
			using namespace System;
			using namespace System::ComponentModel;
			using namespace System::Collections;
			using namespace System::Windows::Forms;
			using namespace System::Data;
			using namespace System::Drawing;
			using namespace System::Data::OracleClient;

			public ref class Tps : public System::Windows::Forms::Form
			{
			public:
				Tps(OracleConnection^ myConnection, String^ CID)
				{
					this -> oraConn = myConnection;
					this -> CID = CID;
					InitializeComponent();
				}

			protected:
				~Tps()
				{
					if (components)
					{
						delete components;
					}
				}
			private: System::Windows::Forms::Label^  label1;
			protected: 
			private: System::Windows::Forms::DataGridView^  dataGridView1;
			private: System::Windows::Forms::Label^  label2;
			private: System::Windows::Forms::TextBox^  textBox1;
			private: System::Windows::Forms::Button^  button1;
			private: System::Windows::Forms::Button^  button2;

			private:
				System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static OracleConnection^ oraConn;
		static String^ CID;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  SID;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  StudentName;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Grade;
			 
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Tps::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->SID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StudentName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Grade = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(153, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Course";
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->SID, this->StudentName, 
				this->Grade});
			this->dataGridView1->Location = System::Drawing::Point(23, 111);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->Size = System::Drawing::Size(346, 380);
			this->dataGridView1->TabIndex = 1;
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(45, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"TopN";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox1->Location = System::Drawing::Point(142, 72);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(279, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 30);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Tps::searchS);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(23, 520);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 30);
			this->button2->TabIndex = 5;
			this->button2->Text = L"<<   Back";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Tps::close);
			// 
			// Tps
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(399, 562);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Tps";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Top N Students In The Course";
			this->Load += gcnew System::EventHandler(this, &Tps::Tps_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		private: System::Void close(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				this -> Close();
		}

		private: System::Void searchS(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				bool isD = true;
				for(int i = 0; i < (this -> textBox1 -> Text -> Length); i++)
				{
					if(!Char::IsDigit(this -> textBox1 -> Text[i]))
					{
						isD = false;
					}
				}

			if(this->textBox1-> Text != "" && isD)
			{
			 	if(oraConn -> State == ConnectionState::Open) 
				{
						int totalRows = 0, n=0;
						this -> dataGridView1->Rows->Clear();
						OracleCommand^ command = oraConn -> CreateCommand();
						command -> CommandText = gcnew String("SELECT student_id, student_name, grade FROM students NATURAL JOIN (SELECT student_id, grade FROM enrollment WHERE course_id=:pCID) ORDER BY grade DESC");

						n = Convert::ToInt32(this->textBox1-> Text);

						command -> Parameters -> Add("pCID", OracleType::Char);
						command -> Parameters -> default[0] -> Value = this -> CID;

						OracleDataReader^ myReader = command -> ExecuteReader();

						while(n-- && myReader -> Read()) 
						{
								String^ student_id = myReader -> GetString(0);
								String^ student_name = myReader -> GetString(1);
								String^ grade = Convert::ToString(myReader -> GetInt32(2));

								this->dataGridView1->Rows->Add();
								this->dataGridView1->Rows[totalRows]->Cells[0]->Value = student_id;
								this->dataGridView1->Rows[totalRows]->Cells[1]->Value = student_name;
								this->dataGridView1->Rows[totalRows]->Cells[2]->Value = grade;

								totalRows++;
						}

						myReader -> Close();
				}//end of if
			}
			else
			{
				MessageBox::Show("Please input the correct number!");
				this -> textBox1 -> Text = "";
			}
		 }

		private: System::Void Tps_Load(System::Object^  sender, System::EventArgs^  e) 
		{
				this -> label1 -> Text = CID;
		}
};
}
