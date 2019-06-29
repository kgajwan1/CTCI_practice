//question 6 CTCI 
//basic string compression
//aaaabbbbcccc  = a4b4c4
//aaabbaacc == a3b2a2c2
//bad method (reiterate, copy and count repeats) and string builder
//good method would be to use string builder

#include<bits/stdc++.h>

std::string compress(std::string str)
{
	size_t original_length = str.length();
	if(original_length < 2)
	{
		return str;
	}
	std::string out{""};
	int count = 1;
	for (int i = 1 ;i < original_length ;++i)
	{
		if(str[i-1] == str[i])
		{
			++count;
			//std::cout<<count<<'\n';
		}
		else
		{
			out+=str[i-1];
			out += std::to_string(count);
			count =1;
		}
		if(out.length()>=original_length){
			return str;
		}
	}
	out += str[str.length()-1];
	out += std::to_string(count);
	if (out.length() >= original_length) {
		return str;
	}
return out;
}

int main()
{
	std::string str = "aaaaaaaaaaaaabbbbbbbbbbbfyyyyyyyyyyytho";
	std::string out;
	//std::cout << "Enter a string:\n";
	//std::cin >> str;
	out = compress(str);
	if (str.compare(out)) {
		std::cout << str << " can be compressed to " << out << std::endl;
	} else {
		std::cout << str << " can not be compressed\n";
	}
	return 0;
}
