#pragma once
#include "planner_form.h"
#include "UserManager.h"
#include "Dialog_window.h"

namespace FutureDo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		bool istrue;
		LoginForm(void)
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ login_button;
	protected:

	private: System::Windows::Forms::Label^ text_login;
	protected:


	protected:

	private: System::Windows::Forms::TextBox^ username;
	private: System::Windows::Forms::Label^ text_username;
	private: System::Windows::Forms::Label^ text_password;
	private: System::Windows::Forms::TextBox^ password;
	private: System::Windows::Forms::PageSetupDialog^ pageSetupDialog1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->login_button = (gcnew System::Windows::Forms::Button());
			this->text_login = (gcnew System::Windows::Forms::Label());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->text_username = (gcnew System::Windows::Forms::Label());
			this->text_password = (gcnew System::Windows::Forms::Label());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->pageSetupDialog1 = (gcnew System::Windows::Forms::PageSetupDialog());
			this->SuspendLayout();
			// 
			// login_button
			// 
			this->login_button->Font = (gcnew System::Drawing::Font(L"Elephant", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_button->Location = System::Drawing::Point(77, 363);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(248, 51);
			this->login_button->TabIndex = 0;
			this->login_button->Text = L"Log in";
			this->login_button->UseVisualStyleBackColor = true;
			this->login_button->Click += gcnew System::EventHandler(this, &LoginForm::login_button_Click);
			// 
			// text_login
			// 
			this->text_login->AutoSize = true;
			this->text_login->Font = (gcnew System::Drawing::Font(L"Elephant", 47.99999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_login->Location = System::Drawing::Point(63, 40);
			this->text_login->Name = L"text_login";
			this->text_login->Size = System::Drawing::Size(222, 83);
			this->text_login->TabIndex = 1;
			this->text_login->Text = L"Login";
			// 
			// username
			// 
			this->username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->username->Location = System::Drawing::Point(77, 196);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(330, 40);
			this->username->TabIndex = 2;
			// 
			// text_username
			// 
			this->text_username->AutoSize = true;
			this->text_username->Font = (gcnew System::Drawing::Font(L"Elephant", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_username->Location = System::Drawing::Point(70, 152);
			this->text_username->Name = L"text_username";
			this->text_username->Size = System::Drawing::Size(173, 41);
			this->text_username->TabIndex = 3;
			this->text_username->Text = L"username";
			// 
			// text_password
			// 
			this->text_password->AutoSize = true;
			this->text_password->Font = (gcnew System::Drawing::Font(L"Elephant", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_password->Location = System::Drawing::Point(70, 249);
			this->text_password->Name = L"text_password";
			this->text_password->Size = System::Drawing::Size(166, 41);
			this->text_password->TabIndex = 4;
			this->text_password->Text = L"password";
			// 
			// password
			// 
			this->password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->password->Location = System::Drawing::Point(77, 293);
			this->password->Name = L"password";
			this->password->PasswordChar = '*';
			this->password->Size = System::Drawing::Size(330, 40);
			this->password->TabIndex = 5;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(487, 526);
			this->Controls->Add(this->password);
			this->Controls->Add(this->text_password);
			this->Controls->Add(this->text_username);
			this->Controls->Add(this->username);
			this->Controls->Add(this->text_login);
			this->Controls->Add(this->login_button);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void login_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (username->Text != "" && password->Text != "") {
			if (ManageUser::login_user(this->username->Text, User::HashPassword(this->password->Text))) {
				Dialog_window::Show("Успешно", "Вы успешно вошли в аккаунт!");
				User^ user = gcnew User();
				user->Username = username->Text;
				ManageUser::SetCurrentUser(user);

				istrue = true;
				this->Close();
			}
			else {
				Dialog_window::Show("Ошибка", "Логин или пароль введены неправильно");
				istrue = false;
			}
		}
	}
};
}
