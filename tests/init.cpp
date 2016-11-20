#include "sort.hpp"
#include <catch.hpp>

SCENARIO("memory_small", "memory_small]"){
  	allsort("name.txt", 2);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("name_test.txt");
	std::string temp1;
	std::string temp2;
	bool Q = true;
	size_t t = 0;
	std::getline(file1, temp1);
	while (!file1.eof() && !file2.eof()) {
		std::getline(file1, temp1);
		std::getline(file2, temp2);
		if (temp1 != temp2) {
			REQUIRE(temp1 != temp2);
      			Q = false;
      			break;
		}
		++t;
	}
	REQUIRE(t == 56972);
  	REQUIRE(Q);
  	file1.close();
  	file2.close();
}

SCENARIO("memory_normal", "[memory_normal]"){
  	allsort("name.txt", 678);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("name_test.txt");
	std::string temp1;
	std::string temp2;
	bool Q = true;
	size_t t = 0;
	std::getline(file1, temp1);
	while (!file1.eof() && !file2.eof()) {
		std::getline(file1, temp1);
		std::getline(file2, temp2);
		if (temp1 != temp2) {
			REQUIRE(temp1 != temp2);
      			Q = false;
      			break;
		}
		++t;
	}
	REQUIRE(t == 56972);
  	REQUIRE(Q);
  	file1.close();
  	file2.close();
}

SCENARIO("memory_big", "[memory_big]"){
  	allsort("name.txt", 5677);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("name_test.txt");
	std::string temp1;
	std::string temp2;
	bool Q = true;
	size_t t = 0;
	std::getline(file1, temp1);
	while (!file1.eof() && !file2.eof()) {
		std::getline(file1, temp1);
		std::getline(file2, temp2);
		if (temp1 != temp2) {
			REQUIRE(temp1 != temp2);
      			Q = false;
      			break;
		}
		++t;
	}
	REQUIRE(t == 56972);
  	REQUIRE(Q);
  	file1.close();
  	file2.close();
}

SCENARIO("memory_very_big", "[memory_very_big]"){
  	allsort("name.txt", 34567);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("name_test.txt");
	std::string temp1;
	std::string temp2;
	bool Q = true;
	size_t t = 0;
	std::getline(file1, temp1);
	while (!file1.eof() && !file2.eof()) {
		std::getline(file1, temp1);
		std::getline(file2, temp2);
		if (temp1 != temp2) {
			REQUIRE(temp1 != temp2);
      			Q = false;
      			break;
		}
		++t;
	}
	REQUIRE(t == 56972);
  	REQUIRE(Q);
  	file1.close();
  	file2.close();
}
