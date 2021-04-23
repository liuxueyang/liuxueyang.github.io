#include <string.h>
#include <stdio.h>

#define STRCMP(a, R, b) (strcmp(a, b) R 0)

int main() {
  char s[100];
  const char *a = "hello";

  while (~scanf("%s", s)) {
    if (STRCMP(s, ==, a)) {
      printf("match\n");
    } else {
      printf("not match\n");
    }
  }

  return 0;
}
