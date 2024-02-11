// #include <bits/stdc++.h>
// using namespace std;

// // Recursive Function
// int cost = 0;

// const int INF = 1e9;

// void DFS(int Graph[][5], int start, int dimension) {
//   static int visited[5] = {0};

//   if (visited[start] == 0) {
//     cout << start << " ";
//     visited[start] = 1;

//     for (int j = 0; j < dimension; j++) {
//       if (Graph[start][j] >= 1 && visited[j] == 0) {
//         cost += Graph[start][j];
//         DFS(Graph, j, dimension);
//       }
//     }
//   }
// }

// // ********************************************************

// int main() {
//   int Graph[5][5] = {{0, 0, 0, 0, 0},
//                      {0, 0, 22, 48, 28},
//                      {0, 22, 0, 20, 18},
//                      {0, 48, 20, 0, 32},
//                      {0, 28, 18, 32, 0}};

//   DFS(Graph, 1, 5);
//   cout << "\n" << cost << "\n";

//   return 0;
// }

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void DFS_TSP(int graph[][5], vector<int> &path, vector<int> &visited,
             int current, int n, int &minCost, int &totalVisited) {
  visited[current] = 1;
  path.push_back(current);
  totalVisited++;

  if (totalVisited == n) {
    // All cities visited, go back to the starting city
    path.push_back(path[0]);
    int cost = 0;
    for (int i = 0; i < n; i++) {
      cost += graph[path[i]][path[i + 1]];
    }
    minCost = min(minCost, cost);
  } else {
    for (int next = 0; next < n; next++) {
      if (graph[current][next] != 0 && !visited[next]) {
        DFS_TSP(graph, path, visited, next, n, minCost, totalVisited);
      }
    }
  }

  visited[current] = 0;
  path.pop_back();
  totalVisited--;
}

int TSP(int graph[][5], int start, int n) {
  vector<int> path, visited(n, 0);
  int minCost = INF, totalVisited = 0;

  DFS_TSP(graph, path, visited, start, n, minCost, totalVisited);

  return minCost;
}

int main() {
  int graph[5][5] = {{0, 0, 0, 0, 0},
                     {0, 0, 22, 48, 28},
                     {0, 22, 0, 20, 18},
                     {0, 48, 20, 0, 32},
                     {0, 28, 18, 32, 0}};

  int startCity = 1; // Starting city (1-indexed)
  int minCost = TSP(graph, startCity, 5);

  if (minCost != INF) {
    cout << "Minimum Cost of TSP starting from city " << startCity << ": "
         << minCost << endl;
  } else {
    cout << "No Hamiltonian cycle exists." << endl;
  }

  return 0;
}
