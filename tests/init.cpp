#include "sort.hpp"
#include <catch.hpp>
#include <chrono>

SCENARIO("file_small", "file_small]"){
	auto start = std::chrono::system_clock::now();
  	allsort("8", 1);
	auto end = std::chrono::system_clock::now();
	std::cout <<
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::ifstream file1("sorted.txt");
	std::string temp1;
	size_t t = 0;
	std::getline(file1, temp1);
	while(!file1.eof()) {
		std::getline(file1, temp1);
		++t;
	}
	REQUIRE(t == 422491+1);
  	file1.close();
}

SCENARIO("file_normal", "file_normal]"){
	auto start = std::chrono::system_clock::now();
  	allsort("15", 4);
	auto end = std::chrono::system_clock::now();
	std::cout <<
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::ifstream file1("sorted.txt");
	std::string temp1;
	size_t t = 0;
	std::getline(file1, temp1);
	while(!file1.eof()) {
		std::getline(file1, temp1);
		++t;
	}
	REQUIRE(t == 792010+1);
  	file1.close();
}

SCENARIO("file_big", "file_big]"){
	auto start = std::chrono::system_clock::now();
  	allsort("32", 17);
	auto end = std::chrono::system_clock::now();
	std::cout <<
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::ifstream file1("sorted.txt");
	std::string temp1;
	size_t t = 0;
	std::getline(file1, temp1);
	while(!file1.eof()) {
		std::getline(file1, temp1);
		++t;
	}
	REQUIRE(t == 1637031+1);
  	file1.close();
}
