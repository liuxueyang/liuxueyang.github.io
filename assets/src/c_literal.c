#include <stdio.h>

int main() {

  int (*(arr[])) = {
                    (int[]){0, 1, 2},
                    (int[]){3, 4, 5},
                    (int[]){6,7,8},
  };
  printf("%d\n", *arr[1]);

  return 0;
}
