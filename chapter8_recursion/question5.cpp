//recursively multiply w/o multiplication

#include<bits/stdc++.h>

//lazy one
//time complexity O(smaller)
int multi (int a, int b)
{
    int val = a;
    int sum = 0;
    while (val --)
    {
        sum += b;
    }
    return sum;
}

//doing it in log time
int multiply (int a,int b, std::vector<int> &v)
{
    int bigger = a < b ? b:a;
	int smaller = a <b ? a:b;

	if (smaller==0)
		return 0;

	if (smaller==1)
		return bigger;
    if(v[smaller] != -1)
        return v[smaller];
    int s = smaller>>1;//divide by 2

    int side1 = multiply(s,bigger,v);
    int side2 = 0;
    if(smaller %2 )
        side2 = side1+ bigger;
    else 
        side2 = side1; 

    v[smaller] = side2+side1;
	
  return side1+side2;
}
int main()
{	
	int m = 7, n = 6;
	int smaller = m>n?n:m;
	int bigger = m>n?m:n;
	std::vector<int> dp(smaller+1,-1);
    std::cout << multi (smaller,bigger)<<'\n';
	std::cout<<multiply(smaller,bigger,dp)<<'\n';
	return 0;
}