class Solution {
public:
  int maximum(int a, int b) {
    int x = a > b;
    return a * (x) + b * (!x);
  }
};
