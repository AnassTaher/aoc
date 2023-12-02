#include "headers.h"

/*
Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
*/

void p1(vector<string> inp) {
  uint64_t res = 0;

  for (string s : inp) {
    // get id
    int red = 12;
    int green = 13;
    int blue = 14;
    bool add = true;

    string id_str = split(s, ' ')[1];
    id_str.pop_back();
    int id = stoi(id_str);

    // get balls and remove all unwanted characters
    string str = split(s, ':')[1];
    str.erase(std::remove(str.begin(), str.end(), ','), str.end());
    vector<string> rounds = split(str, ';');
    for (string& round : rounds) round = round.erase(0, 1);

    // check if count is ever > count color
    for (string round : rounds) {
      vector<string> balls = split(round, ' ');
      for (int i = 0; i < balls.size(); i += 2) {
        int count = stoi(balls[i]);
        string color = balls[i + 1];
        if (color == "red" && count > red) add = false;
        if (color == "green" && count > green) add = false;
        if (color == "blue" && count > blue) add = false;

      }
    }
    if (add) res += id;
  }

  cout << "Res = " << res << "\n";
}

void p2(vector<string> inp) {
  uint64_t res = 0;

  for (string s : inp) {
    // get id
    int red = 0;
    int green = 0;
    int blue = 0;
    bool add = true;

    string id_str = split(s, ' ')[1];
    id_str.pop_back();
    int id = stoi(id_str);

    // get balls and remove all unwanted characters
    string str = split(s, ':')[1];
    str.erase(std::remove(str.begin(), str.end(), ','), str.end());
    vector<string> rounds = split(str, ';');
    for (string& round : rounds) round = round.erase(0, 1);

    // get max count for each round and add (red * green * blue) to res
    for (string round : rounds) {
      vector<string> balls = split(round, ' ');
      for (int i = 0; i < balls.size(); i += 2) {
        int count = stoi(balls[i]);
        string color = balls[i + 1];
        if (color == "red") red = max(red, count);
        if (color == "green") green = max(green, count);
        if (color == "blue") blue = max(blue, count);
      }
    }
    res += (red * green * blue);
  }

  cout << "Res = " << res << "\n";
}

int main(int argc, char** argv) {
  vector<string> inp = input();
  p1(inp);
  p2(inp);
  return 0;
}