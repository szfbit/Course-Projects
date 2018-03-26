#pragma once
#include "ACInfoHis.h"
#include "Tps.h"
namespace ggg {
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::Data::OracleClient;

		public ref class ACourse : public System::Windows::Forms::Form
		{
		public:
			ACourse(OracleConnection^ myConnection)
			{
				this -> oraConn = myConnection;
				InitializeComponent();
			}

		protected:
			~ACourse()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::DataGridView^  dataGridView1;
		private: System::Windows::Forms::Button^  button4;
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label4;
		private: System::Windows::Forms::Label^  label5;
		private: System::Windows::Forms::Label^  label6;
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::TextBox^  textBox2;
		private: System::Windows::Forms::TextBox^  textBox3;
		private: System::Windows::Forms::TextBox^  textBox4;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Button^  button6;
		private: System::Windows::Forms::Button^  button7;

		protected: 

		private:
			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static OracleConnection^ oraConn;	
		static int NOfRows;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  CourseID;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  CourseTitle;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Lecturer;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Section;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  AverageGrade;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  NumberOfStudent;
			 
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ACourse::typeid));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->CourseID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CourseTitle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Lecturer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Section = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AverageGrade = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NumberOfStudent = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(315, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(303, 37);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Course Information";
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->CourseID, 
				this->CourseTitle, this->Lecturer, this->Section, this->AverageGrade, this->NumberOfStudent});
			this->dataGridView1->Location = System::Drawing::Point(12, 96);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(800, 300);
			this->dataGridView1->TabIndex = 4;
			// 
			// CourseID
			// 
			this->CourseID->HeaderText = L"CourseID";
			this->CourseID->Name = L"CourseID";
			this->CourseID->ReadOnly = true;
			this->CourseID->Width = 140;
			// 
			// CourseTitle
			// 
			this->CourseTitle->HeaderText = L"CourseTitle";
			this->CourseTitle->Name = L"CourseTitle";
			this->CourseTitle->ReadOnly = true;
			this->CourseTitle->Width = 200;
			// 
			// Lecturer
			// 
			this->Lecturer->HeaderText = L"Lecturer";
			this->Lecturer->Name = L"Lecturer";
			this->Lecturer->ReadOnly = true;
			this->Lecturer->Width = 120;
			// 
			// Section
			// 
			this->Section->HeaderText = L"Section";
			this->Section->Name = L"Section";
			this->Section->ReadOnly = true;
			this->Section->Width = 70;
			// 
			// AverageGrade
			// 
			this->AverageGrade->HeaderText = L"AverageGrade";
			this->AverageGrade->Name = L"AverageGrade";
			this->AverageGrade->ReadOnly = true;
			this->AverageGrade->Width = 120;
			// 
			// NumberOfStudent
			// 
			this->NumberOfStudent->HeaderText = L"NumberOfStudent";
			this->NumberOfStudent->Name = L"NumberOfStudent";
			this->NumberOfStudent->ReadOnly = true;
			this->NumberOfStudent->Width = 107;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(832, 96);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(130, 130);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Delete";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ACourse::deleteC);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(832, 266);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 130);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Top Students";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ACourse::showTop);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 415);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(162, 28);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Course Adding";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(484, 458);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 22);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Lecturer";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(225, 458);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(107, 22);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Course Title";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(38, 458);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(86, 22);
			this->label5->TabIndex = 13;
			this->label5->Text = L"CourseID";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(664, 458);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 22);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Section";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox1->Location = System::Drawing::Point(42, 483);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(130, 21);
			this->textBox1->TabIndex = 15;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox2->Location = System::Drawing::Point(229, 483);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(200, 21);
			this->textBox2->TabIndex = 16;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox3->Location = System::Drawing::Point(488, 483);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(130, 21);
			this->textBox3->TabIndex = 17;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox4->Location = System::Drawing::Point(668, 483);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 21);
			this->textBox4->TabIndex = 18;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(807, 458);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(155, 46);
			this->button2->TabIndex = 19;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ACourse::addC);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(14, 567);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(90, 30);
			this->button6->TabIndex = 30;
			this->button6->Text = L"<<   Back";
			this->button6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ACourse::backToInter);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(807, 567);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(155, 30);
			this->button7->TabIndex = 32;
			this->button7->Text = L"View history";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ACourse::callhistory);
			// 
			// ACourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 612);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox4);
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
			this->Name = L"ACourse";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Course Information";
			this->Load += gcnew System::EventHandler(this, &ACourse::ACourse_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			private: System::Void backToInter(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
					this -> Close();
			}

			private: System::Void callhistory(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
					ACInfoHis^ ACHis = gcnew ACInfoHis(oraConn);
					ACHis -> Show();
			}

			private: System::Void ACourse_Load(System::Object^  sender, System::EventArgs^  e) 
			{
					if(oraConn -> State == ConnectionState::Open) {
						int totalRows = 0;
						OracleCommand^ command = oraConn -> CreateCommand();
						command -> CommandText = gcnew String("SELECT courses.course_id, course_title, staff_name, section, NVL(ROUND(AVG(grade), 2), 0), NVL(count(grade), 0) FROM courses LEFT OUTER JOIN enrollment ON courses.course_id=enrollment.course_id GROUP BY courses.course_id, enrollment.course_id, course_title, staff_name, section");

						OracleDataReader^ myReader = command -> ExecuteReader();
						while(myReader -> Read()) 
						{
							String^ idStr = myReader -> GetString(0);
							String^ titleStr = myReader -> GetString(1);
							String^ staffStr = myReader -> GetString(2);
							String^ sectionStr = myReader -> GetString(3);
							String^ gradeStr = Convert::ToString(myReader -> GetDouble(4));
							String^ numStr = Convert::ToString(myReader -> GetInt32(5));

							this->dataGridView1->Rows->Add();
							this->dataGridView1->Rows[totalRows]->Cells[0]->Value = idStr;
							this->dataGridView1->Rows[totalRows]->Cells[1]->Value = titleStr;
							this->dataGridView1->Rows[totalRows]->Cells[2]->Value = staffStr;
							this->dataGridView1->Rows[totalRows]->Cells[3]->Value = sectionStr;
							this->dataGridView1->Rows[totalRows]->Cells[4]->Value = gradeStr;
							this->dataGridView1->Rows[totalRows]->Cells[5]->Value = numStr;
							totalRows++;
						}
						if(totalRows != 0)
						{
							this -> dataGridView1 -> Rows[0] -> Selected = true;
							NOfRows = totalRows;
						}
						myReader -> Close();
					}//end of if
			}

			private: System::Void showTop(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
						 String^ CID;
						  bool isSelected = false;

						  for(int i = 0; i < NOfRows; i++)
						  {
							  if(this -> dataGridView1 -> Rows[i] -> Selected == true)
							  {
								 isSelected = true;
								 CID = Convert::ToString(this->dataGridView1->Rows[i]->Cells[0]->Value);
							  }
						  }

						 if(isSelected)
						 {
								Tps^ tpst = gcnew Tps(oraConn, CID);
								tpst -> Show();
						 }
						 else
						 {
							 MessageBox::Show("Please select a course!");
						 }
			}

			private: System::Void deleteC(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
						if(oraConn -> State == ConnectionState::Open)
						{
									int affectRows = 0;
									String ^ courseID;

									for(int i = 0; i < NOfRows; i++)
									{
										if(this -> dataGridView1 -> Rows[i] -> Selected == true)
										{
											courseID = Convert::ToString(this -> dataGridView1 -> Rows[i] ->Cells[0]->Value); 
										}
									}

									OracleCommand^ command = oraConn -> CreateCommand();
									command -> CommandText = gcnew String("INSERT INTO history_courses SELECT * FROM courses WHERE course_id=:pID");
									command -> Parameters -> Add(":pID", OracleType::Char);
									command -> Parameters -> default[0] -> Value = courseID;

									affectRows = command->ExecuteNonQuery();

									command -> CommandText = gcnew String("DELETE FROM courses WHERE course_id=:pID");
									affectRows = command->ExecuteNonQuery();

									command -> CommandText = gcnew String("DELETE FROM enrollment WHERE course_id=:pID");
									affectRows = command->ExecuteNonQuery();
									command -> Parameters -> Clear();

									this -> dataGridView1->Rows->Clear();
									ACourse_Load(sender, e);
						}//end of if
				
			}

			private: System::Void addC(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
						if(oraConn -> State == ConnectionState::Open) 
						{
									String^ idStr = this -> textBox1 -> Text;
									String^ titleStr = this -> textBox2 -> Text;
									String^ staffStr = this -> textBox3 -> Text;
									String^ sectionStr = this -> textBox4 -> Text;

									if(idStr != "" && titleStr != "" && staffStr != "" && sectionStr != "")
									{
												int affectRows = 0;
												OracleCommand^ command = oraConn -> CreateCommand();
												command -> CommandText = gcnew String("SELECT * FROM courses WHERE course_id=:pCID");

												command -> Parameters -> Add(":pCID", OracleType::Char);
												command -> Parameters -> default[0] -> Value = idStr;

												OracleDataReader^ myReader = command -> ExecuteReader();

												bool exist = myReader -> Read();
									
												if(exist)
												{
														MessageBox::Show("Course ID conflicts!");
														this -> textBox1 -> Text = "";
														this -> textBox2 -> Text = "";
														this -> textBox3 -> Text = "";
														this -> textBox4 -> Text = "";
												}
												else
												{
														command -> CommandText = gcnew String("INSERT INTO courses (COURSE_ID, COURSE_TITLE, STAFF_NAME, SECTION) VALUES (:pID, :pTitle, :pStaff, :pSection)");
														command -> Parameters -> Clear();
														command -> Parameters -> Add(":pID", OracleType::Char);
														command -> Parameters -> default[0] -> Value = idStr;
														command -> Parameters -> Add(":pTitle", OracleType::VarChar);
														command -> Parameters -> default[1] -> Value = titleStr;		
														command -> Parameters -> Add(":pStaff", OracleType::VarChar);
														command -> Parameters -> default[2] -> Value = staffStr;
														command -> Parameters -> Add(":pSection", OracleType::Char);
														command -> Parameters -> default[3] -> Value = sectionStr;

														affectRows = command->ExecuteNonQuery();
														this -> dataGridView1->Rows->Clear();
														ACourse_Load(sender, e);
												}
									}
									else
									{
										MessageBox::Show("Please fill all the blanks");
									}
									this -> textBox1 -> Text = "";
									this -> textBox2 -> Text = "";
									this -> textBox3 -> Text = "";
									this -> textBox4 -> Text = "";
						}//end of if
			}
};
}
