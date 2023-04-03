#pragma once
#include <iostream>
#include <cstring>

#define  MATCH_NUMBERS "[+-]?//d+(//.//d+)?"
using namespace std;

class CharTest
{
public:
	char* _strupr(char* src);
	int StrCmpLogicalW_Imitate(char* csText1, char* csText2);
	void removeFilterSemicolon(string& str);
	string reverseLeftWords(string s, int n);
	int strStr(string haystack, string needle);
};

