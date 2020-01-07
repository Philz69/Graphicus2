#include "carre.h"

Carre::~Carre()
{
    cote = 0;
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
    s << "Carre (x=" << ancrage.x << ", y=" << ancrage.y << ", c=" << cote << ", aire=" << aire() << ")" << endl;
}

