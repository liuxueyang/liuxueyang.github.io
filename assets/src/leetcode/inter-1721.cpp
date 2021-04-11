class Solution {
public:
  int trap(vector<int>& a) {
    int res = 0;
    stack<int> stk;
    int n = a.size();

    if (!n) return res;

    stk.push(0);

    int prev = 0;
    for (int i = 1; i < n; ++i) {
      while (!stk.empty() && a[i] > a[stk.top()]) {
        int j = stk.top();
        stk.pop();
        if (stk.empty()) break;

        int k = stk.top();
        res += (min(a[k], a[i]) - a[j]) * (i - k - 1);
      }
      stk.push(i);
    }

    return res;
  }
};
