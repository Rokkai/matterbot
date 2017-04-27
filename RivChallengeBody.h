////		TOC			////
////	C1. Challenges	////
////	C2. Scraps		////


#pragma once
#include "Matterbot.h"
#include "Md5.h"
#include "Md5Utilities.h"
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "RivGetPassword.h"
#include "RivMapCommands.h"

std::wstring passwordvariable;

namespace lospi
{
	struct RChallengeCommand : ICommand 
	{
		std::wstring get_name() override 
		{
			return L"challenges";
		}

		std::wstring get_help() override 
		{
			return L"`challenges` `#`: will read `#` hashes from rivestment and return a try command when matches are found";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override 
		{
			if (user == L"rivestment")
			{
				std::wstring destHash;												//	destination
				std::wistringstream sourceHash( command_text );						//	source
				std::wstring returnValue;											//	value to append destination into

				while (getline(sourceHash, destHash, L' '))							//	while getline grabs the line, delineates and a space, and places stuff in destHash...
				{
					Md5Digest takenMD5 = get_md5_from_str(destHash);				//	...convert what's taken into md5 format

					auto result = lookup.find(takenMD5);							//	create the result variable as the match for takenMD5
					if (result == lookup.end())										//	if the lookup pointer returns null, it needs to be reset.
					{
						return L"you need to reset the map iterator";
					}

					auto value = result->second;									//	create the variable for the new password that we want to try

					returnValue = returnValue + L" " + string_to_wstring(value);	//	append the value to a list of values
				}
				return L"rivestment try" + returnValue;								//	return the line with the list of values
			}
			else
			{
				return L"Invalid permissions";
			}
		}
	};
	////////////////////////////////////////////////////////////////////////////////
	////////	Scrap command for JohnnyFive to grab scraps from rivestment	////////
	////////////////////////////////////////////////////////////////////////////////
	struct RivScrapCommand : ICommand
	{
		std::wstring get_name() override
		{
			return L"scraps";
		}

		std::wstring get_help() override
		{
			return L"`scraps`: will retrieve any unsolved scraps for the bot to retry";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override
		{
			if (user == L"rivestment")
			{
				std::wstring destHash;												//	destination
				std::wistringstream sourceHash(command_text);						//	source
				std::wstring returnValue;											//	value to append destination into

				while (getline(sourceHash, destHash, L' '))							//	while getline grabs the line, delineates and a space, and places stuff in destHash...
				{
					Md5Digest takenMD5 = get_md5_from_str(destHash);				//	...convert what's taken into md5 format

					auto result = lookup.find(takenMD5);							//	create the result variable as the match for takenMD5
					if (result == lookup.end())										//	if the lookup pointer returns null, it needs to be reset.
					{
						return L"you need to reset the map iterator";
					}

					auto value = result->second;									//	create the variable for the new password that we want to try

					returnValue = returnValue + L" " + string_to_wstring(value);	//	append the value to a list of values
				}
				return L"rivestment try" + returnValue;								//	return the line with the list of values
			}
			else if (user == L"rtamo")
			{
				return L"rivestment scraps";
			}
			else
			{
				return L"Invalid permissions";
			}
		}
	};
}
