#pragma once
#include "Matterbot.h"
#include "Md5.h"
#include "Md5Utilities.h"
#include <string.h>


namespace lospi
{
	struct CreateMD5Command : ICommand
	{
		std::wstring get_name() override
		{
			return L"create";
		}

		std::wstring get_help() override
		{
			return L"`create [wstring]`: will make read a line and return its md5 hash";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override
		{
			//command_text is the passed in password

			//	1)	command handler	command_text	wstring	
			//	2)	wstring_to_string	->	string
			std::string newstring = wstring_to_string(command_text);

			//	3)	c_str		size()

			const char * cnewstring = newstring.c_str();

			unsigned long strSize = strlen(cnewstring);

			

			//	4)	compute_md5 char*,	unsigned int.	-> md5digest
			auto digestedmd5 = compute_md5(cnewstring, strSize);

			//	5)	get_str_from_md5	->	wstring
			std::wstring finalString = get_str_from_md5(digestedmd5);

			return finalString;
			//	the command text is a series of hashes delineated by spaces.
			//	I'll use the Md5 hashes to find a password in a wstring variable
			//	I'll then return the wstring variable
			//	return L"rivestment try " + passwordvariable;


			//return L"The password is abcd123456";
		}
	};
}
