/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas()
{
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
    for(int i =0; i < MAX_COUCHES; i++)
    {
        couches[i].reset();
    }
   return true;
}

bool Canevas::activerCouche(int index)
{
    for(int i = 0; i < MAX_COUCHES; i++)
    {
        if(couches[i].getState() == ACTIVE)
        {
        couches[i].setState(INACTIVE);
        }
    }
   couches[index].setState(ACTIVE); 
   return true;
}

bool Canevas::cacherCouche(int index)
{
   couches[index].setState(CACHEE);
   return true;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
   int indexActif;
    for(int i = 0; i < MAX_COUCHES; i++)
    {
        if(couches[i].getState() == ACTIVE)
        {
            indexActif = i;
            break;
        }
  }

   couches[indexActif].addForme(p_forme);
   return true;
}

bool Canevas::retirerForme(int index)
{
   int indexActif;
    for(int i = 0; i < MAX_COUCHES; i++)
    {
        if(couches[i].getState() == ACTIVE)
        {
            indexActif = i;
            break;
        }
  }

   couches[indexActif].removeForme(index);
 return true;
}

double Canevas::aire()
{
    double total = 0;
    for(int i = 0; i < MAX_COUCHES; i++)
    {
        total = total + couches[i].getAire();
    }
   return total;
}

bool Canevas::translater(int deltaX, int deltaY)
{
    for(int i = 0; i < MAX_COUCHES; i++)
    {
        couches[i].translater(deltaX, deltaY);
    }

   return true;
}

void Canevas::afficher(ostream & s)
{

    for(int i = 0; i < MAX_COUCHES; i++)
    {
        s << "----- Couche " << i << endl;
        couches[i].afficher(s);
    }
}
