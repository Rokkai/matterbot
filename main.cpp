#include "Matterbot.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "ConsoleLogger.h"
#include "EchoCommand.h"
#include "ReverseCommand.h"
#include "testcommandJ5.h"
#include "WeatherCommand.h"
#include "Quote.h"
#include "QuitCommand.h"
#include "Calculator.h"
#include "AdventureOne.h"
#include "RivChallengeBody.h"
#include "Md5.h"
#include "Md5Utilities.h"
#include "RivMapCommands.h"
#include "RivGetPassword.h"
#include <map>
#include "RivMapCommandBody.h"
#include "RivStartChallenges.h"
#include "RivStopChallenge.h"
#include "RivSetLevel.h"
#include "RivSetPassword.h"
#include "RivRegister.h"
#include "RivQuit.h"
#include "RivHelp.h"


#define ERROR_SUCCESS 0
#define ERROR_FAILURE -1

using namespace std;
using namespace lospi;

int main()
{
	wstring mattermost_url = L"https://hooks.slack.com",
		incoming_hook_route = L"//",
		outgoing_hook_route = L"//",
		outgoing_hook_token = L"//",
		welcome_message = L"Number Five is *Alive*.",
		rivestment_message = L"_Note:_ `rivHelp` _will be useful for interacting with rivestment._",
		exit_message = L"*NO DISASSEMBLE!* _shutting down_";

	try {
		auto bot = make_shared<Matterbot>(mattermost_url, incoming_hook_route, outgoing_hook_route, outgoing_hook_token);
		bot->set_logger(make_unique<ConsoleLogger>());
		bot->register_command(make_shared<EchoCommand>());
		bot->register_command(make_shared<ReverseCommand>(bot));
		bot->register_command(make_shared<TestCommand>());
		bot->register_command(make_shared<WeatherCommand>());
		bot->register_command(make_shared<QuoteCommand>());
		bot->register_command(make_shared<QuitCommand>());
		bot->register_command(make_shared<CalculateCommand>());
		bot->register_command(make_shared<AdventureOneCommand>());

		bot->register_command(make_shared<RChallengeCommand>());
		bot->register_command(make_shared<RivMapCreateCommand>(bot));
		bot->register_command(make_shared<RivMapDestroyCommand>(bot));
		bot->register_command(make_shared<RivGetPWCommand>());
		bot->register_command(make_shared<RivStartChallengeCommand>(bot));
		bot->register_command(make_shared<RivStopChallengeCommand>(bot));
		bot->register_command(make_shared<RivSetLvlCommand>());
		bot->register_command(make_shared<RivSetPWCommand>());
		bot->register_command(make_shared<RivRegisterCommand>());
		bot->register_command(make_shared<RivQuitCommand>());
		bot->register_command(make_shared<RivScrapCommand>());
		bot->register_command(make_shared<RivHelpCommand>());
		bot->post_message(welcome_message);
		bot->post_message(rivestment_message);

		wstring console;
		wclog << ">> Type \'quit\' to quit. Any other input will be sent to the bot." << endl;

		while (getline(wcin, console))
		{
			if (L"quit" == console)
			{
				bot->post_message(exit_message);
				wclog << ">> Quitting." << endl;
				return ERROR_SUCCESS;
			}
			if (L"" != console)
			{
				bot->post_message(console);
			}
		}
	}


  catch (exception e)
  {
	  wcerr << "[-] Unhandled exception:" << e.what() << endl;
	  return ERROR_FAILURE;
  }


  
}
