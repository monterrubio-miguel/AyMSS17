#include<iostream>

using namespace std;

class Visitor;
class Document
{
protected:
    string quienSoy;
public:
    string getQuienSoy(){return quienSoy;}
    virtual void accept(Visitor*) = 0;
};

class Texto : public Document
{
public:
    Texto()
    {
        quienSoy = "Texto";
    }
    void accept(Visitor*);
};

class Formato : public Document
{
public:
    Formato()
    {
        quienSoy = "Formato";
    }
    void accept(Visitor*);
};

class Imagen : public Document
{
public:
    Imagen()
    {
        quienSoy = "Imagen";
    }
    void accept(Visitor*);
};

class Printer
{
protected:
    string quienSoy;
public:
    string getQuienSoy(){return quienSoy;}
    virtual void accept(Visitor*) = 0;
};

class Laser : public Printer
{
public:
    Laser()
    {
        quienSoy = "Laser";
    }
    void accept(Visitor*);
};

class Inyeccion : public Printer
{
public:
    Inyeccion()
    {
        quienSoy = "Inyeccion";
    }
    void accept(Visitor*);
};

class PDF : public Printer
{
public:
    PDF()
    {
        quienSoy = "PDF";
    }
    void accept(Visitor*);
};

class Postscript : public Printer
{
public:
    Postscript()
    {
        quienSoy = "Postscript";
    }
    void accept(Visitor*);
};


class Visitor
{
public:
    virtual void visit(Document*) = 0;
    virtual void visit(Printer*) = 0;
};

class PresentVisitor : public Visitor
{
    PresentVisitor()
    {
        instance = this;
    }
    static PresentVisitor* instance;
public:
    static PresentVisitor* getInstance()
    {
        if(instance == 0)
        {
            return new PresentVisitor;
        }
        else
            return instance;
    }

    void visit(Integer* i)
    {
        cout << i->getQuienSoy();
    }
    void visit(Double* d)
    {
        cout << d->getQuienSoy();
    }
};
PresentVisitor* PresentVisitor::instance = 0;

void Double::accept(Visitor* v)
{
    v->visit(this);
}

void Integer::accept(Visitor* v)
{
    v->visit(this);
}

class Main
{
public:
    void printAllDocuments(Documents** d, int countDocs, Printers** p, int countPrinters)
    {
        for(int i = 0; i < countDocs; i++)
        {
            for(int j = 0; j < countPrinters; j++)
            {
                d[i].printOn(p[j]); //should work on any printer and for any document
            }
        }
    }
}