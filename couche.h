/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#ifndef COUCHE_H
#define COUCHE_H

#include "vecteur.h"
#define INITIALISE 0
#define ACTIVE 1
#define INACTIVE 2
#define CACHEE 3

class Couche
{
    public:
        Couche();
        ~Couche();
        bool addForme(Forme* forme);
        Forme* removeForme(int index);
        Forme* getForme(int index);
        double getAire();
        bool translater(int x, int y);
        bool reset();
        bool setState(int state);
        int getState();
        void afficher(ostream &s);
    private:
        int state;
        Vecteur formes;
        // Classe a completer

};

#endif
