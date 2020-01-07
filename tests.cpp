/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"

void Tests::tests_unitaires_formes()
{
   Rectangle rectangle1;
   //rectangle1.setHauteur(10);
   //rectangle1.setLargeur(15);
   //rectangle1.translater(5,5);
   //printf("%i | %i | %i,%i", rectangle1.getHauteur(), rectangle1.getLargeur(), rectangle1.getAncrage().x, rectangle1.getAncrage().y);
   // Tests sur les formes geometriques
}

void Tests::tests_unitaires_vecteur()
{
   // Tests sur la classe Vecteur
   Vecteur vecteurTest;
   printf("%i | %i", vecteurTest.getSize(), vecteurTest.getCapacity());
   vecteurTest.doubleCapacity();
   printf("%i | %i", vecteurTest.getSize(), vecteurTest.getCapacity());
}

void Tests::tests_unitaires_couche()
{
   // Tests sur la classe Couche
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_vecteur();
   tests_unitaires_couche();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   cout << "TESTS APPLICATION (CAS 01)" << endl; 
   // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}
