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
  /*
SCENARIO("file_small", "file_small]"){
  	allsort("8", 2);
	std::ifstream file1("sorted.txt");
	std::string temp1;
	size_t t = 0;
	std::getline(file1, temp1);
	while(!file1.eof()) {
		std::getline(file1, temp1);
		if (t > 422453) {
			REQUIRE(temp1 != "ef");
		}
		++t;
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
		if (t > 791948) {
			REQUIRE(temp1 != "ef");
		}
		++t;
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
	}
	REQUIRE(t == 1637032);
  	file1.close();
}
*/
