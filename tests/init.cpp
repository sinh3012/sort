#include "sort.hpp"
#include <catch.hpp>

SCENARIO("memory_very_small", "memory_very_small]"){
  	allsort("name.txt", 1);
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
