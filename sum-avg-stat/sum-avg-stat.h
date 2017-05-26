#ifndef SUM_AVG_STAT_H
#define SUM_AVG_STAT_H

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

#endif
