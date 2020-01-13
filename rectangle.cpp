#include "rectangle.h"
Rectangle::Rectangle(int x, int y)
{
    ancrage.x = x;
    ancrage.y = y;
    hauteur = 1;
    largeur = 1;
}
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

void Rectangle::afficher(ostream &s)
{
    s << "Rectangle(x=" << ancrage.x << ", y=" << ancrage.y << ", l=" << largeur << ", h=" << hauteur << ", aire=" << aire() << ")" << endl;
}

