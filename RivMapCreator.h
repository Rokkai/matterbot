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
#include "RivMapMaker.h"
#include "RivSetLevel.h"

using namespace lospi;
using namespace std;

map <Md5Digest, string> lookup;														//	global variable so that others can see

void mapMaker()
{
		std::string pw = wstring_to_string(rivestmentPassword);						//	create a local variable for the user password		

		////////////////////////////////		Generate the passwords using Combinator					////////////////////////////////
		
		for (size_t i = Level; i < (Level + 10); i++)								//	i is the level					
		{
			Combinator c{ "hsoj", i };
			while (c.has_next())													//	while there is a next combo
			{
				auto combo = c.next();												//	create the combination variable 

				copy(pw.begin(), pw.end(), back_inserter(combo));					//	copy the password with back_inserter to place at the end of the combo

				auto md5 = compute_md5(combo.data(), (unsigned long)combo.size());	//	create an md5 out of it

				lookup.emplace(md5, string{ combo.begin(), combo.end() });			//	insert the key and the password into the map
			}
		}
}