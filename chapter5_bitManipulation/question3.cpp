//question 3 bit manipulation

#include<bits/stdc++.h>
int flipbit(unsigned int a)
{
    if(~a == 0)
    {
        return 8 *sizeof(int);
    }
    int currLength = 0;
    int prevLength = 0;
    int maxLength = 1;

    while (a != 0)
    {
        if(a&1 == 1)
        {
            ++currLength;
        }
        else if ((a & 1) ==0)
        {
                prevLength = (a&2) == 0?0 :currLength; 
            currLength = 0;
        }
        maxLength = std::max (prevLength + currLength,maxLength);
         a>>=1;
    }
    return maxLength+1;
}
int main()
{
    std::cout << flipbit(13)<<'\n';  
    // input 2 
    std::cout << flipbit(1775)<<'\n';
    // input 3 
    std::cout << flipbit(15); 
}