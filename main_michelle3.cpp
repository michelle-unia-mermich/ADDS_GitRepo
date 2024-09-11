#include "BigNumCalc.h"

int main()
{
    BigNumCalc calc;
    std::list<int> num1= calc.buildBigNum("1234567890");
    std::list<int> num2 =calc.buildBigNum("9876543210");
    std::list<int> num3 = calc.add(num1, num2);
    std::cout<< calc.convertbacktoString(num3)<<std::endl;

    std::list<int> num4= calc.buildBigNum("9876543210");
    std::list<int> num5 =calc.buildBigNum("1234567890");
    std::list<int> num6 = calc.sub(num4,num5);
    std::cout<< calc.convertbacktoString(num6)<<std::endl;

    std::list<int> num7= calc.buildBigNum("12341234");
    std::list<int> num8 =calc.buildBigNum("2");
    std::list<int> num9 = calc.mul(num7,num8);
    std::cout<< calc.convertbacktoString(num9)<<std::endl;
    return 0;
}