#include "carre.h"

Carre::~Carre()
{
}

int Carre::getCote()
{
    return cote;
}

void Carre::setCote(int c)
{
    cote = c;
}


double Carre::aire()
{
    return cote*cote;
}

void Carre::afficher(ostream & s)
{
}

