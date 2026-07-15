#pragma once
#include "Timer.h"

namespace FutureDo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ timer_window
	/// </summary>
	public ref class timer_window : public System::Windows::Forms::Form
	{
		static bool Result = false;
	public:
		timer_window(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		static bool Show()
		{
			timer_window^ dialog = gcnew timer_window();
			dialog->ShowDialog();
			return Result;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~timer_window()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_apply;
	protected:
	private: System::Windows::Forms::TextBox^ textBox_new_time;
	private: System::Windows::Forms::Label^ label1;

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
			this->button_apply = (gcnew System::Windows::Forms::Button());
			this->textBox_new_time = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button_apply
			// 
			this->button_apply->Font = (gcnew System::Drawing::Font(L"Elephant", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_apply->Location = System::Drawing::Point(137, 203);
			this->button_apply->Name = L"button_apply";
			this->button_apply->Size = System::Drawing::Size(112, 45);
			this->button_apply->TabIndex = 0;
			this->button_apply->Text = L"apply";
			this->button_apply->UseVisualStyleBackColor = true;
			this->button_apply->Click += gcnew System::EventHandler(this, &timer_window::button_apply_Click);
			// 
			// textBox_new_time
			// 
			this->textBox_new_time->Font = (gcnew System::Drawing::Font(L"Elephant", 47.99999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_new_time->Location = System::Drawing::Point(63, 84);
			this->textBox_new_time->Name = L"textBox_new_time";
			this->textBox_new_time->Size = System::Drawing::Size(258, 90);
			this->textBox_new_time->TabIndex = 1;
			this->textBox_new_time->Text = Timer_pomodoro::Get_seconds().ToString();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(14, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(379, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"введите врем€ таймера (в секундах)";
			// 
			// timer_window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(405, 260);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox_new_time);
			this->Controls->Add(this->button_apply);
			this->Name = L"timer_window";
			this->Text = L"timer_window";
			this->ResumeLayout(false);
			this->PerformLayout();

			this->FormClosing += gcnew FormClosingEventHandler(this, &timer_window::timer_window_FormClosing);
		}
#pragma endregion
	private: System::Void button_apply_Click(System::Object^ sender, System::EventArgs^ e) {
		Timer_pomodoro::Set_timer(System::Int32::Parse(textBox_new_time->Text));
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		Result = true;
	}
	private: void timer_window_FormClosing(Object^ sender, FormClosingEventArgs^ e)
	{
		if (e->CloseReason == CloseReason::UserClosing)
		{
			Result = false;
		}
	}
	};
}
