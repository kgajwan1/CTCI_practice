//binary to string
//numbers between 0 and 1
#include<bits/stdc++.h>

std::string printBinary(double num)
{
    std::cout <<num <<"\t";
    if(num > 1 || num < 0)
       { 
           return "ERROR";
       }
    if (num == 1)
    {
        return "1";
    }
    if(num ==0)
    {
        return "0"; 
    }
    //compare to 0.5    
    std::string answer ;
    double frac = 0.5;
    answer.append(".");
    while (num > 0)
    {
        if (answer.length() >= 32)
        {
            return "ERROR";
        }
        if (num >= frac)
        {
            answer.append("1");
            num = num - frac;
        }
        else 
        {
            answer.append("0");
        }
        frac/=2;
    }
    return answer;
}

int main()
{
    double number = 0.50;
    double number2 = 0.625;
    double number3 = 0.72;
    std::cout <<printBinary(number)<<'\n';
    std::cout <<printBinary(number2)<<'\n';
    std::cout <<printBinary(number3)<<'\n';
}