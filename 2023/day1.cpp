#include "headers.h"
/*
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
*/

void p1(vector<string> inp){
    uint64_t res = 0;

    for(string s : inp){
        int first = -1;
        int second = -1;
        for(char c : s){
            if(isdigit(c)){
                int number = static_cast<int>(c) - 48;
                (first == -1) ? first = number : second = number;
            }
        }
        first = (first == -1 ? 0 : first);
        int to_add = (first * 10) + (second == -1 ? first : second);
        res += to_add;
    }
    cout << "Res = " << res << "\n";
}

const map<string, int> numbers = {
  {"one", 1},
  {"two", 2},
  {"three", 3},
  {"four", 4},
  {"five", 5},
  {"six", 6},
  {"seven", 7},
  {"eight", 8},
  {"nine", 9}
};

// "aone" l = 4, i = 3, 4 - 1 = 3
int isWordDigit(string s, int index, bool get_len){
  bool isDigit = false;
  int remaining_len = s.size() - index;
  int substr_len = 3;
  while(substr_len <= remaining_len){
    isDigit = numbers.count(s.substr(index, substr_len)) > 0;
    if(isDigit) break;
    substr_len++;
  }
  return (!get_len) ? isDigit : numbers.at(s.substr(index, substr_len));
}

int getNumber(string s, int index){
  if(isdigit(s[index])) return static_cast<int>(s[index]) - 48;
  return isWordDigit(s, index, true);
}

void p2(vector<string> inp){
  uint64_t res = 0;

  for(string s : inp){
    int first = -1;
    int second = -1;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(isdigit(c) || isWordDigit(s, i, false)){
            int number = getNumber(s, i);
            (first == -1) ? first = number : second = number;
        }
    }
    first = (first == -1 ? 0 : first);
    int to_add = (first * 10) + (second == -1 ? first : second);
    res += to_add;
  }
    cout << "Res = " << res << "\n";

}

int main(int argc, char** argv){

    vector<string> inp = input();
    //  p1(inp);
    // p2(inp);
    return 0;
}