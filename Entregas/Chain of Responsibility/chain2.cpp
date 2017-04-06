#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DNS
{
  public:
    address a;
    address b;
};

class Servidor1: public DNS
{
  public:
     Servidor1
     {
         a.dns = "a.com"
         a.ip = "1.1.1.1"
         
         b.dns = "b.com"
         b.ip = "1.1.1.2"
     }
};

class Servidor2: public DNS
{
  public:
     Servidor2
     {
         a.dns = "c.com"
         a.ip = "1.1.1.3"
         
         b.dns = "d.com"
         b.ip = "1.1.1.4"
     }
};

class Servidor3: public DNS
{
  public:
     Servidor3
     {
         a.dns = "e.com"
         a.ip = "1.1.1.5"
         
         b.dns = "f.com"
         b.ip = "1.1.1.6"
     }
};

class Servidor4: public DNS
{
  public:
     Servidor4
     {
         a.dns = "g.com"
         a.ip = "1.1.1.7"
         
         b.dns = "h.com"
         b.ip = "1.1.1.8"
     }
};

class Servidor5: public DNS
{
  public:
     Servidor5
     {
         a.dns = "i.com"
         a.ip = "1.1.1.9"
         
         b.dns = "j.com"
         b.ip = "1.1.1.10"
     }
};

class address
{
public:
    string dns;
    string ip;
};

int main()
{
  
}