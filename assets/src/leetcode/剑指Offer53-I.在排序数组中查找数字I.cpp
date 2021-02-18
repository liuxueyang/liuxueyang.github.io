#include <vector>

using namespace std;

class Solution {
public:
  int bsearch_lower(vector<int>& a, int x) {
    int l = 0, r = a.size() - 1, mid;
    while (l < r) {
      mid = (l + r) >> 1;
      if (a[mid] >= x) r = mid;
      else l = mid + 1;
    }
    return a[r] == x ? r : -1;
  }

  int bsearch_upper(vector<int> &a, int x) {
    int l = 0, r = a.size() - 1, mid;
    while (l < r) {
      mid = (l + r + 1) >> 1;
      if (a[mid] <= x)
        l = mid;
      else
        r = mid - 1;
    }
    return a[l] == x ? l : -1;
  }
  int search(vector<int> &nums, int target) {
    if (nums.size() == 0) return 0;
    int left = bsearch_lower(nums, target);
    if (left == -1) return 0;
    int right = bsearch_upper(nums, target);
    return right - left + 1;
  }
};
