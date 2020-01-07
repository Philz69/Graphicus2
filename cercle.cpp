#include "cercle.h"

#define PI 3.141598

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
    return PI * rayon * 2;
}

void Cercle::afficher(ostream & s)
{
}

