#include "headers.h"

// Input
/*
vJrwpWtwJgWrhcsFMMfFFhFp
jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
PmmdzqPrVvPwwTWBwg
wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
ttgJtRGJQctTZtZT
CrZsJsPPZsGzwwsLwLmpwMDw
*/

void p1(){
  string s = "";
  set<char> chars;
  char found;
  int total = 0;
  while(getline(cin, s)){

    string s1 = s.substr(0, s.size() / 2);
    string s2 = s.substr(s.size() / 2);

    for(char c : s1)
      chars.insert(c);
    
    for(char c : s2)
      if(chars.count(c)){
        if(islower(c)){
          total += (c - 'a' + 1);
        }else{
          total += (c - 'A' + 27);
        }
        break;
      }
    chars.clear();
  }
  
  cout << "Total = " << total << "\n";
}

void p2(){
  string s = "";
  int total = 0;
  vector<int> lower(26, 0);
  vector<int> upper(26, 0);

  while(true){
    
    if(cin.eof()) break;
    
    char res;
    for(int i = 1; i < 4; i++){
      getline(cin, s);

      for(char c : s){
        if(islower(c)){
          if(lower[c - 'a'] == i - 1) lower[c - 'a'] += 1;
          if(lower[c - 'a'] == 3){
            total += (c - 'a' + 1);
            break;
          }
        }else{
          if(upper[c - 'A'] == i - 1) upper[c - 'A'] += 1;
          if(upper[c - 'A'] == 3){
            total += (c - 'A' + 27);
            break;
          }
        }
      }
    }

    for(int i = 0; i < 26; i++){
      lower[i] = 0;
      upper[i] = 0;
    }
  }

  cout << "Total = " << total << "\n";
}

int main(int argc, char** argv){
  // p1();
  // p2();
  return 0;
}