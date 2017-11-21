// part7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>


int main()
{
	std::ifstream myfile;
	
	while (std::cin)
	{
		std::string s;
		std::cin >> s;
		if (myfile.is_open())
			myfile.close();
		myfile.open(s);
		if (!myfile.is_open())
		{
			std::cout << "Unable to open file '" + s + "'\n";
			continue;
		}
		std::string line;
		while (std::getline(myfile, line))
			std::cout << line << '\n';
	}
	system("Pause");
    return 0;
}

