class FactoryMethod
{
    protected:
        virtual Product* factoryMethod() = 0;
    public:
        static Product* create()
        {
            Product* p = factoryMethod();
            p->SetUp();
            return p;
        }
};