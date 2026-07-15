#pragma once
using namespace System;

namespace FutureDo {
	public ref class User {
	public:
		String^ Username;
		String^ PasswordHash;
		DateTime RegistrationDate;

		static String^ HashPassword(String^ password) {
			array<Byte>^ bytes = System::Text::Encoding::UTF8->GetBytes(password);
			String^ hash = Convert::ToBase64String(bytes);
			return hash;
		}

		User() {}
		User(String^ username, String^ password)
		{
			Username = username;
			PasswordHash = HashPassword(password);
			RegistrationDate = DateTime::Now;

		}
		bool CheckPassword(String^ password) {
			return PasswordHash == HashPassword(password);
		}
	};
}