#include"potato.h"
#include<bits/stdc++.h>

int main()
{
    potato p ;
    p.quantity = 10;
    int weight = p.get_weight() ; 
    int volume = p.get_volume();
    std::cout << weight<<'\n';
    std::cout << volume ;
}
