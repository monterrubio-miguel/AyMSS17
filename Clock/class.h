#include <ctime>
#include <iostream>


class Hora{
    public:
        time_t t;
        tm* time2;
        void Time();
              
};

void Hora::Time()
{
    t = time(0);
    time2 = localtime(&t);
    std::cout << asctime(time2);
}

