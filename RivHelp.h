#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct RivHelpCommand : ICommand
	{
		std::wstring get_name() override
		{
			return L"rivHelp";
		}

		std::wstring get_help() override
		{
			return L"`rivHelp`: will have JohnnyFive explain using rivestment";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override
		{
			return L"For a list of rivestment commands, you can use the standard help command.\nHere you'll get a specific order of how you want to run the commands.\n\nTo register and begin running challenges:\n1. `rivRegister` - Register me with rivestment.\n2. `rivPassword` - Get the password to use in creating a map.\n3. `rivLevel #` - Choose the level of challenges and to create a map at that level.\n4. `rivCreateMap` - Will create the map of hashes and passwords.\n5. `rivStart` - Will start the automated rivestment challenges.\n\nCommands for specific situations:\n-- `rivStop` - will halt challenges.\n-- `scraps` - will have have JohnnyFive check for unused scraps. _Note: If you're thinking of changing levels, do this first._\n-- `rivDeleteMap` - will delete your current map if you want to change levels.\n-- `rivQuit` - will quit rivestment and remove JohnnyFive from the leaderboard.";
		}
	};
}