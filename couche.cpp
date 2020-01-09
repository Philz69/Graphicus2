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
    setState(INITIALISE);
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
    double total = 0;
    for(int i = 0; i < formes.getSize(); i++)
    {
        total = total + formes.get(i)->aire();
    }
    return 1;
}

bool Couche::translater(int x, int y)
{
    if(formes.getSize() == 0)
    {
        return 0;
    }
    for(int i = 0; i < formes.getSize(); i++)
    {
        formes.get(i)->translater(x, y);
    }
    return 1;
}

bool Couche::reset()
{
    formes.empty();
    if(!formes.isEmpty())
    {
        return 0;
    }
    setState(INITIALISE);
    return 1;
}

bool Couche::setState(int s)
{
   state = s; 
   return 1;
} 

int Couche::getState()
{
   return state;
} 
void Couche::afficher(ostream &s)
{
    if(getState() == INITIALISE)
    {
        s << "Couche Initialise" << endl;
    }
    else if(getState() == CACHEE)
    {
        s << "Couche cachee" << endl;
    }
    else if(formes.isEmpty())
    {
        s << "Couche vide" << endl;
    }
    else
    {
    formes.afficher(s);
    }
}

