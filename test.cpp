#include <iostream>
#include <vector>
#include <string>

#define MAX_N 100
#define MAX_K 100

//Counter for number of times base case, memoisation case
int base=0;
int preCal=0;
int newCal=0;

//Calculate binomial coefficient
int binomialCoefficient(int n, int k, std::vector<std::vector<int>>& dp)
{
    //Base case
    if (k==0||k==n)
    {
        base++;
        return 1;
    }

    else if (dp[n][k]!= -1)
    {
        preCal++;
        return dp[n][k];
    }
    else
    {
        newCal++;
        dp[n][k] = binomialCoefficient(n-1,k-1,dp)+ binomialCoefficient(n-1,k,dp);
        return dp[n][k];
    }
}

int main()
{
    int numTestCases;
    std::cout << "No of times run: ";
    std::cin >> numTestCases;

    std::vector< std::vector<int> > dp( MAX_N +1, std::vector<int>(MAX_K+1,-1));

    for(int roundCtr =1 ; roundCtr <= numTestCases; roundCtr++)
    {
        std::cout<< "Round "<< roundCtr;
        int n,k;
        std::cout<< "n "<< std::endl;
        std::cin >> n;
        std::cout<< "k "<< std::endl;
        std::cin >> k;

        base=0;
        preCal=0;
        newCal=0;
        int result = binomialCoefficient(n,k,dp);

        //print the value
        std::cout<< "The value for C "<<result<<std::endl;
        std::cout<< "The value for base "<<base<<std::endl;
        std::cout<< "The value for preCal "<<preCal<<std::endl;
        std::cout<< "The value for newCal "<<newCal<<std::endl;


    }
    return 0;
}