#pragma once
#include <iostream>
#include <cstring>

#define  MATCH_NUMBERS "[+-]?//d+(//.//d+)?"

class CharTest
{
public:
	char* _strupr(char* src);
	int StrCmpLogicalW_Imitate(char* csText1, char* csText2);
};

