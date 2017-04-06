class Base
{
    public:
        virtual Base* clone() = 0;
};

class SubClass : public Base
{
    public:
        Base* clone()
        {
             return this;
        }
};

int main()
{
    Base* a = new SubClass();
    
    Base* b = a->clone();
}