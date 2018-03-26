#pragma once
namespace ggg {
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::Data::OracleClient;

		public ref class modDept : public System::Windows::Forms::Form
		{
		public:
			modDept(OracleConnection^ myConnection, String^ account)
			{
				this -> oraConn = myConnection;
				this -> account = account;
				InitializeComponent();
			}

		protected:
			~modDept()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::Button^  button1;
		protected: 

		private:
			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		static String^ account;
		static OracleConnection^ oraConn;	

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(modDept::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(156, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Input new address";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(12, 46);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(444, 24);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(196, 87);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &modDept::modifyAdd);
			// 
			// modDept
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(468, 122);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"modDept";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Modify Address";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		private: System::Void modifyAdd(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
				 if(oraConn -> State == ConnectionState::Open) 
				 {
						String^ newAdd = this -> textBox1 -> Text;
						int affectRows = 0;
						OracleCommand^ command = oraConn->CreateCommand();

						command -> CommandText = gcnew String("UPDATE students SET address=:pAddr WHERE STUDENT_ID=:pSID");
						command -> Parameters -> Add(":pAddr", OracleType::VarChar);
						command -> Parameters -> default[0] -> Value = newAdd;
						command -> Parameters -> Add(":pSID", OracleType::Char);
						command -> Parameters -> default[1] -> Value = account;		

						affectRows = command->ExecuteNonQuery();
						MessageBox::Show("Modify address successfully!");
						this -> Close();
					}//end of if 
			}
	};
}
