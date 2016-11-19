#include "sort.hpp"
#include <catch.hpp>

SCENARIO("mem213", "[mem213]"){
  allsort("name.txt", 213);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("sorted_test.txt");
	std::string temp1;
	std::string temp2;
	bool Q = true;;
	while (!file1.eof() && !file2.eof()) {
		std::getline(file1, temp1);
		std::getline(file2, temp2);
		if (temp1 != temp2) {
      Q=false;
      break;
		}
  REQUIRE(Q);
  file1.close();
  file2.close();
  }
}

SCENARIO("mem2050", "[mem2050]"){
  allsort("name.txt", 2500);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("sorted_test.txt");
	std::string temp1;
	std::string temp2;
	bool Q = true;;
	while (!file1.eof() && !file2.eof()) {
		std::getline(file1, temp1);
		std::getline(file2, temp2);
		if (temp1 != temp2) {
      Q=false;
      break;
		}
  REQUIRE(Q);
  file1.close();
  file2.close();
  }
}

SCENARIO("mem23456", "[mem23456]"){
  allsort("name.txt", 23456);
	std::ifstream file1("sorted.txt");
	std::ifstream file2("sorted_test.txt");
	std::string temp1;
	std::string temp2;
	bool Q = true;;
	while (!file1.eof() && !file2.eof()) {
		std::getline(file1, temp1);
		std::getline(file2, temp2);
		if (temp1 != temp2) {
      Q=false;
      break;
		}
  REQUIRE(Q);
  file1.close();
  file2.close();
  }
}
