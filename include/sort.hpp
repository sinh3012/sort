#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
//include <windows.h>
template <typename T>
std::string toString(T value)
{
	std::stringstream oss;
	oss << value << "_temp.txt";
	return oss.str();
}

bool byString(const std::string& a, std::string& b) { return a < b; }

void piece(std::string const name, size_t count_, size_t memory_) {
	std::ifstream file(name);
	if (!file.is_open()) throw("no_file");
	std::ofstream tempfile;
	std::string temp;
	std::vector<std::string> str;
	for (size_t t = 0; t < count_; ++t) {
		tempfile.open((toString(t + memory_ * 100)));
		for (size_t tt = 0; tt < memory_; ++tt) {
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

void merge2(std::string strfile1, std::string strfile2, std::string strtempfile, size_t mem1, size_t mem2 ) {
	std::ifstream file1(strfile1);
	std::ifstream file2(strfile2);
	std::ofstream tempfile(strtempfile);
	std::string temp1;
	std::string temp2;
	size_t t1 = mem1, t2 = mem2;
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
	while (t1 > 0) {
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
	remove(strfile1.c_str());
	remove(strfile2.c_str());
	tempfile.close();
}
/*void merge(size_t count, std::string strtempfile, size_t mem) {
	std::ifstream *p = new std::ifstream[count];
	std::string *ps = new std::string[count];
	size_t *k = new size_t[count];
	for (size_t t = 0; t < count; ++t) {
		p[t].open(toString(t + count * 100));
		std::getline(p[t], ps[t]);
		k[t] = mem;
	}
	std::ofstream tempfile(strtempfile);
	while ( {
	}
	file1.close();
	file2.close();
	remove(strfile1.c_str());
	remove(strfile2.c_str());
	tempfile.close();
}

*/
void allsort(std::string filename_, size_t count_, size_t memory_) 
{
	piece(filename_, count_, memory_);
	size_t num_ = (count_ / 2) * 2;
	size_t mem_ = memory_;
	while (num_ != 1) {
		for (size_t t = 0; t < num_ / 2; ++t) {
			merge2(toString(mem_ * 100 + 2 * t), toString(mem_ * 100 + 2 * t + 1), toString(t + mem_ * 200), mem_, mem_);
		}
		mem_ *= 2;
		num_ /= 2;
	}
	if (count_ % 2 == 1) {
		merge2(toString(100 * mem_), toString(100 * memory_ + count_ - 1), "sorted.txt", mem_, memory_);
	}
	else {
		remove("sorted.txt");
		rename(toString(mem_ * 100).c_str(), "sorted.txt");
	}
}
void mysort()
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	std::string filename = "out_name.txt";
	size_t sizefile = 800;
	size_t memory = 100;
	allsort(filename, sizefile / memory, memory);
	system("pause");
	return 0;
}

