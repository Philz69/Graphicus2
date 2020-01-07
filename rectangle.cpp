#include "rectangle.h"

Rectangle::~Rectangle()
{
}

int Rectangle::getHauteur()
{
    return hauteur;
}

int Rectangle::getLargeur()
{
    return largeur;
}

void Rectangle::setHauteur(int h)
{
    hauteur = h;
}

void Rectangle::setLargeur(int l)
{
    largeur = l;
}

double Rectangle::aire()
{
    return hauteur * largeur;
}

void Rectangle::afficher(ostream & s)
{
}

