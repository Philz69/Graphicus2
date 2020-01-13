/********
 * Fichier: graphicus-01.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include "tests.h"

using namespace std;

int main()
{
   Tests tests;
   
   std::cout << "---- Unitaire Vecteur" << endl;
   tests.tests_unitaires_vecteur();
   std::cout << "---- Unitaire Couche" << endl;
   tests.tests_unitaires_couche();
   std::cout << "---- Valid" << endl;
   tests.tests_validation();
   return 0;
}

