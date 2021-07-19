// Date: Mon Jul 19 20:31:29 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

string form(int s) {
  string res;
  if (s < 60) {
    return to_string(s) + "s";
  }

  int m = s / 60;
  s -= m * 60;

  res += to_string(m) + ":" + to_string(s);
  
  return res;
}

string message = "Command: Start(s), NextProblem(n), Restart(r), Exit(e)";

int main(void)
{
#ifdef _DEBUG
  // freopen("prob.in", "r", stdin);
#endif

  vector<time_t> ts;
  VI dur;

  char op;
  cout << message << endl;
  
  while (cin >> op) {
    if (op == 'e') {
      break;
    }
    
    switch (op) {
    case 's': {
      ts.push_back(time(nullptr));
      break;
    }
    case 'n': {
      time_t cur = time(nullptr);
      
      int n = ts.size();
      if (!n) {
	cout << "Invalid command!" << endl;
	break;
      }
      dur.push_back(cur - ts[n - 1]);

      for (int i = 0; i < n; ++i) {
	cout << "NO." << i + 1 << ": " << form(dur[i]) << endl;
      }

      ts.push_back(cur);
      
      break;
    }
    case 'r': {
      int total = 0;
      for (int i = 0; i < dur.size(); ++i) total += dur[i];
      cout << "total: " << form(total) << endl;
      ts.clear();
      dur.clear();
      cout << message << endl;
      
      break;
    }
    }
  }
  
  return 0;
}
