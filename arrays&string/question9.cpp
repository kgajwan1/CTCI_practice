//question 9 CTCI arrays & strings
#include<bits/stdc++.h>
//is s2 a rotation of s1?
//best way is to check if s2 is subset if s1s1

bool isRotation(std::string s1, std::string s2){
    int len = s1.length();
    /*check if length of s1 and s2 aer same or not */
    if(len = s2.length() && len >0){
        std::string s1s1 = s1 + s1;
        if ( s1s1.find(s2) != std::string::npos ) {
		return true;
	} 
    }
    return false;
}

int main(){
    std::string s1 ="hello";
    std::string s2 ="lohel";
    std::cout <<std::boolalpha<<isRotation(s2,s1);
return 0;
}
