#include <iostream>
#include <string>
#include <vector>
#include <queue>


class Videojuego
{
public:
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

	static Videojuego* genero(int z);

	/*template<class Tipo>
    static Videojuego* factoryMethod(std::string x, int y)
    {
        Tipo* tipo = new Tipo;
        tipo->creacion(x, y);
        return tipo;        
    }*/
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

Videojuego *Videojuego::genero(int z)
{
	switch(z)
		{
			case 1:
				return new estrategia;
				break;

			case 2:
				return new aventura;
				break;

			case 3:
				return new aprendizaje;
				break;

			default:
				return new Videojuego;
				break;
		}
}

class Almacen
{
public:
	std::vector<Videojuego*> Inventario;
	std::queue<Videojuego*> undo;

	Almacen()
	{
		instance = this;
	}

	static Almacen* instance;

	static Almacen* getInstance()
    {
        if(instance != 0)
        {
            return instance;
        }
        else
        {
            Almacen();
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
		int i = 0;
		do
		{
			std::cout << "Elegir género: " << std::endl << "1. Estrategia" << std::endl << "2. Aventura" << std::endl << "3. Aprendizaje" << std::endl << "0. Regresar al menú principal" << std::endl;
			std::cin >> i;
			Inventario.push_back(Videojuego::genero(i));
			/*switch(i)
			{
				case 1:
					//Inventario.push_back(Videojuego::factoryMethod<estrategia>(x,y));
					Videojuego* vid = Videojuego::factoryMethod<estrategia>(x,y);
					i=0;
					break;

				case 2:
					Inventario.push_back(Videojuego::factoryMethod<aventura>(x,y));
					i=0;
					break;

				case 3:
					Inventario.push_back(Videojuego::factoryMethod<aprendizaje>(x,y));
					i=0;
					break;

				case 0:
					std::cout << "Regresando al menú principal";
					return;
					break;
				default:
					std::cout << "Error. Intenta otra opción." << std::endl;
					break;
			}*/	
		}while((i != 0) || (i != 1) || (i!= 2) || (i != 3));
		
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

	}*/

	int buscar()
	{
		std::cout << "Cómo desea especificar el videojuego a buscar?" << std::endl << "1. Por número de serie" << std::endl << "2. Por nombre" << std::endl << "0. Regresar al menú principal" << std::endl;

		int x = 1;
		int y = 1;
		std::string z;
		do
		{
			std::cin >> x;
			switch(x)
			{
				case 1: 
				//por no. serie
					std::cout << "Introducir número de serie: ";
					std::cin >> y;

					for (int i = 0; i < Inventario.size(); i++)
					{
						if(y==Inventario[0]->serial)
						{
							return i;
						}

						else
						{
							return -1;
						}
					}

					break;

				case 2:
				//por nombre

					break;

				case 0:
					std::cout << "Regresando al menú principal";
					return -2;
					break;
			}
		} while(x != 0);
	}

	/*void contar()
	{

	}

	void imprimir()
	{

	}*/
};

Almacen* Almacen::instance = 0;

void menu(Almacen& inv)
{
	int x = 1;
	
	std::cout << std::endl << "Elegir una opción" << std::endl << "1. Crear Videojuego y agregar al inventario" << std::endl << "2. Eliminar un videojuego" << std::endl << "3. Recuperar últimos 3 videojuegos eliminados" << std::endl << "4. Ordenar juegos" << std::endl << "5. Buscar juego por nombre o número de serie" << std::endl << "6. Imprimir número total de videojuegos en el inventario" << std::endl << "7. Imprimir lista de todos los videojuegos"  << std::endl << "0. Salir del programa" << std::endl;
	do
	{
		std::cin >> x;
		switch(x)
		{
			case 1:
				//crear videojuego y agregar al inventario
				inv.agregar();
				break;

			case 2:
				//eliminar videojuegos

				break;
			
			case 3:
				//ctrl+z

				break;
			
			case 4:
				//ordenar juegos

				break;
			
			case 5:
				//buscar juego por no. serie o nombre
				inv.buscar();
				break;
			
			case 6:
				//no. total de juegos en inventario

				break;
			
			case 7:
				//imprimir todos los juegos

				break;

			case 0:
				//salir
				std::cout << std::endl << "Finalizando programa. Hasta luego.";
				return;
				break;
			
			default:
				std::cout << std::endl << "Error. Opción inválida. Intente de nuevo";
				break;
			
		}
	}while(!x != 0);
}

int main()
{
	Almacen* s = Almacen::getInstance();
	std::cout << std::endl << "El inventario ha sido creado..:" << s->instance << std::endl;
	menu(*s);
	return 1;
}