#include <stdio.h>

int main() {
  int x;
  while (~scanf("%d", &x)) {
    int cnt = 0;

    for (int i = 0; i < 4; ++i) {
      int y = x >> (8 * i);
      int z = y & 0xff;
      printf("byte %d = %d\n", i, z);

      char c = (char)(y & 0xff);
      printf("c=%d\n", c);

      if (z) {
        if (cnt < i) cnt = i;
      }
    }

    cnt++;
    printf("byte cnt: %d\n", cnt);
  }

  return 0;
}
