#include "headers.h"

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}



void p1(){

  // ROCK: A, X
  // Paper: B, Y
  // Scissors: C, Z

  // Lose = 0, draw = 3, win = 6

  map<char, char> convert = {
    {'X', 'A'},
    {'Y', 'B'},
    {'Z', 'C'}
  };

  map<char, int> choices = {
    {'A', 1},
    {'B', 2},
    {'C', 3}
  };

  map<pair<char, char>, int> points={
    {{'A', 'B'}, 6 + 2},
    {{'A', 'C'}, 0 + 3},
    {{'B', 'A'}, 0 + 1},
    {{'B', 'C'}, 6 + 3},
    {{'C', 'A'}, 6 + 1},
    {{'C', 'B'}, 0 + 2}
  };


  string s = "";
  int total = 0;
  while(getline(cin, s)){
    char op1 = s[0];
    char op2 = convert[s[2]];

    if(op1 == op2){
      total += (3 + choices[op2]);
    } else{
      total += (points[{op1, op2}]);
    }

  }
  cout << "Total = " << total << "\n";
}

void p2(){
  // X means you need to lose, 
  // Y means you need to end the round in a draw, 
  // and Z means you need to win.
  
  map<char, int> points = {
    {'A', 1},
    {'B', 2},
    {'C', 3}
  };

  map<char, char> lose = {
    {'A', 'C'},
    {'B', 'A'},
    {'C', 'B'}
  };

  map<char, char> win = {
    {'A', 'B'},
    {'B', 'C'},
    {'C', 'A'}
  };

  string s = "";
  int total = 0;
  
  while(getline(cin, s)){
    char op1 = s[0];
    char op2 = s[2];
    char choice;

    if(op2 == 'X'){
      choice = lose[op1];
      total += 0;
    }
    if(op2 == 'Y'){
      choice = op1;
      total += 3;
    }
    if(op2 == 'Z'){
      choice = win[op1];
      total += 6;
    }
    total += points[choice];
  }

  cout << "Total = " << total << "\n";
}

int main(int argc, char** argv){

  // p1();
  p2();
  return 0;
}

