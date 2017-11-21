// part7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
int vint = 10;
char vchar = 'c';

typedef void(*MY_FUNC)(char *ch, int &v);

void f(char *ch, int &v);

MY_FUNC fuk = &f;

void g(MY_FUNC some) {
	some(&vchar, vint);
}

MY_FUNC h(MY_FUNC some)
{
	return some;
}

void f(char *ch, int &v) {
	std::cout << *ch << " " << v << "\n";
}

int main()
{
	g(h(fuk));
	system("Pause");
    return 0;
}

