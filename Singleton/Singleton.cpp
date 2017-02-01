#include<iostream>

class Singleton
{
private:
    Singleton()
    {
        instance = this;
    }
    
    static Singleton* instance;

public:
    void doStuff(){std::cout << instance << std::endl;}
    
    static Singleton* getInstance()
    {
        if(instance != 0)
        {
            return instance;
        }
        else
        {
            Singleton();
            return instance;
        }
        
        //second shorter version
        //static Singleton instance;
        //return &instance;
    }
};

Singleton* Singleton::instance = 0;

int main()
{
    Singleton* s = Singleton::getInstance();
    s->doStuff();
    Singleton* ss = Singleton::getInstance();
    ss->doStuff();
    //delete s;
}