#include "sort.hpp"
#include <catch.hpp>

SCENARIO("Init", "[Init]"){
  mysort();
  std::ifstream file1("sorted1.txt");
  REQUIRE(file1.is_open());
  if (!file1.is_open()) throw("no_file");
  std::ifstream file2("sorted.txt");
  REQUIRE(file1.is_open());
  if (!file1.is_open()) throw("no_file");
  std::string str1;
  std::string str2;
  for (size_t t = 0; t < 800; ++t)
    std::getline(file1, str1);
    std::getline(file2, str2);
    REQUIRE(str1 == str2);
}
