/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "couche.h"
Couche::Couche()
{
}

Couche::~Couche()
{
}

bool Couche::addForme(Forme* forme)
{
    formes.add(forme);
    return 1;
}

Forme* Couche::removeForme(int index)
{
    return formes.del(index);
}

Forme* Couche::getForme(int index)
{
    return formes.get(index);
}

double Couche::getAire()
{
    double total;
    for(int i = 0; i < formes.getSize(); i++)
    {
        total = total + formes.get(i)->aire();
    }
    return 1;
}

bool Couche::translation(int x, int y)
{
    for(int i = 0; i < formes.getSize(); i++)
    {
        formes.get(i)->translater(x, y);
    }
    return 1;
}

bool Couche::reset()
{
    formes.empty();
    return 1;
}

bool Couche::changeState(int s)
{
   state = s; 
}

