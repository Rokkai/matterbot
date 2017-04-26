#pragma once
#include "Matterbot.h"

std::wstring rivestmentPassword;

namespace lospi
{
	struct RivGetPWCommand : ICommand {
		std::wstring get_name() override {
			return L"password";
		}

		std::wstring get_help() override {
			return L"`password [MESSAGE]`: will assign the given password to a variable.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			if (user == L"rivestment")
			{
				rivestmentPassword = command_text;					//	Grab the password from rivestment and place it into variable 'rivestmentPassword'

				return L"Password set";
			}
			else
			{
				return L"Invalid permissions";
			}
		}
	};
}

