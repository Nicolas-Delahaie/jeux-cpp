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
void deplacerDisque(UnePile &tourOrigine, UnePile &tourDestination);
// But : déplace un disque d'une tour à une autre
// pré-condition : la tour de destination peut accueillir le disque de la tour d'origine
void remplirTour(UnePile &tourARemplir , const unsigned int nbDisques);
// But remplit la tourARemplir avec nbDisques, du plus grand (en bas) au plus 
// petit (au sommet) de la tour
void initialiserPiles(UnePile pile[], unsigned int taille);
// But : initialise les NB_TOURS tours du tableau lesTours
unsigned short int tourSuivante (unsigned short int indiceTour, unsigned short int nbTours);
//But : infiquer l'indice de la tour suivant par rapport à la tour du petit disque

void deplacerPetit (UnePile tours[], unsigned short int &posPetit);
//But : deplacer le petit disque
void deplacerAutre(UnePile tours[], unsigned short int posPetit, unsigned int nbDisques);
//But : déplace l'autre disque 

/* ---------- Affichage -----------*/ 
void afficherToursJoli(const UnePile lesTours[], unsigned int nombreDisques);
// Affiche le contenu des tours passées en paramètre


/* ---------- Outils -----------*/
bool saisieVerifDeplacementDemande(unsigned int& origine, unsigned int& destination, unsigned int compteurTour);
   // Saisie de l'instruction du joueur. Premiere saisie pour la 1ere tour et deuxième saisie pour la deuxième tour.
   // Jouable sur 4 endroits : "²&é"", "²123", ",;:!", "?./§"
   // Renvoie faux si les valeurs correspondent à :
   //    3 pour abandonner
   //    4 pour retour
bool traductionSaisie(unsigned int &saisie);
//Traduit la saisie de manière à indiquer si elle est bonne et si c'est le cas, la modifier en 0, 1, 2 ou 3 pour abandonner et 4 pour retour



#endif