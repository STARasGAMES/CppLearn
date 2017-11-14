// L1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <complex>
#include <limits>

char ch;
std::string s;
int count = 1;
const double pi = 3.1415926535897932385;
extern int err_number;
int err_number = 10;
const char* name = "Njal";
const char* season[] = { "spring", "summer" , "fall", "winter" };
struct Date { int d, m, y; };
int day(Date* p) { return p->d; }
double sqrt(double);
double sqrt(double s) {
	return s / 2;
}
typedef std::complex<short> Point;
struct User;
struct User {
	std::string name;
	std::string password;
	int phone_number;
};
User someStructVar;
enum Beer {
	Carlsberg, Tuborg, Thor
};
namespace NS { int a; }

template<typename T> void WriteLimits();


int main()
{

	std::cout << "Hello, World!\n";
	std::cout << "Sizeof User:" << sizeof(User) << ",\nsizeof long:" << sizeof(long long)
		<< ",\nsizeof int:" << sizeof(short) << "\n";
	for (char i = int('a'); i <= int('z'); i++)
	{
		std::cout << char(i);
	}
	std::cout << "\n";
	for (char i = int('0'); i <= int('9'); i++)
	{
		std::cout << "Char: " << i << ", value: " << int(i) << "\n";
	}
	WriteLimits<long long>();
	WriteLimits<char>();
	WriteLimits<short>();
	WriteLimits<int>();
	WriteLimits<long>();
	WriteLimits<float>();
	WriteLimits<double>();
	WriteLimits<long double>();
	WriteLimits<unsigned>();
	system("Pause");
	return 0;
}


template<typename T> void WriteLimits() {
	std::cout << "Type name: " << typeid(T).name()
		<< ", min: " << std::numeric_limits<T>().min()
		<< ", max: " << std::numeric_limits<T>().max()
		<< "\n";
}


