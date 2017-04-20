#pragma once
#include "Matterbot.h"
#include <math.h>
#include <string>
//#include <sstream>
#include <iostream>


int num1 = 0;
int num2 = 0;
char operand = 0;


namespace lospi
{
	struct CalculateCommand : ICommand
	{
		std::wstring get_name() override
		{
			return L"calc";
		}

		std::wstring get_help() override
		{
			return L"`calc`: will have JohnnyFive use his advanced 1980s electronics to do math... *single digits only*";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override
		{
			
			std::wstring strNum1 = command_text.substr(0,1);
			std::wstring strOp = command_text.substr(1, 1);
			std::wstring strNum2 = command_text.substr(2,1);
			

			int conNum1 = _wtoi(strNum1.c_str());
			int conNum2 = _wtoi(strNum2.c_str());

			int sumNums = conNum1 + conNum1;
			int minNums = conNum1 - conNum1;
			int mulNums = conNum1 * conNum2;
			int divNums = conNum1 / conNum2;
			int modNums = conNum1 % conNum2;

			if (strOp == L"+")
			{
				return L"The answer is " + std::to_wstring(sumNums);
			}
			else if (strOp == L"-")
			{
				return L"The answer is " + std::to_wstring(minNums);
			}
			else if (strOp == L"*")
			{
				return L"The answer is " + std::to_wstring(mulNums);
			}
			else if (strOp == L"/")
			{
				return L"The answer is " + std::to_wstring(divNums);
			}
			else if (strOp == L"%")
			{
				return L"The answer is " + std::to_wstring(modNums);
			}
			else
			{
				return L"Functioning 100%. Perfectly KO";
			}
		}
	};
}