#pragma once
#include "Matterbot.h"

int Level;
std::wstring setLevel;

namespace lospi
{
	struct RivSetLvlCommand : ICommand {
		std::wstring get_name() override {
			return L"rivLevel";
		}

		std::wstring get_help() override {
			return L"`rivLevel` `#`: will assign the rivestment level to a variable.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			if (user == L"rtamo")
			{

				setLevel = command_text;

				std::string stringLevel = wstring_to_string(setLevel);

				Level = stoi(stringLevel);

				return L"rivestment level " + setLevel;
			}
			else
			{
				return L"Invalid permissions";
			}
		}
	};
}

