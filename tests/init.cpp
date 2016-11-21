#include "sort.hpp"
#include <catch.hpp>

SCENARIO("memory_very_small", "memory_very_small]"){
  	allsort("name1.txt", 3);
	std::ifstream file1("sorted.txt");
	std::string temp1;
	size_t t = 0;
	std::getline(file1, temp1);
	while (!file1.eof()) {
		std::getline(file1, temp1);
		++t;
	}
	REQUIRE(t == 1069553);
  	file1.close();
}
/*
SCENARIO("memory_small", "memory_small]"){
  	allsort("name1.txt", 2);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("name1_test.txt");
	std::string temp1;
	std::string temp2;
	bool Q = true;
	size_t t = 0;
	//std::getline(file1, temp1);
	std::getline(file2, temp2);
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
	REQUIRE(t == 1069553);
  	REQUIRE(Q);
  	file1.close();
  	file2.close();
}

SCENARIO("memory_normal", "memory_normal]"){
  	allsort("name1.txt", 4);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("name1_test.txt");
	std::string temp1;
	std::string temp2;
	bool Q = true;
	size_t t = 0;
	//std::getline(file1, temp1);
	std::getline(file2, temp2);
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
	REQUIRE(t == 1069553);
  	REQUIRE(Q);
  	file1.close();
  	file2.close();
}

SCENARIO("memory_big", "memory_big]"){
  	allsort("name1.txt", 8);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("name1_test.txt");
	std::string temp1;
	std::string temp2;
	bool Q = true;
	size_t t = 0;
	//std::getline(file1, temp1);
	std::getline(file2, temp2);
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
	REQUIRE(t == 1069553);
  	REQUIRE(Q);
  	file1.close();
  	file2.close();
}
*/
