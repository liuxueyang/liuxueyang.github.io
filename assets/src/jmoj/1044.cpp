#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> get_divisors(int n) {
  vector<int> ans;

  for (int i = 1; i <= n / i; ++i) {
    if (n % i == 0) {
      ans.push_back(i);
      if (i != n / i)
        ans.push_back(n / i);
    }
  }
  sort(ans.begin(), ans.end());

  return ans;
}

int main() {
  #ifdef _DEBUG
  freopen("1044.in", "r", stdin);
  #endif

  int n;
  scanf("%d", &n);
  vector<int> ans = get_divisors(n);
  for (auto &x : ans) printf("%d ", x);
  puts("");

  return 0;
}
