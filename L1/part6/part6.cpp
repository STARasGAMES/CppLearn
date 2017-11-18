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

int main()
{
	char s[] = "";
	char s2[10];
	char s3[] = "";
	std::cout << strlen(s) << "\n";
	strcpy1(s, s2);
	std::cout << s2 << "\n";
	std::cout << (strcmp(s, s3) ? "Equal" : "not Equal") << "\n";
	std::system("Pause");
	return 0;
}

