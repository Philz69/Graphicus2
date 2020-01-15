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
    std::cout << "-----TEST DE VALIDATION-----" << endl;
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
    std::cout << "-----FIN DU TEST DE VALIDATION-----" << endl;
}


void Tests::tests_application_cas_01()
{
    cout << "TESTS APPLICATION (CAS 01)" << endl; 

    cout << "1: Créer un canevas" << endl; 
    Canevas canevas1;

    cout << "2: Afficher l'aire du canevas" << endl; 
    cout << canevas1.aire() << endl;

    cout << "3: Retirer une forme du canevas" << endl; 
    canevas1.retirerForme(0);

    cout << "4: Afficher le canevas" << endl; 
    canevas1.afficher(std::cout);

    cout << "5: Activer la couche 1" << endl; 
    canevas1.activerCouche(1);

    cout << "6: Ajouter deux formes" << endl; 
    Rectangle* rect1 = new Rectangle;
    Cercle* cercle1 = new Cercle;
    rect1->setHauteur(4);
    rect1->setLargeur(2);
    canevas1.ajouterForme(rect1);
    canevas1.ajouterForme(cercle1);
   
    cout << "7: Activer la couche 2" << endl;
    canevas1.activerCouche(2);

    cout << "8: Cacher la couche 2" << endl;
    canevas1.cacherCouche(2);

    cout << "9: Ajouter une forme" << endl;
    Rectangle* rect2 = new Rectangle;
    canevas1.ajouterForme(rect2);
    

    cout << "10: Afficher le canevas" << endl;
    canevas1.afficher(std::cout);

    cout << "11: Activer la couche 4" << endl;
    canevas1.activerCouche(4);

    cout << "12: Retirer la forme 2" << endl;
    canevas1.retirerForme(2);

    cout << "13: Affier l'air du canevas" << endl;
    cout << canevas1.aire() << endl;
    
    
    
    
    
    // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
    cout << "TESTS APPLICATION (CAS 02)" << endl;  
    Canevas canevas1;

    cout << "1: Activer la couche 1" << endl;
    canevas1.activerCouche(1);

    cout << "2: Ajouter un rectangle d'une hauteur de 2 et d'une largeur de 3";
    Rectangle* rect1 = new Rectangle;
    rect1->setHauteur(2);
    rect1->setLargeur(3);

    cout << "3: Activer la couche 2" << endl;
    canevas1.activerCouche(2);
    
    cout << "4: Ajouter un cercle avec un rayon de 1 au point(5,6);" << endl;
    Cercle* cercle1 = new Cercle(5,6);
    canevas1.ajouterForme(cercle1);

    cout << "5: Afficher le canevas" << endl;
    canevas1.afficher(std::cout);

    cout << "6: Afficher l'aire du canevas" << endl;
    cout << canevas1.aire() << endl;

    cout << "7:Activer la couche 1" << endl;
    canevas1.activerCouche(1);

    cout << "8: Ajouter un carré a l'origine" << endl;
    Carre* carre1 = new Carre;
    canevas1.ajouterForme(carre1); 

    cout << "9: translater la couche 1 de 5 unités" << endl;
    canevas1.translater(5,0);

    cout << "10: Cacher la couche 2" << endl;
    canevas1.cacherCouche(2);

    cout << "11: Afficher le  canevas" << endl;
    canevas1.afficher(std::cout);

    cout << "12: Afficher l'air du canevas" << endl;
    cout << canevas1.aire() << endl;

    cout << "13: Retirer la deuxieme forme de la couche" << endl;
    canevas1.retirerForme(2);

    cout << "14: Afficher le  canevas" << endl;
    canevas1.afficher(std::cout);

    cout << "15: Afficher l'air du canevas" << endl;
    cout << canevas1.aire() << endl;





    // Il faut ajouter les operations realisant ce scenario de test.
}
