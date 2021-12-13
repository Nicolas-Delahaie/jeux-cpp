#ifndef HANOI_H
#define HANOI_H

#include "pile.h"
#include <stack>
using namespace std;


const unsigned int NB_TOURS = 3;

/* ---------- Observateurs -----------*/
bool estDeplacable(const UnePile tourOrigine, const UnePile tourDestination);
//But : indiquer si la tour d'origine peut déplacer son dernier disque vers la tour de destination.


/* ---------- Primitives -----------*/
void deplacerDisque(UnePile &tourOrigine, UnePile &tourDestination, UnePile saves[]);
// But : déplace un disque d'une tour à une autre
// pré-condition : la tour de destination peut accueillir le disque de la tour d'origine
void remplirTour(UnePile &tourARemplir , const unsigned int nbDisques);
// But remplit la tourARemplir avec nbDisques, du plus grand (en bas) au plus 
// petit (au sommet) de la tour
void initialiserPiles(UnePile pile[], unsigned int taille);
// But : initialise les NB_TOURS tours du tableau lesTours


/* ---------- Affichage -----------*/ 
void afficherToursJoli(const UnePile lesTours[], const unsigned short int &nombreDisques);
// Affiche le contenu des tours passées en paramètre


/* ---------- Outils -----------*/
bool saisieVerifDeplacementDemande(unsigned int& origine, unsigned int& destination);
   // saisie du choix des tours prenant part au déplacement d'un disque :
   // 12 pour deplacement d'un disque de la tour 1 vers la tour 2
   // Indique si la saisie est bonne
   // Si elle est mauvaise, renvoie origine selon un code :
   //  10 pour la touche espace
   //  11 pour la touche '²'
bool traductionSaisie(unsigned int &saisie);
//Traduit la saisie de manière à indiquer si elle est bonne et si c'est le cas, la modifier en 1, 2, 3 ou 51 pour ²





#endif