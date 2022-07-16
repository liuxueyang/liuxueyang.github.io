class Solution {
public:
  bool check(char s) {
    return s == '+' || s == '-' || s == '*' || s == '/';
  }

  int evalRPN(vector<string>& tokens) {
    stack<int> stk;

    for (auto &x : tokens) {
      if (x.size() == 1 && check(x[0])) {
        int b = stk.top();
        stk.pop();
        int a = stk.top();
        stk.pop();

        int t = 0;

        if (x[0] == '+') t = a + b;
        else if (x[0] == '-') t = a - b;
        else if (x[0] == '*') t = a * b;
        else if (x[0] == '/') t = a / b;

        stk.push(t);
      } else {
        stk.push(atoi(x.c_str()));
      }
    }

    return stk.top();
  }
};
