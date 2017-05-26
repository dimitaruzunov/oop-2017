#include <iostream>
#include "sum-avg-stat.h"

using std::cout;

int main() {
  SumAvgStat sas1 = 10, sas2(13);

  sas1 += 10;
  sas1 -= 5;
  cout << *sas1 << '\n';

  sas2 += sas1;
  cout << sas2.avg() << '\n';

  return 0;
}