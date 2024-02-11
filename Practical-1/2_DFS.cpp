#include <bits/stdc++.h>
using namespace std;

// Recursive Function
void DFS(int Graph[][7], int start, int dimension) {

  static int visited[7] = {0};

  if (visited[start] == 0) {
    cout << start << " ";
    visited[start] = 1;

    for (int j = 0; j < dimension; j++) {
      if (Graph[start][j] == 1 && visited[j] == 0) {
        DFS(Graph, j, dimension);
      }
    }
  }
}

// ********************************************************

int main() {
  int Graph[7][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0},
                     {0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 0, 0},
                     {0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0}};

  //   DFS(Graph, 1, 7); // starting vertex = 1
  DFS(Graph, 4, 7); // starting vertex = 4

  return 0;
}