#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int ival = 42, &rval = ival;
  int *pval = &rval;

  return 0;
}
