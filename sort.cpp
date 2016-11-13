// sort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream last_name("C:\\Users\\A\\Documents\\Visual Studio 2015\\Projects\\sort\\Фамилии.txt");
	std::string last[503];
	std::ifstream male_first_name("C:\\Users\\A\\Documents\\Visual Studio 2015\\Projects\\sort\\Мужские имена.txt");
	std::string male[100];
	std::ifstream female_first_name("C:\\Users\\A\\Documents\\Visual Studio 2015\\Projects\\sort\\Женские имена.txt");
	std::string female[100];
	size_t t = 0;
	while (!last_name.eof() ) {
		std::getline(last_name, last[t]);
		++t;
	}
	std::cout << t << std::endl;
	t = 0;
	last_name.close();
	while (!male_first_name.eof()) {
		std::getline(male_first_name, male[t]);
		++t;
	}
	std::cout << t << std::endl;
	t = 0;
	male_first_name.close();
	while (!female_first_name.eof()) {
		std::getline(female_first_name, female[t]);
		++t;
	}
	std::cout << t << std::endl;
	t = 0;
	female_first_name.close();

	std::ofstream out_name("C:\\Users\\A\\Documents\\Visual Studio 2015\\Projects\\sort\\out_name.txt");
	for (size_t i = 0; i < 800; ++i) {
		std::cout << i << std::endl;
		out_name << last[rand() % 503];
		if (rand() % 2)	{
			out_name << " " << male[rand() % 100] << " " << rand()%116+1900 << std::endl;
		}
		else {
			out_name << "a " << female[rand() % 100] << " " << rand() % 116 + 1900 << std::endl;
		}
	}
	out_name.close();
	system("pause");
    return 0;
}

