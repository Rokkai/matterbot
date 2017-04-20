#pragma once
#include "Matterbot.h"
#include "Md5.h"
#include "Md5Utilities.h"


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
			return L"`challenges [hashes]`: will read a given list of MD5 hashes return try commands to rivestment";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override 
		{

			//	the command text is a series of hashes delineated by spaces.
				//	

			//	I'll use the Md5 hashes to find a password in a wstring variable
			//	I'll then return the wstring variable
			//	return L"rivestment try " + passwordvariable;

			
			return L"The password is abcd123456";
		}
	};
}
