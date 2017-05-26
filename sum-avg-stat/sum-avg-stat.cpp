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

ostream& operator<<(ostream& os, const SumAvgStat& sas) {
  return os << "Sum: " << *sas
            << "\nAvg: " << sas.avg()
            << "\nNumbers count: " << sas.count() << '\n';
}

istream& operator>>(istream& is, SumAvgStat& sas) {
  int numbersCount;
  is >> numbersCount;

  for (int i = 0; i < numbersCount; ++i) {
    int number;
    is >> number;
    sas += number;
  }

  return is;
}
