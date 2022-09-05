using ll = long long;

class Solution {
public:
    int nthUglyNumber(int n) {
        ll a[1700] {};
        memset(a, 0x3f, sizeof a);
        a[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; ++i) {
            ll &t = a[i];
            t = min(t, a[p2] * 2);
            t = min(t, a[p3] * 3);
            t = min(t, a[p5] * 5);
            if (t == a[p2] * 2) ++p2;
            if (t == a[p3] * 3) ++p3;
            if (t == a[p5] * 5) ++p5;
        }
        return a[n];
    }
};
