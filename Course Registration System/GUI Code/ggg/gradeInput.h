#pragma once
namespace ggg {
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::Data::OracleClient;

		public ref class gradeInput : public System::Windows::Forms::Form
		{
		public:
			gradeInput(OracleConnection^ myConnection, String^ account, String^ cid)
			{
				this -> oraConn = myConnection;
				this -> account = account;
				this -> cid = cid;
				InitializeComponent();
			}

		protected:
			~gradeInput()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^  label1;
		protected: 
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Button^  button1;

		private:
			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static OracleConnection^ oraConn;	
		static String^ account;
		static String^ cid;
		static String^ gradeS;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(gradeInput::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(52, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(185, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Please input your grade";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(56, 59);
			this->textBox1->MaxLength = 3;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(170, 24);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(110, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"(0~100)";
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(104, 95);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 25);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Confirm";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &gradeInput::submitG);
			// 
			// gradeInput
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(284, 132);
			this->ControlBox = false;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"gradeInput";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Input Grade";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			private: System::Void submitG(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
				bool isD = true;
				for(int i = 0; i < (this -> textBox1 -> Text -> Length); i++)
				{
					if(!Char::IsDigit(this -> textBox1 -> Text[i]))
					{
						isD = false;
					}
				}
				
				if(this -> textBox1 -> Text != "" && isD)
				{
					gradeS = Convert::ToString(this -> textBox1 -> Text);
					int gradeT = Convert::ToInt32(this -> textBox1 -> Text);

					if(gradeT >= 0 && gradeT <= 100)
					{
						if(oraConn -> State == ConnectionState::Open) 
						{
									int affectRows = 0;
									OracleCommand^ command = oraConn->CreateCommand();
									command -> CommandText = gcnew String("UPDATE enrollment SET grade=:pGrade WHERE student_id=:pSID AND course_id=:pCID");

									command -> Parameters -> Add(":pCID", OracleType::Char);
									command -> Parameters -> default[0] -> Value = cid;
									command -> Parameters -> Add(":pSID", OracleType::Char);
									command -> Parameters -> default[1] -> Value = account;
									command -> Parameters -> Add(":pGrade", OracleType::Number);
									command -> Parameters -> default[2] -> Value = gradeS;

									affectRows = command->ExecuteNonQuery();
									MessageBox::Show("Add grade successfully!");
									this -> Close();
						}
						else
						{
							MessageBox::Show("Connection failed!");
						}
					}//end of if 
					else
					{
						MessageBox::Show("Out of range!");
						this -> textBox1 -> Text = "";
					}
			 }
			else
			{
				MessageBox::Show("Please input the correct grade!");
				this -> textBox1 -> Text = "";
			}
		}

};
}
