#include <iostream>
using namespace std;

class Personaje
{
protected:
    Personaje()
    {
        instance = this;
    }
    
    static Personaje* instance;

public:
    virtual void correr() = 0;
    void doStuff(){std::cout << instance << std::endl;}

    template<class SubClase>
    static Personaje* factoryMethod()
    {
        if(instance != 0)
        {
            return instance;
        }
        else
        {
            SubClase* subclase = new SubClase;
            subclase->correr();
            return subclase;
        }
        
    }
};


class Principe : public Personaje
{   
public:
    void seleccionarArma();
    void atacar();
    void correr()
    {
        cout << "El principe corre rápido" << endl;
    }
};

class Princesa : public Personaje
{
public:
    void gritar();
    void correr()
    {
        cout << "La princesa corre medio lento" << endl;
    }
};

class Villano : public Personaje
{
public:
    void doStuff(){std::cout << instance << std::endl;}
    void atacar();
    void atraparPricnesa();
    void correr()
    {
        cout << "El villano no necesita correr" << endl;
    }
};

class VillanoVolador : public Personaje
{
public:
    void correr()
    {
        cout << "También puede volar" << endl;
    }
};

Personaje* Personaje::instance = 0;

int main()
{
    Personaje* pr1 = Personaje::factoryMethod<Principe>();
    pe->doStuff();
    
    Personaje* pr2 = Personaje::factoryMethod<Principe>();
    pa->doStuff();


    
    return 1;
}