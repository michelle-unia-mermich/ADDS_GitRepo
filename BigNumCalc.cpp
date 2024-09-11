#include "BigNumCalc.h"
#include <vector>
#include <algorithm>

std::list<int> BigNumCalc::buildBigNum(std::string numString)
{
    std::list<int> l = {};
    int length=numString.length();
    for(int i=0; i<length ; i++)
    {
        //*REMEMBER TO CONVERT CHAR TO INT HAVE TO MINUS 48 
        l.push_back( ((int)((char)numString[i])-48) );
    }
    return l;
}

std::string BigNumCalc::convertbacktoString(std::list<int> num)
{
    std::string result="";
    for(auto i: num)
    {
        char new_char = (char) (i+48);
        result += new_char;
    }
    return result;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2)
{
    std::string str1=convertbacktoString(num1);
    std::string str2=convertbacktoString(num2);
    // Before proceeding further, make sure length
    // of str2 is larger.

    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    std::string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    std::reverse(str1.begin(), str1.end());
    std::reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        // Calculate carry for next step
        carry = sum/10;
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    std::reverse(str.begin(), str.end());
 
    return buildBigNum(str);
}

// Returns true if str1 is smaller than str2, 
// else false. 
bool isSmaller(std::string str1, std::string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return true; 
    if (n2 < n1) 
        return false; 
  
    for (int i = 0; i < n1; i++) { 
        if (str1[i] < str2[i]) 
            return true; 
        else if (str1[i] > str2[i]) 
            return false; 
    } 
    return false; 
} 

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2)
{
    std::string str1=convertbacktoString(num1);
    std::string str2=convertbacktoString(num2);
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    std::string str = ""; 
  
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n1 - n2; 
  
    // Initially take carry zero 
    int carry = 0; 
  
    // Traverse from end of both strings 
    for (int i = n2 - 1; i >= 0; i--) { 
        // Do school mathematics, compute difference of 
        // current digits and carry 
        int sub = ((str1[i + diff] - '0') - (str2[i] - '0') 
                   - carry); 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of str1[] 
    for (int i = n1 - n2 - 1; i >= 0; i--) { 
        if (str1[i] == '0' && carry) { 
            str.push_back('9'); 
            continue; 
        } 
        int sub = ((str1[i] - '0') - carry); 
        if (i > 0 || sub > 0) // remove preceding 0's 
            str.push_back(sub + '0'); 
        carry = 0; 
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return buildBigNum(str); 
}

std::list<int> BigNumCalc::mul(std::list<int> list1, std::list<int> list2)
{
    std::string num1=convertbacktoString(list1);
    std::string num2=convertbacktoString(list2);
    // Convert the input numbers from strings to vectors of integers
    std::vector<int> vec1(num1.size());
    for (unsigned int i = 0; i < num1.size(); i++) {
        vec1[i] = num1[num1.size() - i - 1] - '0';
    }
    std::vector<int> vec2(num2.size());
    for (unsigned int i = 0; i < num2.size(); i++) {
        vec2[i] = num2[num2.size() - i - 1] - '0';
    }

    // Initialize the result vector with zeros
    std::vector<int> result(vec1.size() + vec2.size());

    // Multiply each digit in vec2 with vec1 and add the result to the appropriate position in the result vector
    for (unsigned int i = 0; i < vec2.size(); i++) {
        int carry = 0;
        for (unsigned int j = 0; j < vec1.size(); j++) {
            int product = vec1[j] * vec2[i] + carry + result[i + j];
            carry = product / 10;
            result[i + j] = product % 10;
        }
        result[i + vec1.size()] = carry;
    }

    // Remove leading zeros from the result vector and convert it back to a string
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    std::string str(result.size(), '0');
    for (unsigned int i = 0; i < result.size(); i++) {
        str[result.size() - i - 1] = result[i] + '0';
    }
    return buildBigNum(str);

}