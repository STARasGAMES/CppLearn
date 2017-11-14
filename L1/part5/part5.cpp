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


int main()
{
	std::cout
		<< constantInt << "\n"
		<< *pointerToConstantInt << "\n"
		<< *pointerToIntConstant << "\n"
		;
	pointerToConstantInt = &constantInt2;
	std::cout
		<< constantInt << "\n"
		<< *pointerToConstantInt << "\n"
		<< *pointerToIntConstant << "\n"
		;
	system("Pause");
    return 0;
}

