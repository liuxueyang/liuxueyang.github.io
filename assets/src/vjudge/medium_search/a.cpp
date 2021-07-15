#include <cstring>
#include <iostream>
#include <cstdio>

#include <string>
#include <set>
#include <queue>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

const int N = 3;
const int dir[4][2] = {
  {-1, 0}, {1, 0},
  {0, -1}, {0, 1},
};

struct Point {
  string s;
  int op;
  Point() {}
  Point(string _s, int _op) :s(_s), op(_op) {}
};

char a[N][N];

string zip() {
  string res;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) res += a[i][j];
  return res;
}

void unzip(string &s) {
  for (int i = 0; i < s.size(); ++i) {
    a[i / 3][i % 3] = s[i];
  }
}

char get_op(int op) {
  switch (op) {
  case 1: return 'u';
  case 2: return 'd';
  case 3: return 'l';
  case 4: return 'r';
  }
  return ' ';
}

int main() {
  #ifdef _DEBUG
  freopen("a.in", "r", stdin);
  #endif

  set<string> vis;
  map<string, Point> path;
  queue<string> que;
  string target = "12345678x";

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> a[i][j];
    }
  }

  string starts = zip();
  vis.insert(starts);

  que.push(starts);
  bool flag = false;

  while (!que.empty()) {
    string t = que.front();
    que.pop();

    if (target == t) {
      flag = true;
      break;
    }

    unzip(t);
    int x, y;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (a[i][j] == 'x') {
          x = i; y = j; break;
        }
      }
    }

    for (int i = 0; i < 4; ++i) {
      unzip(t);
      int x1 = x + dir[i][0], y1 = y + dir[i][1];

      if (x1 >= 0 && x1 < 3 && y1 >= 0 && y1 < 3) {
        swap(a[x][y], a[x1][y1]);
        string tmp = zip();

        if (vis.find(tmp) == vis.end()) {
          path[tmp] = Point(t, i + 1);
          vis.insert(tmp);
          que.push(tmp);
        }
      }
    }
  }

  if (flag) {
    string res, tmp = target;
    while (tmp != starts) {
      Point t = path[tmp];
      res += get_op(t.op);
      tmp = t.s;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
  } else {
    cout << "unsolvable" << endl;
  }

  return 0;
}
