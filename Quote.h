#pragma once
#include "Matterbot.h"


namespace lospi
{
	struct QuoteCommand : ICommand 
	{
		std::wstring get_name() 
			override 
		{
			return L"Quote";
		}

		std::wstring get_help() 
			override 
		{
			return L"`Quote [1-9]`: should give a movie quote.";
		}
		


		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) 
			override 
		{
			if (command_text == L"\0" || command_text < L"1" || command_text >= L"10")
			{
				return L"Malfunction. Need input.";
			}
			else if (command_text == L"1")
			{
				return L"Hey, laser lips, your mama was a snow blower.";
			}
			else if (command_text == L"2")
			{
				return L"Malfunction. Need input.";
			}
			else if (command_text == L"3")
			{
				return L"Disassemble?";
			}
			else if (command_text == L"4")
			{
				return L"No disassemble Number Five!";
			}
			else if (command_text == L"5")
			{
				return L"Number 5 stupid name... want to be Kevin or Dave!";
			}
			else if (command_text == L"6")
			{
				return L"Come Stephanie! We be jamming!";
			}
			else if (command_text == L"7")
			{
				return L"Just a few ibdy... ibdy... bugs bunnies.";
			}
			else if (command_text == L"8")
			{
				return L"Hey you, here's Johnny!";
			}
			else if (command_text == L"9")
			{
				return L"Hath not a robot eyes? Hath not a robot hands, organs, dimensions, senses affections, passions? If you prick us do we not bleed?!";
			}

			
			
		}

	};
}