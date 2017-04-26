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
#include "RivMapMaker.h"

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
			if (user == L"rivestment" || user == L"rtamo")
			{
				std::wstring destHash;												//	destination
				std::wistringstream sourceHash( command_text );						//	source
				std::wstring returnValue;											//	value to append destination into

				while (getline(sourceHash, destHash, L' '))
				{
					Md5Digest takenMD5 = get_md5_from_str(destHash);

					auto result = lookup.begin();
					result = lookup.find(takenMD5);

					if (result == lookup.end())
					{
						result = lookup.begin();
						return L"you need to reset the map iterator";
					}

					auto value = result->second;

					returnValue = returnValue + L" " + string_to_wstring(value);
				}
				return L"rivestment try" + returnValue;
			}
			else
			{
				return L"Invalid permissions";
			}

				
			
		}
	};
}
