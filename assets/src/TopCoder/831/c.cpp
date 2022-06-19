// Date: Wed Jun  8 19:57:24 2022

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i, a, b) for (int i = int(a); i < int(b); ++i)
#define PER(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define REP1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define PER1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define REPE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(),(a).end()
#define SZ(a) int((a).size())

#ifdef _DEBUG
#define debug1(x) cout << #x" = " << x << endl;
#define debug2(x,y) cout << #x" = " << x << " "#y" = " << y << endl;
#define debug3(x,y,z) cout << #x" = " << x << " "#y" = " << y << " "#z" = " << z << endl;
#else
#define debug1
#define debug2
#define debug3
#endif

class RerollCheater {
public:
	vector <int> reroll(vector <int> a, vector <int> b) {
		priority_queue<PII, vector<PII>, greater<PII>> q;
    REP(i, 0, SZ(a)) {
      q.push({a[i], i});
    }

    VI res;
    int n = SZ(b);
    VI pob(n + 1, -INF);
    PER(i, 0, n) {
      pob[i] = max(b[i], pob[i + 1]);
    }

    REP(i, 0, n) {
      if (pob[i] > q.top().f1) {
        auto t = q.top();
        q.pop();
        res.pb(t.f2);
        t.f1 = b[i];
        q.push(t);
      } else {
        break;
      }
    }

    return res;
	}
};
