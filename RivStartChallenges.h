#pragma once
#include "Matterbot.h"
#include <algorithm>
#include "RivRegister.h"

bool loop;

namespace lospi {
	struct RivStartChallengeCommand : ICommand {
		explicit RivStartChallengeCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"rivStart"; }

		std::wstring get_help() override { return L"`rivStart` will start rivestment challenges."; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {

			loop = true;
			while (loop == true)
			{
				if (pointLevel > 10)
				{
					if (Level > 2)
					{
						bot->post_message(L"rivestment challenge 200");
						_sleep(5000);
					}
					else
					{
						bot->post_message(L"rivestment challenge 200");
						_sleep(3000);
					}
				}
				else
				{
					if (Level > 2)
					{
						bot->post_message(L"rivestment challenge 100");
						_sleep(5000);
					}
					else
					{
						bot->post_message(L"rivestment challenge 100");
						_sleep(3000);
					}
					pointLevel++;
				}
			}

			return L"challenges stopped";
		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}