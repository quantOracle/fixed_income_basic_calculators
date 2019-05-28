#include "CompoundIntCalc.h"
#include <iostream>

int mainCompoundIntCalc(int argc, const char *argv[]) {
    if(argc !=4) {
        std::cout << "Use: progName <interest rate> <present value> <num periods>" << std::endl;
        return 1;
    }
    
double rate = atof(argv[1]);
double value = atof(argv[2]);
int num_period = atoi(argv[3]);

CompoundIntCalc cCalc(rate);
double result = cCalc.period(value, num_period);
double cResult = cCalc.compound(value, num_period);

std::cout << "The value after compounded interest is " << result << std::endl;
std::cout << "The value after continous compounding " << cResult << std::endl;

return 0;
}

//  compound 0.05 1000 4
// The value after compounded interest is 1215.51
// The value after continous compounding is 1221.4
