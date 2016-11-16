#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
//#include <windows.h>

template <typename T>
auto toString(T value) -> std::string //создаем название временного файла
{
	std::stringstream oss;
	oss << value << "_temp.txt";
	return oss.str();
}

auto byString(const std::string& a, std::string& b) -> bool { return a < b; }

auto piece(std::string const name, size_t memory_) -> size_t //разделяем исходный файл на отсортированнные
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
		std::sort(str.begin(), str.end(), byString);
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

auto merge2(std::string strfile1, std::string strfile2, std::string strtempfile) -> void //сливаем 2 файла
{
	std::ifstream file1(strfile1);
	std::ifstream file2(strfile2);
	std::ofstream tempfile("temp.txt");
	std::string temp1;
	std::string temp2;
	std::getline(file1, temp1);
	std::getline(file2, temp2);
	bool k1 = true, k2 = true;
	while (k1 && k2) {
		if (byString(temp1, temp2)) {
			tempfile << temp1 << std::endl;
			k1 = false;
			if (!file1.eof()) {
				std::getline(file1, temp1);
				k1 = true;
			}
		}
		else {
			tempfile << temp2 << std::endl;
			k2 = false;
			if (!file2.eof()) {
				std::getline(file2, temp2);
				k2 = true;
			}
		}
	}
	while (k1) {
		tempfile << temp1;
		k1 = false;
		if (!file1.eof()) {
			tempfile << std::endl;
			std::getline(file1, temp1);
			k1 = true;
		}
	}
	while (k2) {
		tempfile << temp2;
		k2 = false;
		if (!file2.eof()) {
			tempfile << std::endl;
			std::getline(file2, temp2);
			k2 = true;
		}
	}
	file1.close();
	file2.close();
	remove(strfile1.c_str());
	remove(strfile2.c_str());
	remove(strtempfile.c_str());
	tempfile.close();
	rename("temp.txt", strtempfile.c_str());
}

auto allsort(std::string filename_, size_t memory_) -> void 
{

	size_t num_ = piece(filename_, memory_);
	size_t mem_ = memory_;
	while (num_ != 1) {
		for (size_t t = 0; t < num_ / 2; ++t) {
			merge2(toString(mem_ * 100000 + 2 * t), toString(mem_ * 100000 + 2 * t + 1), toString(t + mem_ * 200000));
		}
		if (num_ % 2 == 1) {
			merge2(toString(mem_ * 200000), toString(mem_ * 100000 + num_ - 1), toString(mem_ * 200000));
		}
		mem_ *= 2;
		num_ /= 2;
	}
	remove("sorted.txt");
	rename(toString(mem_ * 100000).c_str(), "sorted.txt");
}

void main(int argc, char* argv[])
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	if (argc == 3) {
		allsort(static_cast<std::string>(argv[1]), std::atoi(argv[2]));
		system("pause");
	}
	else if (argc == 4 && static_cast<std::string>(argv[1]) == "test") { //сравниваем содержимое 2 файлов
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
}
