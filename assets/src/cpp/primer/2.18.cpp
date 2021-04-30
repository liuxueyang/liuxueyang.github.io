#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int i = 10;
  int *p = &i;

  int j = 20;

  p = &j;
  *p = 30;

  cout << j << endl;

  return 0;
}
