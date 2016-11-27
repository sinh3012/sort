#include "sort.hpp"
#include <catch.hpp>

SCENARIO("file_small", "file_small]"){
  	allsort("8", 2);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("8_test.txt");
	std::string temp1;
	std::string temp2;
	bool Q = true;
	size_t m = 0;
	std::getline(file1, temp1);
	for (size_t t = 0; t < 422453; ++t) {
		std::getline(file1, temp1);
		std::getline(file2, temp2);
		if (temp1 != temp2) {
			REQUIRE(temp1 != temp2);
      			Q = false;
      			//break;
		}
		m=t;
	}
	REQUIRE(m == 422453);
  	REQUIRE(Q);
  	file1.close();
  	file2.close();
}
SCENARIO("file_normal", "file_normal]"){
  	allsort("15", 4);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("15_test.txt");
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
	REQUIRE(t == 791948);
  	REQUIRE(Q);
  	file1.close();
  	file2.close();
}

SCENARIO("memory_20", "memory_20]"){
  	allsort("name1.txt", 8);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("name1_test.txt");
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
	REQUIRE(t == 1069553);
  	REQUIRE(Q);
  	file1.close();
  	file2.close();
}
