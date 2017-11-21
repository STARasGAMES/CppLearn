// part7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
int vint = 10;
char vchar = 'c';

void f(char *ch, int &v);

void(*fuk)(char *ch, int &v) = &f;

void g(void(*some)(char *ch, int &v)) {
	some(&vchar, vint);
}

void f(char *ch, int &v) {
	std::cout << *ch << " " << v << "\n";
}

int main()
{
	g(fuk);
	system("Pause");
    return 0;
}

