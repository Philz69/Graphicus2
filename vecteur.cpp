#include "vecteur.h"

Vecteur::Vecteur()
{
    formes = new Forme*[1];    
    size = 0;
    capacity = 1; 
}

Vecteur::~Vecteur()
{
    delete formes;
}

int Vecteur::doubleCapacity()
{
    capacity = capacity * 2;
    Forme **tmp;
    tmp = new Forme*[capacity];
    for(int i = 0; i < size; i++)
    {
       tmp[i] = formes[i];
    } 
   delete formes;
   formes = tmp;
   return capacity;
}

int Vecteur::getCapacity()
{
    return capacity;
}

int Vecteur::getSize()
{
    return size;
}

bool Vecteur::isEmpty()
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

bool Vecteur::add(Forme *forme)
{
    if(size == capacity)
    {
        capacity = doubleCapacity();
    } 
    formes[size] = forme; 
    size++;
    return true;
}

Forme* Vecteur::del(int index)
{
    Forme* tmp = formes[index];
    for(int i = index; i < size - 1; i++)
    {
        formes[i] = formes[i + 1];
    }
    formes[getSize() - 1] = NULL;
    size = size - 1;
    return tmp;
}

Forme* Vecteur::get(int index)
{
    return formes[index];
}

void Vecteur::empty()
{
    for(int i = 0; i < capacity; i++)
    {
        formes[i] = NULL;
    }
    size = 0;
}

void Vecteur::afficher(ostream &s)
{
    for(int i = 0; i < size; i++)
    {
            formes[i]->afficher(s);     
    }
    return;
}
