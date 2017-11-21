// part7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdarg>


void write(std::string *names, std::string * ...)
{
	va_list a;
	va_start(a, names);
	for (;;)
	{
		std::string *p = va_arg(a, std::string*);
		std::cout << p << "\n";
		if (p == 0) break;
		std::cout << "Hello, " << (*p) << "!\n";
	}
	va_end(a);
}

int main()
{
	while (std::cin)
	{
		std::string s;
		std::cin >> s;
		write(&s, &s, &s, &s);
	}
	system("Pause");
    return 0;
}

