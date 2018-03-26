#pragma once
namespace ggg {
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::Data::OracleClient;

		public ref class SAllC : public System::Windows::Forms::Form
		{
		public:
			SAllC(OracleConnection^ myConnection)
			{
				 this -> oraConn =  myConnection;
				InitializeComponent();
			}

		protected:
			~SAllC()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::DataGridView^  dataGridView1;
		private: System::Windows::Forms::Button^  button1;
		protected: 

		private:
			System::ComponentModel::Container ^components;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  CourseID;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  CourseName;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Lecturer;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Section;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  AverageGrade;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  NumberOfStudent;

#pragma region Windows Form Designer generated code
		static OracleConnection^ oraConn;	

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SAllC::typeid));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->CourseID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CourseName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Lecturer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Section = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AverageGrade = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NumberOfStudent = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(316, 9);
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
				this->CourseName, this->Lecturer, this->Section, this->AverageGrade, this->NumberOfStudent});
			this->dataGridView1->Location = System::Drawing::Point(12, 63);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->Size = System::Drawing::Size(960, 380);
			this->dataGridView1->TabIndex = 4;
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
			this->Section->Width = 117;
			// 
			// AverageGrade
			// 
			this->AverageGrade->HeaderText = L"AverageGrade";
			this->AverageGrade->Name = L"AverageGrade";
			this->AverageGrade->ReadOnly = true;
			// 
			// NumberOfStudent
			// 
			this->NumberOfStudent->HeaderText = L"NumberOfStudent";
			this->NumberOfStudent->Name = L"NumberOfStudent";
			this->NumberOfStudent->ReadOnly = true;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 470);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 30);
			this->button1->TabIndex = 6;
			this->button1->Text = L"<<   Back";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SAllC::close);
			// 
			// SAllC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 512);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"SAllC";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Course Information";
			this->Load += gcnew System::EventHandler(this, &SAllC::SAllC_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void close(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				this -> Close();
		}

		private: System::Void SAllC_Load(System::Object^  sender, System::EventArgs^  e) 
		{
					if(oraConn -> State == ConnectionState::Open) 
					{
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
						myReader -> Close();
					}//end of if
		}//end of function	 
};
}
