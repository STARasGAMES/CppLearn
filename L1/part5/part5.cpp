// part5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

char someChar = '3';
char arrayOfChar[] = "someshet";
char* pointerToChar = &someChar;
char* pointerToArrayOfChar = &arrayOfChar[1];
char* pointerToPointerToChar = pointerToChar;
int arrayOfInt[10];
int *pointerToArrayOfInt = arrayOfInt;

const int constantInt = 1;
const int constantInt2 = 2;
 int constantInt3 = 3;
const int* pointerToConstantInt = &constantInt;
const int* const pointerToIntConstant = &constantInt;

typedef unsigned char Uchar;
typedef const Uchar C_Uchar;
typedef int* Pint;
typedef char** P_Pchar;
typedef char* Pchar;
typedef Pint ArrOfPint[7];
typedef ArrOfPint* PArrOfPint;
typedef ArrOfPint ArrOfArrOfPint[8];

void swap1(int* a, int* b) {
	int buf = *a;
	*a = *b;
	*b = buf;
}

void swap2(int& a, int& b) {
	int buf = a;
	a = b;
	b = buf;
}

char str[] = "a shord string";

void f(char c) {}
void g(char& c) {}
void h(const char& c) {}


struct Month {
	char* name;
	int countOfDays;
};
Month months[] = {
	{ "Marth", 31 },
	{ "May", 31 },
	{ "December", 31 }
};

void writeAllMonths(Month* a, int size) {
	int i = 0;
	while (size > i++) {
		std::cout << (*a++).name << "\n";
	}
	/*for (int i = 0; i < size; i++)
	{
		std::cout << a[i].name << "\n";
	}*/
}

int main()
{
	writeAllMonths(months, 3);

	/*typedef char* arrayOfChar[2];
	arrayOfChar month = { "Martch", "May" };
	int daysAtMonth[] = { 31, 31 };
	for (int i = 0; i < 2; i++)
	{
		std::cout << month[i] << " " << daysAtMonth[i] << "\n";
	}

	
	Month* pointer = months;
	for (int i = 0; i < 3; i++)
	{
		std::cout << pointer->name << " " << pointer->countOfDays << "\n";
		++pointer;
	}*/

	/* // 'a'
	f('a');
	//g('a'); ERROR 'a' is constant and char& is not a constant reference
	h('a');
	// 49
	f(49);
	//g(49); ERROR 49 is constant and char& is not a constant reference
	h(49);
	//3300
	f(3300);
	//g(3300); ERROR 3300 is constant and char& is not a constant reference
	h(3300);
	char c = 'c';
	f(c);
	g(c);
	h(c);
	unsigned char uc = 'd';
	f(uc);
	//g(uc); ERROR
	h(uc);
	signed char sc = 'd';
	f(sc);
	//g(sc); ERROR
	h(sc);*/

	//std::cout<<sizeof(str);
	/*int a = 3;
	int b = 10; 
	std::cout << a << " " << b << "\n";
	swap1(&a, &b);
	std::cout << a << " " << b << "\n";
	swap2(a, b);
	std::cout << a << " " << b << "\n";*/

	/*std::cout
		<< constantInt << "\n"
		<< *pointerToConstantInt << "\n"
		<< *pointerToIntConstant << "\n"
		;
	pointerToConstantInt = &constantInt2;
	std::cout
		<< constantInt << "\n"
		<< *pointerToConstantInt << "\n"
		<< *pointerToIntConstant << "\n"
		;*/
	system("Pause");
    return 0;
}

