#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int prev_min = INT_MAX;

bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; }

class Node {
public:
  int mx[3][3];
  Node *ch1, *ch2, *ch3, *ch4;
  int level;
  map<int, int> prev_cost = {
      {0, INT_MAX}, {1, INT_MAX}, {2, INT_MAX}, {3, INT_MAX}};
};

int init_mx[3][3] = {{1, 2, 3}, {0, 4, 6}, {7, 5, 8}};
int final_mx[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

int return_h_val(int mx[3][3]) {
  // int i, j = 0;
  int h = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (mx[i][j] != final_mx[i][j] && mx[i][j] != 0) {
        h++;
      }
    }
  }
  return h;
}

void Swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

// int* generate_children(int* mx)
Node *generate_children(Node n) {
  int pos_x = 0, pos_y = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (n.mx[i][j] == 0) {
        pos_x = i;
        pos_y = j;
      }
    }
  }
  // cout << pos_x << " " << pos_y;

  if (pos_x - 1 > -1) {
    n.ch1 = new Node();
    n.ch1->level = n.level + 1;
  } else {
    n.ch1 = NULL;
  }
  if (pos_x + 1 < 3) {
    n.ch2 = new Node();
    n.ch2->level = n.level + 1;
  } else {
    n.ch2 = NULL;
  }
  if (pos_y - 1 > -1) {
    n.ch3 = new Node();
    n.ch3->level = n.level + 1;
  } else {
    n.ch3 = NULL;
  }
  if (pos_y + 1 < 3) {
    n.ch4 = new Node();
    n.ch4->level = n.level + 1;
  } else {
    n.ch4 = NULL;
  }
  int arr_x[] = {pos_x + 1, pos_x - 1};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (n.ch1 != NULL) {
        n.ch1->mx[i][j] = n.mx[i][j];
      }
      if (n.ch2 != NULL) {
        n.ch2->mx[i][j] = n.mx[i][j];
      }
      if (n.ch3 != NULL) {
        n.ch3->mx[i][j] = n.mx[i][j];
      }
      if (n.ch4 != NULL) {
        n.ch4->mx[i][j] = n.mx[i][j];
      }
    }
  }
  if (n.ch1 != NULL) {
    Swap(&n.ch1->mx[pos_x - 1][pos_y], &n.ch1->mx[pos_x][pos_y]);
  }
  if (n.ch2 != NULL) {
    Swap(&n.ch2->mx[pos_x + 1][pos_y], &n.ch2->mx[pos_x][pos_y]);
  }
  if (n.ch3 != NULL) {
    Swap(&n.ch3->mx[pos_x][pos_y - 1], &n.ch3->mx[pos_x][pos_y]);
  }
  if (n.ch4 != NULL) {
    Swap(&n.ch4->mx[pos_x][pos_y + 1], &n.ch4->mx[pos_x][pos_y]);
  }
  /**
  for(int i=0; i<3; i++) {
      cout << "\n";
      for(int j=0; j<3; j++) {
          cout << n.ch4->mx[i][j] << " ";
      }
  }
  **/
  map<int, int> cost;
  cost.clear();
  for (int i = 0; i < 4; i++) {
    cost[i] = INT_MAX;
  }

  Node *arr[4];
  arr[0] = n.ch1;
  arr[1] = n.ch2;
  arr[2] = n.ch3;
  arr[3] = n.ch4;
  int h = 0, g = 0;
  for (int i = 0; i < 4; i++) {
    if (arr[i] != NULL) {
      h = return_h_val(arr[i]->mx);
      g = arr[i]->level;
      cost[i] = h + g;
    }
  }
  int minimum = INT_MAX;
  int min_in = 0;
  vector<int> min_in_arr;

  /*
  for (int i = 0; i < 4; i++) {
    // minimum = min(minimum, cost[i] == 0 ? INT_MAX : cost[i]);
    if (minimum > (cost[i] == 0 ? INT_MAX : cost[i])) {
      minimum = cost[i];
      min_in = i;
    }
  }
  */

  sort(cost.begin(), cost.end(), cmp);
  auto it = cost.begin();
  min_in = it->first;

  /*
for (int i = 0; i < 4; i++)
{
    cout << cost[i] << " ";
}
*/
  return arr[min_in];
}

int main() {
  // int ch1[3][3], ch2[3][3], ch3[3][3], ch4[4][4];
  Node in_node;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> in_node.mx[i][j];
      // in_node.mx[i][j] = init_mx[i][j];
    }
  }
  in_node.level = 0;
  while (true) {
    Node *next;
    next = generate_children(in_node);
    cout << "\n";
    for (int i = 0; i < 3; i++) {
      cout << "\n";
      for (int j = 0; j < 3; j++) {
        cout << next->mx[i][j] << " ";
      }
    }
    if (!return_h_val(next->mx)) {
      break;
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        in_node.mx[i][j] = next->mx[i][j];
      }
    }
    in_node.level = next->level;
  }
  // cout << return_h_val(init_mx);

  return 0;
}