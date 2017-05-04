//Miguel Monterrubio3
//A01022153

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Asteroid;
class Planet;

class Spacecraft
{
public:
    string type;
    template<class T>
    static Spacecraft* factoryMethod()
    {
        return T::getInstance();
    }
    template<class T>
    void Collision(T* x);
    
};

class Exploration : public Spacecraft
{
protected:
    Exploration()
    {
        instance = this;
        type = "Spacecraft: Planet Exploration Ship";
        cout << endl << "Created " << type << endl;
    }

    static Exploration* instance;

public:
    static Exploration* getInstance()
    {
        static Exploration instance;
        return &instance;
    }
    
};

Exploration* Exploration::instance = 0;

class Colonization : public Spacecraft
{
protected:
    Colonization()
    {
        instance = this;
        type = "Spacecraft: Colonization Ship";
        cout << endl << "Created " << type << endl;
    }

    static Colonization* instance;

public:
    static Colonization* getInstance()
    {
        static Colonization instance;
        return &instance;
    }
   
};

Colonization* Colonization::instance = 0;

class Observation : public Spacecraft
{
protected:
    Observation()
    {
        instance = this;
        type = "Spacecraft: Planet Observation Ship";
        cout << endl << "Created " << type << endl;
    }

    static Observation* instance;

public:
    static Observation* getInstance()
    {
        static Observation instance;
        return &instance;
    }
    
};

Observation* Observation::instance = 0;

class Asteroid
{
public:
    string type;
    template<class T>
    static Asteroid* factoryMethod()
    {
        return T::getInstance();
    }
    template<class T>
    void Collision(T* x);
};

class Stony : public Asteroid
{
protected:
    Stony()
    {
        instance = this;
        type = "Asteroid: Stony Meteorite";
        cout << endl << "Created " << type << endl;
    }

    static Stony* instance;
    
public:
    static Stony* getInstance()
    {
        static Stony instance;
        return &instance;
    }
    
};

Stony* Stony::instance = 0;

class Iron : public Asteroid
{
protected:
    Iron()
    {
        instance = this;
        type = "Asteroid: Iron Meteorite";
        cout << endl << "Created " << type << endl;
    }

    static Iron* instance;
    
public:
    static Iron* getInstance()
    {
        static Iron instance;
        return &instance;
    }
    
};

Iron* Iron::instance = 0;

class Planet
{
public:
    string type;
    template<class T>
    static Planet* factoryMethod()
    {
        return T::getInstance();
    }
};

class Desert : public Planet
{
protected:
    Desert()
    {
        instance = this;
        type = "Planet: Desert Planet";
        cout << endl << "Created " << type << endl;
    }

    static Desert* instance;
    
public:
    static Desert* getInstance()
    {
        static Desert instance;
        return &instance;
    }
    
};

Desert* Desert::instance = 0;

class EarthAnalog : public Planet
{
protected:
    EarthAnalog()
    {
        instance = this;
        type = "Planet: Earth Analog";
        cout << endl << "Created " << type << endl;
    }

    static EarthAnalog* instance;
    
public:
    static EarthAnalog* getInstance()
    {
        static EarthAnalog instance;
        return &instance;
    }
    
};

EarthAnalog* EarthAnalog::instance = 0;

template<class T>
void Spacecraft::Collision(T* x)
{
    cout << endl << type << " collided with " << x->type << endl;
}

template<class T>
void Asteroid::Collision(T* x)
{
    cout << endl << type << " collided with " << x->type << endl;
}

int main()
{
    vector<Spacecraft*> Spacecrafts;

    Spacecrafts.push_back(Spacecraft::factoryMethod<Exploration>());
    Spacecrafts.push_back(Spacecraft::factoryMethod<Colonization>());
    Spacecrafts.push_back(Spacecraft::factoryMethod<Observation>());

    vector<Asteroid*> Asteroids;

    Asteroids.push_back(Asteroid::factoryMethod<Stony>());
    Asteroids.push_back(Asteroid::factoryMethod<Iron>());    

    vector<Planet*> Planets;

    Planets.push_back(Planet::factoryMethod<Desert>());
    Planets.push_back(Planet::factoryMethod<EarthAnalog>());

    cout << endl << endl;

    for(int i = 0; i < Spacecrafts.size(); i++)
    {
        for(int j = 0; j < Asteroids.size(); j++)
        {
            Spacecrafts[i]->Collision(Asteroids[j]);
        }

        for(int k = 0; k < Planets.size(); k++)
        {
            Spacecrafts[i]->Collision(Planets[k]);
        }
    }

    for(int i = 0; i < Asteroids.size(); i++)
    {
        for(int j = 0; j < Planets.size(); j++)
        {
            Asteroids[i]->Collision(Planets[j]);
        }
    }
}