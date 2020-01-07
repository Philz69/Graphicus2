
#ifndef CARRE_H
#define CARRE_H

#include "forme.h"

class Carre: public Forme
{
    public:
        Carre();
        ~Carre();
        int getCote();
        void setCote(int c);
        double aire();
        void afficher(ostream & s);
    private:
        int cote;
};

#endif
