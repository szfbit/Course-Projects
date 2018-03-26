#pragma once
namespace ggg {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OracleClient;

	public ref class SshowAllG : public System::Windows::Forms::Form
	{
	public:
		SshowAllG(OracleConnection^ myConnection, String^ account)
		{
			this -> oraConn = myConnection;
			this -> account = account;
			InitializeComponent();
		}

	protected:
		~SshowAllG()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	protected: 

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static OracleConnection^ oraConn;
		static String^ account;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  CourseID;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  CourseName;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Grade;
	
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SshowAllG::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->CourseID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CourseName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Grade = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(69, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(350, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Grades For Registered Courses";
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->CourseID, 
				this->CourseName, this->Grade});
			this->dataGridView1->Location = System::Drawing::Point(12, 70);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->Size = System::Drawing::Size(450, 390);
			this->dataGridView1->TabIndex = 1;
			// 
			// CourseID
			// 
			this->CourseID->HeaderText = L"CourseID";
			this->CourseID->Name = L"CourseID";
			this->CourseID->ReadOnly = true;
			this->CourseID->Width = 110;
			// 
			// CourseName
			// 
			this->CourseName->HeaderText = L"CourseName";
			this->CourseName->Name = L"CourseName";
			this->CourseName->ReadOnly = true;
			this->CourseName->Width = 180;
			// 
			// Grade
			// 
			this->Grade->HeaderText = L"Grade";
			this->Grade->Name = L"Grade";
			this->Grade->ReadOnly = true;
			this->Grade->Width = 116;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 480);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 30);
			this->button1->TabIndex = 2;
			this->button1->Text = L"<<  Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SshowAllG::close);
			// 
			// SshowAllG
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(476, 522);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"SshowAllG";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Show All Grades";
			this->Load += gcnew System::EventHandler(this, &SshowAllG::SshowAllG_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void close(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				this -> Close();
		}

		private: System::Void SshowAllG_Load(System::Object^  sender, System::EventArgs^  e) 
		{
				if(oraConn -> State == ConnectionState::Open) 
				{
					int totalRows=0;
					OracleCommand^ command = oraConn -> CreateCommand();
					command -> CommandText = gcnew String("SELECT course_id, course_title, grade FROM courses NATURAL JOIN (SELECT course_id, grade FROM enrollment WHERE student_id=:pSID)");

					command -> Parameters -> Add(":pSID", OracleType::Char);
					command -> Parameters -> default[0] -> Value = account;

					OracleDataReader^ myReader = command -> ExecuteReader();

					while(myReader -> Read()) 
					{
						String^ course_id = myReader -> GetString(0);
						String^ course_title = myReader -> GetString(1);
						String^ grade = Convert::ToString(myReader -> GetInt32(2));

						this->dataGridView1->Rows->Add();
						this->dataGridView1->Rows[totalRows]->Cells[0]->Value = course_id;
						this->dataGridView1->Rows[totalRows]->Cells[1]->Value = course_title;
						this->dataGridView1->Rows[totalRows]->Cells[2]->Value = grade;
						totalRows++;
					}

					myReader -> Close();
			}//end of if
		 }
};
}
