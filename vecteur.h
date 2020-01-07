
#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include "forme.h"

class Vecteur
{
    public:
        Vecteur();
        ~Vecteur();
        int getCapacity();
        int getSize(); 
        int isEmpty();
        bool add(Forme *forme);
        Forme* del(int index);
        Forme* get(int index);
        void empty();
        void output();
        int doubleCapacity();
    private:
        Forme** formes;
        int capacity;
        int size;
};

#endif
