#include <iostream>
#include <algorithm>

using namespace std;

// n 中最多只包含 1 个大于 sqrt(n) 的质因子

// 分解质因数
// 试除法 O(sqrt(n))

void divide(int x) {
	for (int i = 2; i <= n / i; ++i) {
		if (n % i == 0) {
			int c = 0;
			while (n % i == 0) {
				c++;
				n /= i;
			}
			printf("%d %d\n", c, i);
		}
	}
	
	if (n > 1) printf("1 %d\n", n);
}
