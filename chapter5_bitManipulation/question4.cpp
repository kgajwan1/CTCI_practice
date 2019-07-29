//question 4
//given a positive integer print a next smallest positive and next 
//largest positive number that contains same number of ones

#include <bits/stdc++.h> 

int getNextBit(int n)
{
    int c = n;
    int c0=0;
    int c1 =0;
     
     while (((c&1) ==0 ) && (c!=0))
     {
        //count of zeroes
        c0++;
        c >>=1;
     //  std::cout << c<<'\n';
      //  std::cout << c0<<'\n'; 
     }
     while ((c&1) ==1)
     {  // count of ones
        c1++;
        c >>=1;
     }
    if ((c0+c1) == 31 ||(c0+c1) ==0 )
    {
        return -1;
    }
    int p = c0 + c1;
    //flip bit at position p
    n |= (1<<p);
    //1<<2  = 4
    //std::cout << ~((1<<p)-1)<<'\n';
    n &= ~((1<<p)-1);
    n |= ((1<<(c1-1)))-1;
    return n;
}

int getPrevBit(int n) {
    int c = n;
    int c0 =0;
    int c1 = 0;
    while ((c&1)==1)
    {
        c1++;
        c>>=1;
    }
   if (c == 0)
    {
        return -1;
    }
    while (((c & 1) == 0) && (c!=0))
    {
        c0++;
        c>>=1;
    } 

    int p = c0+c1;
    if(p == 32)
    {
        return -1;
    }    
    //most important segment 
    // std::cout <<(~0)<<'\n';
    n = n & ((~0) << (p + 1));   
   // Sequence of (c1+1) ones 
    int mask = (1 << (c1 + 1)) - 1;  
    n = n | mask << (c0 - 1); 
    return n;
}

int main()
{
    int n = 15;
    //std::cout << getNext(n)<<'\n';

     std::cout << getNextBit(n)<<'\n';
    //std::cout << getPrev(n)<<'\n';

     std::cout << getPrevBit(n)<<'\n';
}