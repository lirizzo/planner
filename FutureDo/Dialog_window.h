#pragma once

namespace FutureDo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Dialog_window
	/// </summary>
	public ref class Dialog_window : public System::Windows::Forms::Form
	{
	public:
		Dialog_window(String^ title, String^message)
		{
			InitializeComponent();
			this->Text = title;
			label1->Text = message;
			//
			//TODO: добавьте код конструктора
			//
		}
		static bool Show(String^ title, String^ message)
		{
			Dialog_window^ dialog = gcnew Dialog_window(title, message);
			return dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Dialog_window()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(23, 66);
			this->label1->MaximumSize = System::Drawing::Size(400, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button1->Font = (gcnew System::Drawing::Font(L"Elephant", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(118, 148);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(132, 41);
			this->button1->TabIndex = 1;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// Dialog_window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(376, 201);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Dialog_window";
			this->Text = L"Dialog_window";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		};
}
