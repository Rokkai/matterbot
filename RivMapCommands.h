////	TOC		////
//C1. Create Map	////
//C2. Delete Map	////

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
#include "RivMapCommandBody.h"
#include "RivSetLevel.h"

//C1. Create Map
namespace lospi
{
	struct RivMapCreateCommand : ICommand
	{
		explicit RivMapCreateCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override
		{
			return L"rivCreateMap";
		}

		std::wstring get_help() override
		{
			return L"`rivCreateMap`: will run the function to create a md5 hash map and return notification of when it's completed.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override
		{
			if (user == L"rtamo")
			{
				bot->post_message(L"Creating map... please wait...");
				if (Level == 4)
				{
					bot->post_message(L"At level 4 this will take about 5 minutes...");
				}
				mapMaker();																//	call the mapMaker function from MapCreator.h
				std::wstring levelString = L"Level " + setLevel;
				return levelString + L" map created";
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

//C2. Delete Map
namespace lospi
{
	struct RivMapDestroyCommand : ICommand
	{
		explicit RivMapDestroyCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override
		{
			return L"rivDeleteMap";
		}

		std::wstring get_help() override
		{
			return L"`rivDeleteMap`: will delete the current map.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override
		{
			if (user == L"rtamo")
			{
				bot->post_message(L"Deleting the current map... please wait...");
				MapDestroyer();
				return L"map deleted";
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