#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

using VI = vector<int>;

int main() {
    #ifdef _DEBUG
    freopen("a.in", "r", stdin);
    #endif

    int n;
    string s;

    cin >> n >> s;
    VI a(n + 1, 0);
    for (int i = 0; i < n + 1; ++i) cin >> a[i];

    vector<VI> res;
    VI cur(n + 1, 0);

    int k = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '<') {
            k = 0;
            continue;
        }
        cur[i] = ++k;
    }
    k = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '>') {
            k = 0;
            continue;
        }
        cur[i + 1] = max(cur[i + 1], ++k);
    }

    for (auto &x : cur) {
        cout << x << " ";
    }
    cout << endl;

    // return 0;

    for (; ;) {
        for (int j = 0; j <= n; ++j) {
            a[j] -= cur[j];
        }

        bool flag = true;
        for (int j = 1; j <= n; ++j) {
            if (a[j] == a[j - 1] || a[j] < 0 || a[j - 1] < 0) {
                flag = false;
                break;
            }
        }

        if (!flag) {
            for (int j = 0; j <= n; ++j) {
                a[j] += cur[j];
            }
            res.push_back(a);
            break;
        }

        res.push_back(cur);
    }

    cout << res.size() << endl;
    for (auto &v : res) {
        for (auto &x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
