#include "CharTest.h"

#include <iostream>
using namespace std;

char* CharTest::_strupr(char* src)
{
	char* s = src;
	while (*s != '\0')
	{
		if (*s >= 'a' && *s <= 'z')
		{
			*s -= 32;
		}
		s++;
	};
	cout << endl << src << std::endl;
	return src;
}
