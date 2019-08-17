//swap num
#include<bits/stdc++.h>
//need pass by reference
//when you pass by value, a copy is generated and when
//function is over, memory is released, so values do not change
//so when we do something that requires modifying values of 
//orignal stuff, we pass by reference 
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swap2(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 10;
    int b = 20;
    std::cout << "before swap"<< a << '\t'<<b<<'\n';
    swap(a,b);
    std::cout << "after swap"<< a << '\t'<<b<<'\n';
    swap2(a,b);

    std::cout << "after swap by reference"<< a << '\t'<<b<<'\n';


}