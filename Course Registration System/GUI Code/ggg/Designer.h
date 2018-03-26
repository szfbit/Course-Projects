#pragma once

namespace ggg {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Designer : public System::Windows::Forms::Form
	{
	public:
		Designer(void)
		{
			InitializeComponent();
		}

	protected:
		~Designer()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 








	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Designer::typeid));
			this->SuspendLayout();
			// 
			// Designer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(449, 262);
			this->ControlBox = false;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Designer";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Designer";
			this->Load += gcnew System::EventHandler(this, &Designer::Designer_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void Designer_Load(System::Object^  sender, System::EventArgs^  e) 
		{			
		}
};
}
