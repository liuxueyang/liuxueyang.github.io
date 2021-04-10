#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

bool check(string s) {
    int n = s.size();
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

int main() {
    #ifdef _DEBUG
    freopen("a.in", "r", stdin);
    #endif

    string s;
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        string t = s + 'a', t1 = 'a' + s;
        if (!check(t)) {
            cout << "YES\n" << t << endl;
        } else if (!check(t1)) {
            cout << "YES\n" << t1 << endl;
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
