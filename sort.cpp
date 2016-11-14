// sort.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <algorithm>
//#include <ctime>

std::string filename = "C:\\Users\\A\\Documents\\Visual Studio 2015\\Projects\\sort\\out_name_test.txt";
size_t sizefile = 160000;
size_t memory = 10000;
size_t count = sizefile / memory;

template <typename T>
std::string toString(T value)
{
	std::stringstream oss;
	oss << value << "_temp.txt";
	return oss.str();
}

bool byString(const std::string& a, std::string& b) { return a < b; }
size_t byString4(const std::string& a, std::string& b, std::string& c, std::string& d)
{
	size_t t;
	bool ab = byString(a, b), ac = byString(a, c), ad = byString(a, d),
		bc = byString(b, c), bd = byString(b, d), cd = byString(c, d);
	if (ab && ac && ad) { return t = 1; }
	else if (!ab && bc && bd) { return t = 2; }
	else if (!ac && !bc && cd) { return t = 3; }
	else return t = 4;
}

void piece(std::string const name, size_t count_, size_t mem) {
	std::ifstream file(name);
	std::ofstream tempfile;
	std::string temp;
	std::vector<std::string> str;
	for (size_t t = 0; t < count_; ++t) {
		tempfile.open((toString(t+count*100)));
		for (size_t tt = 0; tt < mem; ++tt) {
			std::getline(file, temp);
			str.push_back(temp);
		}
		std::sort(str.begin(), str.end(), byString);
		for (auto i : str) {
			tempfile << i << std::endl;
		}
		str.clear();
		tempfile.close();
	}
	file.close();
}

void merge2(std::string strfile1, std::string strfile2, std::string strtempfile, size_t mem) {
	std::ifstream file1(strfile1);
	std::ifstream file2(strfile2);
	std::ofstream tempfile(strtempfile);
	std::string temp1;
	std::string temp2;
	size_t t1 = mem, t2 = mem;	
	std::getline(file1, temp1);
	std::getline(file2, temp2);
	while (true) {
		if (byString(temp1, temp2)) {
			tempfile << temp1 << std::endl;
			if (--t1) {
				std::getline(file1, temp1);
			}
			else break;
		}
		else {
			tempfile << temp2 << std::endl;
			if (--t2) {
				std::getline(file2, temp2);
			}
			else break;
		}
	}
	while(t1 > 0) {
		tempfile << temp1 << std::endl;
		std::getline(file1, temp1);
		--t1;
	}
	while (t2 > 0) {
		tempfile << temp2 << std::endl;
		std::getline(file2, temp2);
		--t2;
	}
	file1.close();
	file2.close();
	tempfile.close();
}

void merge4(std::string strfile1, std::string strfile2, std::string strfile3, std::string strfile4, std::string strtempfile, size_t mem) {
	std::ifstream file1(strfile1);
	std::ifstream file2(strfile2);
	std::ifstream file3(strfile3);
	std::ifstream file4(strfile4);
	std::ofstream tempfile(strtempfile);
	std::string temp1;
	std::string temp2;
	std::string temp3;
	std::string temp4;
	size_t t1 = mem, t2 = mem, t3 = mem, t4 = mem;
	std::getline(file1, temp1);
	std::getline(file2, temp2);
	std::getline(file3, temp3);
	std::getline(file4, temp4);
	while (t1 > 0 || t2 > 0 || t3 > 0 || t4 > 0) {
		if (byString4(temp1, temp2, temp3, temp4) == 1) {
			tempfile << temp1 << std::endl;
			if (--t1) {
				std::getline(file1, temp1);
			}
			else temp1 = "ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ";
		}
		else if (byString4(temp1, temp2, temp3, temp4) == 2) {
			tempfile << temp2 << std::endl;
			if (--t2) {
				std::getline(file2, temp2);
			}
			else temp2 = "ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ";
		}
		else if (byString4(temp1, temp2, temp3, temp4) == 3) {
			tempfile << temp3 << std::endl;
			if (--t3) {
				std::getline(file3, temp3);
			}
			else temp3 = "ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ";
		}
		else {
			tempfile << temp4 << std::endl;
			if (--t4) {
				std::getline(file4, temp4);
			}
			else temp4 = "ßÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ";
		}
	}
	file1.close();
	file2.close();
	file3.close();
	file4.close();
	tempfile.close();
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*std::ifstream file(filename);
	std::ofstream tempfile;
	tempfile.open("C:\\Users\\A\\Documents\\Visual Studio 2015\\Projects\\sort\\out.txt");
	std::string temp;
	std::vector<std::string> str;
	for (size_t t = 0; t < sizefile; ++t) {
		std::getline(file, temp);
		str.push_back(temp);
	}
	std::sort(str.begin(), str.end(), byString);
	for (auto i : str) {
		tempfile << i << std::endl;
	}
	file.close();
	tempfile.close();*/
	//unsigned int start_time = clock();
	piece(filename, count, memory);
	while (count / 4 > 1 && count % 4 == 0) {
		for (size_t t = 0; t < count / 4; ++t) {
			merge4(toString(count * 100 + 4 * t), toString(count * 100 + 4 * t + 1), toString(count * 100 + 4 * t + 2),
				toString(count * 100 + 4 * t + 3), toString(t + count * 25), memory);
		}
		memory *= 4;
		count /= 4;
	}
	while (count != 1) {
		for (size_t t = 0; t < count / 2; ++t) {
			merge2(toString(count * 100 + 2 * t), toString(count * 100 + 2 * t + 1), toString(t + count * 50), memory);
		}
		memory *= 2;
		count /= 2;
	}
	//unsigned int end_time = clock(); 
	//unsigned int search_time = end_time - start_time;
	//std::cout << search_time << std::endl;
	system("pause");
    return 0;
}

