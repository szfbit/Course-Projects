#pragma once
#include "gradeInput.h"
namespace ggg {
			using namespace System;
			using namespace System::ComponentModel;
			using namespace System::Collections;
			using namespace System::Windows::Forms;
			using namespace System::Data;
			using namespace System::Drawing;
			using namespace System::Data::OracleClient;

			public ref class gradeWarning : public System::Windows::Forms::Form
			{
			public:
				gradeWarning(OracleConnection^ myConnection, String^ account, String^ cid)
				{
					this -> oraConn = myConnection;
					this -> account = account;
					this -> cid = cid;
					InitializeComponent();
				}

			protected:
				~gradeWarning()
				{
					if (components)
					{
						delete components;
					}
				}
			private: System::Windows::Forms::Label^  label1;
			private: System::Windows::Forms::Label^  label2;
			private: System::Windows::Forms::CheckBox^  checkBox1;
			private: System::Windows::Forms::Button^  button1;


			private: System::ComponentModel::IContainer^  components;
			protected: 

			private:

#pragma region Windows Form Designer generated code
		static OracleConnection^ oraConn;	
		static String^ account;
		static String^ cid;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(gradeWarning::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(214, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Warning";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Transparent;
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label2->Location = System::Drawing::Point(28, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(510, 171);
			this->label2->TabIndex = 1;
			this->label2->Text = resources->GetString(L"label2.Text");
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkBox1->ForeColor = System::Drawing::Color::Transparent;
			this->checkBox1->Location = System::Drawing::Point(32, 271);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(444, 23);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"I have read the things below and I promise my grade is true.";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckStateChanged += gcnew System::EventHandler(this, &gradeWarning::showButton);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(423, 308);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 30);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Continue   >>";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &gradeWarning::openInput);
			// 
			// gradeWarning
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(550, 350);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"gradeWarning";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"gradeWarning";
			this->Load += gcnew System::EventHandler(this, &gradeWarning::gradeWarning_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

			private: System::Void gradeWarning_Load(System::Object^  sender, System::EventArgs^  e) 
			{
					this -> button1 -> Hide();
			}

			private: System::Void showButton(System::Object^  sender, System::EventArgs^  e) 
			{
					 if(this -> checkBox1 -> Checked == true)
					 {
						 this -> button1 -> Show();
					 }
					 else
					 {
						 this -> button1 -> Hide();
					 }
			}

			private: System::Void openInput(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
					 gradeInput^ inp = gcnew gradeInput(oraConn, account, cid);
					 inp -> Show();
					 this->Hide();
			}
};
}
