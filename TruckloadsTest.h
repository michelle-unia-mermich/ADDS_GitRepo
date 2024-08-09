#ifndef TRUCKLOADSTEST_H
#define TRUCKLOADSTEST_H
#include <iostream>
#include <vector>
#include "Truckloads.h"
#include <string>
#include <sstream>

class TruckloadTest
{
    public:
	void run_test(int Case) 
    { if ((Case == -1) || (Case == 0)) test_case_0(); 
    if ((Case == -1) || (Case == 1)) test_case_1(); 
    if ((Case == -1) || (Case == 2)) test_case_2(); }
	
    private:
	template <typename T> std::string print_array(const std::vector<T> &V) 
    {   std::ostringstream os; 
        os << "{ "; 
        for (typename std::vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; 
        return os.str(); 
    }
	void verify_case(int Case, const int &Expected, const int &Received) 
    {   std::cout << "Test Case #" << Case << "..."; 
        if (Expected == Received) 
        {
            std::cout << "PASSED" << std::endl; 
        }
        else 
        { 
            std::cout << "FAILED" << std::endl; 
            std::cout << "\tExpected: \"" << Expected << '\"' << std::endl; 
            std:: cout << "\tReceived: \"" << Received << '\"' << std::endl; 
        } 
    }
	void test_case_0() { int Arg0 = 14; int Arg1 = 3; int Arg2 = 6; Truckloads truckload; verify_case(0, Arg2, truckload.numTrucks(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 15; int Arg1 = 1; int Arg2 = 15; Truckloads truckload; verify_case(1, Arg2, truckload.numTrucks(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1024; int Arg1 = 5; int Arg2 = 256; Truckloads truckload; verify_case(2, Arg2, truckload.numTrucks(Arg0, Arg1)); }

};
#endif