#include "sum-avg-stat.h"

SumAvgStat::SumAvgStat(int firstNumber): sum(firstNumber), numbersCount(1) {}

int SumAvgStat::operator*() const {
  return sum;
}

SumAvgStat& SumAvgStat::operator+=(int number) {
  sum += number;
  ++numbersCount;

  return *this;
}

SumAvgStat& SumAvgStat::operator-=(int number) {
  return *this += -number;
}

SumAvgStat& SumAvgStat::operator+=(const SumAvgStat& other) {
  sum += other.sum;
  numbersCount += other.numbersCount;

  return *this;
}

int SumAvgStat::count() const {
  return numbersCount;
}

double SumAvgStat::avg() const {
  return (double) sum / numbersCount;
}
