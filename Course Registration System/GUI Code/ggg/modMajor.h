#pragma once
namespace ggg {
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::Data::OracleClient;

		public ref class modMajor : public System::Windows::Forms::Form
		{
		public:
			modMajor(OracleConnection^ myConnection, String^ account)
			{
				this -> oraConn = myConnection;
				this -> account = account;
				InitializeComponent();
			}

		protected:
			~modMajor()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^  label1;
		protected: 
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::Button^  button1;

		private:
			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static String^ account;
		static OracleConnection^ oraConn;	

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(modMajor::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(22, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(179, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Input new Department";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(26, 53);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(162, 24);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(67, 92);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &modMajor::modifyDpt);
			// 
			// modMajor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(204, 127);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"modMajor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Modify Dept";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void modifyDpt(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				 String^ newDept = this -> textBox1 -> Text;
				if(oraConn -> State == ConnectionState::Open) 
				{
					int affectRows = 0;
					OracleCommand^ command = oraConn->CreateCommand();
					command -> CommandText = gcnew String("UPDATE students SET department=:pDept WHERE STUDENT_ID=:pSID");

					command -> Parameters -> Add(":pDept", OracleType::VarChar);
					command -> Parameters -> default[0] -> Value = newDept;
					command -> Parameters -> Add(":pSID", OracleType::Char);
					command -> Parameters -> default[1] -> Value = account;

					affectRows = command->ExecuteNonQuery();
					MessageBox::Show("Modify department successfully!");
					this -> Close();
				}//end of if
			 }
	};
}
