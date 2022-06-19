// Date: Wed Jun  8 19:06:37 2022

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

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

class SmallestOppositeNumber {
public:
	int construct(int n) {
    VI vis(10, 0);
    if (!n) vis[0] = 1;

    while (n) {
      vis[n % 10] = 1;
      n /= 10;
    }

    int res = 0;
    VI b;
    REP(i, 0, 10) {
      if (!vis[i]) b.pb(i);
    }

    if (SZ(b) == 1) return b[0];
    if (!b[0]) swap(b[0], b[1]);

    for (auto x : b) {
      res = res * 10 + x;
    }
    return res;
	}
};

