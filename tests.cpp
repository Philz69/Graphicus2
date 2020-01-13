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
    rectangle1.afficher(std::cout);
    rectangle1.setHauteur(10);
    rectangle1.setLargeur(15);
    rectangle1.translater(5,5);
    rectangle1.afficher(std::cout);
    Carre carre1;
    carre1.afficher(std::cout);
    carre1.setCote(7);
    carre1.translater(7,7);
    carre1.afficher(std::cout);
    Cercle cercle1;
    cercle1.afficher(std::cout);
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
    //printf("%i | %i \n", vecteurTest.getSize(), vecteurTest.getCapacity());
    vecteurTest.doubleCapacity();
    //printf("%i | %i \n", vecteurTest.getSize(), vecteurTest.getCapacity());
    Rectangle rectangle1;
    rectangle1.setHauteur(10);
    rectangle1.setLargeur(15);
    rectangle1.translater(5,5);

    for(int i = 0; i < 10; i++)
    {
        Rectangle *rect = new Rectangle;
        rect->setHauteur(10);
        rect->setLargeur(10);
        vecteurTest.add(rect);
    }
    std::cout << vecteurTest.getSize() << endl;
    //vecteurTest.get(0)->afficher(std::cout);
    vecteurTest.afficher(std::cout);
    vecteurTest.empty();
    //printf("%i | %i \n", vecteurTest.getSize(), vecteurTest.getCapacity());
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
    for(int i = 0; i < 50; i++)
    {
            rect1.setHauteur(rand() % 10);
            rect1.setLargeur(rand() % 10);
            rect1.translater(rand() % 10, rand() % 10);
            couche1.addForme(rectPtr);
            //couche1.afficher(std::cout);
            carre1.setCote(rand() % 10);
            carre1.translater(rand() % 10, rand() % 10);
            couche1.addForme(carrePtr); 
            cercle1.setRayon(rand() % 10);
            cercle1.translater(rand() % 10, rand() % 10);
            couche1.addForme(cerclePtr);
     }
    //couche1.getForme(1)->afficher(std::cout);
    couche1.afficher(std::cout);
    std::cout << "Aire couche: " << couche1.getAire() << endl;
    // Tests sur la classe Couche


}

void Tests::tests_unitaires_canevas()
{
   Canevas canevas1;
   for(int i =0;i< 3; i++)
   {
       Rectangle* rect1 = new Rectangle;
       Cercle *cercle1 = new Cercle; 
       Carre *carre1 = new Carre;
       canevas1.activerCouche(i);
       rect1->setHauteur(rand() * i % 10);
       rect1->setLargeur(rand() * i % 10);
       rect1->translater(rand() * i % 10, rand() * i% 10);
       canevas1.ajouterForme(rect1);
       carre1->setCote(rand() * i % 10);
       carre1->translater(rand() * i % 10, rand() * i % 10);
       canevas1.ajouterForme(carre1); 
       cercle1->setRayon(rand() * i % 10);
       cercle1->translater(rand() * i % 10, rand() * i % 10);
       canevas1.ajouterForme(cercle1);
   }
   
   canevas1.afficher(std::cout);
   canevas1.cacherCouche(1);
   canevas1.activerCouche(4);
   canevas1.afficher(std::cout);
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
    tests_unitaires_canevas();
    // Fait tous les tests applicatifs
    tests_application_cas_01();
    tests_application_cas_02();
}

void Tests::tests_validation()
{
    Canevas canevas1;
    std::cout << "1: Activer couche 1" << endl;
    canevas1.activerCouche(1);

    std::cout << "2: Ajouter trois formes" << endl;
    Rectangle *rect1 = new Rectangle(0,0);
    Carre *carre1 = new Carre(1,1);
    Cercle *cercle1 = new Cercle(2,2);
    canevas1.ajouterForme(rect1);
    canevas1.ajouterForme(carre1);
    canevas1.ajouterForme(cercle1);


    std::cout << "3: Activer couche 2" << endl;
    canevas1.activerCouche(2);

    std::cout << "4: Ajouter une forme" << endl;
    Rectangle *rect2 = new Rectangle(2,2);
    canevas1.ajouterForme(rect2); 

    std::cout << "5: Afficher le canvas" << endl;
    canevas1.afficher(std::cout);

    std::cout << "6: Afficher l'aire du canvas" << endl;
    std::cout << "Aire du canvas: " << canevas1.aire() << endl;

    std::cout << "7: Activer couche 0" << endl;
    canevas1.activerCouche(0);

    std::cout << "8: ajouter trois formes" << endl;
    Rectangle *rect3 = new Rectangle(3,3);
    Carre *carre2 = new Carre(9,9);
    Cercle *cercle2 = new Cercle(7,7);
    canevas1.ajouterForme(rect3);
    canevas1.ajouterForme(carre2);
    canevas1.ajouterForme(cercle2);


    std::cout << "7.1: Afficher le canvas" << endl;
    canevas1.afficher(std::cout);

    std::cout << "7.2: Cacher la couche 0" << endl;
    canevas1.cacherCouche(0);

    std::cout << "7.3: Translater la couche" << endl;
    canevas1.translater(5,5);

    std::cout << "7.4: Cacher la couche 0" << endl;
    canevas1.activerCouche(0);

    std::cout << "7.5: Afficher le canvas" << endl;
    canevas1.afficher(std::cout);

    std::cout << "9: Cacher la couche 2" << endl;
    canevas1.cacherCouche(2);


    std::cout << "10: Activer la couche 1" << endl;
    canevas1.activerCouche(1);

    std::cout << "11: Translater la couche" << endl;
    canevas1.translater(5,5);

    std::cout << "12: Afficher le canvas" << endl;
    canevas1.afficher(std::cout);

    std::cout << "13: Afficher l'aire du canvas" << endl;
    std::cout << "Aire du canvas: " << canevas1.aire() << endl;

    std::cout << "14: Retirer la premiere forme de la couche" << endl;
    canevas1.retirerForme(0);

    std::cout << "15: Afficher le canvas" << endl;
    canevas1.afficher(std::cout);

    std::cout << "16: Afficher l'aire du canvas" << endl;
    std::cout << "Aire du canvas: " << canevas1.aire() << endl;

    std::cout << "17: Reinitialiser le canvas" << endl;
    canevas1.reinitialiser();

    std::cout << "18: Afficher le canvas" << endl;
    canevas1.afficher(std::cout);

    std::cout << "19: Afficher l'aire du canvas" << endl;
    std::cout << "Aire du canvas: " << canevas1.aire() << endl;
}


void Tests::tests_application_cas_01()
{
    tests_unitaires_formes();
    cout << "TESTS APPLICATION (CAS 01)" << endl; 
    // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
    cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}
