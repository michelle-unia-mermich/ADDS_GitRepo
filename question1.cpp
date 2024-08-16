#include <iostream>
#include <math.h>    
#include <vector> 

int arithmetic(int d,int n)
{
    if (n==1)
    {
        return 1;
    }
    else
    {
        return d + arithmetic(d,n-1);
    }

}
/*
//this function is not needed
int geometric(int r,int n)
{
    if (n==1)
    {
        return 1;
    }
    else
    {
        return r*geometric(r,n-1);
    }
}
*/


std::vector<int> question1(int d, int r, int n)
{
    std::vector<int> result_vector;
    for (int i=1 ; i<=n ; i++)
    {
        int arithmetric = arithmetic(d,i);
        int temp_result = arithmetric * pow(r,i-1);
        result_vector.push_back(temp_result);
    }
    return result_vector;
}

