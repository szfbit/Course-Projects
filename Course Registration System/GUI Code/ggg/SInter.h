#pragma once
#include "SCourseR.h"
#include "SAllC.h"
#include "SModifyInfo.h"
#include "SshowAllG.h"
#include "SChangePassW.h"
#include "Designer.h"
namespace ggg {
			using namespace System;
			using namespace System::ComponentModel;
			using namespace System::Collections;
			using namespace System::Windows::Forms;
			using namespace System::Data;
			using namespace System::Drawing;
			using namespace System::Data::OracleClient;

			public ref class SInter : public System::Windows::Forms::Form
			{
			public:
				SInter(OracleConnection^ myConnection, String^ account)
				{
					this -> myConnection = myConnection;
					this -> account = account;
					InitializeComponent();
				}

			protected:
				~SInter()
				{
					if (components)
					{
						delete components;
					}
				}

			protected: 

			private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
			private: System::Windows::Forms::Button^  button1;
			private: System::Windows::Forms::Button^  button2;
			private: System::Windows::Forms::Button^  button3;

			private: System::Windows::Forms::Label^  label2;
			private: System::Windows::Forms::Label^  label1;

			private:
				System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static OracleConnection^ myConnection;	
		static String^ account;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Button^  button4;
		private: System::Windows::Forms::Button^  button5;
		private: System::Windows::Forms::Button^  button6;
			 
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SInter::typeid));
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Enabled = false;
			this->dateTimePicker1->Location = System::Drawing::Point(247, 9);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 21);
			this->dateTimePicker1->TabIndex = 2;
			this->dateTimePicker1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(41, 111);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 80);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Register/Drop Course";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SInter::callRegister);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Cambria", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(176, 111);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 80);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Show All Courses";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SInter::callSearch);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Cambria", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(320, 111);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 80);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Modify Information";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SInter::callModify);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(95, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(264, 25);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Please select one function";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Dear";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F));
			this->label3->Location = System::Drawing::Point(64, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 25);
			this->label3->TabIndex = 8;
			this->label3->Text = L"StdName";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Cambria", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(41, 246);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 80);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Show All Grades";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SInter::showMyGrades);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Cambria", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(176, 246);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 80);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Change Password";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SInter::changePassW);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Cambria", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(320, 246);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(100, 80);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Exit";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SInter::close);
			// 
			// SInter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(459, 362);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"SInter";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Student Interface";
			this->Load += gcnew System::EventHandler(this, &SInter::SInter_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void callRegister(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				 SCourseR^ reg = gcnew SCourseR(myConnection, account);	
				 reg -> Show();
		}

		private: System::Void callSearch(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				 SAllC^ search = gcnew SAllC(myConnection);
				 search -> Show();
		}

		private: System::Void callModify(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				 SModifyInfo^ mod = gcnew SModifyInfo(myConnection, account);
				 mod -> Show();
		}

		private: System::Void SInter_Load(System::Object^  sender, System::EventArgs^  e) 
		{
				if(myConnection -> State == ConnectionState::Open) 
				{
							String^ student_name;
							OracleCommand^ command = myConnection -> CreateCommand();
							command -> CommandText = gcnew String("SELECT student_name FROM students WHERE student_id=:pSID");

							command -> Parameters -> Add(":pSID", OracleType::Char);
							command -> Parameters -> default[0] -> Value = account;

							OracleDataReader^ myReader = command -> ExecuteReader();

							while(myReader -> Read()) 
							{
								student_name = myReader -> GetString(0);
							}

							this -> label3 -> Text = student_name;
							myReader -> Close();
				}//end of if
		 }

		private: System::Void close(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				this -> Close();
				Designer^ end = gcnew Designer();
				end -> Show();
				System::Threading::Thread::Sleep(5000);  
				end -> Close();
		}

		private: System::Void showMyGrades(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				SshowAllG^ showAG = gcnew SshowAllG(myConnection, account);
				showAG -> Show();
		}

		private: System::Void changePassW(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				SChangePassW^ changePW = gcnew SChangePassW(myConnection, account);
				changePW -> Show();
		}
};
}
