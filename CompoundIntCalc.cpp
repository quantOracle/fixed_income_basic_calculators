#include "CompoundIntCalc.h"
#include <cmath>

CompoundIntCalc::CompoundIntCalc(double rate) :
m_rate(rate) {

}

CompoundIntCalc::~CompoundIntCalc(){

}

CompoundIntCalc::CompoundIntCalc(const CompoundIntCalc &v):
m_rate(v.m_rate) {

}
CompoundIntCalc &CompoundIntCalc::operator =(const CompoundIntCalc &v) {
    if(this != &v) { 
        this->m_rate = v.m_rate;
        }
    return *this;
}

double CompoundIntCalc::period(double value, int numPeriod) {
    double f = value * pow(1 + m_rate, numPeriod);
    return  f;  
}

double CompoundIntCalc::compound(double value, int numPeriod) {
    double f = value * exp(m_rate * numPeriod);
    return f;   
}
