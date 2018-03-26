#pragma once
#include "ACourse.h"
#include "AStident.h"
#include "Designer.h"
namespace ggg {
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::Data::OracleClient;

		public ref class AInter : public System::Windows::Forms::Form
		{
		public:
			AInter(OracleConnection^ myConnection)
			{
				this -> myConnection = myConnection;
				InitializeComponent();
			}

		protected:
			~AInter()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Button^  button1;

		protected: 

		private:
			System::ComponentModel::Container ^components;
		private: System::Windows::Forms::Button^  button3;

#pragma region Windows Form Designer generated code
		static OracleConnection^ myConnection;	

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AInter::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(134, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(329, 34);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Please select one object";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Enabled = false;
			this->dateTimePicker1->Location = System::Drawing::Point(372, 9);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 21);
			this->dateTimePicker1->TabIndex = 11;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(206, 25);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Dear Administrator";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button2->Location = System::Drawing::Point(225, 113);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 110);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Student";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AInter::callStudent);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->Location = System::Drawing::Point(32, 113);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 110);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Course";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AInter::callCourse);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button3->Location = System::Drawing::Point(422, 113);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(140, 110);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AInter::close);
			// 
			// AInter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(584, 262);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"AInter";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Administrator Interface";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

			private: System::Void callCourse(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
					ACourse^ adCourse = gcnew ACourse(myConnection);
					adCourse -> Show();
			}

			private: System::Void callStudent(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
					AStident^ adStudent = gcnew AStident(myConnection);
					adStudent -> Show();
			}

			private: System::Void close(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
					this -> Close();
					Designer^ end = gcnew Designer();
					end -> Show();
					System::Threading::Thread::Sleep(5000);  
					end -> Close();
			}
};
}
