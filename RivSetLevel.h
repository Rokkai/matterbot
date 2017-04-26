#pragma once
#include "Matterbot.h"

int Level;											//	create a variable used by mapMaker to create the map of hashes
std::wstring setLevel;								//	create a variable used to print out what level we've chosen

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
				setLevel = command_text;									//	set a variable to the chosen level
				std::string stringLevel = wstring_to_string(setLevel);		//	convert that variable..
				Level = stoi(stringLevel);									//	...so that it can be converted to an int
				return L"rivestment level " + setLevel;
			}
			else
			{
				return L"Invalid permissions";
			}
		}
	};
}

