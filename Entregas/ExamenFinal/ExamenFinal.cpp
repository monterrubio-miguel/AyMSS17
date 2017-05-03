#include <iostream>
#include <string>

using namespace std;

class Visitor;
class GraphicElement
{
public:    
    std::string type;
    
    void setType(std::string x)
    {
        type = x;
    }
    
    string getType()
    {
        return type;
    }

    virtual GraphicElement* clonar() = 0;
    //virtual void accept(Visitor*) = 0;
};

template <class Tipo>
class Spacecraft : public GraphicElement
{
public:    
    virtual GraphicElement* clonar()
    {
        return new Tipo(dynamic_cast<Tipo&>(*this));    
    }
    
    //void accept(Visitor*);

}

class PlanetExplorer : public Spacecraft<PlanetExplorer>
{
public:
    PlanetExplorer()
    {
        instance = this;
    }
    static Singleton* instance;
}

class Colonization : public Spacecraft<Colonization>
{
public:
    Colonization()
    {
        instance = this;
    }
    static Singleton* instance;
}

class PlanetObservation : public Spacecraft<PlanetObservation>
{
public:
    PlanetObservation()
    {
        instance = this;
    }
    static Singleton* instance;
}

template <class Tipo>
class Asteroid : public GraphicElement
{
public:    
    virtual GraphicElement* clonar()
    {
        return new Tipo(dynamic_cast<Tipo&>(*this));    
    }
    
    //void accept(Visitor*);

}

class Stony : public Asteroid<Stony>
{
public: 
    Stony()
    {
        instance = this;
    }
    static Singleton* instance;
}

class Iron : public Asteroid<Iron>
{
public:
    Iron()
    {
        instance = this;
    }
    static Singleton* instance;
}

template <class Tipo>
class Planet : public GraphicElement
{
public:    
    virtual GraphicElement* clonar()
    {
        return new Tipo(dynamic_cast<Tipo&>(*this));    
    }
    
    //void accept(Visitor*);

}

class Desert : public Planet<Desert>
{
public:
    Desert()
    {
        instance = this;
    }
    static Singleton* instance;
}

class EarthAnalog : public Planet<EarthAnalog>
{
public:
    EarthAnalog()
    {
        instance = this;
    }
    static Singleton* instance;
}

/*class Visitor
{
public:
    virtual void visit(Spacecraft*) = 0;
    virtual void visit(Asteroid*) = 0;
    virtual void visit(Planet*) = 0;
};*/

int main()
{


}