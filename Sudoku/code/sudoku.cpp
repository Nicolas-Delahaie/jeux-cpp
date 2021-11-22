/**
 * @file sudoku.cpp
 * @author N. DELAHAIE
 * @brief SOus-programmes du sudoku
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "sudoku.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
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



void afficheGrille(unsigned short int grille[9][9])
{
    for (unsigned short int ligne = 0; ligne < 9; ligne++ )
    {
        for (unsigned short int colonne = 0; colonne < 9 ; colonne++)
        {
            cout << grille[ligne][colonne];
            if ( (colonne == 2) || (colonne ==5) )
            {
                cout << " | ";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;

        if ( (ligne == 2) || (ligne == 5) )
        {
            cout << "------|-------|------" << endl;
        }
    }
}

/*
void saisieDeplacemeent (short int &ligneEmplacmeent, short int &colonneEmplacement, bool &deplacement)
{
    int saisie1;
    int saisie2;
    saisie1 = getch();

    if (saisie1 == 224)
    {
        saisie2 = getch();
        saisie2 -= 72;

        if (saisie2 == 0)
        {

        }
        else if (saisie2 == 3)
        {
            
        }
        else if (saisie2 == 5)
        {
            
        }
        else if (saisie2 == 8)
        {
            
        }
    }
}
*/

 
