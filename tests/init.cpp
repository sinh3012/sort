#include "sort.hpp"
#include <catch.hpp>

SCENARIO("file_small", "file_small]"){
  	allsort("8", 2);
	std::ifstream file1("sorted.txt");
	std::string temp1;
	size_t t = 0;
	std::getline(file1, temp1);
	while(!file1.eof()) {
		std::getline(file1, temp1);
		if (temp1!="") {
			++t;
		}
		else break;
	}
	REQUIRE(t == 422453);
  	file1.close();
}
SCENARIO("file_normal", "file_normal]"){
  	allsort("15", 4);
	std::ifstream file1("sorted.txt");
	std::string temp1;
	size_t t = 0;
	std::getline(file1, temp1);
	while(!file1.eof()) {
		std::getline(file1, temp1);
		if (temp1!="") {
			++t;
		}
		else break;
	}
	REQUIRE(t == 791948);
  	file1.close();
}
SCENARIO("file_big", "file_big]"){
  	allsort("32", 8);
	std::ifstream file1("sorted.txt");
	std::string temp1;
	size_t t = 0;
	std::getline(file1, temp1);
	while(!file1.eof()) {
		std::getline(file1, temp1);
		if (temp1!="") {
			++t;
		}
		else break;
	}
	REQUIRE(t == 1637032);
  	file1.close();
}
