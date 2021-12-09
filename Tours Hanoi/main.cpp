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
    UnePile lesTours[3];                        //Tableau contenant les 3 tours (piles) d'Hanoi
    UnePile saves[2];                           //Tableau comprenant les instructions passées avec origine en 0 colonne en 1
    unsigned int nbDisques;                     // nbre de disques à déplacer
    unsigned int tourOrigine;                   // tour origine du déplacement
    unsigned int tourDestination;               // tour destination du déplacement
    bool deplacementDemande;
    bool retour;
    bool jouer;                                 //Indique si le joueur veut jouer
    bool gagne;                                 //Indique si le joueur a gagné
    char reponseFin;                            //Réponse de fin du joueur à la s'il veut rejouer

    jouer = true;


    while(jouer)
    {
        //Saisie-Verif du nombre de disques
        system("CLS");
        cout << "Entrer le nbre de disques de la tour de Hanoi : ";
        cin >> nbDisques;
        

        // Initialisations
        initialiserPiles(lesTours, 2);
        initialiserPiles(lesTours, 3);
        remplirTour(lesTours[0], nbDisques);
        gagne = false;

        //Affichages
        system("CLS");
        afficherToursJoli(lesTours, nbDisques);
        cout << endl;

        //Jouer la partie
        while(gagne == false)
        {
            // Saisie le déplacement souhaité
            if (saisieVerifDeplacementDemande(tourOrigine, tourDestination))
            {
                //Déplace le dique si possible
                if (estDeplacable(lesTours[tourOrigine], lesTours[tourDestination]))
                {
                    system("CLS");
                    deplacerDisque(lesTours[tourOrigine], lesTours[tourDestination]);
                    afficherToursJoli(lesTours, nbDisques);
                }
                else
                {
                    system("CLS");
                    afficherToursJoli(lesTours, nbDisques);
                    cout << endl << "Deplacement impossible";
                }
                if (estVide(lesTours[0]) && (estVide(lesTours[1])))
                {
                    gagne = true;
                }
            }

            // Abandon ou retour
            else
            {
                cout << "origine : " << tourOrigine << endl << "destination : " << tourDestination << endl;
            
                //Abandon
                if (tourOrigine == 10)
                {
                    break;
                }

                //Retour arrière
                else if (tourDestination == 11)
                {
                    deplacerDisque(lesTours[tourOrigine], lesTours[tourDestination]);
                }   
            } 
        }
        if (gagne)
        {
            cout << endl << "T'AS GAGNE BG JTM" << endl ;
            cout << "Recommencer ? (o/n)  ";
            reponseFin = getch();
            if ((reponseFin == 'n') || (reponseFin == 'N'))
            {
                jouer = false;
            }
        }
    }

    return 0;
}
