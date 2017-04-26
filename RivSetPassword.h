#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct RivSetPWCommand : ICommand {
		std::wstring get_name() override {
			return L"rivPassword";
		}
		std::wstring get_help() override {
			return L"`rivPassword`: will have JohnnyFive retrieve the password from rivestment.";
		}
		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			if (user == L"rtamo")
			{
				return L"rivestment password";
			}
			else
			{
				return L"Invalid permissions";
			}
		}
	};
}