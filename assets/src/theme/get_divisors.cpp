#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

// 找到所有约数
vector<int> get_divisors(int n) {
	vector<int> res;

	for (int i = 1; i <= n / i; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (i != n / i) res.push_back(n / i);
		}
	}

	sort(res.begin(), res.end());
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> res = get_divisors(n);
	for (auto &x : res) {
		printf("%d ", x);
	}
	puts("");

	return 0;
}