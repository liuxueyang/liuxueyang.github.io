class Solution {
public:
  using ll = long long;
  int maximum(int a, int b) {
    ll x = a, y = b;
    int s = 1 + ((x - y) >> 63);
    return a * s + b * (!s);
  }
};
