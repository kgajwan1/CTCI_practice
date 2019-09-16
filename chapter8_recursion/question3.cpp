/*
 A magic index in an array A[ 1 .•. n-1] is defined to be an index such that A[ i] =  i. Given a sorted 
 array of distinct integers, write a method to find a magic index, if one exists, in array A. */
#include <bits/stdc++.h>

//brute force

int magicIndex(std::vector<int> v)
{
    for (int i = 0; i<v.size(); i++)
    {
        if (v[i] == i)
        {
            return i;
        }
    }
    return -1;
}

//since array is sorted, we use binary search
int findMagicUtil(std::vector<int> v, int start, int end)
{
    int n = v.size();
    if (start<0 || end >= n)//aoob
    {
        return -1;
    }
    if(start > end)
    {
        return -1;
    }

    int mid = start + (end-start)/2; //to avoid overflow
    if (mid == v[mid])
    {
        return mid;
    }
    else
    { 
        if (findMagicUtil(v,start , std::min(v[mid],mid)) != -1 )
            {
                return findMagicUtil(v,start,std::min(v[mid],mid));
            }
    		return (findMagicUtil(v,std::max(v[mid],mid),end));
    }
}

int findMagicIndex(std::vector<int> v){

	int n = v.size();
	if(n==0){
		return -1;
	}

	return findMagicUtil(v,0,n-1);
}
int main()
{
    std::vector<int> v; 
	v.push_back(-10);
	v.push_back(-1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(8);
	v.push_back(9);
	v.push_back(12);
	v.push_back(13);

	std::cout<<magicIndex(v)<<'\n';
    std::cout<<findMagicIndex(v)<<'\n';

	return 0;
}