#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
  return a + rand() % (b - a + 1);
}

int main(void) {
  srand(clock());

  int t = rand(1, 10);
  cout << t << endl;
  while(t--) {
    int n = 10;
    cout << n<< endl;
    for(int i = 0; i < n; i++) {
      cout << rand(1, 20) << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
      cout << rand(1, 20) << " ";
    }
    cout << endl;
  }
}