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
   couches[index].setState(ACTIVE); 
   coucheactive = index;
   return true;
}

bool Canevas::cacherCouche(int index)
{
    if(couches[index].getState() == ACTIVE)
    {
        coucheactive = -1;
    }
   couches[index].setState(CACHEE);
   return true;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
   if(coucheactive == -1)
      {
          return false;
      }
   couches[coucheactive].addForme(p_forme);
   return true;
}

bool Canevas::retirerForme(int index)
{
   if(coucheactive == -1)
      {
          return false;
      }
   couches[coucheactive].removeForme(index);
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
   if(coucheactive == -1)
      {
          return false;
      }
    couches[coucheactive].translater(deltaX, deltaY);
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
