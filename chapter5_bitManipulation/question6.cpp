//question 5 is debugging,so i am doing question 6
//after 4
///how many bits do you need to change to convert one bit to 
//another

#include<bits/stdc++.h>
int flipBits(int a,int b)
{
    int count = 0;
    int c = a ^b;
   // std::cout <<c;
    while (c != 0)
    {
        count += (c&1);
        c >>= 1;
    }
    return count;
}

int main()
{
    int a = 11;
    int  b =5;

    std::cout << flipBits(a,b)<<'\n';

}