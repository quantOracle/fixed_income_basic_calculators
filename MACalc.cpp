#include "MACalculator.h"
#include <iostream>
MACalculator::MACalculator(int numPeriods)
: m_numPeriods(numPeriods)
{
}
MACalculator::~MACalculator()
{
}
MACalculator::MACalculator(const MACalculator &ma)
: m_numPeriods(ma.m_numPeriods)
{
}

MACalculator &MACalculator::operator = (const MACalculator &ma)
{
 if (this != &ma)
 {
 m_numPeriods = ma.m_numPeriods;
 m_prices = ma.m_prices;
 }
 return *this;
}
std::vector<double> MACalculator::calculateMA()
{
 std::vector<double> ma;
 double sum = 0;
 for (int i=0; i<m_prices.size(); ++i)
 {
 sum += m_prices[i];
 if (i >= m_numPeriods)
 {
 ma.push_back(sum / m_numPeriods);
 sum -= m_prices[i-m_numPeriods];
 }
 }
 return ma;
}
std::vector<double> MACalculator::calculateEMA()
{
 std::vector<double> ema;
 double sum = 0;
 double multiplier = 2.0 / (m_numPeriods + 1);
 for (int i=0; i<m_prices.size(); ++i)
 {
 sum += m_prices[i];
 if (i == m_numPeriods)
 {
 ema.push_back(sum / m_numPeriods);
 sum -= m_prices[i-m_numPeriods];
 }
 else if (i > m_numPeriods)
 {
 double val = (1-multiplier) * ema.back() + multiplier * m_prices[i];
 ema.push_back(val);
 }
 }
 return ema;
}

void MACalculator::addPriceQuote(double close)
{
 m_prices.push_back(close);
}

int main(int argc, const char * argv[])
{
 if (argc != 2)
 {
 std::cout << "usage: progName <num periods>" << std::endl;
 return 1;
 }
 int num_periods = atoi(argv[1]);

 double price;
 MACalculator calculator(num_periods);
 for (;;) {
 std::cin >> price;
 if (price == -1)
 break;
 calculator.addPriceQuote(price);
 }
 std::vector<double> ma = calculator.calculateMA();
 for (int i=0; i<ma.size(); ++i)
 {
 std::cout << "average value " << i << " = " << ma[i] << std::endl;
 }
 std::vector<double> ema = calculator.calculateEMA();
 for (int i=0; i<ema.size(); ++i)
 {
 std::cout << "exponential average value "
 << i << " = " << ema[i] << std::endl;
 }
 return 0;
}
