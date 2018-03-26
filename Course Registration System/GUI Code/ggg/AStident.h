#pragma once
#include "ASInfoHis.h"
#include "Tps.h"
#include "TpsU.h"
namespace ggg {
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::Data::OracleClient;

		public ref class AStident : public System::Windows::Forms::Form
		{
		public:
			AStident(OracleConnection^ myConnection)
			{
				this -> oraConn = myConnection;
				InitializeComponent();
			}

		protected:
			~AStident()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Button^  button7;
		protected: 

		private: System::Windows::Forms::Button^  button6;
		private: System::Windows::Forms::Button^  button2;

		private: System::Windows::Forms::TextBox^  textBox3;
		private: System::Windows::Forms::TextBox^  textBox2;
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::Label^  label6;
		private: System::Windows::Forms::Label^  label5;
		private: System::Windows::Forms::Label^  label4;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::Button^  button4;
		private: System::Windows::Forms::DataGridView^  dataGridView1;

		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Label^  label7;
		private: System::Windows::Forms::Label^  label8;
		private: System::Windows::Forms::TextBox^  textBox5;
		private: System::Windows::Forms::TextBox^  textBox6;

		private:
			System::ComponentModel::Container ^components;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  SID;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  StudentName;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Dept;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Address;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Birthdate;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Gender;

#pragma region Windows Form Designer generated code
		static OracleConnection^ oraConn;	
		static int NOfRows;

		private: System::Windows::Forms::RadioButton^  radioButton1;
		private: System::Windows::Forms::RadioButton^  radioButton2;
		private: System::Windows::Forms::Panel^  panel1;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AStident::typeid));
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->SID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StudentName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Dept = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Address = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Birthdate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Gender = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(771, 615);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(196, 30);
			this->button7->TabIndex = 59;
			this->button7->Text = L"View history";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AStident::showHisS);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(20, 614);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(90, 30);
			this->button6->TabIndex = 57;
			this->button6->Text = L"<<   Back";
			this->button6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AStident::back);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(771, 457);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(196, 113);
			this->button2->TabIndex = 46;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AStident::addS);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox3->Location = System::Drawing::Point(404, 482);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(130, 21);
			this->textBox3->TabIndex = 44;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox2->Location = System::Drawing::Point(209, 482);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(161, 21);
			this->textBox2->TabIndex = 43;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox1->Location = System::Drawing::Point(22, 482);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(142, 21);
			this->textBox1->TabIndex = 42;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(205, 515);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(77, 22);
			this->label6->TabIndex = 41;
			this->label6->Text = L"Address";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(18, 457);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 22);
			this->label5->TabIndex = 40;
			this->label5->Text = L"StudentID";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(205, 457);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(124, 22);
			this->label4->TabIndex = 39;
			this->label4->Text = L"Student Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(18, 515);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 22);
			this->label2->TabIndex = 38;
			this->label2->Text = L"Department";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(17, 413);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(180, 28);
			this->label1->TabIndex = 37;
			this->label1->Text = L"Student Adding";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(837, 255);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 140);
			this->button1->TabIndex = 36;
			this->button1->Text = L"Top Students";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AStident::showTop);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(837, 65);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(130, 140);
			this->button4->TabIndex = 35;
			this->button4->Text = L"Delete";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AStident::deleteS);
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
				this->Dept, this->Address, this->Birthdate, this->Gender});
			this->dataGridView1->Location = System::Drawing::Point(20, 65);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(800, 330);
			this->dataGridView1->TabIndex = 34;
			// 
			// SID
			// 
			this->SID->HeaderText = L"SID";
			this->SID->Name = L"SID";
			this->SID->ReadOnly = true;
			this->SID->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->SID->Width = 150;
			// 
			// StudentName
			// 
			this->StudentName->HeaderText = L"StudentName";
			this->StudentName->Name = L"StudentName";
			this->StudentName->ReadOnly = true;
			this->StudentName->Width = 150;
			// 
			// Dept
			// 
			this->Dept->HeaderText = L"Dept";
			this->Dept->Name = L"Dept";
			this->Dept->ReadOnly = true;
			this->Dept->Width = 50;
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
			this->Birthdate->Width = 149;
			// 
			// Gender
			// 
			this->Gender->HeaderText = L"Gender";
			this->Gender->Name = L"Gender";
			this->Gender->ReadOnly = true;
			this->Gender->Width = 57;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(324, 8);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(315, 37);
			this->label3->TabIndex = 33;
			this->label3->Text = L"Student Information";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(400, 457);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(86, 22);
			this->label7->TabIndex = 60;
			this->label7->Text = L"Birthdate";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(619, 457);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(70, 22);
			this->label8->TabIndex = 61;
			this->label8->Text = L"Gender";
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox5->Location = System::Drawing::Point(24, 549);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(140, 21);
			this->textBox5->TabIndex = 62;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox6->Location = System::Drawing::Point(209, 549);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(480, 21);
			this->textBox6->TabIndex = 63;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(23, 0);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(60, 23);
			this->radioButton1->TabIndex = 64;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Male";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(108, 0);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(76, 23);
			this->radioButton2->TabIndex = 65;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Female";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Location = System::Drawing::Point(565, 482);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 41);
			this->panel1->TabIndex = 66;
			// 
			// AStident
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 657);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"AStident";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Student Information";
			this->Load += gcnew System::EventHandler(this, &AStident::AStident_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			private: System::Void back(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
					this -> Close();
			}

			private: System::Void AStident_Load(System::Object^  sender, System::EventArgs^  e) 
			{
						if(oraConn -> State == ConnectionState::Open) 
						{
								this -> radioButton1 -> Checked = true;
								int totalRows = 0;

								OracleCommand^ command = oraConn -> CreateCommand();
								command -> CommandText = gcnew String("SELECT * FROM students");

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
								}//end of while

								if(totalRows != 0)
								{
										this -> dataGridView1 -> Rows[0] -> Selected = true;
								}

								NOfRows = totalRows;
								myReader -> Close();
								this -> textBox1 -> Text = "";
								this -> textBox2 -> Text = "";
								this -> textBox3 -> Text = "";
								this -> textBox5 -> Text = "";
								this -> textBox6 -> Text = "";
						}//end of if
			}

			private: System::Void showTop(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
					 TpsU^ tpsu = gcnew TpsU(oraConn);
					 tpsu -> Show();
			}

			private: System::Void addS(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
						if(oraConn -> State == ConnectionState::Open) 
						{
									this -> radioButton1 -> Checked = true;
									String^ idStr = this -> textBox1 -> Text;
									String^ nameStr = this -> textBox2 ->Text;
									String^ deptStr = this -> textBox5 -> Text;
									String^ addrStr = this -> textBox6 -> Text;
									String^ birthStr = this -> textBox3 -> Text;
									String^ genderStr = (this -> radioButton1 -> Checked == true)? "MALE" : "FEMALE";

									if(idStr != "" && nameStr != "" && deptStr != "" && addrStr != "" && birthStr != "" )
									{
											int affectRows = 0;
											OracleCommand^ command = oraConn -> CreateCommand();
											command -> CommandText = gcnew String("SELECT * FROM students WHERE student_id=:pSID");

											command -> Parameters -> Add(":pSID", OracleType::Char);
											command -> Parameters -> default[0] -> Value = idStr;

											OracleDataReader^ myReader = command -> ExecuteReader();

											bool exist = myReader -> Read();

											if(exist)
											{
														MessageBox::Show("Student ID conflicts!");
														this -> textBox1 -> Text = "";
														this -> textBox2 -> Text = "";
														this -> textBox3 -> Text = "";
														this -> textBox5 -> Text = "";
														this -> textBox6 -> Text = "";
											}
											else
											{
													command -> CommandText = gcnew String("INSERT INTO students VALUES (:pID, :pName, :pDept, :pAddr, :pBirth, :pGender)");
													//(STUDENT_ID, STUDENT_NAME, DEPARTMENT, ADDRESS, BIRTHDATE, GENDER)

													command -> Parameters -> Clear();//important
													command -> Parameters -> Add(":pID", OracleType::Char);
													command -> Parameters -> default[0] -> Value = idStr;
													command -> Parameters -> Add(":pName", OracleType::VarChar);
													command -> Parameters -> default[1] -> Value = nameStr;		
													command -> Parameters -> Add(":pDept", OracleType::VarChar);
													command -> Parameters -> default[2] -> Value = deptStr;
													command -> Parameters -> Add(":pAddr", OracleType::VarChar);
													command -> Parameters -> default[3] -> Value = addrStr;
													command -> Parameters -> Add(":pBirth", OracleType::DateTime);
													command -> Parameters -> default[4] -> Value = birthStr;
													command -> Parameters -> Add(":pGender", OracleType::VarChar);
													command -> Parameters -> default[5] -> Value = genderStr;

													affectRows = command->ExecuteNonQuery();
													this -> dataGridView1->Rows->Clear();
													AStident_Load(sender, e);

													command -> Parameters -> Clear();
													command -> CommandText = gcnew String("INSERT INTO login VALUES (:pID, :pPassword)");

													String^ passwordStr =  idStr;

													command -> Parameters -> Add(":pID", OracleType::Char);
													command -> Parameters -> default[0] -> Value = idStr;
													command -> Parameters -> Add(":pPassword", OracleType::Char);
													command -> Parameters ->default[1] -> Value = passwordStr;
													command->ExecuteNonQuery();
											}
									}
									else
									{
											MessageBox::Show("Please fill all the blanks");
									}
								}//end of if
				}
		 
				private: System::Void deleteS(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
				{
					if(oraConn -> State == ConnectionState::Open) 
					{
								int affectRows = 0;
								String^ idStr;

								for(int i = 0; i < NOfRows; i++)
								{
									 if(this -> dataGridView1 -> Rows[i] -> Selected == true)
									  {
										 idStr = Convert::ToString(this->dataGridView1->Rows[i]->Cells[0]->Value);
									  }
								 }


								OracleCommand^ command = oraConn -> CreateCommand();
								command -> CommandText = gcnew String("INSERT INTO history_students SELECT * FROM students WHERE student_id=:pID");
								command -> Parameters -> Add(":pID", OracleType::Char);
								command -> Parameters -> default[0] -> Value = idStr;

								affectRows = command->ExecuteNonQuery();

								if(affectRows == 0)
								{
									MessageBox::Show("There is no student!");
								}
								else 
								{
									command -> CommandText = gcnew String("DELETE FROM students WHERE student_id=:pID");
									affectRows = command->ExecuteNonQuery();

									command -> CommandText = gcnew String("DELETE FROM login WHERE user_name=:pID");
									command->ExecuteNonQuery();

									command -> CommandText = gcnew String("DELETE FROM enrollment WHERE student_id=:pID");
									affectRows = command->ExecuteNonQuery();
									this -> dataGridView1->Rows->Clear();
									AStident_Load(sender, e);
								}
							}//end of if
				 }

				private: System::Void showHisS(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
				{
						ASInfoHis^ Ahis = gcnew ASInfoHis(oraConn);
						Ahis -> Show();
				}
};
}
