/**
 * @file sudoku.cpp
 * @author N. DELAHAIE
 * @brief Entête de sudoku.cpp
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

enum Couleur
{
    bleu2 = 1,
    rougeFonce = 4,
    rougeFonceRempli = 68,
    
    jauneSurRouge = 70,

    noirSurRouge = 64,
    noirSurBleuClair = 176,

    /** La couleur gris a pour code couleur 7*/
    gris = 7,
    /** La couleur bleu a pour code couleur 9*/
    bleu = 9,
    /** La couleur vert a pour code couleur 10*/
    vert = 10,
    /** La couleur cyan a pour code couleur 11*/
    cyan = 11,
    /** La couleur rouge a pour code couleur 12*/
    rouge = 12,
    /** La couleur violet a pour code couleur 13*/
    violet = 13,
    /** La couleur jaune a pour code couleur 14*/
    jaune = 14,
    /** La couleur blanc a pour code couleur 15*/
    blanc = 15
};


void effacer (void);
void afficherNombreEnCouleur (double nombre, Couleur couleur);


/**
 * @brief Affiche une grille de sudoku
 * 
 * @param grille 
 */
void afficheGrille(unsigned short int grille[9][9], short int ligneEmplacement, short int colonneEmplacement);

/**
 * @brief saisie un déplacement avec les flèches et modifie la ligne et la colonne de la case séléctionnée
 * 
 * @param ligneEmplacmeent 
 * @param colonneEmplacement 
 */
void saisieDeplacement (short int &ligneEmplacement, short int &colonneEmplacement, bool &deplacement);
