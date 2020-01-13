#include "cercle.h"

#define PI 3.141598

Cercle::Cercle(int x, int y)
{
    ancrage.x = x;
    ancrage.y = y;
    rayon = 1;
}

Cercle::~Cercle()
{
}

int Cercle::getRayon()
{
    return rayon;
}


void Cercle::setRayon(int r)
{
    rayon = r;
}


double Cercle::aire()
{
    return PI * rayon * rayon;
}

void Cercle::afficher(ostream & s)
{
    s << "Cercle (x=" << ancrage.x << ", y=" << ancrage.y << ", r=" << rayon << ", aire=" << aire() << ")" << endl;
}

