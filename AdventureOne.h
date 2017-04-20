#pragma once
#include "Matterbot.h"


namespace lospi
{
	struct AdventureOneCommand : ICommand {
		std::wstring get_name() override {
			return L"game";
		}

		std::wstring get_help() override {
			return L"`game` `begin` will initiate a text adventure game.\n`game` '[CMD]' will execute actions.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			
			//Permission check to run a reset command (FORCE)
			if (command_text == L"FORCE" && user == L"rtamo")
			{
				game_started = false;
				has_gun = false;
				std::wstring currentUser;
				return L"Game reset";
			}
			else if (command_text == L"FORCE" && user != L"rtamo")
			{
				return L"You don't have permission to run that command.";
			}

			//No command given
			if (command_text == L"\0")
			{
				return L"Please issue a command.";
			}

			//Game start
			if (game_started == false)
			{
				if (command_text == L"begin")
				{
					game_started = true;
					has_gun = false;
					currentUser = user;
					return L"For some reason you're out at midnight, in the middle of nowhere, and you're standing at a crossing.\nYou have the choice to move `north`, `south`, `east`, or	`west`. \nYou also have the choice to `look` around or `quit`.";
				}
				else
				{
					return L"`begin` a new game to start playing.";
				}
			}
			else if (game_started == true && user == currentUser)
			{
				if (command_text == L"begin")
				{
					game_started = true;
					has_gun = false;
					return L"Game Reset\nFor some reason you're out at midnight in the middle of nowhere and you're standing at a crossing.\nYou have the choice to move `north`, `south`, `east`, or	`west`. \nYou also have the choice to `look` around or `quit`.";
				}
				if (command_text == L"look")
				{
					return L"It's a pretty foggy night. Visibility is poor. You see your car. In any case, it's got an empty gas tank. Though I guess you can `check` it for anything useful.\nYou're standing at a crossing.\nYou have the choice to move `north`, `south`, `east`, or	`west`. \nYou also have the choice to `look` around, `check` your car or `quit`.";
				}
				else if (command_text == L"check")
				{
					has_gun = true;
					return L"You look inside your car for anything to add to your inventory. There's a gun in the glove box. You take it.";
				}
				else if (command_text == L"north" || command_text == L"south" || command_text == L"east" || command_text == L"west")
				{
					if (has_gun == false)
					{
						game_started = false;
						return L"Game Over: You start walking and eventually get mauled by wild animals.";
					}
					else if (has_gun == true)
					{
						game_started = false;
						return L"Game Over: You start walking and come across a pack of wild animals.\nYou try to use your gun, but you're a terrible shot and it's foggy, so it does you no good. You just got mauled by wild animals.\nThank you for playing!";
					}
				}
				else if (command_text == L"quit")
				{
					game_started = false;
					return L"Game Over:\nYou get in your car and drive home.\nThanks for playing!";
				}
				else	//	if an improper command is given
				{
					return L"You made a incorrect choice. Well, aside from the one that brought you out in the middle of nowhere at midnight.";
				}
			}
			else if (user != currentUser)
			{
				return L"You're not the current player";
			}
		}
	private:
		bool has_gun = false;
		bool game_started = false;
		std::wstring currentUser;
	};
}


////	Future releases
//	Actual separate paths
//	More items than just the gun.
//	multi word commands
