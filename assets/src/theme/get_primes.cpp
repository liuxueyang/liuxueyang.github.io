#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10000;

int primes[N], cnt;
bool st[N];

// 埃氏筛法 O(nloglog(n))
void get_primes(int n) {
	for (int i = 2; i <= n; ++i) {
		if (!st[i]) {
			primes[cnt++] = i;
			for (int j = i * 2; j <= n; j += i) {
				st[j] = true;
			}
		}
	}
}

// 线性筛法 O(n)
void get_primes_v1(int n) {
	for (int i = 2; i <= n; ++i) {
		if (!st[i]) primes[cnt++] = i;
		for (int j = 0; primes[j] <= n / i; ++j) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int main() {
#ifdef _DEBUG
#endif
	
	get_primes_v2(1000);
	
	for (int i = 0; i < cnt; ++i) {
		printf("%d ", primes[i]);
	}
	puts("");
	
	return 0;
}
