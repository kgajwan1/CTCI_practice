#include<bits/stdc++.h>

#define num_stacks 5;
int indice = 0;
std::vector<std::stack<int>*> vec;

bool initialized = false;

void init_stacks()
{
    std::stack<int> *s = new std::stack<int>;
    vec.push_back(s);
}

void stack_push(int v)
{
    if(initialized == false)
    {
        initialized  = true;
    }

    std::stack<int> *s = vec.at(indice) ;
    if(s->size() == 5)
    {
        s = new std::stack<int>;
        vec.push_back(s);
        indice++;
    } 
    s->push(v);
}

void stack_pop()
{
    std::stack<int> *s  = vec.at(indice) ;
    if(indice > 0)
    {
        if (s->size() == 0)
        {
            delete s;
            indice--;
            s = vec.at(indice); 
        }
        s->pop();
    }
    
    else {
        s->pop();
        }   
    
}

bool stack_top(int &v)
{
    std::stack<int> *s = vec.at(indice);
    if(s->size() == 0 && indice == 0){
        
        return false;
    }
    if(s->size() == 0){
        delete s;
        indice --;
        s = vec.at(indice);
    }
    v = s->top();

    return true;
}

void deinit_stacks()
{
    std::stack<int> *s;

    for(int i = 0; i <= indice; i++){
        s = vec.at(i);
        delete s;
    }
}
int main(int argc, char* argv[])
{
    init_stacks();

    for(int i = 0; i < 30; i++){
        stack_push(i);
        std::cout << "Push: Stack indice " << indice << " -- " << i <<'\n'; 
    }

    for(int i = 0; i < 40; i++){
        int v;
        int b = stack_top(v);
        stack_pop();

        if(b){
           std::cout << "Stack indice " << indice << " -- " << v << '\n';
        }
        else{
            std::cout << "No more elements in stack !\n";
        }
    }

    for(int i = 0; i < 10; i++){
        stack_push(i);
        std::cout << "Push: Stack indice " << indice << " -- " << i << '\n'; 
    }

    for(int i = 0; i < 15; i++){
        int v;
        int b = stack_top(v);
        stack_pop();

        if(b){
            std::cout << "Stack indice " << indice << " -- " << v << '\n';
        }
        else{
            std::cout << "No more elements in stack !\n";
        }
    }


    deinit_stacks();

 return 0;
}