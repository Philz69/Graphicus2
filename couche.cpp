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
    if(state != ACTIVE)
    {
        return false;
    }
    formes.add(forme);
    return true;
}

Forme* Couche::removeForme(int index)
{
    if(state != ACTIVE)
    {
        return nullptr;
    }
    return formes.del(index);
}

Forme* Couche::getForme(int index)
{
    return formes.get(index);
}

double Couche::getAire()
{
    double total = 0;
    if(getState() != CACHEE)
    {
        for(int i = 0; i < formes.getSize(); i++)
        {
            total = total + formes.get(i)->aire();
        }
    }
    return total;
}

bool Couche::translater(int x, int y)
{
    if(formes.getSize() == 0)
    {
        return false;
    }
    if(state != ACTIVE)
    {
        return false;
    }
    for(int i = 0; i < formes.getSize(); i++)
    {
        formes.get(i)->translater(x, y);
    }
    return true;
}

bool Couche::reset()
{
    formes.empty();
    //if(!formes.isEmpty())
    //{
    //    return false;
    //}
    state = INITIALISE;
    return true;
}

bool Couche::setState(int s)
{
    if(s == INITIALISE)
    {
        return false;
    }
    state = s; 
    return true;
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

