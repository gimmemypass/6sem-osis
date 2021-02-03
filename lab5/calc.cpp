#include "calc.h"
#include <sstream>

std::string calc(double a, double b, operation op){
    switch(op){
        case SUM:
            return std::to_string(a + b);
        case MUL:
            return std::to_string(a * b);
        case SQUARE_SUM:
            return std::to_string(a *a + b* b);
    }
}