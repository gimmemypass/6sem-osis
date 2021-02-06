#include <string>

enum operation{
    SUM = 1,
    MUL = 2,
    SQUARE_SUM = 3
};

// std::string calc(std::string &raw);
std::string calc(double a, double b, operation op);