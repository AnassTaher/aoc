#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <stdlib.h>

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

std::vector<std::string> input(){
  std::vector<std::string> inp;
  std::string s = "";
  while(getline(std::cin, s)) inp.push_back(s);
  return inp;
}


using namespace std;