//#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <queue>
//#include <windows.h>

template <typename T>
auto toString(T value) -> std::string
{
	std::stringstream oss;
	oss << value << "_temp.txt";
	return oss.str();
}
auto piece(std::string const name, size_t memory_) -> size_t
{
	std::ifstream file(name);
	if (!file.is_open()) throw("no_file");
	std::ofstream tempfile;
	std::string temp;
	std::vector<std::string> str;
	size_t t = 0;
	while (!file.eof()) {
		tempfile.open((toString(t + memory_ * 100000)));
		for (size_t tt = 0; tt < memory_; ++tt) {
			if (file.eof()) break;
			std::getline(file, temp);
			str.push_back(temp);
		}
		std::sort(str.begin(), str.end());
		for (size_t tt = 0; tt < str.size() - 1; ++tt) {
			tempfile << str[tt] << std::endl;
		}
		tempfile << str[str.size() - 1];
		str.clear();
		tempfile.close();
		++t;
	}
	file.close();
	return t;
}

struct file_str
{
	file_str(std::ifstream* file, std::string& str) : file_(file), str_(str) {}
	std::ifstream* file_;
	std::string str_;
};

auto operator < (const file_str& fs1, const file_str& fs2) -> bool { return fs1.str_ > fs2.str_; }

auto merge(size_t memory_, size_t piece_, std::string strtempfile) -> void
{
	std::ifstream** files = new std::ifstream*[piece_];
	std::ofstream tempfile("temp.txt");
	std::string temp;
	std::priority_queue<file_str> q;
	for (size_t t = 0; t < piece_; ++t) {
		files[t] = new std::ifstream(toString(t + memory_ * 100000));
		std::getline(*files[t], temp);
		q.push(file_str(files[t], temp));
	}
	while (q.size() != 1) {
		file_str fs = q.top();
		tempfile << fs.str_ << std::endl;
		q.pop();
		if (!(*fs.file_).eof()) {
			std::getline(*fs.file_, temp);
			q.push(file_str(fs.file_, temp));
		}
		else (*fs.file_).close();
	}
	file_str fs = q.top();
	tempfile << fs.str_;
	q.pop();
	(*fs.file_).close();
	for (size_t t = 0; t < piece_; ++t) {
		delete files[t];
		remove(toString(t + memory_ * 100000).c_str());
	}
	delete files;
	remove(strtempfile.c_str());
	tempfile.close();
	rename("temp.txt", strtempfile.c_str());
}

auto allsort(std::string filename_, size_t memorymbyte_, std::string outfile = "sorted.txt") -> void
{
	size_t mem_ = memorymbyte_ * 1024 * 1024 / sizeof(std::string);
	merge(mem_, piece(filename_, mem_), outfile);
}
/*
void main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (argc == 3) {
		allsort(static_cast<std::string>(argv[1]), std::atoi(argv[2]));
		system("pause");
	}
	else if (argc == 4 && static_cast<std::string>(argv[1]) == "test") {
		std::string filename1 = argv[2];
		std::string filename2 = argv[3];
		std::ifstream file1(filename1);
		std::ifstream file2(filename2);
		std::string temp1;
		std::string temp2;
		size_t t = 0;
		while (true) {
			if (file1.eof() || file2.eof()) break;
			std::getline(file1, temp1);
			std::getline(file2, temp2);
			if (temp1 != temp2) {
				std::cout << "Error " << t << " " << temp1 << " " << temp2 << std::endl;
				system("pause");
			}
		}
		system("pause");
	}
	else {
		std::cout << "Неверные входные параметры" << std::endl;
		system("pause");
	}
}*/

