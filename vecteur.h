
#ifndef VECTEUR_H
#define VECTEUR_H

#include "forme.h"

class Vecteur
{
    public:
        Vecteur();
        ~Vecteur();
        int getCapacity();
        int getSize(); 
        int isEmpty();
        bool add(int *forme);
        int* del(int index);
        int* get(int index);
        void empty();
        void output();
    private:
        int* formes;
        int capacity;
        int size;
};

#endif
