#include "vecteur.h"

Vecteur::Vecteur()
{
    formes = new int[1];    
    size = 0;
    capacity = 1; 
}

int Vecteur::getCapacity()
{
    return capacity;
}

int Vecteur::getSize()
{
    return size;
}

int Vecteur::isEmpty()
{
    if(size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Vecteur::add(int *forme)
{
    return true;
}

int* Vecteur::del(int index)
{
    return NULL;
}

int* Vecteur::get(int index)
{
    return NULL;
}

void Vecteur::empty()
{
    return;
}

void Vecteur::output()
{
    return;
}
