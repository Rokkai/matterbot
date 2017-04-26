#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct RivQuitCommand : ICommand 
	{
		std::wstring get_name() override 
		{
			return L"rivQuit";
		}

		std::wstring get_help() override {
			return L"`rivQuit`: will have JohnnyFive quit rivestment.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override 
		{
			if (user == L"rtamo")
			{
				return L"rivestment quit";
			}
			else
			{
				return L"Invalid permissions";
			}
		}
	};
}

