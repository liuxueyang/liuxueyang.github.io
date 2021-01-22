#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int sz1, sz2, h1[30], h2[30], n1, n2;

// min heap
void Down1(int x) {
  int t = x, l = x * 2, r = l + 1;
  if (l <= sz1 && h1[l] < h1[t]) t = l;
  if (r <= sz1 && h1[r] < h1[t]) t = r;
  if (t == x) return;
  swap(h1[t], h1[x]);
  Down1(t);
}

int Pop1() {
  int res = h1[1];
  h1[1] = h1[sz1--];
  Down1(1);
  return res;
}

void Up1(int x) {
  while (x / 2 && h1[x / 2] > h1[x]) {
    swap(h1[x / 2], h1[x]);
    x /= 2;
  }
}

void Push1(int x) {
  h1[++sz1] = x;
  Up1(sz1);
  if (sz1 > n1) Pop1();
}

// max heap
void Down2(int x) {
  int t = x, l = x * 2, r = l + 1;
  if (l <= sz2 && h2[l] > h2[t])
    t = l;
  if (r <= sz2 && h2[r] > h2[t])
    t = r;
  if (t == x) return;
  swap(h2[t], h2[x]);
  Down2(t);
}

int Pop2() {
  int res = h2[1];
  h2[1] = h2[sz2--];
  Down2(1);
  return res;
}

void Up2(int x) {
  while (x / 2 && h2[x / 2] < h2[x]) {
    swap(h2[x / 2], h2[x]);
    x /= 2;
  }
}

void Push2(int x) {
  h2[++sz2] = x;
  Up2(sz2);
  if (sz2 > n2)
    Pop2();
}

int main() {
  #ifdef DEBUG
  freopen("2833.in", "r", stdin);
  #endif

  int n;
  while (~scanf("%d%d%d", &n1, &n2, &n)) {
    if (n1 + n2 + n == 0) break;
    memset(h1, 0, sizeof h1);
    memset(h2, 0, sizeof h2);

    sz1 = sz2 = 0;
    double sum = 0;

    for (int i = 1; i <= n; ++i) {
      int tmp;
      scanf("%d", &tmp);
      sum += tmp;

      if (sz1 < n1 || tmp >= h1[1]) {
        Push1(tmp);
      }
      if (sz2 < n2 || tmp <= h2[1]) {
        Push2(tmp);
      }
    }

    // for (int i = 1; i <= sz1; ++i) printf(" %d", h1[i]);
    // puts("");

    // for (int i = 1; i <= sz2; ++i)
    //   printf(" %d", h2[i]);
    // puts("");

    while (sz1) sum -= Pop1();
    while (sz2) sum -= Pop2();
    double res = 0;
    if (n != n1 + n2) {
      res = sum / (n - n1 - n2);
    }
    printf("%.6f\n", res);
  }
  return 0;
}
