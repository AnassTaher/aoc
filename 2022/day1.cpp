#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void solve(){

  auto comp = [](int a, int b){return a < b;};
  priority_queue<int, vector<int>, decltype(comp)> q(comp);
  string s = "";
  int max = 0;
  int cur = 0;
  while(getline(cin, s)){

    
   if(!s.empty()){
    cur += stoi(s);
   }else{
    q.push(cur);
    max = std::max(max, cur);
    cur = 0;
   }
  }

  int n = 3;
  int sum = 0;
  for(int i = 0; i < n; i++){
    cout << "Max = " << q.top() << "\n";
    sum += q.top();
    q.pop();
  }
  cout << "Sum = " << sum << "\n";
}

int main(int argc, char** argv){


  solve();

  return 0;
}