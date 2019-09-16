//count ways to reach top of stairs in 1 2 or 3 steps
#include<bits/stdc++.h>

//recursive method
int count_recursive(int n)
{
    if(n ==1 || n == 0)
    {
        return 1;
    }
    else if (n ==2 )
    {
        return 2;
    }
    else return count_recursive(n-3)+ count_recursive(n-2)+count_recursive(n-1);
}
//using vector caching

int countWays(int n,std::vector<int> v)
{
    if(n == 0)
    {
        return 1;
    }

    int sum = 0;
    for (int i = 0;i<v.size();i++)
    {
        if(n>= v[i])
        {
            sum = sum + countWays((n-v[i]),v);
        }
    }
    return sum;
}

//method 2, using memorization
int countways (int n)
{
    int result[n+1];
    result[0] =1;
    result[1] =1;
    result[2] = 2;
    for (int i= 3;i<=n;i++)
    {
        result[i] = result[i-1]+ result[i-2]+ result[i-3];
    }
    return result[n];
}

int main()
{
    int n = 6;
    std::vector<int> v;
    v.push_back(1);
	v.push_back(2);
	v.push_back(3);
    int csteps = countways(n);
    std::cout << csteps;
    int csteps2 = countWays(n,v);
    std::cout << '\n'<<csteps2;
    int crecursive = count_recursive(n);
    std::cout<< '\n'<<crecursive;
}

