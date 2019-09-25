// question 11
//Given an infinite number of quarters (25 cents), dimes (1 O cents), nickels (5 cents), and pennies (1 cent), 
//write code to calculate the number of ways of representing n cents
#include<bits/stdc++.h>

//basic 
int makeChange (int amt,int *denoms, int index ,int size)
{    
    if (index >= size-1) 
        {
            return 1;
        } 
    int denomAmount =  denoms[index];
    int ways = 0; 
    for (int i =0;i*denomAmount <= amt;  i++) 
    {
        int amountRemaining = amt - i * denomAmount; 
        ways+= makeChange(amountRemaining, denoms, index + 1,size);
    }
    return ways;
}

int makeChange(int n)
{
    int denoms[] = {25,10,5,1};
    int size = sizeof(denoms)/sizeof(denoms[0]);
    int u = makeChange(n,denoms,0,size);
    return u;
}


int main()
{
    int amt = 10;
    std::cout<< makeChange(amt);
    int denoms[] = {25,10,5,1};
    int n =1;
}