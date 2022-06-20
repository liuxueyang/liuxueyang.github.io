#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

using VI = vector<int>;
using PII = pair<int, int>;

const int N = 10010, M = 500010, INF = 0x3f3f3f3f;

int tc, n, dis[N], st[N], h[N];
int e[M], ne[M], w[M], idx;
string s[N];
unordered_map<string, int> names;

void init() {
    idx = 0;
    memset(dis, 0x3f, sizeof(dis));
    memset(st, 0, sizeof st);
    memset(h, -1, sizeof h);
}

void Add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(st, 0, sizeof st);

    dis[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s});

    while (!q.empty()) {
        auto t = q.top(); q.pop();
        int base = t.first, ver = t.second;

        if (st[ver]) continue;
        st[ver] = 1;

        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i], tmp = base + w[i];
            if (tmp < dis[j]) {
                dis[j] = tmp;
                q.push({tmp, j});
            }
        }
    }
}

int main() {
    cin >> tc;
    while (tc--) {
        cin >> n;
        init();
        for (int i = 1; i <= n; ++i) {
            cin >> s[i];
            names[s[i]] = i;
            int m; cin >> m;
            while (m--) {
                int j, c; cin >> j >> c;
                Add(i, j, c);
            }
        }

        int q; cin >> q;
        while (q--) {
            string a, b; cin >> a >> b;
            int i = names[a], j = names[b];
            dijkstra(i);
            cout << dis[j] << '\n';
        }

        if (tc) cout << '\n';
    }

    return 0;
}