#ifndef SUM_AVG_STAT_H
#define SUM_AVG_STAT_H

#include <iostream>

using std::ostream;
using std::istream;

class SumAvgStat {
  int sum;
  int numbersCount;

public:

  SumAvgStat(int firstNumber);

  int operator*() const;
  SumAvgStat& operator+=(int number);
  SumAvgStat& operator-=(int number);
  SumAvgStat& operator+=(const SumAvgStat& other);

  int count() const;
  double avg() const;
};

ostream& operator<<(ostream& os, const SumAvgStat& sas);
istream& operator>>(istream& is, SumAvgStat& sas);

#endif
