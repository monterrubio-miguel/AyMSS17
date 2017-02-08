#include <iostream>
#include <string>
#include <vector>

void menu();

class Videojuego
{
private:
	std::string compania;
	std::string plataforma;
	int price;
	int serial;
	std::string nombre;

	virtual void setName(std::string x)
	{
		nombre = x;
	}

	virtual void setPrice(int x)
	{
		price = x;
	}

	virtual void setSerial(int x)
	{
		serial = x+10000;
	}

	virtual std::string getName()
	{
		return nombre;
	}

	virtual std::string getPlatform()
	{
		return plataforma;
	}

	virtual int getPrice()
	{
		return price;
	}

	virtual int getSerial()
	{
		return serial;
	}

	virtual std::string getCompany()
	{
		return compania;
	}
public:
	Videojuego()
	{
		compania = "Chell A.S.";
		plataforma = "PC";
	}
	void creacion(std::string x, int y)
	{
		std::cout << std::endl << "Te encuentras en la etapa de creación." << std::endl; 
		setName(x);
		setPrice(y);
		diseno();
		return;
	}
	void diseno()
	{
		std::cout << "Te encuentras en la etapa de diseño" << std::endl;
		planificacion();
		return;
	}
	void planificacion()
	{
		std::cout << "Te encuentras en la etapa de planificación" << std::endl;
		produccion();
		return;
	}
	void produccion()
	{
		std::cout << "Te encuentras en la etapa de producción" << std::endl;
		pruebas();
		return;
	}
	void pruebas()
	{
		std::cout << "Te encuentras en la etapa de pruebas" << std::endl;
		terminado();
		return;
	}
	void terminado()
	{
		std::cout << "El juego " << getName() << " ha sido terminado con éxito" << std::endl << std::endl;
		return;
	}

	template<class Tipo>
    static Videojuego* factoryMethod(std::string x, int y)
    {
        Tipo* tipo = new Tipo;
        tipo->creacion(x, y);
        return tipo;        
    }
};

class estrategia : public Videojuego
{
	public:
		int jugadores;
		estrategia()
		{
			jugadores = 2;
		}
};

class aventura : public Videojuego
{
	public:
		std::string areamapa;
		aventura()
		{
			areamapa = "120 km^2";
		}
};

class aprendizaje : public Videojuego
{
	public:
		std::string clasificacion;
		aprendizaje()
		{
			clasificacion = "E for Everyone";
		}
};


class Almacen
{
public:
	std::vector<Videojuego*> Inventario;
	Almacen()
	{
		instance = this;
	}

	static Singleton* instance;

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
    }

	void agregar()
	{
		std::string x;
		int y;
		std::cout << std::endl << "Escribir nombre del juego: ";
		std::cin >> x;
		std::cout << std::endl << "Declarar precio del juego:";
		std::cin >> y;
		std::cout << "Elegir género: " << std::endl << "1. Estrategia" << std::endl << "2. Aventura" << std::endl << "3. Aprendizaje" << std::endl;
		int i;
		std::cin >> i;
		switch(i)
		{
			case 1:
				Inventario.push_back(Videojuego::factoryMethod<estrategia>(x,y));
				break;

			case 2:
				Inventario.push_back(Videojuego::factoryMethod<estrategia>(x,y));
				break;

			case 3:
				Inventario.push_back(Videojuego::factoryMethod<estrategia>(x,y));
				break;
			default:
				std::cout << "Error. Regresando al menú principal" << std::endl;
				break;
		}
	}

	/*void eliminar()
	{

	}

	void deshacer()
	{

	}

	void ordenar()
	{

	}

	void ordenar2()
	{

	}

	void buscar()
	{
		
	}

	void contar()
	{

	}

	void imprimir()
	{

	}*/
};

Singleton* Singleton::instance = 0;

int main()
{
	menu();
	return 1;
}

void menu()
{
	Singleton* s = Singleton::getInstance();
	al->agregar();
}