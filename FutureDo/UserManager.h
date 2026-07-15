#pragma once
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace System::IO;

namespace FutureDo {
	public ref class ManageUser {
	
	private:
		
		static User^ currentUser;  

	public:

		static void SetCurrentUser(User^ user) { currentUser = user; }
		static User^ GetCurrentUser() { return currentUser; } 

		static bool register_user(String^ username, String^ passwordHash) {
			if (!find_user(username)) {
				if (!Directory::Exists("users")) {
					Directory::CreateDirectory("users");
				}
				String^ directory_name = "users/" + username;
				String^ profile_file_name = "users/" + username + "/profile.txt";
				String^ tasks_file_name = "users/" + username + "/tasks.txt";
				String^ habbits_directory_name = "users/" + username + "/habbits";
				if (!Directory::Exists(directory_name)) {
					Directory::CreateDirectory(directory_name);
					File::Create(profile_file_name)->Close();
					File::Create(tasks_file_name)->Close();
					Directory::CreateDirectory(habbits_directory_name);
				}
				StreamWriter^ add_profile = gcnew StreamWriter(profile_file_name, true);
				String^ recordstr = username + "|" + passwordHash;
				add_profile->WriteLine(recordstr);

				add_profile->Close();
				return true;
			}
			return false;
		}

		static bool find_user(String^ username){
			String^ directory = "users/" + username;
			if (Directory::Exists("users")){
				if (Directory::Exists(directory)) {
					return true;
				}
			}
			return false;
		}
		static bool login_user(String^ username, String^ passwordHash) {
			String^ file = "users/" + username + "/profile.txt";
			if (find_user(username)) {
				if (File::Exists(file)) {
					StreamReader^ open_file = gcnew StreamReader(file);
					array <String^>^ pass_hash = open_file->ReadLine()->Split('|');
					open_file->Close();
					if (passwordHash == pass_hash[1]) {
						return true;
					}
				}
			}
			return false;

		}

	};
}