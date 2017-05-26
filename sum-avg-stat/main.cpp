#include <iostream>
#include "sum-avg-stat.h"

using std::cout;
using std::cin;

int main() {
  SumAvgStat sas1 = 10, sas2(13);

  sas1 += 10;
  sas1 -= 5;
  cout << *sas1 << '\n';

  sas2 += sas1;
  cout << sas2.avg() << '\n';

  SumAvgStat sas3(1);
  cin >> sas3;
  cout << sas3 << '\n';

  return 0;
}