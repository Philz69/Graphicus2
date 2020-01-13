
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "forme.h"

class Rectangle: public Forme
{
    public:
        Rectangle(int x = 0, int y = 0);
        ~Rectangle();
        int getHauteur();
        int getLargeur();
        void setHauteur(int h);
        void setLargeur(int l);
        double aire();
        void afficher(ostream & s);
    private:
        int hauteur;
        int largeur;
};

#endif
