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
#include "RivMapCreator.h"
#include "RivSetLevel.h"





namespace lospi
{
	struct CreateMD5MapCommand : ICommand
	{
		std::wstring get_name() override
		{
			return L"rivMap";
		}

		std::wstring get_help() override
		{
			return L"`rivMap [wstring]`: will run the function to create a md5 hash map and return notification of when it's completed.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override
		{
			mapMaker();

			std::wstring levelString = L"Level " + setLevel;
			return levelString + L" map created";
		}
	};
}



////Generate an md5 from a string					////////////////////////////////
//std::string newstring = wstring_to_string(command_text);		//	convert the wstring to a string	//md5Utilities
//const char * cnewstring = newstring.c_str();					//	from the string create a c-type string
//unsigned long strSize = strlen(cnewstring);						//	get the size of the newly created c-type string
//auto digestedmd5 = compute_md5(cnewstring, strSize);			//	create the variable for the digested md5 hash	//md5Utilities
//std::wstring finalString = get_str_from_md5(digestedmd5);		//	create a wstring for printing from the md5 hash	//md5Utilities