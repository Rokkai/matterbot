#pragma once
#include "Matterbot.h"
#include <algorithm>
#include "RivRegister.h"

bool loop;																					//	initialize a loop variable

namespace lospi {
	struct RivStartChallengeCommand : ICommand {
		explicit RivStartChallengeCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"rivStart"; }

		std::wstring get_help() override { return L"`rivStart` will start rivestment challenges."; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {
			if (user == L"rtamo")
			{
				loop = true;																	//	set the loop to true (set false in other command)
				while (loop == true)
				{
					if (pointLevel > 5 && pointLevel < 15)										//	when we've gone through enough iterations...
					{
						if (Level > 3)															//	...and the level is set higher than 2...
						{
							bot->post_message(L"rivestment challenge 200");						//	...we can pull 200 scraps (affected by pointLevel)
							_sleep(7000);														//	...and sleep for 7 seconds (affected by map level)
						}
						else
						{
							bot->post_message(L"rivestment challenge 200");
							_sleep(5000);
						}
						pointLevel++;
					}
					else if (pointLevel == 15)													//	Once we reach pointLevel 15, retry unsolved scraps
					{
						bot->post_message(L"rivestment scraps");
						_sleep(7000);
						pointLevel = 5;															//	Set pointLevel back to 5
					}
					else																		//	Under pointLevel 4, just do 100 scraps
					{
						bot->post_message(L"rivestment challenge 100");
						_sleep(5000);
						pointLevel++;
					}
				}
				return L"Command returned, challenged stopped";
			}
			else
			{
				return L"Invalid permissions";
			}
		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}