#include <iostream>
#include <random>
#include <vector>
using namespace std;

pair<int, int> shapex = {8, 2};
vector<pair<double, double>> X = {{0.25, 0.353}, {0.25, 0.471}, {0.5, 0.353},
                                  {0.5, 0.647},  {0.75, 0.705}, {0.75, 0.882},
                                  {1, 0.705},    {1, 1}};
vector<double> w, pred, z, b;
vector<double> y = {0, 1, 0, 1, 0, 1, 0, 1};

void randomizeWeights() {
  double w1, w2;
  // Weight initialized randomly
  uniform_real_distribution<double> unif(-0.00001, 0.00001);
  default_random_engine re;
  for (int i = 0; i < shapex.second; i++) {
    w1 = unif(re);
    w.push_back(w1);
  }
  w1 = unif(re);
  b.push_back(w1);
  for (auto x : w) {
    cout << x << "\n";
  }
  cout << "\n";
}

void matrixMult() {
  double res1, sum;
  sum = 0;
  z.clear();
  for (int i = 0; i < shapex.first; i++) {
    res1 = (X[i].first) * (w[0]) + (X[i].second) * (w[1]);
    z.push_back((res1 + b[0]));
  }
  // for (auto x: z) {
  //     cout << x << "\n";
  // }
}

void makePrediction() {
  matrixMult();
  pred.clear();
  for (int i = 0; i < shapex.first; i++) {
    if (z[i] > 0) {
      pred.push_back(1);
    } else {
      pred.push_back(0);
    }
  }
  // for (auto x: z) {
  //     cout << x << " ";
  // }
}

double accuracy() {
  double acc = 0;
  for (int i = 0; i < shapex.first; i++) {
    if (pred[i] == y[i]) {
      acc++;
    }
  }
  acc = (acc / shapex.first);
  return acc;
}

void updateWeights(double alpha) {
  double inter1, inter2;
  inter1 = 0;
  inter2 = 0;
  for (int i = 0; i < shapex.first; i++) {
    inter1 += (y[i] - pred[i]) * X[i].first;
    inter2 += (y[i] - pred[i]) * X[i].second;
    b[0] += alpha * (y[i] - pred[i]);
  }
  w[0] += alpha * inter1;
  w[1] += alpha * inter2;

  for (auto x : w) {
    cout << "w: " << x << "  ";
  }
  cout << "\tb: " << b[0] << "  ";
}

int main() {
  double alpha, acc;
  alpha = 0.000000001;
  randomizeWeights();
  makePrediction();
  acc = accuracy();
  long long ep = 1;
  while (acc < 1) {
    updateWeights(alpha);
    makePrediction();
    acc = accuracy();
    cout << "\t";
    cout << "epoch: " << ep << "\t accuracy: " << acc << "\n";
    ep++;
  }
  return 0;
}