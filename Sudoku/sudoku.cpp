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

void effacer (void)
{
    HANDLE idTerminal;
    CONSOLE_SCREEN_BUFFER_INFO caracteristiquesTerminal;
    DWORD count;
    DWORD nbreCellulesDansTerminal;
    COORD coordonneesOrigine = {0, 0};

    idTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
    if (idTerminal == INVALID_HANDLE_VALUE)
    {
        return;
    }

    /* Calculer le nombre de cellules du terminal */
    if (!GetConsoleScreenBufferInfo(idTerminal, &caracteristiquesTerminal))
    {
        return;
    }
    nbreCellulesDansTerminal = caracteristiquesTerminal.dwSize.X * caracteristiquesTerminal.dwSize.Y;

    /* Remplir le terminal avec des espaces */
    if (!FillConsoleOutputCharacter(idTerminal, (TCHAR)' ', nbreCellulesDansTerminal, coordonneesOrigine, &count))
    {
        return;
    }

    /*Remplir le terminal avec les couleurs courantes */
    if (!FillConsoleOutputAttribute(
            idTerminal,
            caracteristiquesTerminal.wAttributes,
            nbreCellulesDansTerminal,
            coordonneesOrigine,
            &count))
    {
        return;
    }

    /* Déplacer le curseur au début du terminal */
    SetConsoleCursorPosition(idTerminal, coordonneesOrigine);
}

void afficherNombreEnCouleur (double nombre, Couleur couleur)
{
    HANDLE idTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(idTerminal, couleur);
    cout << nombre << flush;
    SetConsoleTextAttribute(idTerminal, gris);
}

void afficheGrille(unsigned short int grille[9][9], short int ligneEmplacement, short int colonneEmplacement)
{
    unsigned short int chiffreSelectionne;
    Couleur couleur;
    chiffreSelectionne = grille[ligneEmplacement][colonneEmplacement];

    for (unsigned short int ligne = 0; ligne < 9; ligne++ )
    {
        for (unsigned short int colonne = 0; colonne < 9 ; colonne++)
        {
            if ( (ligne == ligneEmplacement) && (colonne == colonneEmplacement) )  
            {
                if (grille[ligne][colonne] == 10)   {afficherNombreEnCouleur(0, rougeFonceRempli);}
                else                                {afficherNombreEnCouleur(grille[ligne][colonne], noirSurRouge);}

            }
            else                                                                   
            {
                if (grille[ligne][colonne] == 10)    {cout << " ";}
                else                                {cout << grille[ligne][colonne];}
            }

            if ( (colonne == 2) || (colonne ==5) )  {cout << " | ";}
            else                                    {cout << " ";}
        }
        cout << endl;

        if ( (ligne == 2) || (ligne == 5) )
        {
            cout << "------|-------|------" << endl;
        }
    }
}


void saisieDeplacement (short int &ligneEmplacement, short int &colonneEmplacement, bool &deplacement)
{
    int saisie1;
    int saisie2;
    unsigned short int chiffreSelectionne;

    saisie1 = getch();

    if (saisie1 == 224)
    {
        saisie2 = getch();
        saisie2 -= 72;

        if (saisie2 == 0)           {ligneEmplacement--;}//haut
        else if (saisie2 == 3)      {colonneEmplacement--;}//gauche
        else if (saisie2 == 5)      {colonneEmplacement++;}//droite
        else if (saisie2 == 8)      {ligneEmplacement++;}//bas

        if (ligneEmplacement < 0)           {ligneEmplacement = 0;}
        else if (ligneEmplacement > 8)      {ligneEmplacement = 8;}
        if (colonneEmplacement < 0)         {colonneEmplacement = 0;}
        else if (colonneEmplacement > 8)    {colonneEmplacement = 8;}
    }

    else 
    {
        deplacement = false; 
    }
}


 
