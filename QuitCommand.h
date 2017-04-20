#pragma once
#include "Matterbot.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "ConsoleLogger.h"

namespace lospi
{
	struct QuitCommand : ICommand 
	{
		std::wstring get_name() override 
		{
			return L"quit";
		}

		std::wstring get_help() override 
		{
			return L"`quit`: `quit` will shut Johnny Five down.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override 
		{


			return L"No dissassemble Number 5! _I haven't figured this command out yet_";
			//	palceholder
		}
	};
}