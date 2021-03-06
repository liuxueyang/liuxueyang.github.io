#include <cstdio>

using namespace std;
using ll = long long;
const int N = 5000010;
int a[N], b[N], n, res;

ll merge_sort(int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    ll left = merge_sort(l, mid), right = merge_sort(mid + 1, r);
    ll res = left + right;

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else {
            b[k++] = a[j++];
            res += (mid - i + 1);
        } 
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];

    for (int i = l; i <= r; ++i) a[i] = b[i];
    return res;
}

int main() {
    #ifdef _DEBUG
    freopen("1908.in", "r", stdin);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);

    res = merge_sort(0, n - 1);
    printf("%lld\n", res);

    return 0;
}