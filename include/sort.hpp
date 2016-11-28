// sort.cpp: определяет точку входа для консольного приложения.
//

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
//#include <forward_list>

template <typename T>
auto toString(T value) -> std::string
{
	std::stringstream oss;
	oss << value << "_temp.txt";
	return oss.str();
}

struct mydata
{
	std::string fn;
	std::string ln;
	short y;
};

auto operator < (const mydata& d1, const mydata& d2) -> bool { return d1.fn < d2.fn; }

auto operator > (const mydata& d1, const mydata& d2) -> bool { return d1.fn > d2.fn; }

auto piecenew(std::string const name, size_t memory_) -> size_t
{
	std::ifstream file(name);
	if (!file.is_open()) throw("no_file");
	std::ofstream tempfile;
	mydata temp;
	std::vector<mydata> str;
	str.reserve(memory_);
	size_t t = 0;
	while (!file.eof()) {
		tempfile.open((toString(t + memory_ * 100000)));
		for (size_t tt = 0; tt < memory_; ++tt) {
			file >> temp.ln;
			file >> temp.fn;
			file >> temp.y;
			if (file.eof()) break;
			str.push_back(temp);
		}
		std::sort(str.begin(), str.end());
		for (size_t tt = 0; tt < str.size() - 1; ++tt) {
			tempfile << str[tt].ln << ' ' << str[tt].fn << ' ' << str[tt].y << std::endl;
		}
		tempfile << str[str.size() - 1].ln << ' ' << str[str.size() - 1].fn << ' ' << str[str.size() - 1].y;
		str.clear();
		tempfile.close();
		++t;
	}
	file.close();
	return t;
}

struct file_d
{
	file_d(std::ifstream* file, mydata data) : file_(file), data_(data) {}
	std::ifstream* file_;
	mydata data_;
};

auto operator < (const file_d& fd1, const file_d& fd2) -> bool { return fd1.data_ > fd2.data_; }

auto mergenew(size_t memory_, size_t piece_, std::string strtempfile) -> void
{
	std::ifstream** files = new std::ifstream*[piece_];
	std::ofstream tempfile("temp.txt");
	mydata d;
	std::priority_queue<file_d> q;
	for (size_t t = 0; t < piece_; ++t) {
		files[t] = new std::ifstream(toString(t + memory_ * 100000));
		*files[t] >> d.ln;
		*files[t] >> d.fn;
		*files[t] >> d.y;
		q.push(file_d(files[t], d));
	}
	while (!q.empty()) {
		file_d fs = q.top();
		tempfile << fs.data_.ln << ' ' << fs.data_.fn << ' ' << fs.data_.y << std::endl;
		q.pop();
		if (!(*fs.file_).eof()) {
			*fs.file_ >> d.ln;
			*fs.file_ >> d.fn;
			*fs.file_ >> d.y;
			q.push(file_d(fs.file_, d));
		}
		else (*fs.file_).close();
	}
	for (size_t t = 0; t < piece_; ++t) {
		delete files[t];
		remove(toString(t + memory_ * 100000).c_str());
	}
	delete[] files;
	remove(strtempfile.c_str());
	tempfile.close();
	rename("temp.txt", strtempfile.c_str());
}


auto allsort(std::string filename_, size_t memorymbyte_, std::string outfile = "sorted.txt") -> void
{
	size_t mem_ = memorymbyte_ * 1024 * 1024 / (2 * sizeof(std::string) + sizeof(short));
	mem_ = mem_ * 0.6;
	mergenew(mem_, piecenew(filename_, mem_), outfile);
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
