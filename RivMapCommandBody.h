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
#include "RivMapCommands.h"
#include "RivSetLevel.h"

using namespace lospi;
using namespace std;

map <Md5Digest, string> lookup;														//	global variable so that others can see

//C1. Create Map
void mapMaker()
{
		std::string pw = wstring_to_string(rivestmentPassword);						//	create a local variable for the user password		

		////////////////////////////////		Generate the password and hash map using Combinator					////////////////////////////////
		
		for (size_t i = Level; i < (Level + 10); i++)								//	i is the level					
		{
			Combinator c{ "hsoj", i };
			while (c.has_next())													//	while there is a next combo
			{
				auto combo = c.next();												//	create the combination variable 

				copy(pw.begin(), pw.end(), back_inserter(combo));					//	copy the password with back_inserter to place at the end of the combo

				auto md5 = compute_md5(combo.data(), (unsigned long)combo.size());	//	create an md5 out of it

				lookup.emplace(md5, string{ combo.begin(), combo.end() });			//	insert the key(md5) and the password(string) into the map
			}
		}
}

//C2. Delete Map
void MapDestroyer()
{
	lookup.clear();
}