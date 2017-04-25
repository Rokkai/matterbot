#pragma once
#include "Matterbot.h"
#include <algorithm>
bool loop;

namespace lospi {
	struct RivStartChallengeCommand : ICommand {
		explicit RivStartChallengeCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"startCH"; }

		std::wstring get_help() override { return L"`startCH` will start rivestment challenges."; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {
			
			loop = true;
			while (loop == true)
			{
				_sleep(5000);
				bot->post_message(L"rivestment challenge");
			}

			return L"challenges stopped";
		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}