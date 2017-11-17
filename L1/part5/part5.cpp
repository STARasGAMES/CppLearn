// part5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

struct Date {
	int day, month, year;
};

Date inputDate() 
{
	Date res;
	std::cout << "Input day month and year\n";
	std::cin >> res.day >> res.month >> res.year;
	return res;
}

void outputDate(Date& date)
{
	std::cout << date.day << "." << date.month << "." << date.year << "\n";
}

int main()
{
	Date date = inputDate();
	outputDate(date);
	system("Pause");
	return 0;
}

