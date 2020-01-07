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
    rectangle1.setHauteur(10);
    rectangle1.setLargeur(15);
    rectangle1.translater(5,5);
    rectangle1.afficher(std::cout);
    Carre carre1;
    carre1.setCote(7);
    carre1.translater(7,7);
    carre1.afficher(std::cout);
    Cercle cercle1;
    cercle1.setRayon(9);
    cercle1.translater(9,9);
    cercle1.afficher(std::cout);
    //printf("%i | %i | %i,%i\n", rectangle1.getHauteur(), rectangle1.getLargeur(), rectangle1.getAncrage().x, rectangle1.getAncrage().y);
    // Tests sur les formes geometriques
}

void Tests::tests_unitaires_vecteur()
{
    // Tests sur la classe Vecteur
    Vecteur vecteurTest;
    printf("%i | %i \n", vecteurTest.getSize(), vecteurTest.getCapacity());
    vecteurTest.doubleCapacity();
    printf("%i | %i \n", vecteurTest.getSize(), vecteurTest.getCapacity());
    for(int i = 0; i < 100; i++)
    {
        Rectangle rectangle1;
        vecteurTest.add(&rectangle1);
    }
    printf("%i | %i \n", vecteurTest.getSize(), vecteurTest.getCapacity());
}

void Tests::tests_unitaires_couche()
{
    Couche couche1;
    Rectangle rect1;
    Rectangle* rectPtr;
    rectPtr = &rect1;
    Carre carre1;
    Carre* carrePtr;
    carrePtr = &carre1;
    Cercle cercle1;
    Cercle* cerclePtr;
    cerclePtr = &cercle1;
    int selector;
    for(int i = 0; i < 50; i++)
    {
        selector = rand() % 3;
            if(selector == 0)
            {
                rect1.setHauteur(rand());
                rect1.setLargeur(rand());
                rect1.translater(rand() % 10, rand() % 10);
                couche1.addForme(rectPtr);
            }
            else if(selector == 1)
            {
                carre1.setCote(rand());
                carre1.translater(rand() % 10, rand() % 10);
                couche1.addForme(carrePtr); 
            }
            else
            {
                cercle1.setRayon(rand());
                cercle1.translater(rand() % 10, rand() % 10);
                couche1.addForme(cerclePtr);
            }
    }
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
    tests_unitaires();
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
