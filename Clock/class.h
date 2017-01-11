#include <ctime>
#include <iostream>


class Hour{
    private:
        Hour()
        {
            Instance = this;
        }
        static Hour* Instance;
    
    public:
        void thingamajig()
        {
            std::cout << Instance << std::endl;
        }
        static Hour* getInstance()
        {
            if (Instance != 0)
            {
                return Instance;
            }
            
            else
            {
                Hour();
                return Instance;
            }
        }
        time_t t;
        tm* time2;
        void Time()
        {
            t = time(0);
            std::cout << asctime(localtime(&t));
        };
              
};


Hour* Hour::Instance = 0;
