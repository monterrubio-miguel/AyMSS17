#include <iostream>
struct A
{
    int x, y;
    A() : x(0) //default constructor, default initialization
    {
        std::cout << "Default constructor" << std::endl;
    }
    
    explicit A(int x, int y) : x(x), y(y) //params constructor
    {
         std::cout << "Params constructor" << std::endl;
    }
    
    A(const A&)
    {
        //this->x = A.x;
        std::cout << "Copy constructor" << std::endl;
    }
};

A llamaCopyConst(A a)
{
    A temp(a);
    return temp;
}

int main()
{
    A uno;
    A dos(5, 10);
    A tres(dos);
    llamaCopyConst(tres);
}