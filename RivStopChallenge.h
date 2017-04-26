#pragma once
#include "Matterbot.h"
#include <algorithm>
#include "RivStartChallenges.h"



namespace lospi
{
	struct RivStopChallengeCommand : ICommand
	{
		explicit RivStopChallengeCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }			//	enable usage of bot commands

		std::wstring get_name() override {	return L"rivStop";	}

		std::wstring get_help() override	{	return L"`rivStop [wstring]`: will stop the rivestment challenge loop";	}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override
		{

			loop = false;

			return L"challenge stopped";
		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}