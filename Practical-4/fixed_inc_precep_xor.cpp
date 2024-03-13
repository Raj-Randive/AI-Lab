#include <iostream>
#include <random>
#include <vector>
using namespace std;

pair<int, int> shapex = {4, 3};
vector<vector<double>> X = {{0, 0, 1}, {0, 1, 1}, {1, 0, 1}, {1, 1, 1}};

vector<double> w, pred, z;
vector<double> y = {0, 1, 1, 0};

void randomize_weights() {
  double w1, w2;
  // Weight initialized randomly
  uniform_real_distribution<double> unif(-0.00001, 0.00001);
  default_random_engine re;
  for (int i = 0; i < shapex.second; i++) {
    w1 = unif(re);
    w.push_back(w1);
  }
  for (auto x : w) {
    cout << x << "\n";
  }
  cout << "\n";
}

void mx_mult() {
  double res1 = 0;
  z.clear();
  for (int i = 0; i < shapex.first; i++) {
    res1 = 0;
    for (int j = 0; j < shapex.second; j++) {
      res1 += (X[i][j] * w[j]);
    }
    z.push_back((res1));
  }
  // for (auto x: z) {
  //     cout << x << "\n";
  // }
}

void make_pred() {
  mx_mult();
  pred.clear(); // very important
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

void update_weights(double alpha) {
  double inter[shapex.second];
  for (int i = 0; i < shapex.first; i++) {
    for (int j = 0; j < shapex.second; j++) {
      inter[j] += (y[i] - pred[i]) * X[i][j];
    }
  }
  for (int i = 0; i < shapex.second; i++) {
    w[i] += alpha * inter[i];
  }
  for (auto x : w) {
    cout << x << " ";
  }
}

int main() {
  double alpha, acc;
  // alpha = 0.000000001;
  alpha = 0.01;
  randomize_weights();
  make_pred();
  acc = accuracy();
  long long ep = 1;

  // loop over until we get acc=1
  while (acc < 1) {
    update_weights(alpha);
    make_pred();
    acc = accuracy();
    cout << "\t\tep: " << ep << " \t accuracy: " << acc << "\n";
    ep++;
  }

  return 0;
}