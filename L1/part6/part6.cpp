// part6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int strlen(char* s) 
{
	int len = 0;
	while (*s++)
		len++;
	return len;
}

void strcpy1(char* from, char* to)
{
	while (*(to++) = *(from++));
}

bool strcmp(char* s1, char* s2)
{
	while (*(s1++) != 0 & *(s2++) != 0 & *s1==*s2);
	return *s1 == *s2;
}

char* cat(const char* s1, const char* s2)
{
	char* res = new char[strlen(s1) + strlen(s2) + 1];
	char* start = res;
	while (*(res++) = *s1, *(s1++));
	res--;
	while (*(res++) = *s2, *(s2++));
	return start;
}

void rev(char* s)
{
	char* l = s;
	char* r = s + strlen(s) - 1;
	do {
		char buf = *l;
		*l = *r;
		*r = buf;
	} while (++l < --r);
}

char* revc(char* s)
{
	int len = strlen(s);
	char* res = new char[len + 1];
	char* p = res + len;
	*(p--) = 0;
	while (*(p--) = *s, *(++s));
	return res;
}

int main()
{
	char s[] = "str1";
	char s2[] = "str2";
	std::cout << "Output 1: '" << cat(s, s2) << "'\n";
	rev(s);
	std::cout << "Output 2: '" << s << "'\n";
	std::cout << "Output 3: '" << revc(s) << "'\n";
	std::system("Pause");
	return 0;
}

