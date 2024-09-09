
#ifndef ROULETTE_H
#define ROULETTE_H

#include "game-tools.h"
#include "file.h"
using namespace std;



void test();

/**
 * @brief tirage renvoie une nombre aléatoire compris entre 0 et 39
 * 
 * @return unsigned short int 
 */
unsigned short int tirage();



// I N D I C A T E U R S
/**
 * @brief Renvoie le nombre associé à la couleur du numero (0 -> vert, 20 -> noir, 16 -> rouge).
 *        Il renvoie du blanc sur orange si le numero est selectionne
 * 
 * @param numero 
 * @return unsigned short int 
 */
Couleur couleurTirage(unsigned short int numero);
/**
 * @brief Indique si le pari est valide ou non
 * 
 * @param resultat 
 * @param pari 
 * @return true 
 * @return false 
 */
bool gagnant (unsigned short int resultat, unsigned short int pari);
/**
 * @brief Renvoie l'équivalence de pari en une chaine de caractère. 
 *        Les nombre de 0 à 36 resteront contrairement aux autres. 
 *        Sera utile à l'affichage de la grille.
 * 
 * @param pari 
 * @return string 
 */
string equivalenceEnString (unsigned short int pari);
/**
 * @brief Reenvoie l'équivalence en nombre
 *
 * @param pari 
 * @return unsigned short int 
 */
//unsigned short int equivalenceEnNombre (string pari);


// A F F I C H A G E S
/**
 * @brief Affiche la roulette graphiquement avec une animation prolongées sur duree secondes
 * 
 * @param resultat 
 * @param duree 
 */
void affichageResultatDynamique (unsigned short int resultat, float duree);
/**
 * @brief Affiche la roulette graphiquement avec en surligné la selection (définie par sa ligne et sa colonne), la mise actuelle (coloree si est en train d etre modifiee) et la file des resultats précédents
 * 
 * @param selectionne 
 * @param ligneSelection 
 * @param colonneSelection 
 * @param mise 
 */
void affichageSimple (unsigned short int ligneSelection, unsigned short int colonneSelection, unsigned int mise, bool reglageMise, File historique);
/**
 * @brief Retourne au début de la conseole pour actualiser les nouveaux élements
 * 
 */
void retournerAuDebut();

// C A L C U L A T E U R S
/**
 * @brief Retourne le bénéfice d'un numero joue gagnant par rappport à l'argent misé dessus
 *        Pre requis : 
 * 
 * @param pari 
 * @param argentMise 
 * @return int 
 */
unsigned int gain (unsigned short int pari, unsigned int argentMise);


// S A I S I E
/**
 * @brief Saisie une touche. Si c'est la touche entrer, saisie est vrai. Renvoie les lignes et colonnes associées au déplacement
 * 
 * @param ligneEmplacement 
 * @param colonneEmplacement 
 * @param saisie 
 */
void saisieDeplacement (short int &ligneEmplacement, short int &colonneEmplacement, bool &saisie);
/**
 * @brief Ajustement de la mise : 1 pour 1€
 *                                2 pour 2€
 *                                3 pour 5€
 *                                4 pour 10€
 *                                5 pour 20€
 *                                6 pour 50€
 *                                7 pour 100€
 *                                8 pour 200€
 *                                9 pour 500€
 *                                0 pour 1000€
 *      Validee est vrai lorsque la mise a été entree
 * 
 * @param mise 
 * @param validee 
 */
void ajustementMise (unsigned int &mise, bool &validee);


// A U T O M A T I S A T I O N
/**
 * @brief Calcule la moyenne sur nbLancers de la fonctions saisie dans ce sous-programme
 * 
 * @param nbLancers 
 */
void moyenne(unsigned int nbLancers);


//unsigned short int pourcentage
//Joue avec une certaine méthode sur n essais avec x seuil à depasser et retourne le pourcentage de réussite.

//Saisie une méthode pour jouer et joue une partie jusqu'à depasser la somme indiquée


#endif