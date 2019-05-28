#include "BondCalculator.h"

using namespace std;

BondCalculator::BondCalculator(const std::string institution,
 int numPeriods, double principal, double couponValue)
: m_institution(institution),
 m_numPeriods(numPeriods),
 m_principal(principal),
 m_coupon(couponValue)
{
}

BondCalculator::BondCalculator(const BondCalculator &v)
: m_institution(institution),
 m_numPeriods(v.m_numPeriods),
 m_principal(v.m_principal),
 m_coupon(v.m_coupon)
{
}
BondCalculator::~BondCalculator()
{
}
BondCalculator &BondCalculator::operator =(const BondCalculator &v)
{
 if (this != &v)
 {
 this->m_institution = v.m_institution;
 this->m_principal = v.m_principal;
 this->m_numPeriods = v.m_numPeriods;
 this->m_coupon = v.m_coupon;
 }
 return *this;
}
double BondCalculator::interestRate()
{
 return m_coupon / m_principal;
}

// the main function receives parameters passed to the program
int main(int argc, const char * argv[])
{
 if (argc != 4)
 {
 std::cout << "usage: progName <institution> <principal> <coupon> <num periods>"
 << std::endl;
 return 1;
 }
 std::string issuer = argv[1];
 double principal = atof(argv[2]);
 double coupon = atof(argv[3]);
 int num_periods = atoi(argv[4]);

BondCalculator bc(issuer, principal, coupon, num_periods);
 std::cout << "reading information for bond issued by " << issuer << std::endl;
 std::cout << " the internal rate of return is " << bc.interestRate() << std::endl;
 return 0;
}
