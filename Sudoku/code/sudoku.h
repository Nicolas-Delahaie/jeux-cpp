/**
 * @file sudoku.cpp
 * @author N. DELAHAIE
 * @brief Entête de sudoku.cpp
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */


/**
 * @brief Affiche une grille de sudoku
 * 
 * @param grille 
 */
void afficheGrille(unsigned short int grille[9][9]);

/**
 * @brief saisie un déplacement avec les flèches et modifie la ligne et la colonne de la case séléctionnée
 * 
 * @param ligneEmplacmeent 
 * @param colonneEmplacement 
 */
void saisieDeplacemeent (short int &ligneEmplacmeent, short int &colonneEmplacement, bool &deplacement);
