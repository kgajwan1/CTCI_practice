#include<bits/stdc++.h>
//method 1 O(n * n!)
//easier
void permute(std::string s, int l, int r)
{
    if(l == r)
    {
        std::cout << s << '\n';
    }
    else 
    {
        for (int i = l; i<= r;i++)
        {
            std::swap(s[l],s[i]);
            permute(s,l+1,r);
            std::swap(s[l],s[i]);
        }
    }
}

//way 2
 void findPermutations(std::string str, std::string curr,std::vector<std::string> &res)
 {
     int n = str.size();
     if(!n)
     {
         res.push_back(curr);
         return;
     }
     
     for (int i = 0; i< n;++i)
     {
        std::string first = curr + str.substr(i,1);
		std::string rem = str.substr(0,i) + str.substr(i+1,n-i-1);
        findPermutations(rem,first,res);   
     }
 }

int main()
{
    std::string str = "ABC";  
    int n = str.size();  
    permute(str, 0, n-1);  
    std::string curr ="";
	std::vector<std::string> res;
	findPermutations(str,curr,res);
    std::cout <<" trying way 2\n";
	for (int i = 0; i < res.size(); ++i)
		std::cout<<res[i]<<'\n';
    return 0;  
}