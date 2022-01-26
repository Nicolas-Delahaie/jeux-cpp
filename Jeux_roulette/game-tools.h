/**
 * @file game-tools.h
 * @author Patrick Etcheverry
 * @brief Fichier d'entête du module game-tools
 * @date 2021-07-12
 */
#ifndef GAME_TOOLS_H
#define GAME_TOOLS_H

#include <windows.h> // pour afficher du texte en couleur
#include <iostream>
using namespace std;

enum Couleur
{
    wtfMan = 24,
    blancSurOrange = 111,   //caractère séléctionné
    pioche = 22,            //Couleur attribuée au résultat de la pioche
    gris = 7,

    blancSurNoir = 7,
    blancSurVert = 47,
    blancSurRouge = 71,
    blancSurViolet = 95,

    noirSurVert = 32
};

/**
 * @brief Permet d'afficher une chaine de caractères en couleur.
 *
 * @param [in] chaine la chaine à afficher.
 * @param [in] couleur la couleur à utiliser pour afficher la chaine. La couleur doit faire partie
 * des valeurs proposées par le type #Couleur
 * @param [in] retourALaLigne indique si l'affichage de la chaine doit être suivi d'un
 * retour à la ligne (true) ou pas (false).
 */
void afficherTexteEnCouleur(string chaine, Couleur couleur, bool retourALaLigne = false);

/**
 * @brief Permet d'afficher un caractère en couleur.
 *
 * @param [in] caractere le caractère à afficher.
 * @param [in] couleur la couleur à utiliser pour afficher le caractère. La couleur doit faire partie
 * des valeurs proposées par le type #Couleur
 * @param [in] retourALaLigne indique si l'affichage du caractère doit être suivi d'un
 * retour à la ligne (true) ou pas (false).
 */
void afficherTexteEnCouleur(char caractere, Couleur couleur, bool retourALaLigne = false);

/**
 * @brief Permet d'afficher un nombre en couleur.
 *
 * @param [in] nombre le nombre à afficher. Il peut s'agit d'un nombre entier ou d'un nombre à virgule.
 * @param [in] couleur la couleur à utiliser pour afficher le nombre. La couleur doit faire partie
 * des valeurs proposées par le type #Couleur
 * @param [in] retourALaLigne indique si l'affichage du nombre doit être suivi d'un
 * retour à la ligne (true) ou pas (false).
 */
void afficherNombreEnCouleur(unsigned short int nombre, Couleur couleur, bool retourALaLigne = false);

/**
 * @brief Génère un nombre entier aléatoire compris dans un intervalle donné.
 *
 * @param [in] min la borne min de l'intervalle.
 * @param [in] max la borne max de l'intervalle.
 * @return int le nombre aléatoire généré.
 */
int random(int min, int max);

/**
 * @brief Met en pause l'exécution du programme durant un temps
 * déterminé ou jusqu'à ce que l'utilisateur appuie sur une touche.
 *
 * @param [in] dureeEnSecondes la durée en secondes de la pause. Si ce 
 * paramètre est égal à 0, le programme s'interrompt jusqu'à ce que
 * l'utilisateur appuie sur une touche.
 */
void pause(unsigned int dureeEnSecondes = 0);

/**
 * @brief Efface le contenu du terminal
 *
 */
void effacer();

#endif