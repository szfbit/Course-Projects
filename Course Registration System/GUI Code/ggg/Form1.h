#pragma once
#include "Form2.h"
#include "AInter.h"
#include "SInter.h"
namespace ggg {
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::Data::OracleClient;

		public ref class Form1 : public System::Windows::Forms::Form
		{
		public:
			Form1(void)
			{
				InitializeComponent();
			}
		protected:
			~Form1()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label3;

		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::TextBox^  textBox2;
		private: System::Windows::Forms::CheckBox^  checkBox1;

		protected: 

		private:
			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static String^ account;
		static String^ password;
		static OracleConnection^ myConnection;	
		private: System::Windows::Forms::Label^  label4;
		private: System::Windows::Forms::PictureBox^  pictureBox1;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SteelBlue;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(68, 207);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 40);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Log in";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SteelBlue;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(230, 207);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 40);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::close);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(132, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 34);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Welcome";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(64, 94);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 23);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Account";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(64, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 23);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Password";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Info;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(175, 91);
			this->textBox1->MaxLength = 8;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(160, 26);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Info;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(175, 135);
			this->textBox2->MaxLength = 8;
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(160, 26);
			this->textBox2->TabIndex = 1;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::Transparent;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(175, 167);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(137, 23);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"show password";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckStateChanged += gcnew System::EventHandler(this, &Form1::showpassword);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 9);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(50, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cambria", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(310, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 14);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Version: Beta 1.1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(405, 263);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Log in - Course Registration System";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//for clicking connect button
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		{	
					account = this->textBox1->Text;
					password = this->textBox2->Text;
					if(!(account -> Equals("")) &&!(password -> Equals("")))
					{
								//this->Hide();
		
								Form2^ connectingBox = gcnew Form2();
								connectingBox->Show();

								try 
								{	
										String^ ConnectionString;
										ConnectionString = gcnew String("Data Source=ora11g;User ID= C52640166;Password= 52640166;Unicode=True");
										myConnection = gcnew OracleConnection(ConnectionString);
										myConnection -> Open();
										connectingBox -> Close();
								}//end of try
								catch (Exception^ ex) 
								{
										MessageBox::Show("Connecting failed");
										this-> Close();
								}

								if(myConnection -> State == ConnectionState::Open) 
								{
										OracleCommand^ command = myConnection -> CreateCommand();
										command -> CommandText = gcnew String("SELECT password FROM login WHERE user_name=:pName");

										command -> Parameters -> Add(":pName", OracleType::Char);
										command -> Parameters -> default[0] -> Value = account;

										OracleDataReader^ myReader = command -> ExecuteReader();

										/**
										* Check whether the user name is valid
										 */
										bool flag = myReader->Read();

										if(flag == false) 
										{
												myReader -> Close();
												MessageBox::Show("User Name Not Found!");
												this -> textBox1 -> Text = "";
												this -> textBox2 -> Text = "";
												return;
										}

										String^ testPassW = myReader -> GetString(0) -> Trim();
										/**
										 * Check whether the password is correct
										 */
										while(!(testPassW -> Equals(password))) 
										{
												MessageBox::Show("Password Incorrect!");
												this -> textBox1 -> Text = "";
												this -> textBox2 -> Text = "";
												return;
										}
	
										myReader -> Close();

										char role = (account -> Equals("admin"))? 'a':'s';
										MessageBox::Show("Connecting successfully!");
										if(role == 'a')
										{
												AInter^ aOpen = gcnew AInter(myConnection);
												aOpen -> Show();
										}
										else
										{
												SInter^ sOpen = gcnew SInter(myConnection, account);
												sOpen -> Show();
										}
								}//end of if
						}//end of if
						else
						{
							MessageBox::Show("Please input your acocunt and password again!");
						}
				}

				static bool isS = false;
				//for selection box
				private: System::Void showpassword(System::Object^  sender, System::EventArgs^  e) 
				{ 
					if(!isS)
					{
						this->textBox2->PasswordChar = isS;
					}
					else
					{
						this->textBox2->PasswordChar = '*';
					}
					isS = !isS;
				}

			private: System::Void close(System::Object^  sender, System::EventArgs^  e) 
			{
					this -> Close();
			}
};


}