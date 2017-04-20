#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct WeatherCommand : ICommand 
	{
		std::wstring get_name() override 
		{
			return L"weather";
		}

		std::wstring get_help() override 
		{
			return L"`weather [CMD]`:\n`weather rain`: Make it rain\n`weather sunny`: Make it sunny\n`weather report`: Print the status";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override 
		{
			if (command_text == L"sunny")
			{
				is_raining = false;
				//make it sunny
				return L"It's sunny.";
			}
			else if (command_text == L"rain")
			{
				is_raining = true;
				//make it rain
				return L"It's raining.";
			}
			else if (command_text == L"report")
			{
				//return the status
				if (is_raining)
				{
					return L"Get your umbrella.";
				}
				else
				{
					return L"Get some sunscreen.";
				}
			}
			else
			{
				return L"No weather reported... AFAIK it's just an empty void out there";
			}
		}
	private:
		bool is_raining;
	};
}
