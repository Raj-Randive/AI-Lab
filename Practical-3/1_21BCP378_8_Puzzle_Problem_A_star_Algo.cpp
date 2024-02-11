#include <iostream>
using namespace std;

// Class which stores all the possible moves from one state to another
class Node {
public:
  int mx[3][3];
  Node *ch1, *ch2, *ch3, *ch4;
  int level;
};

// init_mx --> Initializing the start matrix
int init_mx[3][3] = {{1, 2, 3}, {0, 4, 6}, {7, 5, 8}};
// init_mx --> Initializing the goal matrix
int final_mx[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

// function to find h(x) for current State(Matrix).
int return_h_val(int mx[3][3]) {
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

// Function to swap the values of the matrix
void Swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

// This is the function for generating all the children nodes.
Node *generateChildren(Node n) {
  int pos_x = 0, pos_y = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (n.mx[i][j] == 0) {
        pos_x = i;
        pos_y = j;
      }
    }
  }

  // Checking if moves are possible and creating child nodes accordingly
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

  // actually creating the child matrices
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

  // swaping the moves one at a time and generating diff childs
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

  // finding the children which has minimum f(x) value
  int cost[4] = {0};
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
  for (int i = 0; i < 4; i++) {
    // minimum = min(minimum, cost[i] == 0 ? INT_MAX : cost[i]);
    if (minimum > (cost[i] == 0 ? INT_MAX : cost[i])) {
      minimum = cost[i];
      min_in = i;
    }
  }

  /*
  for (int i = 0; i < 4; i++)
  {
      cout << cost[i] << " ";
  }
  */
  return arr[min_in];
}

// main driver function
int main() {
  Node in_node;

  // Input the start matrix
  cout << "Enter initial mx: \n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> in_node.mx[i][j];
      // in_node.mx[i][j] = init_mx[i][j];
    }
  }
  // Input the goal matrix
  cout << "Enter final state:  \n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> final_mx[i][j];
      // in_node.mx[i][j] = init_mx[i][j];
    }
  }
  in_node.level = 0;

  // do this until the h(x) value becomes '0'.
  while (true) {
    Node *next;
    next = generateChildren(in_node);
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
  return 0;
}