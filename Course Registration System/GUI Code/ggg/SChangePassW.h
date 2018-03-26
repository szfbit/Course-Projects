#pragma once
namespace ggg {
			using namespace System;
			using namespace System::ComponentModel;
			using namespace System::Collections;
			using namespace System::Windows::Forms;
			using namespace System::Data;
			using namespace System::Drawing;
			using namespace System::Data::OracleClient;

			public ref class SChangePassW : public System::Windows::Forms::Form
			{
			public:
				SChangePassW(OracleConnection^ myConnection, String^ account)
				{
					this -> oraConn = myConnection;
					this -> account = account;
					InitializeComponent();
				}

			protected:
				~SChangePassW()
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
			private: System::Windows::Forms::TextBox^  textBox1;
			private: System::Windows::Forms::TextBox^  textBox2;
			private: System::Windows::Forms::Button^  button1;

			private:
				System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static OracleConnection^ oraConn;
		static String^ account;
		private: System::Windows::Forms::CheckBox^  checkBox1;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SChangePassW::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(84, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(200, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Modify Password";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(56, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(232, 22);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Please input new password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(56, 140);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(269, 22);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Please input the password again";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(60, 92);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(228, 24);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(60, 181);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(228, 24);
			this->textBox2->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(128, 283);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 35);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Confirm";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SChangePassW::changePassW);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::Transparent;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(103, 225);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(137, 23);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"show password";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckStateChanged += gcnew System::EventHandler(this, &SChangePassW::showPW);
			// 
			// SChangePassW
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(354, 330);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"SChangePassW";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Modify Password";
			this->Load += gcnew System::EventHandler(this, &SChangePassW::SChangePassW_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		private: System::Void changePassW(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				if(oraConn -> State == ConnectionState::Open) 
				{
								int affectRows = 0;
								OracleCommand^ command = oraConn -> CreateCommand();
								command -> CommandText = gcnew String("UPDATE login SET password=:pPassword WHERE user_name=:pSID");

								String^ passwordStr = this -> textBox1 -> Text;
								String^ passwordStr2 = this -> textBox2 -> Text;
								
								if(!(passwordStr -> Equals(passwordStr2)))
								{
									MessageBox::Show("The passwords are not the same. \n Please input again!");
									this -> textBox1 -> Text = "";
									this -> textBox2 -> Text = "";
								}
								else
								{
									command -> Parameters -> Add(":pSID", OracleType::Char);
									command -> Parameters -> default[0] -> Value = account;
									command -> Parameters -> Add(":pPassword", OracleType::Char);
									command -> Parameters -> default[1] -> Value = passwordStr;

									affectRows = command->ExecuteNonQuery();
									this -> Close();
									MessageBox::Show("Change password successfully!");
								}
				}//end of if
		}

		static bool isS = false;
		private: System::Void showPW(System::Object^  sender, System::EventArgs^  e) 
		{
				if(!isS)
						{
							this->textBox1->PasswordChar = isS;
							this->textBox2->PasswordChar = isS;
						}
						else
						{
							this->textBox1->PasswordChar = '*';
							this->textBox2->PasswordChar = '*';
						}
						isS = !isS;
		 }

		private: System::Void SChangePassW_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			 		this->textBox1->PasswordChar = '*';
					this->textBox2->PasswordChar = '*';
		}
};
}
