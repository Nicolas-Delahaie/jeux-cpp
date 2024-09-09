/**
 * @file main.cpp
 * @author N. DELAHAIE (dont Pantxika Dagorret)
 * @brief Résolution des tours de Hanoi pour 3 à 9 disques
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <conio.h>
#include <windows.h>

#include <iostream>
#include <stdlib.h>
#include "pile.h"       //Emprunté : Pour manipuler les piles
#include "hanoi.h"
using namespace std;

/*
A faire :
    -Faire un algo automatique qui déplace une pile sur une autre 
    -Saisie-verif du nombre de disques


     1    |     2     |     3
----------|-----------|-----------
          |           |
          |           |
 -------  |     -     |
--------- |    ---    |   -----
mmmmmmmmmm|mmmmmmmmmmm|mmmmmmmmmmm

Astuce : 
Aller au bon endroit quand c'est impair
*/

int main()
{
    UnElement indiceDepile;                     //Index de la tour d'origine et de destination de la dernière action, dépilé de saves
    UnePile lesTours[3];                        //Tableau contenant les 3 tours (piles) d'Hanoi
    UnePile saves[2];                           //Tableau comprenant les instructions passées avec origine en 0 colonne en 1
    unsigned int nbDisques;                     // nbre de disques à déplacer
    unsigned int tourOrigine;                   // tour origine du déplacement
    unsigned int tourDestination;               // tour destination du déplacement
    unsigned int compteurTour;                  //Compte le nombre de tours joués
    unsigned short int posPetit;                //
    bool deplacementDemande;
    bool jouer;                                 //Indique si le joueur veut jouer
    bool gagne;                                 //Indique si le joueur a gagné
    char reponseFin;                            //Réponse de fin du joueur à la s'il veut rejouer

    jouer = true; 

    while(jouer)
    {
        //Saisie-Verif du nombre de disques
        cout << "Entrer le nbre de disques de la tour de Hanoi : ";
        cin >> nbDisques;
        
        
        // Initialisations
        initialiserPiles(lesTours, 2);
        initialiserPiles(lesTours, 3);
        remplirTour(lesTours[0], nbDisques);
        gagne = false;
        compteurTour = 0;
        posPetit = 0;

        //Affichage
        system("CLS");
        afficherToursJoli(lesTours, nbDisques);
        cout << endl;

        //Jouer la partie
        while (!(gagne))
        {
            // Deplacement
            if (saisieVerifDeplacementDemande(tourOrigine, tourDestination, compteurTour))
            {
                //Déplace le dique si possible
                if (estDeplacable(lesTours[tourOrigine], lesTours[tourDestination]))
                {
                    system("CLS");
                    //Ajout des instructions à saves
                    empiler(saves[0], tourOrigine);
                    empiler(saves[1], tourDestination);
                    compteurTour++;

                    deplacerDisque(lesTours[tourOrigine], lesTours[tourDestination]);
                    afficherToursJoli(lesTours, nbDisques);
                }
                else
                {
                    system("CLS");
                    afficherToursJoli(lesTours, nbDisques);
                    cout << endl << "Deplacement impossible";
                }
                if ( (estVide(lesTours[0])) && (estVide(lesTours[1])) )
                {
                    gagne = true;
                }
            }


            // Abandon ou retour
            else
            {
                system("CLS");

                //Abandon
                if  ((tourOrigine == 3) || (tourDestination == 3))
                {
                    break;
                }

                //Retour
                else if ((tourOrigine == 4) && (!(estVide(saves[0]))))
                {                       
                    depiler(saves[0], indiceDepile);
                    tourOrigine = indiceDepile;
                    depiler(saves[1], indiceDepile);
                    tourDestination = indiceDepile;
                    compteurTour--;

                    deplacerDisque(lesTours[tourDestination], lesTours[tourOrigine]);
                    
                    afficherToursJoli(lesTours, nbDisques);
                }

                //Resolution auto
                else if  ((tourOrigine == 5) || (tourDestination == 5))
                {
                    system("CLS");
                    deplacerPetit(lesTours, posPetit);
                    deplacerAutre(lesTours, posPetit, nbDisques);
                    afficherToursJoli(lesTours, nbDisques);
                }
            }  
        } 
        //Partie gagnee
        if (gagne)
        {
            cout << endl << "T'AS GAGNE EN " << compteurTour << " TOURS" << endl ;
            cout << endl <<"Recommencer ? (o/n)  ";
            reponseFin = static_cast<char>(getch());

            //Joueur arrete
            if ((reponseFin == 'n') || (reponseFin == 'N'))
            {
                jouer = false;
                cout << endl <<"Non ? Bah tchao" << endl;
            }
            //Joueur continue
            else
            {
                system("CLS");
            }
        }

        //Partie recommencee
        else
        {
            system("CLS");
        }
    }
    return 911;
}
