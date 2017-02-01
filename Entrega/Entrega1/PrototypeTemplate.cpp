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

    template<class SubClase>
    static Personaje* factoryMethod()
    {
        SubClase* subclase = new SubClase;
        subclase->correr();
        return subclase;
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
    Personaje* pe = Personaje::factoryMethod<Principe>();
    Personaje* v = Personaje::factoryMethod<Villano>();
    Personaje* pa = Personaje::factoryMethod<Princesa>();
    
    return 1;
}