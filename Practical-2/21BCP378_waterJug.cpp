// Name: Raj Randive
// Roll Number: 21BCP378

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int GCD(int a, int b) {
    while (b != 0) {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }

  bool canMeasureWater(int j1, int j2, int cap) {

    if (j1 + j2 < cap)
      return false;
    if (cap % GCD(j2, j1) == 0)
      return true;
    return false;
  }
};

int main() {
  Solution sol;
  int j1, j2, cap;
  cout << "Enter the Jug-1 capacity: ";
  cin >> j1;
  cout << "Enter the Jug-2 capacity: ";
  cin >> j2;
  cout << "Enter the Target-capacity: ";
  cin >> cap;

  if (sol.canMeasureWater(j1, j2, cap))
    cout << "True";
  else
    cout << "False";

  return 0;
}