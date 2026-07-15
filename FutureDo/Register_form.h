#pragma once
#include "UserManager.h"
#include "User.h"
#include "Dialog_window.h"




namespace FutureDo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Register_form
	/// </summary>
	public ref class Register_form : public System::Windows::Forms::Form
	{
	public:
		Register_form(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Register_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ text_register;
	protected:

	private: System::Windows::Forms::Label^ text_username;
	private: System::Windows::Forms::TextBox^ username;
	private: System::Windows::Forms::TextBox^ password;
	private: System::Windows::Forms::Label^ text_password;
	private: System::Windows::Forms::Button^ register_button;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Register_form::typeid));
			this->text_register = (gcnew System::Windows::Forms::Label());
			this->text_username = (gcnew System::Windows::Forms::Label());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->text_password = (gcnew System::Windows::Forms::Label());
			this->register_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// text_register
			// 
			this->text_register->AutoSize = true;
			this->text_register->Font = (gcnew System::Drawing::Font(L"Elephant", 47.99999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_register->Location = System::Drawing::Point(58, 60);
			this->text_register->Name = L"text_register";
			this->text_register->Size = System::Drawing::Size(308, 83);
			this->text_register->TabIndex = 2;
			this->text_register->Text = L"Register";
			// 
			// text_username
			// 
			this->text_username->AutoSize = true;
			this->text_username->Font = (gcnew System::Drawing::Font(L"Elephant", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_username->Location = System::Drawing::Point(65, 155);
			this->text_username->Name = L"text_username";
			this->text_username->Size = System::Drawing::Size(173, 41);
			this->text_username->TabIndex = 4;
			this->text_username->Text = L"username";
			// 
			// username
			// 
			this->username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->username->Location = System::Drawing::Point(72, 199);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(330, 40);
			this->username->TabIndex = 5;
			// 
			// password
			// 
			this->password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->password->Location = System::Drawing::Point(72, 310);
			this->password->Name = L"password";
			this->password->PasswordChar = '*';
			this->password->Size = System::Drawing::Size(330, 40);
			this->password->TabIndex = 8;
			// 
			// text_password
			// 
			this->text_password->AutoSize = true;
			this->text_password->Font = (gcnew System::Drawing::Font(L"Elephant", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_password->Location = System::Drawing::Point(65, 254);
			this->text_password->Name = L"text_password";
			this->text_password->Size = System::Drawing::Size(166, 41);
			this->text_password->TabIndex = 7;
			this->text_password->Text = L"password";
			// 
			// register_button
			// 
			this->register_button->Font = (gcnew System::Drawing::Font(L"Elephant", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->register_button->Location = System::Drawing::Point(72, 374);
			this->register_button->Name = L"register_button";
			this->register_button->Size = System::Drawing::Size(248, 51);
			this->register_button->TabIndex = 6;
			this->register_button->Text = L"Register";
			this->register_button->UseVisualStyleBackColor = true;
			this->register_button->Click += gcnew System::EventHandler(this, &Register_form::register_button_Click);
			// 
			// Register_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(576, 596);
			this->Controls->Add(this->password);
			this->Controls->Add(this->text_password);
			this->Controls->Add(this->register_button);
			this->Controls->Add(this->username);
			this->Controls->Add(this->text_username);
			this->Controls->Add(this->text_register);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Register_form";
			this->Text = L"Register_form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

private: System::Void register_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (username->Text != "" && password->Text != ""){
		if (ManageUser::register_user(this->username->Text, User::HashPassword(this->password->Text)) == true) {
			Dialog_window::Show("Успешно", "Вы были успешно зарегестрированы!");
			this->Close();
		}
		else {
			Dialog_window::Show("Ошибка", "Пользователь с таким логином уже\n существует");
		}
	}
}

};
}
