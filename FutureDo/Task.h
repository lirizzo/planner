#pragma once
#include "UserManager.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace System;

namespace FutureDo {
	public ref class Task {
	private:
		String^ name;
		String^ date;
	public:

		static System::Collections::Generic::List<String^>^ LoadTasks(String^ date) {
			
			User^ user = ManageUser::GetCurrentUser();

			String^ filename = "users/" + user->Username + "/tasks.txt";
			array<String^>^ tasks = File::ReadAllLines(filename);

			System::Collections::Generic::List<String^>^ curent_tasks = gcnew System::Collections::Generic::List<String^>();
			for each(String ^ task in tasks) {
				if (task->Contains(date)) {
					curent_tasks->Add((task));
				}
			}
			return curent_tasks;
			
		}
		static void uncheck_task(String^ task) {
			User^ user = ManageUser::GetCurrentUser();
			String^ filename = "users/" + user->Username + "/tasks.txt";

			System::Collections::Generic::List<String^>^ lines = gcnew System::Collections::Generic::List<String^>(File::ReadAllLines(filename));

			for each (String ^ line in lines) {
				if (line == task) {
					array<String^>^ change = line->Split('|');
					change[2] = "No";
					lines->Remove(task);
					lines->Insert(0, String::Join("|", change));
					File::WriteAllLines(filename, lines);
					break;
				}
			}
		}

		static void check_task(String^ task) {
			User^ user = ManageUser::GetCurrentUser();
			String^ filename = "users/" + user->Username + "/tasks.txt";
			
			System::Collections::Generic::List<String^>^ lines = gcnew System::Collections::Generic::List<String^>(File::ReadAllLines(filename));

			for each(String^ line in lines) {
				if (line == task) {
					array<String^>^ change = line->Split('|');
					change[2] = "Yes";
					lines->Remove(task);
					lines->Insert(0,String::Join("|", change));
					File::WriteAllLines(filename, lines);
					break;
				}
			}

		}

		static bool ischecked(String^ task) {
			if (task->Split('|')[2] == "Yes") {
				return true;
			}
			else {
				return false;
			}
		}

		static void AddTask(String^ name, String^ date) {
			User^ user = ManageUser::GetCurrentUser();

			String^ filename = "users/" + user->Username + "/tasks.txt";
			String^ task = date + "|" + name + "|" + "No";

			StreamWriter^ task_writer = gcnew StreamWriter(filename, true);
			task_writer->WriteLine(task);
			task_writer->Close();

		}

		static void delete_task(String^ task) {
			User^ user = ManageUser::GetCurrentUser();
			String^ filename = "users/" + user->Username + "/tasks.txt";

			System::Collections::Generic::List<String^>^ lines = gcnew System::Collections::Generic::List<String^>(File::ReadAllLines(filename));

			for each(String^ line in lines) {
				if (task == line) {
					lines->Remove(line);
					File::WriteAllLines(filename, lines);
					
					break;
				}
			}


		}

		static void AddHabbit(String^ name) {
			User^ user = ManageUser::GetCurrentUser();

			String^ filename = "users/" + user->Username + "/habbits/" + name + ".txt";

			File::Create(filename)->Close();

		}

		static System::Collections::Generic::List<String^>^ LoadHabbits() {
			User^ user = ManageUser::GetCurrentUser();

			String^ directoryname = "users/" + user->Username + "/habbits/";
			array<String^>^ files = Directory::GetFiles(directoryname);
			System::Collections::Generic::List<String^>^ filesname = gcnew System::Collections::Generic::List<String^>();

			for each(String ^ file in files) {
				String^ name = Path::GetFileName(file);
				filesname->Add(Path::GetFileNameWithoutExtension(name));
			}

			return filesname;

		}
		static void complete_habbit(String^ name, String^ date) {
			User^ user = ManageUser::GetCurrentUser();
			
			String^ filename = "users/" + user->Username + "/habbits/" + name + ".txt";

			File::AppendAllText(filename, " " + date);
		}

		static void uncomplete_habbit(String^ name, String^ date) {
			User^ user = ManageUser::GetCurrentUser();
			String^ filename = "users/" + user->Username + "/habbits/" + name + ".txt";

			System::Collections::Generic::List<String^>^ habbits = gcnew System::Collections::Generic::List<String^>(File::ReadAllText(filename)->Split(' '));

			for (int i = 0; i < habbits->Count; i++)
			{
				if (habbits[i] == date)
				{
					habbits->RemoveAt(i);
				}
			}

			File::WriteAllText(filename, String::Join(" ", habbits->ToArray()));
		}

		static bool habbit_iscomplete(String^ name, String^ date){
			User^ user = ManageUser::GetCurrentUser();

			String^ filename = "users/" + user->Username + "/habbits/" + name + ".txt";
			String^ complete =  File::ReadAllText(filename);
			if (complete->Contains(" " + date)) {
				return true;
			}
			else {
				return false();
			}
		}

		static bool findsame(String^ name) {
			User^ user = ManageUser::GetCurrentUser();

			String^ directory = "users/" + user->Username + "/habbits/";
			array<String^>^ files = Directory::GetFiles(directory);
			for each(String^ file in files) {
				if (Path::GetFileNameWithoutExtension(Path::GetFileName(file)) == name) {
					return true;
				}
			}
			return false;
		}

		static void delete_habbit(String^ name) {
			User^ user = ManageUser::GetCurrentUser();

			String^ filename = "users/" + user->Username + "/habbits/" + name + ".txt";
			File::Delete(filename);
		}
	};
}