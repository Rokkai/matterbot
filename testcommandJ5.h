#pragma once
#include "Matterbot.h"
#include <ctime>

using namespace std;

namespace lospi
{
	struct TestCommand : ICommand {
		std::wstring get_name() override {
			return L"test";
		}

		std::wstring get_help() override {
			return L"`test [MESSAGE]`: `hello` will test a command.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

		
			return L"I don't know what time it is...";
		}
	};
}