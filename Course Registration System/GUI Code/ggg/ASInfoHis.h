#pragma once
namespace ggg {
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::Data::OracleClient;

		public ref class ASInfoHis : public System::Windows::Forms::Form
		{
		public:
			ASInfoHis(OracleConnection^ myConnection)
			{
				this -> oraConn = myConnection;
				InitializeComponent();
			}

		protected:
			~ASInfoHis()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Button^  button1;
		protected: 
		private: System::Windows::Forms::Button^  button4;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::DataGridView^  dataGridView1;

		private:
			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static OracleConnection^ oraConn;	
		static int NRows;

		private: System::Windows::Forms::DataGridViewTextBoxColumn^  SID;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  StudentName;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Department;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Address;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Birthdate;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Gender;
	
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ASInfoHis::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->SID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StudentName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Department = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Address = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Birthdate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Gender = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(842, 261);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 140);
			this->button1->TabIndex = 40;
			this->button1->Text = L"Done";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ASInfoHis::close);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(842, 71);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(130, 140);
			this->button4->TabIndex = 39;
			this->button4->Text = L"Recover";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ASInfoHis::recoverS);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(252, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(432, 37);
			this->label3->TabIndex = 37;
			this->label3->Text = L"Student Information History";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->SID, this->StudentName, 
				this->Department, this->Address, this->Birthdate, this->Gender});
			this->dataGridView1->Location = System::Drawing::Point(22, 71);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(800, 330);
			this->dataGridView1->TabIndex = 41;
			// 
			// SID
			// 
			this->SID->HeaderText = L"SID";
			this->SID->Name = L"SID";
			this->SID->ReadOnly = true;
			this->SID->Width = 150;
			// 
			// StudentName
			// 
			this->StudentName->HeaderText = L"StudentName";
			this->StudentName->Name = L"StudentName";
			this->StudentName->ReadOnly = true;
			this->StudentName->Width = 150;
			// 
			// Department
			// 
			this->Department->HeaderText = L"Department";
			this->Department->Name = L"Department";
			this->Department->ReadOnly = true;
			this->Department->Width = 70;
			// 
			// Address
			// 
			this->Address->HeaderText = L"Address";
			this->Address->Name = L"Address";
			this->Address->ReadOnly = true;
			this->Address->Width = 200;
			// 
			// Birthdate
			// 
			this->Birthdate->HeaderText = L"Birthdate";
			this->Birthdate->Name = L"Birthdate";
			this->Birthdate->ReadOnly = true;
			this->Birthdate->Width = 129;
			// 
			// Gender
			// 
			this->Gender->HeaderText = L"Gender";
			this->Gender->Name = L"Gender";
			this->Gender->ReadOnly = true;
			this->Gender->Width = 57;
			// 
			// ASInfoHis
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 432);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"ASInfoHis";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Student Information History";
			this->Load += gcnew System::EventHandler(this, &ASInfoHis::ASInfoHis_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			private: System::Void close(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
					this -> Close();
			}
			private: System::Void ASInfoHis_Load(System::Object^  sender, System::EventArgs^  e) 
			{
					if(oraConn -> State == ConnectionState::Open) 
					{
						int totalRows = 0;
						OracleCommand^ command = oraConn -> CreateCommand();
						command -> CommandText = gcnew String("SELECT * FROM history_students");

						OracleDataReader^ myReader = command -> ExecuteReader();

						while(myReader -> Read()) 
						{
							String^ student_id = myReader -> GetString(0);
							String^ student_name = myReader -> GetString(1);
							String^ department = myReader -> GetString(2);
							String^ address = myReader -> GetString(3);
							String^ birthdate = Convert::ToString(myReader -> GetDateTime(4));
							String^ gender = myReader -> GetString(5);			

							this->dataGridView1->Rows->Add();
							this->dataGridView1->Rows[totalRows]->Cells[0]->Value = student_id;
							this->dataGridView1->Rows[totalRows]->Cells[1]->Value = student_name;
							this->dataGridView1->Rows[totalRows]->Cells[2]->Value = department;
							this->dataGridView1->Rows[totalRows]->Cells[3]->Value = address;	
							this->dataGridView1->Rows[totalRows]->Cells[4]->Value = birthdate -> Substring(0, 10);
							this->dataGridView1->Rows[totalRows]->Cells[5]->Value = gender;		
							totalRows++;
						}

						if(totalRows != 0)
						{
							this -> dataGridView1 -> Rows[0] -> Selected = true;
						}

						NRows = totalRows;
						myReader -> Close();
					}//end of if
			}

			private: System::Void recoverS(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
			{
					if(oraConn -> State == ConnectionState::Open) 
					{
						if(NRows != 0)
						{
							int affectRows = 0;
							String^ idStr;
							OracleCommand^ command = oraConn -> CreateCommand();

							command -> CommandText = gcnew String("INSERT INTO students SELECT * FROM history_students WHERE student_id=:pID");

							for(int i  = 0; i < NRows; i++)
							{
								if(this -> dataGridView1 -> Rows[i] -> Selected == true)
								{
									idStr = Convert::ToString(this -> dataGridView1 -> Rows[i] ->Cells[0]->Value);
								}
							}

							command -> Parameters -> Add(":pID", OracleType::Char);
							command -> Parameters -> default[0] -> Value = idStr;

							affectRows = command->ExecuteNonQuery();

							if(affectRows == 0)
							{
								MessageBox::Show("There is no student!");
							}
							else 
							{
								command -> CommandText = gcnew String("DELETE FROM history_students WHERE student_id=:pID ");
								command->ExecuteNonQuery();

								command -> Parameters -> Clear();
								command -> CommandText = gcnew String("INSERT INTO login VALUES (:pID, :pPassword)");

								String^ passwordStr = idStr;

								command -> Parameters -> Add(":pID", OracleType::Char);
								command -> Parameters -> default[0] -> Value = idStr;
								command -> Parameters -> Add(":pPassword", OracleType::Char);
								command -> Parameters -> default[1] -> Value = passwordStr;

								command->ExecuteNonQuery();
								MessageBox::Show("Recover successfully!");
							}

							this -> dataGridView1->Rows->Clear();
							ASInfoHis_Load(sender, e);
						}
					}//end of if
					else
					{
						MessageBox::Show("No history");
					}
			}
};
}
