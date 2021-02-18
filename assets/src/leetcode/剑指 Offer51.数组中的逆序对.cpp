#include <vector>
#include <algorithm>

using namespace std;

const int N = 50010;
int b[N];

class Solution {
public:
  int merge_sort(int l, int r, vector<int>& a) {
    if (l >= r) return 0;
    int mid = (l + r) >> 1;
    int res = merge_sort(l, mid, a) + merge_sort(mid + 1, r, a);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
      if (a[i] <= a[j]) b[k++] = a[i++];
      else {
        res += (mid - i + 1);
        b[k++] = a[j++];
      }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];

    for (int i = l, j = 0; i <= r; i++, j++) a[i] = b[j];
    return res;
  }

  int reversePairs(vector<int> &nums) {
    return merge_sort(0, nums.size() - 1, nums);
  }
};
