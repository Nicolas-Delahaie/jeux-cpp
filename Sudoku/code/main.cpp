/**
 * @file sudoku.cpp
 * @author N. DELAHAIE
 * @brief Manipule les sous-programmes pour faire fonctionner le sudoku
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "sudoku.h"
#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#include <iostream>
using namespace std;

/*

X X X | X X X | X X X
X X X | X X X | X X X
X X X | X X X | X X X
------|-------|------
X X X | X X X | X X X
X X X | X X X | X X X
X X X | X X X | X X X
------|-------|------
X X X | X X X | X X X
X X X | X X X | X X X
X X X | X X X | X X X

*/
int main(void)
{
    bool deplacement;
    short int ligneEmplacement;
    short int colonneEmplacement;
    unsigned short int grille[9][9] = {{8,2,9,10,8,3,6,2,10},{9,10,8,2,7,10,0,2,9},{9,1,8,2,10,3,9,2,8},{10,10,10,9,1,0,2,7,3},{10,0,2,9,1,8,10,6,10},{9,1,0,10,9,3,8,4,10},{1,9,10,8,3,0,1,8,3},{0,10,4,9,2,10,4,4,0},{10,10,9,2,8,3,6,4,9}};

    //afficheGrille(grille);
    ligneEmplacement = 4;
    colonneEmplacement = 4;
    deplacement = true;

    while(deplacement)
    {
        afficheGrille(grille, ligneEmplacement, colonneEmplacement);
        saisieDeplacement(ligneEmplacement, colonneEmplacement, deplacement);
        effacer();
        
    }
    


    return 0;
}