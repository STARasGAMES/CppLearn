// part5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

int countOfStr(std::string s, std::string s2) {
	int res = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		bool find = true;
		for (size_t j = 0, const n2 = s2.length(); j < n2; j++)
		{
			if (s[i + j] != s2[j]) {
				find = false;
				break;
			}
		}
		res += find;
	}
	return res;
}

int countOfStrC(char *s, char *s2) {
	int res = 0;
	int i = 0;
	for (char *p1 = s; *p1 != 0; p1++) {
		bool find = true;
		for (size_t i = 0; *(s2+i)!=0; i++)
		{
			if (*(p1+i) != *(s2 + i))
			{
				find = false;
				break;
			}
		}
		std::cout << "\n";
		res += find;
	}
	std::cout << "\n";
	return res;
}

int main()
{
	char s1[] = "xabaacbaxabb";
	char s2[] = "ab";
	std::cout << countOfStrC(s1, s2);
	system("Pause");
	return 0;
}

