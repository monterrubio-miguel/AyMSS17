#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DNS
{
  public:
    string name;
    address a;
    address b;
    
    string checkaddress(string value)
    {
        if(value == a.dns)
        {
            return a.ip;
        }
        
        elseif(value == b.dns)
        {
            return b.ip;
        }
        
        else
        {
            delegate();
        }
    }
    
    void delegate()
    {
        
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