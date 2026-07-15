#pragma once
#include "LoginForm.h"
#include "Register_form.h"
#include "planner_form.h"
#include "UserManager.h"



namespace FutureDo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Menu_window
	/// </summary>
	public ref class Menu_window : public System::Windows::Forms::Form
	{
	public:
		Menu_window(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Menu_window()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ login_button;
	private: System::Windows::Forms::Button^ register_button;

	protected:


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Menu_window::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->login_button = (gcnew System::Windows::Forms::Button());
			this->register_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(111, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(534, 114);
			this->label1->TabIndex = 0;
			this->label1->Text = L"FutureDo";
			// 
			// login_button
			// 
			this->login_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->login_button->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->login_button->Location = System::Drawing::Point(230, 198);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(237, 99);
			this->login_button->TabIndex = 1;
			this->login_button->Text = L"Login";
			this->login_button->UseVisualStyleBackColor = true;
			this->login_button->Click += gcnew System::EventHandler(this, &Menu_window::Start_click);
			// 
			// register_button
			// 
			this->register_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->register_button->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->register_button->Location = System::Drawing::Point(209, 338);
			this->register_button->Name = L"register_button";
			this->register_button->Size = System::Drawing::Size(289, 99);
			this->register_button->TabIndex = 2;
			this->register_button->Text = L"Register";
			this->register_button->UseVisualStyleBackColor = true;
			this->register_button->Click += gcnew System::EventHandler(this, &Menu_window::register_button_Click);
			// 
			// Menu_window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(744, 611);
			this->Controls->Add(this->register_button);
			this->Controls->Add(this->login_button);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Menu_window";
			this->Text = L"FutureDo";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Start_click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		LoginForm^ login = gcnew LoginForm();
		login->ShowDialog();
		Console::WriteLine(login->istrue);
		if (login->istrue == true) {
			planner_form^ planner = gcnew planner_form();

			planner->ShowDialog();
		}
		else {
			this->Show();
		}
	}
	private: System::Void register_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Register_form^ reg = gcnew Register_form();
		reg->ShowDialog();
		this->Show();
	}

};
}
