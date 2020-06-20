#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 100 + 10;
const int INF = 0x7fffffff;

int d[N][N];
int path[N][N];
string a;

void print_res(int I, int J) {
  if (I == J) {
    if (a[I] == '(' || a[J] == ')') cout << "()";
    else cout << "[]";
    return;
  }
  if (I > J) return;
  if (((a[I] == '(' && a[J] == ')') ||
       (a[I] == '[' && a[J] == ']')) &&
      d[I][J] == d[I+1][J-1]) {
    cout << a[I];
    print_res(I + 1, J - 1);
    cout << a[J];
  }
  else {
    int k = path[I][J];
    print_res(I, k);
    print_res(k + 1, J);
  }
}

int main() {

#ifdef DEBUG
  freopen("brackets.in", "r", stdin);
#endif
  int n_case;
  cin >> n_case;
  cin.get();
  bool fst = true;

  while (n_case--) {
    cin.get();
    getline(cin, a);
    int len = a.size();

    if (fst) fst = false;
    else cout << endl;

    if (!len) {
      cout << endl;
      continue;
    }

    for (int i = 0; i < len; i++)
      for (int j = 0; j < len; j++)
        if (i < j)
          d[i][j] = INF - 1;
        else if (i == j)
          d[i][j] = 1;
        else
          d[i][j] = 0;

    for (int l = 1; l <= len - 1; l++) {
      for (int i = 0; i < len - l; i++) {
        int j = i + l;

        if ((a[i] == '(' && a[j] == ')') ||
            (a[i] == '[' && a[j] == ']')) {
          d[i][j] = min(d[i][j], d[i+1][j-1]);
        }

        for (int k = i; k < j; k++) {
          int tmp = d[i][k] + d[k+1][j];
          if (tmp < d[i][j]) {
            d[i][j] = tmp;
            path[i][j] = k;
          }
        }
      }
    }

    print_res(0, len - 1);
    cout << endl;
  }

  return 0;
}
