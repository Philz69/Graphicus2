
#ifndef CARRE_H
#define CARRE_H

#include "forme.h"

class Carre: public Forme
{
    public:
        Carre(int x = 0, int y = 0);
        ~Carre();
        int getCote();
        void setCote(int c);
        double aire();
        void afficher(ostream & s);
    private:
        int cote;
};

#endif
