
#include <iostream>
#include <string>
#include <vector>
#include <queue>


using namespace std;

void solve(){

  auto comp = [](int a, int b){return a < b;};
  priority_queue<int, vector<int>, decltype(comp)> q(comp);


  string s = "";
  int cur = 0;
  int max = 0;
  while(getline(cin, s)){

    if(s.empty()){
      
    }else{

    }
  }
}

int main(int argc, char** argv){


  solve();

  return 0;
}