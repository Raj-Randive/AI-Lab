#include <bits/stdc++.h>
using namespace std;

// ******************** BFS uses Queue ********************
class Node {
public:
  int val;
  Node *next;
};

Node *front = NULL;
Node *rear = NULL;

class Queue {
public:
  void enqueue(int x);
  int dequeue();
  void displayQueue();
  bool isEmpty();
};

void Queue::enqueue(int x) {
  Node *temp = new Node();

  if (temp == NULL) {
    cout << "Queue is Full\n";

  } else {
    temp->val = x;
    temp->next = NULL;

    if (front == NULL) {
      front = rear = temp;
    } else {
      rear->next = temp;
      rear = temp;
    }
  }
}

int Queue::dequeue() {
  int x = -1;
  Node *temp;
  if (front == NULL) {
    cout << "The queue is empty.\n";
  } else {
    temp = front;
    front = front->next;
    x = temp->val;
    delete temp;
  }
  return x;
}

void Queue::displayQueue() {
  Node *temp = front;
  while (temp) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << "\n";
}

bool Queue::isEmpty() { return front == NULL ? true : false; }

// *****************************************************
// BFS Algorithm which uses Queue
void BFS(int Graph[][7], int start, int n) {
  int i = start;
  Queue q1;

  int visited[7] = {0};

  cout << i << " ";
  visited[i] = 1;
  q1.enqueue(i);

  while (!q1.isEmpty()) {
    i = q1.dequeue();
    for (int j = 1; j < 7; j++) {
      if (Graph[i][j] == 1 && visited[j] == 0) {
        cout << j << " ";
        visited[j] = 1;
        q1.enqueue(j);
      }
    }
  }
}

int main() {
  int Graph[7][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0},
                     {0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 0, 0},
                     {0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0}};

  BFS(Graph, 4, 7); // Starting vertex is 4
                    //   BFS(Graph, 5, 7); // Starting vertex is 5

  return 0;
}