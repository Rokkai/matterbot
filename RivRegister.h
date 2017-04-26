#pragma once
#include "Matterbot.h"
int pointLevel;					//	create a point variable that will be used to determine how many scraps can be handled per challenge.

namespace lospi
{
	struct RivRegisterCommand : ICommand 
	{
		std::wstring get_name() override 
		{
			return L"rivRegister";
		}
		std::wstring get_help() override {
			return L"`rivRegister`: will have JohnnyFive register with rivestment.";
		}
		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override 
		{
			if (user == L"rtamo")
			{
				pointLevel = 1;
				return L"rivestment register JohnnyFive";
			}
			else
			{
				return L"Invalid permissions";
			}
		}
	};
}

