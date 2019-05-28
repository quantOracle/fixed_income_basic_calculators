#ifndef _COMPOUNDINTCALC_
#define _COMPOUNDINTCALC_

class CompoundIntCalc {
  public: 
    CompoundIntCalc(double rate);
    CompoundIntCalc(const CompoundIntCalc &v);
    CompoundIntCalc &operator = (const CompoundIntCalc &v);
    ~CompoundIntCalc();
    
    double period(double value, int numPeriod);
    double compound(double value, int numPeriod);
  private:
    double m_rate;
};
#endif /*defined(_COMPOUNDINTCALC_) */

