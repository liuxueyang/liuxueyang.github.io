#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 100009;
int e[N], l[N], r[N], idx;

void init() {
  // 0 head, 1 tail
  r[0] = 1;
  l[0] = -1;
  
  l[1] = 0;
  r[1] = -1;
  idx = 2;
}

void push_front(int x) {
  e[idx] = x;
  int q = r[0];
  l[idx] = 0;
  r[idx] = q;

  l[q] = idx;
  r[0] = idx;
  ++idx;
}

void push_back(int x) {
  e[idx] = x;
  int p = l[1];
  l[idx] = p;
  r[idx] = 1;
  
  r[p] = idx;
  l[1] = idx;
  ++idx;
}

void insert_after_k(int k, int x) {
  e[idx] = x;
  int q = r[k];
  l[q] = idx;
  r[idx] = q;
  l[idx] = k;
  r[k] = idx;
  ++idx;
}

void insert_before_k(int k, int x) {
  e[idx] = x;
  int p = l[k];
  r[idx] = k;
  l[idx] = p;
  l[k] = idx;
  r[p] = idx;
  ++idx;
}

void delete_at_k(int k) {
  int q = r[k], p = l[k];
  r[p] = q;
  l[q] = p;
}

void print() {
  for (int i = r[0]; i != 1; i = r[i]) {
    cout << e[i] << ' ';
  }
  cout << endl;
}

int main()
{
  init();
  int m;
  cin >> m;
  while (m--) {
    string op;
    int k, x;
    cin >> op;
    if (op == "L") {
      cin >> x;
      push_front(x);
    } else if (op == "R") {
      cin >> x;
      push_back(x);
    } else if (op == "D") {
      cin >> k;
      delete_at_k(k+1);
    } else if (op == "IL") {
      cin >> k >> x;
      insert_before_k(k+1, x);
    } else if (op == "IR") {
      cin >> k >> x;
      insert_after_k(k+1, x);
    }
  }
  print();
  return 0;
}
