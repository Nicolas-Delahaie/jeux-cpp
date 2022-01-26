/**
 * @file main.cpp
 * @author N. DELAHAIE
 * @brief Permet de jouer au jeux de la roulette, de manière la plus fidèle aux casinos
 * @version 0.1
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */




#include "Jeux_roulette.h"
#include "file.h"
#include <windows.h>        //Pour clear
#include <iostream>
using namespace std;


/*

CTRL K + CTRL J   : déplier
         CTRL 0   : plier

37 : tier 1
38 : tier 2
39 : tier 3
40 : ligne 1
41 : ligne 2
42 : ligne 3

43 : 1-18
44 : pair
45 : rouge
46 : noir
47 : impair
48 : 19-36

Possibilité de jouer seulement une case

      
|-----|--------------------------------------------------------------|---------|
|     |   3    6    9    12   15   18   21   24   27   30   33   36  | Ligne 1 |
|  0  |   2    5    8    11   14   17   20   23   26   29   32   35  | ligne 2 |
|     |   1    4    7    10   13   16   19   22   25   28   31   34  | Ligne 3 |
|-----|--------------------------------------------------------------|---------|
      |       Tier 1       |       Tier 2       |       Tier 3       |         |
      |--------------------------------------------------------------|    5    |
      |   1-18  |   Pair   |  Rouge   |  Noir   |  Impair  |  19-36  |         |
      |--------------------------------------------------------------|---------|
      | 11 | 36 | 3 | 23 | 4 | 12 | 1 | 32 | 36 | 6 | 23 | 7 | 9
      | 21 | 5 | 2 | 18 | 16 | 12 | 18  <--

      derniers 24 tirs
*/


int main()
{
    const unsigned short int LARGEUR = 14; 
    unsigned short int ordre[5][LARGEUR] = {{255,3,6,9,12,15,18,21,24,27,30,33,36,40},
                                        {0,2,5,8,11,14,17,20,23,26,29,32,35,41},
                                        {255,1,4,7,10,13,16,19,22,25,28,31,34,42},
                                        {37,38,39},
                                        {43,44,45,46,47,48}};



    unsigned short int pari;
    unsigned int mise;
    int argentActuel;
    unsigned short int resultat;
    unsigned short int argentGagne;
    short int ligneCaseCourante;
    short int colonneCaseCourante;
    bool saisie;                        //Lorsque la case est valide et que la mise doit etre saisie
    bool validee;                       //lorsque la mise est figee
    File historique;


    
    
/*
    cout << "3e sur pair: " << gain(43, 3) << endl;
    cout << "10e sur ligne 1: " << gain(40, 10) << endl;
    cout << "3e sur 0 : " << gain(0, 3) << endl;

    cout << endl;

    resultat = 34;
    pari = 43;
    if (gagnant(resultat, pari))
    {
        cout << "Le resultat etant le " << resultat << ", vous venez de gagner en pariant sur le " << pari <<" !" << endl;
    }
    else
    {
        cout << "Le resultat etant le " << resultat << ", vous venez de perdre en pariant sur le " << pari <<" !" << endl;
    }
    

    cout << endl;

    cout << "Equivalence de 8 en string : " << equivalenceEnString(8) << endl;
    cout << "Equivalence de 21 en string : " << equivalenceEnString(21) << endl;
    cout << "Equivalence de 37 en string : " << equivalenceEnString(37) << endl;
    cout << "Equivalence de 40 en string : " << equivalenceEnString(40) << endl;
    cout << "Equivalence de 45 en string : " << equivalenceEnString(45) << endl;
    

    int saisie3;
    while (true)
    {
        saisie3 = getch();
        cout << saisie3 << endl;
    }
*/

    //initialisations
    initialiser(historique);
    argentActuel = 500;
    mise = 5;
    ligneCaseCourante = 3;
    colonneCaseCourante = 1;

    //Jouer la partie
    while (argentActuel > 0)
    {
        //Deplacement 
        saisie = false;
        while (!(saisie))
        {
            retournerAuDebut();
            cout << "Solde : " << argentActuel << endl << endl;
            affichageSimple(ligneCaseCourante, colonneCaseCourante, mise, false);
            for (unsigned short int i = 0; i < historique.nbElements ; i++)
            {
                cout << " | ";
                afficherNombreEnCouleur(historique.elements[i], couleurTirage(historique.elements[i]));
            }
            cout << endl;
            saisieDeplacement(ligneCaseCourante, colonneCaseCourante, saisie);
        }

        //Ajustement mise
        validee = false;
        while (!(validee))
        {
            retournerAuDebut();
            cout << "Solde : " << argentActuel << endl << endl;
            affichageSimple(ligneCaseCourante, colonneCaseCourante, mise, true);
            for (unsigned short int i = 0; i < historique.nbElements ; i++)
            {
                cout << " | ";
                afficherNombreEnCouleur(historique.elements[i], couleurTirage(historique.elements[i]));
            }
            cout << endl;
            ajustementMise(mise, validee);
        }
        argentActuel -= mise;

        pari = ordre[ligneCaseCourante][colonneCaseCourante];
        
        //Tirage
        resultat = tirage();
        ajouterElement(historique, resultat);

        //Affichage tirage et gain
        cout << endl << "--> ";
        afficherNombreEnCouleur(resultat, couleurTirage(resultat));
        cout << endl;

        //Reussite
        if (gagnant(resultat, pari))
        {
            argentGagne = static_cast<unsigned short int>(gain(pari, mise));
            argentActuel += argentGagne;
            cout << "  +" << argentGagne - mise;
        }
        //Echec
        else
        {
            cout << "  -" << mise ;
        }

        pause(0);

    }
    cout << "Tas plus d argent man" << endl;

/*    
    File test;
    initialiser(test);
    enfiler(test, 20);
    enfiler(test, 29);
    enfiler(test, 2);


    for (unsigned short int i = 0; i < 20; i++)
    {
        enfiler(test, i*3);
    }

    ajouterElement(test, 0);
    ajouterElement(test, 1);
    ajouterElement(test, 2);

    for (unsigned short int i = 0; i < test.nbElements ; i++)
    {
        cout << test.elements[i] << " - ";
    }
    cout << endl;
*/

    

       


       
    return 911;
}


