
#ifndef CERCLE_H
#define CERCLE_H

#include "forme.h"

class Cercle: public Forme
{
    public:
        Cercle(int x = 0, int y = 0);
        ~Cercle();
        int getRayon();
        void setRayon(int r);
        double aire();
        void afficher(ostream & s);
    private:
        int rayon;
};

#endif
