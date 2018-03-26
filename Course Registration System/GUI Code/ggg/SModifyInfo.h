#pragma once
#include "modDept.h"
#include "modMajor.h"
namespace ggg {
			using namespace System;
			using namespace System::ComponentModel;
			using namespace System::Collections;
			using namespace System::Windows::Forms;
			using namespace System::Data;
			using namespace System::Drawing;
			using namespace System::Data::OracleClient;

			public ref class SModifyInfo : public System::Windows::Forms::Form
			{
			public:
				SModifyInfo(OracleConnection^ myConnection, String^ account)
				{
					this -> oraConn = myConnection;
					this -> account = account;
					InitializeComponent();
				}

			protected:
				~SModifyInfo()
				{
					if (components)
					{
						delete components;
					}
				}

			private: System::Windows::Forms::Label^  label3;
			private: System::Windows::Forms::Label^  label1;
			private: System::Windows::Forms::Label^  label2;
			private: System::Windows::Forms::Label^  label4;
			private: System::Windows::Forms::Label^  label5;
			private: System::Windows::Forms::Label^  label6;
			private: System::Windows::Forms::Label^  label7;
			private: System::Windows::Forms::Label^  label8;
			private: System::Windows::Forms::Label^  label9;
			private: System::Windows::Forms::Label^  label10;
			private: System::Windows::Forms::Label^  label11;
			private: System::Windows::Forms::Label^  label12;
			private: System::Windows::Forms::Label^  label13;
			private: System::Windows::Forms::Button^  button1;
			private: System::Windows::Forms::Button^  button3;
			private: System::Windows::Forms::Button^  button4;

			protected: 

			private:
				System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static String^ account;
		static OracleConnection^ oraConn;	
		private: System::Windows::Forms::Button^  button2;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SModifyInfo::typeid));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(130, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(248, 28);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Personal Information";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(26, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 22);
			this->label1->TabIndex = 5;
			this->label1->Text = L"SID:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(26, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 22);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Name:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(26, 185);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 22);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Address:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(26, 144);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(113, 22);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Department:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(26, 242);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(91, 22);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Birthdate:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(26, 282);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(75, 22);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Gender:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label8->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(70, 69);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(20, 21);
			this->label8->TabIndex = 11;
			this->label8->Text = L"3";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label9->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label9->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(83, 105);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(20, 21);
			this->label9->TabIndex = 12;
			this->label9->Text = L"4";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label10->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(135, 147);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(20, 21);
			this->label10->TabIndex = 13;
			this->label10->Text = L"5";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label11->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(26, 207);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(20, 21);
			this->label11->TabIndex = 14;
			this->label11->Text = L"2";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label12->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(121, 245);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(20, 21);
			this->label12->TabIndex = 15;
			this->label12->Text = L"1";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label13->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label13->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(99, 285);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(20, 21);
			this->label13->TabIndex = 16;
			this->label13->Text = L"6";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(11, 450);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 30);
			this->button1->TabIndex = 17;
			this->button1->Text = L"<<   Back";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SModifyInfo::close);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(30, 355);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(180, 60);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Modify Department";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SModifyInfo::callModiM);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(293, 355);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(180, 60);
			this->button4->TabIndex = 20;
			this->button4->Text = L"Modify Address";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SModifyInfo::callModiD);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(343, 450);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(130, 26);
			this->button2->TabIndex = 21;
			this->button2->Text = L"Refresh";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SModifyInfo::refresh);
			// 
			// SModifyInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(504, 492);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"SModifyInfo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Student Information";
			this->Load += gcnew System::EventHandler(this, &SModifyInfo::SModifyInfo_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void close(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				 this -> Close();
		}

		private: System::Void callModiM(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				modMajor^ newMajor = gcnew modMajor(oraConn, account);
				newMajor -> Show();
		}

		private: System::Void callModiD(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				 modDept^ newDept = gcnew modDept(oraConn, account);
				 newDept -> Show();
		}

		private: System::Void SModifyInfo_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			 	if(oraConn -> State == ConnectionState::Open) 
				{
							OracleCommand^ command = oraConn -> CreateCommand();
							command -> CommandText = gcnew String("SELECT * FROM students WHERE student_id=:pSID");

							command -> Parameters -> Add(":pSID", OracleType::Char);
							command -> Parameters -> default[0] -> Value = account;

							OracleDataReader^ myReader = command -> ExecuteReader();

							while(myReader -> Read()) 
							{
								String^ student_id = myReader -> GetString(0);
								String^ student_name = myReader -> GetString(1);
								String^ department = myReader -> GetString(2);
								String^ address = myReader -> GetString(3);
								String^ birthdate = Convert::ToString(myReader -> GetDateTime(4));
								String^ gender = myReader -> GetString(5);			

								this -> label8 -> Text = student_id;
								this -> label9 -> Text = student_name;
								this -> label10 -> Text = department;
								this -> label11 -> Text = address;
								this -> label12 -> Text = birthdate -> Substring(0, 10);
								this -> label13 -> Text = gender;
							}//end of while
			}//end of if
		 }

		private: System::Void refresh(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
			 SModifyInfo_Load(sender, e);
		}
};
}
