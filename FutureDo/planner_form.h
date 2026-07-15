#pragma once
#include "Task.h"
#include "Timer.h"
#include "Dialog_window.h"
#include "timer_window.h"

namespace FutureDo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для planner_form
	/// </summary>
	public ref class planner_form : public System::Windows::Forms::Form
	{
	public:
		planner_form(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		static void setPomodoroTime(int Time) {
			Timer_pomodoro::Set_timer(Time);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~planner_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MonthCalendar^ monthCalendar1;
	private: System::Windows::Forms::ProgressBar^ progressBar_tasks;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckedListBox^ ListBox_tasks;
	private: System::Windows::Forms::Label^ text_data;
	private: System::Windows::Forms::CheckedListBox^ ListBox_habbits;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ add_task_button;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ add_task_textBox;
	private: System::Windows::Forms::Timer^ timer_pomodoro;
	private: System::Windows::Forms::Label^ Time_text;

	private: System::Windows::Forms::Button^ button_timer;
	private: System::Windows::Forms::Label^ label5;

	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::TextBox^ textBox_habbit;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ addHabbit;

	private: System::Windows::Forms::Button^ button_reset;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Button^ button_delete_task;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button_edit_timer;



	protected:

	private:
		int remainingSeconds = Timer_pomodoro::Get_seconds();
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
	
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(planner_form::typeid));
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->progressBar_tasks = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ListBox_tasks = (gcnew System::Windows::Forms::CheckedListBox());
			this->text_data = (gcnew System::Windows::Forms::Label());
			this->ListBox_habbits = (gcnew System::Windows::Forms::CheckedListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->add_task_button = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->add_task_textBox = (gcnew System::Windows::Forms::TextBox());
			this->timer_pomodoro = (gcnew System::Windows::Forms::Timer(this->components));
			this->Time_text = (gcnew System::Windows::Forms::Label());
			this->button_timer = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox_habbit = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->addHabbit = (gcnew System::Windows::Forms::Button());
			this->button_reset = (gcnew System::Windows::Forms::Button());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_delete_task = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button_edit_timer = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Location = System::Drawing::Point(29, 48);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 0;
			this->monthCalendar1->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &planner_form::monthCalendar1_DateSelected);
			// 
			// progressBar_tasks
			// 
			this->progressBar_tasks->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->progressBar_tasks->Location = System::Drawing::Point(233, 119);
			this->progressBar_tasks->Name = L"progressBar_tasks";
			this->progressBar_tasks->Size = System::Drawing::Size(885, 91);
			this->progressBar_tasks->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Elephant", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(226, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(207, 38);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Day progress";
			// 
			// ListBox_tasks
			// 
			this->ListBox_tasks->Font = (gcnew System::Drawing::Font(L"Elephant", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ListBox_tasks->FormattingEnabled = true;
			this->ListBox_tasks->Location = System::Drawing::Point(29, 319);
			this->ListBox_tasks->Name = L"ListBox_tasks";
			this->ListBox_tasks->ScrollAlwaysVisible = true;
			this->ListBox_tasks->Size = System::Drawing::Size(547, 485);
			this->ListBox_tasks->TabIndex = 3;
			this->ListBox_tasks->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &planner_form::ListBox_tasks_ItemCheck);
			// 
			// text_data
			// 
			this->text_data->AutoSize = true;
			this->text_data->Font = (gcnew System::Drawing::Font(L"Elephant", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_data->Location = System::Drawing::Point(41, 262);
			this->text_data->Name = L"text_data";
			this->text_data->Size = System::Drawing::Size(0, 38);
			this->text_data->TabIndex = 4;
			// 
			// ListBox_habbits
			// 
			this->ListBox_habbits->Font = (gcnew System::Drawing::Font(L"Elephant", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ListBox_habbits->FormattingEnabled = true;
			this->ListBox_habbits->Location = System::Drawing::Point(614, 319);
			this->ListBox_habbits->Name = L"ListBox_habbits";
			this->ListBox_habbits->Size = System::Drawing::Size(486, 374);
			this->ListBox_habbits->TabIndex = 5;
			this->ListBox_habbits->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &planner_form::ListBox_habbits_ItemCheck);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Elephant", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(607, 262);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(135, 38);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Habbits";
			// 
			// add_task_button
			// 
			this->add_task_button->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_task_button->Location = System::Drawing::Point(44, 872);
			this->add_task_button->Name = L"add_task_button";
			this->add_task_button->Size = System::Drawing::Size(64, 56);
			this->add_task_button->TabIndex = 7;
			this->add_task_button->Text = L"+";
			this->add_task_button->UseVisualStyleBackColor = true;
			this->add_task_button->Click += gcnew System::EventHandler(this, &planner_form::add_task_button_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Elephant", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(114, 890);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(138, 38);
			this->label3->TabIndex = 8;
			this->label3->Text = L"add task";
			// 
			// add_task_textBox
			// 
			this->add_task_textBox->Font = (gcnew System::Drawing::Font(L"Elephant", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_task_textBox->Location = System::Drawing::Point(44, 821);
			this->add_task_textBox->Name = L"add_task_textBox";
			this->add_task_textBox->Size = System::Drawing::Size(434, 45);
			this->add_task_textBox->TabIndex = 9;
			// 
			// timer_pomodoro
			// 
			this->timer_pomodoro->Interval = 1000;
			this->timer_pomodoro->Tick += gcnew System::EventHandler(this, &planner_form::timer_pomodoro_Tick);
			// 
			// Time_text
			// 
			this->Time_text->AutoSize = true;
			this->Time_text->Font = (gcnew System::Drawing::Font(L"Elephant", 80.24998F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Time_text->Location = System::Drawing::Point(100, 157);
			this->Time_text->Name = L"Time_text";
			this->Time_text->Size = System::Drawing::Size(0, 138);
			this->Time_text->TabIndex = 10;
			// 
			// button_timer
			// 
			this->button_timer->Font = (gcnew System::Drawing::Font(L"Elephant", 71.99999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_timer->Location = System::Drawing::Point(1404, 613);
			this->button_timer->Name = L"button_timer";
			this->button_timer->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button_timer->Size = System::Drawing::Size(256, 218);
			this->button_timer->TabIndex = 11;
			this->button_timer->Text = L"▷";
			this->button_timer->UseVisualStyleBackColor = true;
			this->button_timer->Click += gcnew System::EventHandler(this, &planner_form::button_timer_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(51, 17);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(481, 73);
			this->label5->TabIndex = 12;
			this->label5->Text = L"pomodoro timer";
			// 
			// textBox_habbit
			// 
			this->textBox_habbit->Font = (gcnew System::Drawing::Font(L"Elephant", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_habbit->Location = System::Drawing::Point(628, 714);
			this->textBox_habbit->Name = L"textBox_habbit";
			this->textBox_habbit->Size = System::Drawing::Size(376, 45);
			this->textBox_habbit->TabIndex = 15;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Elephant", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(698, 783);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(171, 38);
			this->label4->TabIndex = 14;
			this->label4->Text = L"add habbit";
			// 
			// addHabbit
			// 
			this->addHabbit->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addHabbit->Location = System::Drawing::Point(628, 765);
			this->addHabbit->Name = L"addHabbit";
			this->addHabbit->Size = System::Drawing::Size(64, 56);
			this->addHabbit->TabIndex = 13;
			this->addHabbit->Text = L"+";
			this->addHabbit->UseVisualStyleBackColor = true;
			this->addHabbit->Click += gcnew System::EventHandler(this, &planner_form::addHabbit_Click);
			// 
			// button_reset
			// 
			this->button_reset->BackColor = System::Drawing::Color::White;
			this->button_reset->Location = System::Drawing::Point(1485, 890);
			this->button_reset->Name = L"button_reset";
			this->button_reset->Size = System::Drawing::Size(105, 86);
			this->button_reset->TabIndex = 17;
			this->button_reset->Text = L"reset";
			this->button_reset->UseVisualStyleBackColor = false;
			this->button_reset->Click += gcnew System::EventHandler(this, &planner_form::button_reset_Click);
			// 
			// button_delete
			// 
			this->button_delete->BackColor = System::Drawing::Color::White;
			this->button_delete->Location = System::Drawing::Point(1031, 713);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(53, 46);
			this->button_delete->TabIndex = 18;
			this->button_delete->Text = L"delete";
			this->button_delete->UseVisualStyleBackColor = false;
			this->button_delete->Click += gcnew System::EventHandler(this, &planner_form::button_delete_Click);
			// 
			// button_delete_task
			// 
			this->button_delete_task->BackColor = System::Drawing::Color::White;
			this->button_delete_task->Location = System::Drawing::Point(496, 820);
			this->button_delete_task->Name = L"button_delete_task";
			this->button_delete_task->Size = System::Drawing::Size(53, 46);
			this->button_delete_task->TabIndex = 19;
			this->button_delete_task->Text = L"delete";
			this->button_delete_task->UseVisualStyleBackColor = false;
			this->button_delete_task->Click += gcnew System::EventHandler(this, &planner_form::button1_Click_1);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->Time_text);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Location = System::Drawing::Point(1229, 48);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(593, 818);
			this->panel1->TabIndex = 20;
			// 
			// button_edit_timer
			// 
			this->button_edit_timer->BackColor = System::Drawing::Color::White;
			this->button_edit_timer->Location = System::Drawing::Point(1717, 890);
			this->button_edit_timer->Name = L"button_edit_timer";
			this->button_edit_timer->Size = System::Drawing::Size(105, 86);
			this->button_edit_timer->TabIndex = 21;
			this->button_edit_timer->Text = L"edit";
			this->button_edit_timer->UseVisualStyleBackColor = false;
			this->button_edit_timer->Click += gcnew System::EventHandler(this, &planner_form::button_edit_timer_Click);
			// 
			// planner_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->button_edit_timer);
			this->Controls->Add(this->button_delete_task);
			this->Controls->Add(this->button_delete);
			this->Controls->Add(this->button_reset);
			this->Controls->Add(this->textBox_habbit);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->addHabbit);
			this->Controls->Add(this->button_timer);
			this->Controls->Add(this->add_task_textBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->add_task_button);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->ListBox_habbits);
			this->Controls->Add(this->text_data);
			this->Controls->Add(this->ListBox_tasks);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar_tasks);
			this->Controls->Add(this->monthCalendar1);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"planner_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"planner_form";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &planner_form::planner_form_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	

private: System::Void monthCalendar1_DateSelected(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
	DateTime^ selectedDate = e->Start;
	text_data->Text = selectedDate->ToString("dd.MM.yyyy");
	System::Collections::Generic::List<String^>^ curent_tasks = Task::LoadTasks(text_data->Text);
	System::Collections::Generic::List<String^>^ taken_habbits = Task::LoadHabbits();
	ListBox_tasks->Items->Clear();
	ListBox_habbits->Items->Clear();
	progressBar_tasks->Value = 0;
	progressBar_tasks->Maximum = curent_tasks->Count + taken_habbits->Count;

	int complete = 0;
	int ind = 0;
	for each(String^ task in curent_tasks) {
		ListBox_tasks->Items->Add(task->Split('|')[1]);
		ListBox_tasks->SetItemChecked(ind, Task::ischecked(task));
		ind++;
		if (Task::ischecked(task)) {
			complete++;
		}
	}
	for (int i = 0; i < taken_habbits->Count; i++) {
		ListBox_habbits->Items->Add(taken_habbits[i]);
		ListBox_habbits->SetItemChecked(i, Task::habbit_iscomplete(taken_habbits[i], text_data->Text));
		if (Task::habbit_iscomplete(taken_habbits[i], text_data->Text)) {
			complete++;
		}
	}
	progressBar_tasks->Value = complete;
}
private: System::Void add_task_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (add_task_textBox->Text != "") {
		ListBox_tasks->Items->Add(add_task_textBox->Text);
		Task::AddTask(add_task_textBox->Text, text_data->Text);
		add_task_textBox->Text = "";
		progressBar_tasks->Maximum += 1;
	}
}
private: System::Void planner_form_Load(System::Object^ sender, System::EventArgs^ e) {

	Time_text->Text = (remainingSeconds / 60).ToString() + ":" + (remainingSeconds % 60).ToString("D2");
	text_data->Text = DateTime::Now.ToString("dd.MM.yyyy");
	System::Collections::Generic::List<String^>^ curent_tasks = Task::LoadTasks(text_data->Text);
	System::Collections::Generic::List<String^>^ taken_habbits = Task::LoadHabbits();
	progressBar_tasks->Value = 0;
	progressBar_tasks->Maximum = curent_tasks->Count + taken_habbits->Count;

	int complete = 0;

	for (int i = 0; i < curent_tasks->Count; i++) {
		ListBox_tasks->Items->Add(curent_tasks[i]->Split('|')[1]);
		ListBox_tasks->SetItemChecked(i, Task::ischecked(curent_tasks[i]));
		if (Task::ischecked(curent_tasks[i])) {
			complete++;
		}
	}
	for (int i = 0; i < taken_habbits->Count; i++) {
		this->ListBox_habbits->Items->Add(taken_habbits[i]);
		this->ListBox_habbits->SetItemChecked(i, Task::habbit_iscomplete(taken_habbits[i], text_data->Text));
		if (Task::habbit_iscomplete(taken_habbits[i], text_data->Text)) {
			complete++;
		}
	}
	progressBar_tasks->Value = complete;
}
private: void ListBox_tasks_ItemCheck(Object^ sender, ItemCheckEventArgs^ e)
{
	String^ taskText = ListBox_tasks->Items[e->Index]->ToString();

	System::Collections::Generic::List<String^>^ allTasks = Task::LoadTasks(text_data->Text);

	for (int i = 0; i < allTasks->Count; i++)
	{
		if (allTasks[i]->Split('|')[1] == taskText)  
		{
			if (e->NewValue == CheckState::Checked)
			{
				Task::check_task(allTasks[i]);
				if (progressBar_tasks->Value < progressBar_tasks->Maximum) {
					progressBar_tasks->Value += 1;
				}
			}
			else
			{
				Task::uncheck_task(allTasks[i]);
				if (progressBar_tasks->Value > 0) {
					progressBar_tasks->Value -= 1;
				}
			}
			break;
		}
	}

}

private: System::Void button_timer_Click(System::Object^ sender, System::EventArgs^ e) {
	if (timer_pomodoro->Enabled == false) {
		timer_pomodoro->Enabled = true;
		button_timer->Text = L"\u23F8";
	}
	else {
		timer_pomodoro->Enabled = false;
		button_timer->Text = L"\u25B6";
	}
}
private: System::Void timer_pomodoro_Tick(System::Object^ sender, System::EventArgs^ e) {
	remainingSeconds -= 1;
	Time_text->Text = (remainingSeconds / 60).ToString() + ":" + (remainingSeconds % 60).ToString("D2");
	if (remainingSeconds == 0) {
		timer_pomodoro->Stop();
	}

}
private: System::Void addHabbit_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox_habbit->Text != "") {
		if (!Task::findsame(textBox_habbit->Text)) {
			ListBox_habbits->Items->Add(textBox_habbit->Text);
			Task::AddHabbit(textBox_habbit->Text);
			textBox_habbit->Text = "";
			progressBar_tasks->Maximum += 1;
		}
		else {
			Dialog_window::Show("Ошибка", "Такая привычка уже существует!");
		}
	}
}
private: System::Void ListBox_habbits_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e) {
	if (e->NewValue == CheckState::Checked)
	{
		System::Collections::Generic::List<String^>^ habbits = Task::LoadHabbits();
		Task::complete_habbit(habbits[e->Index], text_data -> Text);
		if (progressBar_tasks->Value < progressBar_tasks->Maximum) {
			progressBar_tasks->Value += 1;
		}
	}
	else if (e->NewValue == CheckState::Unchecked) {
		System::Collections::Generic::List<String^>^ habbits = Task::LoadHabbits();
		Task::uncomplete_habbit(habbits[e->Index], text_data->Text);
		if (progressBar_tasks->Value > progressBar_tasks->Minimum) {
			progressBar_tasks->Value -= 1;
		}
	}
}
private: System::Void button_reset_Click(System::Object^ sender, System::EventArgs^ e) {
	timer_pomodoro->Stop();
	button_timer->Text = L"\u25B6";
	remainingSeconds = Timer_pomodoro::Get_seconds();
	Time_text->Text = (remainingSeconds / 60).ToString() + ":" + (remainingSeconds % 60).ToString("D2");
}
private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e) {
	int index = ListBox_habbits->SelectedIndex;
	

	if (index != -1) 
	{
		String^ habbitText = ListBox_habbits->Items[index]->ToString();
		if (Task::habbit_iscomplete(habbitText, text_data->Text)) {
			if (progressBar_tasks->Value > progressBar_tasks->Minimum) {
				progressBar_tasks->Value -= 1;
			}
		}
		Task::delete_habbit(habbitText);
		ListBox_habbits->Items->RemoveAt(index);
		progressBar_tasks->Maximum -= 1;
	}
	else
	{
		Dialog_window::Show("Ошибка", "Ничего не выбрано!");
	}
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	int index = ListBox_tasks->SelectedIndex;

	if (index != -1) {
		System::Collections::Generic::List<String^>^ curent_tasks = Task::LoadTasks(text_data->Text);
		String^ task = curent_tasks[index];
		Task::delete_task(task);
		Console::WriteLine(task);
		ListBox_tasks->Items->RemoveAt(index);
		if (Task::ischecked(task)) {
			if (progressBar_tasks->Value > progressBar_tasks->Minimum) {
				progressBar_tasks->Value -= 1;
			}
		}
		progressBar_tasks->Maximum -= 1;
	}
	else
	{
		Dialog_window::Show("Ошибка", "Ничего не выбрано!");
	}
}
private: System::Void button_edit_timer_Click(System::Object^ sender, System::EventArgs^ e) {
	if (timer_window::Show()) {
		timer_pomodoro->Stop();
		button_timer->Text = L"\u25B6";
		remainingSeconds = Timer_pomodoro::Get_seconds();
		Time_text->Text = (remainingSeconds / 60).ToString() + ":" + (remainingSeconds % 60).ToString("D2");
		
	}
	
}
};
}