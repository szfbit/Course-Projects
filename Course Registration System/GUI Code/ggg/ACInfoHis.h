#pragma once

namespace ggg {
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::Data::OracleClient;

		public ref class ACInfoHis : public System::Windows::Forms::Form
		{
		public:
			ACInfoHis(OracleConnection^ myConnection)
			{
				this -> oraConn = myConnection;
				InitializeComponent();
			}

		protected:
			~ACInfoHis()
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
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  CourseID;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  CourseName;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Lecturer;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Section;
		private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static OracleConnection^ oraConn;	
		static int NRows;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ACInfoHis::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->CourseID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CourseName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Lecturer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Section = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(831, 255);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 140);
			this->button1->TabIndex = 43;
			this->button1->Text = L"Done";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ACInfoHis::close);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(831, 78);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(130, 140);
			this->button4->TabIndex = 42;
			this->button4->Text = L"Recover";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ACInfoHis::recoverC);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(279, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(420, 37);
			this->label3->TabIndex = 41;
			this->label3->Text = L"Course Information History";
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
			this->dataGridView1->Location = System::Drawing::Point(12, 75);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(795, 320);
			this->dataGridView1->TabIndex = 44;
			// 
			// CourseID
			// 
			this->CourseID->HeaderText = L"CourseID";
			this->CourseID->Name = L"CourseID";
			this->CourseID->ReadOnly = true;
			this->CourseID->Width = 220;
			// 
			// CourseName
			// 
			this->CourseName->HeaderText = L"CourseName";
			this->CourseName->Name = L"CourseName";
			this->CourseName->ReadOnly = true;
			this->CourseName->Width = 230;
			// 
			// Lecturer
			// 
			this->Lecturer->HeaderText = L"Lecturer";
			this->Lecturer->Name = L"Lecturer";
			this->Lecturer->ReadOnly = true;
			this->Lecturer->Width = 180;
			// 
			// Section
			// 
			this->Section->HeaderText = L"Section";
			this->Section->Name = L"Section";
			this->Section->ReadOnly = true;
			this->Section->Width = 120;
			// 
			// ACInfoHis
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
			this->Name = L"ACInfoHis";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Course Information History";
			this->Load += gcnew System::EventHandler(this, &ACInfoHis::ACInfoHis_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void close(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				this -> Close();
		}
		private: System::Void ACInfoHis_Load(System::Object^  sender, System::EventArgs^  e) 
		{
					if(oraConn -> State == ConnectionState::Open) 
					{
						int totalRows = 0;
						OracleCommand^ command = oraConn->CreateCommand();
						command -> CommandText = gcnew String("SELECT * FROM history_courses");

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

						if(totalRows != 0)
						{
							this -> dataGridView1 -> Rows[0] -> Selected = true;
						}

						NRows = totalRows;
						myReader -> Close();
					}//end of if
		}
		private: System::Void recoverC(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
						if(oraConn -> State == ConnectionState::Open) 
						{
							if(NRows != 0)
							{
									int affectRows = 0;
									String^ idStr;

									OracleCommand^ command = oraConn -> CreateCommand();
									command -> CommandText = gcnew String("INSERT INTO courses SELECT * FROM history_courses WHERE course_id=:pID");
									

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
										MessageBox::Show("No course is deleted!");
									}
									else 
									{
										command -> CommandText = gcnew String("DELETE FROM history_courses WHERE course_id=:pID ");
										command->ExecuteNonQuery();
										MessageBox::Show("Recover successfully!");
									}

									this -> dataGridView1->Rows->Clear();
									ACInfoHis_Load(sender, e);
							}
						}//end of if 
						else
						{
							MessageBox::Show("No history");
						}
			}
};
}
