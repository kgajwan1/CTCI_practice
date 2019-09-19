#include <bits/stdc++.h>

//more than 100 would cause 100 factorial
//Write a function to generate all possible n pairs of balanced parentheses. 

/*
 Keep track of counts of open and close brackets.

    Initialize these counts as 0.
    Recursively call the _printParenthesis() function until open bracket count is 
    less than the given n.
    If open bracket count becomes more than the close bracket count, 
    then put a closing bracket and recursively call for the remaining brackets.
    If open bracket count is less than n, then put an opening bracket and call _printParenthesis() 
    for the remaining brackets.
*/

//directly taking krish  munots algo, mine was slower
void print_all_parentheses_internal(size_t count, size_t opened, size_t closed, std::string args){

  if(closed > opened){
    return;
  }
  else if(opened > count){
    return;
  }
  else if(args.size()==2*count){
    std::cout << args << std::endl;
  }

  print_all_parentheses_internal(count,opened+1,closed,  args+"(");
  print_all_parentheses_internal(count,opened  ,closed+1,args+")");
}

void print_all_parentheses(size_t count){
  print_all_parentheses_internal(count, 0, 0, "");
}

int main(int argc, const char* argv[]) {
  print_all_parentheses(3);
  return 0;
}

   