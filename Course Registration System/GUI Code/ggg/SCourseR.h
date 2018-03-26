#pragma once
#include "SAllC.h"
#include "gradeWarning.h"
namespace ggg {
			using namespace System;
			using namespace System::ComponentModel;
			using namespace System::Collections;
			using namespace System::Windows::Forms;
			using namespace System::Data;
			using namespace System::Drawing;
			using namespace System::Data::OracleClient;

			public ref class SCourseR : public System::Windows::Forms::Form
			{
			public:
				SCourseR(OracleConnection^ myConnection, String^ account)
				{
					this -> oraConn = myConnection;
					this -> account = account;
					InitializeComponent();
				}

			protected:
				~SCourseR()
				{
					if (components)
					{
						delete components;
					}
				}
			private: System::Windows::Forms::Label^  label1;
			protected: 
			private: System::Windows::Forms::Label^  label2;
			private: System::Windows::Forms::Label^  label3;
			private: System::Windows::Forms::DataGridView^  dataGridView1;
			private: System::Windows::Forms::DataGridViewTextBoxColumn^  CourseID;
			private: System::Windows::Forms::DataGridViewTextBoxColumn^  CourseName;
			private: System::Windows::Forms::DataGridViewTextBoxColumn^  Lecturer;
			private: System::Windows::Forms::DataGridViewTextBoxColumn^  Section;
			private: System::Windows::Forms::Button^  button1;

			private: System::Windows::Forms::Button^  button3;
			private: System::Windows::Forms::Button^  button4;
			private: System::Windows::Forms::ComboBox^  comboBox1;
			private: System::Windows::Forms::Label^  label4;
			private: System::Windows::Forms::Button^  button5;

			private:
				System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static OracleConnection^ oraConn;	
		static String^ account;
		static int NRows;
		static int nC = 0;
		private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
		private: System::Windows::Forms::Label^  label5;
		private: System::Windows::Forms::Label^  label6;
		public: static int gradeStr;

		void InitializeComponent()
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SCourseR::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->CourseID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CourseName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Lecturer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Section = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 97);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"SID:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(298, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(355, 37);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Register/Drop Courses";
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->CourseID, 
				this->CourseName, this->Lecturer, this->Section});
			this->dataGridView1->Location = System::Drawing::Point(12, 142);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(800, 195);
			this->dataGridView1->TabIndex = 3;
			// 
			// CourseID
			// 
			this->CourseID->HeaderText = L"CourseID";
			this->CourseID->Name = L"CourseID";
			this->CourseID->ReadOnly = true;
			this->CourseID->Width = 200;
			// 
			// CourseName
			// 
			this->CourseName->HeaderText = L"CourseName";
			this->CourseName->Name = L"CourseName";
			this->CourseName->ReadOnly = true;
			this->CourseName->Width = 200;
			// 
			// Lecturer
			// 
			this->Lecturer->HeaderText = L"Lecturer";
			this->Lecturer->Name = L"Lecturer";
			this->Lecturer->ReadOnly = true;
			this->Lecturer->Width = 200;
			// 
			// Section
			// 
			this->Section->HeaderText = L"Section";
			this->Section->Name = L"Section";
			this->Section->ReadOnly = true;
			this->Section->Width = 157;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 467);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 30);
			this->button1->TabIndex = 4;
			this->button1->Text = L"<<   Back";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SCourseR::close);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(832, 24);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(130, 50);
			this->button3->TabIndex = 6;
			this->button3->Text = L"All courses >>";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SCourseR::callAll);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(832, 142);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(130, 195);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Drop";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SCourseR::dropC);
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(12, 395);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(800, 20);
			this->comboBox1->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cambria", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 357);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(144, 23);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Select a course";
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(832, 390);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(130, 25);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Register";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SCourseR::registerC);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CalendarFont = (gcnew System::Drawing::Font(L"Cambria", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Enabled = false;
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(12, 12);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 21);
			this->dateTimePicker1->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Cambria", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(83, 74);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(21, 23);
			this->label5->TabIndex = 12;
			this->label5->Text = L"n";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Cambria", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(62, 97);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(19, 23);
			this->label6->TabIndex = 13;
			this->label6->Text = L"s";
			// 
			// SCourseR
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 512);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"SCourseR";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Register/Drop Courses";
			this->Load += gcnew System::EventHandler(this, &SCourseR::SCourseR_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void close(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				this -> Close();
		}

		private: System::Void callAll(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				SAllC^ all = gcnew SAllC(this -> oraConn);
				all ->Show();
		}

		private: System::Void SCourseR_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			if(oraConn -> State == ConnectionState::Open) 
			{
						OracleCommand^ command = oraConn -> CreateCommand();
						String^ student_name;
						command -> CommandText = gcnew String("SELECT student_name FROM students WHERE student_id=:pSID");

						command -> Parameters -> Add(":pSID", OracleType::Char);
						command -> Parameters -> default[0] -> Value = account;

						OracleDataReader^ myReader = command -> ExecuteReader();

						while(myReader -> Read()) 
						{
								student_name = myReader -> GetString(0);		
						}

						this -> label5 -> Text = student_name;
						this -> label6 -> Text = account;
						myReader -> Close();
			}//end of if 

			if(oraConn -> State == ConnectionState::Open) 
			{
						int totalRows = 0;
						OracleCommand^ command = oraConn -> CreateCommand();
						command -> CommandText = gcnew String("SELECT * FROM courses WHERE course_id in (SELECT course_id FROM enrollment WHERE student_id=:pSID)");

						command -> Parameters -> Add("pSID", OracleType::Char);
						command -> Parameters -> default[0] -> Value = account;

						OracleDataReader^ myReader = command -> ExecuteReader();

						while(myReader -> Read()) 
						{
								String^ course_id = myReader -> GetString(0);
								String^ course_title = myReader -> GetString(1);
								String^ staff_name = myReader -> GetString(2);
								String^ section = myReader -> GetString(3);

								this->dataGridView1->Rows->Add();
								this->dataGridView1->Rows[totalRows]->Cells[0]->Value = course_id;
								this->dataGridView1->Rows[totalRows]->Cells[1]->Value = course_title;
								this->dataGridView1->Rows[totalRows]->Cells[2]->Value = staff_name;
								this->dataGridView1->Rows[totalRows]->Cells[3]->Value = section;
								totalRows++;
						}

						NRows = totalRows;
						command -> Parameters -> Clear();
						myReader -> Close();
			}	//end of if

			if(oraConn -> State == ConnectionState::Open) 
			{
					int totalRows = 0;
					OracleCommand^ command = oraConn -> CreateCommand();
					command -> CommandText = gcnew String("SELECT * FROM courses");

					OracleDataReader^ myReader = command -> ExecuteReader();
					comboBox1 -> Items -> Add("---------------Please Select A Course---------------");
					while(myReader -> Read()) 
					{
							String^ course_id = myReader -> GetString(0);
							String^ course_title = myReader -> GetString(1);
							String^ staff_name = myReader -> GetString(2);
							String^ section = myReader -> GetString(3);

							comboBox1 -> Items -> Add(course_id + "      " + course_title + "      " + staff_name + "     " + section);
							totalRows++;
					}

					this -> comboBox1 -> SelectedIndex = 0;
					myReader -> Close();
					command -> Parameters -> Clear();
			}//end of if
		 }

		private: System::Void dropC(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
			 if(NRows > 0)
			 {
					if(oraConn -> State == ConnectionState::Open) 
					{
							int affectRows = 0;
							String^ courseID;
							OracleCommand^ command = oraConn -> CreateCommand();
							command -> CommandText = gcnew String("DELETE FROM enrollment WHERE student_id=:pSID AND course_id=:pCID");

							command -> Parameters -> Add(":pSID", OracleType::Char);
							command -> Parameters -> default[0] -> Value = account;
					
							for(int i = 0; i < NRows; i++)
							{
								if(this -> dataGridView1 -> Rows[i] -> Selected == true)
								{
									courseID = Convert::ToString(this -> dataGridView1 -> Rows[i] ->Cells[0]->Value);
									command -> Parameters -> Add(":pCID", OracleType::Char);
									command -> Parameters -> default[1] -> Value = courseID;
								}	
							}
							
							affectRows = command->ExecuteNonQuery();

							command -> Parameters -> Clear();
							this -> dataGridView1->Rows->Clear();

							if(oraConn -> State == ConnectionState::Open) 
							{
										int totalRows = 0;
										OracleCommand^ command = oraConn -> CreateCommand();
										command -> CommandText = gcnew String("SELECT * FROM courses WHERE course_id in (SELECT course_id FROM enrollment WHERE student_id=:pSID)");

										command -> Parameters -> Add("pSID", OracleType::Char);
										command -> Parameters -> default[0] -> Value = account;

										OracleDataReader^ myReader = command -> ExecuteReader();


										while(myReader -> Read()) 
										{
													String^ course_id = myReader -> GetString(0);
													String^ course_title = myReader -> GetString(1);
													String^ staff_name = myReader -> GetString(2);
													String^ section = myReader -> GetString(3);

													this->dataGridView1->Rows->Add();
													this->dataGridView1->Rows[totalRows]->Cells[0]->Value = course_id;
													this->dataGridView1->Rows[totalRows]->Cells[1]->Value = course_title;
													this->dataGridView1->Rows[totalRows]->Cells[2]->Value = staff_name;
													this->dataGridView1->Rows[totalRows]->Cells[3]->Value = section;
													totalRows++;
										}

										NRows = totalRows;
										command -> Parameters -> Clear();
										myReader -> Close();
							}	//end of if
						}// end of if
				}//end of if
		 }

		private: System::Void registerC(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				bool valid = false;
				nC = NRows;
				String^ sC = Convert::ToString(this -> comboBox1 -> Text);
				String^ cid = Convert::ToString(sC -> Substring(0, 6));
				OracleCommand^ command = oraConn -> CreateCommand();
				command -> CommandText = gcnew String("SELECT * FROM (SELECT course_id FROM courses WHERE course_id in (SELECT course_id FROM enrollment WHERE student_id=:pSID)) WHERE course_id=:pCID");

				command -> Parameters -> Add(":pSID", OracleType::Char);
				command -> Parameters -> default[0] -> Value = account;
				command -> Parameters -> Add(":pCID", OracleType::Char);
				command -> Parameters -> default[1] -> Value = cid;	

				OracleDataReader^ myReader = command -> ExecuteReader();
				valid = myReader -> Read();

				if(!valid) 
				{
						 String^ dateT = Convert::ToString(dateTimePicker1-> Value);
						 if(!sC-> Equals("---------------Please Select A Course---------------"))
						 {
								nC++;
								if(nC <= 6)
								{
								String ^ dateM = Convert::ToString(dateT -> Substring(0, 10));
					
								gradeStr = Convert::ToInt32(0);
								if(oraConn -> State == ConnectionState::Open) 
								{
								int affectRows = 0;
								OracleCommand^ command = oraConn -> CreateCommand();
								command -> CommandText = gcnew String("INSERT INTO enrollment (STUDENT_ID, COURSE_ID, REG_DATE, GRADE) VALUES (:pSID, :pCID, :pDate, :pGrade)");

								command -> Parameters -> Add(":pSID", OracleType::Char);
								command -> Parameters -> default[0] -> Value = account;
								command -> Parameters -> Add(":pCID", OracleType::Char);
								command -> Parameters -> default[1] -> Value = cid;		
								command -> Parameters -> Add(":pDate", OracleType::DateTime);
								command -> Parameters -> default[2] -> Value = dateM;
								command -> Parameters -> Add(":pGrade", OracleType::Number);
								command -> Parameters -> default[3] -> Value = gradeStr;

								affectRows = command->ExecuteNonQuery();
								command -> Parameters -> Clear();
								this -> dataGridView1->Rows->Clear();

								if(oraConn -> State == ConnectionState::Open) 
								{
									int totalRows = 0;
									OracleCommand^ command = oraConn -> CreateCommand();
									command -> CommandText = gcnew String("SELECT * FROM courses WHERE course_id in (SELECT course_id FROM enrollment WHERE student_id=:pSID)");

									command -> Parameters -> Add("pSID", OracleType::Char);
									command -> Parameters -> default[0] -> Value = account;

									OracleDataReader^ myReader = command -> ExecuteReader();

									while(myReader -> Read()) 
									{
												String^ course_id = myReader -> GetString(0);
												String^ course_title = myReader -> GetString(1);
												String^ staff_name = myReader -> GetString(2);
												String^ section = myReader -> GetString(3);

												this->dataGridView1->Rows->Add();
												this->dataGridView1->Rows[totalRows]->Cells[0]->Value = course_id;
												this->dataGridView1->Rows[totalRows]->Cells[1]->Value = course_title;
												this->dataGridView1->Rows[totalRows]->Cells[2]->Value = staff_name;
												this->dataGridView1->Rows[totalRows]->Cells[3]->Value = section;
												totalRows++;
									}
									NRows = totalRows;
									command -> Parameters -> Clear();
									myReader -> Close();
									gradeWarning^ warn = gcnew gradeWarning(oraConn,account, cid);
									warn -> Show();
								}	//end of if
							}
					}//end of if(cN <=6)
					else
					{
						MessageBox::Show("You can select at most 6 courses!");
					}
			 }//end of if
			 else
			 {
				 MessageBox::Show("Please select a course!");
			 }
		}// end of if 
		else
		{
			MessageBox::Show("You cannot register the same course twice!");
		}
	}
};
}
