#include "headers.h"
/*
2-4,6-8
2-3,4-5
5-7,7-9
2-8,3-7
6-6,4-6
2-6,4-8
*/

void p1(vector<string> inp){

  uint64_t res = 0;
  for(string p : inp){
    vector<string> pairs = split(p, ',');

    string p1 = pairs[0];
    string p2 = pairs[1];

    vector<string> range1 = split(p1, '-');
    vector<string> range2 = split(p2, '-');

    uint64_t s1 = stoi(range1[0]);
    uint64_t e1 = stoi(range1[1]);

    uint64_t s2 = stoi(range2[0]);
    uint64_t e2 = stoi(range2[1]);

    if((s2 >= s1 && e2 <= e1) || (s1 >= s2 && e1 <= e2))
      res += 1;
    
  }
   cout << "Res = " << res << "\n";
}

void p2(vector<string> inp){
  uint64_t res = 0;
  for(string p : inp){
    vector<string> pairs = split(p, ',');

    string p1 = pairs[0];
    string p2 = pairs[1];

    vector<string> range1 = split(p1, '-');
    vector<string> range2 = split(p2, '-');

    uint64_t s1 = stoi(range1[0]);
    uint64_t e1 = stoi(range1[1]);

    uint64_t s2 = stoi(range2[0]);
    uint64_t e2 = stoi(range2[1]);

    // 2-4,6-8  E1 < S2
    // 6-8, 2-4 S1 > E2
    if(!(s1 > e2 || e1 < s2))
      res += 1;
    
  }
   cout << "Res = " << res << "\n";
}

int main(int argc, char** argv){

  vector<string> inp = input();
  // p1(inp);
  // p2(inp);
  return 0;
}