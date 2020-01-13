
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
        bool isEmpty();
        bool add(Forme *forme);
        Forme* del(int index);
        Forme* get(int index);
        void empty();
        void afficher(ostream &s);
    private:
        Forme** formes;
        int doubleCapacity();
        int capacity;
        int size;
};

#endif
