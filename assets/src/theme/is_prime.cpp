#include <iostream>
#include <algorithm>

using namespace std;

// 质数判定

// 试除法
// 暴力 O(n)
bool is_prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i < n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

// 试除法
// 优化 O(sqrt(n))
bool is_prime_v1(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= n / i; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	
	return 0;
}
