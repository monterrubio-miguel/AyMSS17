#include <iostream>

using namespace std;

class Child
{
public:
	int* p;
	Child()
	{
		p = new int;
	}
	~Child()
	{
		delete p;
		p = NULL;
	}
};

int main()
{
	Child a;
	Child b = a;
	*(a.p) = 5;
	cout << *(b.p);
}