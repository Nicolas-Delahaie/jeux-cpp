/*
  Auteur : N. DELAHAIE
  Date de dernière modification : 07/11/2021
*/

#include <iostream>
#include <windows.h>
#include "programmes.h"
#include <random>       // pour la fonction random
#include <chrono>       // pour la fonction now() utilisée dans la fonction random()

using namespace std;


// **************    F O N C T I O N N E L S   ********************

void afficherNombreEnCouleur (double nombre, Couleur couleur)
{
    HANDLE idTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(idTerminal, couleur);
    cout << nombre << flush;
    SetConsoleTextAttribute(idTerminal, gris);
}

void afficherCaractereEnCouleur (char caractere, Couleur couleur)
{
    HANDLE idTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(idTerminal, couleur);
    cout << caractere << flush;
    SetConsoleTextAttribute(idTerminal, gris);
}

int random (int min, int max)
{
    std::default_random_engine generateur;
    std::uniform_int_distribution<int> distributionNombres;
    unsigned int tempsActuel = static_cast<unsigned int>(chrono::steady_clock::now().time_since_epoch().count());
    generateur.seed(tempsActuel);

    return ((distributionNombres(generateur) % (max - min + 1)) + min);
}

void afficherLigne(unsigned int nombreCases)
{
    cout << endl << "+";
    for (unsigned int i = 0; i < nombreCases; i++)
    {
        cout << "---+";
    }
    cout << endl;    
}

void bombes(unsigned int emplacementsBombes[], const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR, const unsigned int &NOMBRE_BOMBES)
{
    unsigned int caseMax;                           //Index de la dernière case du tableau
    unsigned int emplacementBombe;                  //Emplacement temporaire d'une bombe, verifiée puis stockée dans EmplacementsBombes[] si l'emplacement a pas déjà été selectionné
    
    bool dejaPresent;                               //Indique si emplacementBombe a déjà été selectionné
    unsigned int i;

    i = 0;
    caseMax = LONGUEUR*LARGEUR -1;
    while (i != NOMBRE_BOMBES)
    {
        emplacementBombe = random (0, caseMax);
        cout << emplacementBombe << endl;

        dejaPresent = false;
        for (unsigned int n = 0 ; n < i ; n++)
        {
            if (emplacementBombe == emplacementsBombes[n])
            {
                dejaPresent = true;
            }
        }

        if (dejaPresent == false)
        {
            emplacementsBombes[i] = emplacementBombe;
            i++;
        }      
    }
}



// **************    N O N  -  F O N C T I O N N E L S   ********************

void afficheTableau(const short unsigned int tableau[][2],const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR)
{
    for (unsigned short int ligne = 0 ; ligne < LONGUEUR +1; ligne++)
    {
        if (ligne == 0) //Pour la première ligne
        {
            afficherLigne(LARGEUR+1);
            //Affichage lettres colorees
            cout << "|   |";
            for (unsigned int i = 0 ; i < LARGEUR ; i++)
            {
                cout << " ";
                afficherCaractereEnCouleur (char(65+i), rouge);
                cout << " |";
            }
            afficherLigne(LARGEUR+1);

        }
        else
        {
            for (unsigned short int colonne = 0 ; colonne < LARGEUR +1; colonne++)
            {
                if (colonne == 0) //Pour la première colonne
                {
                    cout << "| ";
                    afficherNombreEnCouleur(double(ligne), rouge);
                    if (ligne < 10)
                    {
                        cout << " |";
                    }
                    else
                    {
                        cout <<"|";
                    }
                }
                else 
                {
                    cout << " " << tableau[ligne-1][colonne-1] << " |";
                }
            }
            afficherLigne(LARGEUR+1);
        }
    }
}



void remplissageTableauUtilisateur(char tableau[][2], const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR)
{
    for (unsigned short int ligne = 0; ligne < LONGUEUR; ligne++)
    {
        for (unsigned short int colonne = 0 ; colonne < LARGEUR ; colonne++)
        {
            tableau[ligne][colonne] = char(219);
        }
    }
}


void remplissageBombesTableauInvisible(unsigned short int tableau[][2], const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR, const unsigned int NOMBRE_BOMBES, const unsigned int emplacementsBombes[])
{
    unsigned short int colonneBombe;                //Colonne d'une bombe de emplacementsBombes
    unsigned short int ligneBombe;                  //Ligne d'une bombe de emplacementsBombes
 
    // -- remplissage cases vides --
    for (unsigned short int ligne = 0 ; ligne < LONGUEUR ; ligne++)
    {
        for (unsigned short int colonne = 0 ; colonne < LARGEUR ; colonne++)
        {
            tableau[ligne][colonne] = 0;
        }
    }

    // -- remplissage bombes --
    for (unsigned int n = 0 ; n < NOMBRE_BOMBES ; n++)
    {
        ligneBombe =  static_cast<unsigned short int>(emplacementsBombes[n] / LARGEUR);
        colonneBombe = static_cast<unsigned short int>(emplacementsBombes[n] % LARGEUR);
        //cout << "Ligne " << ligneBombe << "  Colonne " << colonneBombe;
        tableau[ligneBombe][colonneBombe] = 9;
        //afficheTableau(tableau, LARGEUR, LONGUEUR);
    }
}


void remplissageNombresTableauInvisible(unsigned short int tableau[][2], const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR)
{
    unsigned short int y;
    unsigned short int x;
    short int xmin;                 //Encadrement de recherche de bombes
    short int xmax;                 //
    short int ymin;                 //
    short int ymax;                 //
    
    for (unsigned short int ligne = 0 ; ligne < LONGUEUR ; ligne++)
    {
        for (unsigned short int colonne = 0 ; colonne < LARGEUR ; colonne++)
        {
            if (tableau[ligne][colonne] != 9)
            {
                //unsigned int compteurDebug;
                //compteurDebug = 0;

                // Encadrement de recherche
                ymin = ligne -1;
                ymax = ligne +1;
                xmin = colonne -1;
                xmax = colonne +1;

                if (ligne == 0)                 {ymin = ligne;}
                else if (ligne == LONGUEUR -1)  {ymax = ligne;}
                if (colonne == 0)               {xmin = colonne;}
                else if (colonne == LARGEUR -1) {xmax = colonne;}
                
                /*
                afficheTableau(tableau, LARGEUR, LONGUEUR);
                cout << "Ligne : " << ligne << endl
                     << "Colonne : " << colonne << endl
                     << "x de " << xmin << " a " << xmax << endl
                     << "y de " << ymin << " a " << ymax << endl;
                */
               
                for (y = ymin ; y <= ymax ; y++)
                {
                    for (x = xmin ; x <= xmax ; x++)
                    {
                        if (tableau[y][x] == 9)
                        {
                            tableau[ligne][colonne]++;
                            //compteurDebug++;
                        }
                    }
                }
                //cout << compteurDebug << " bombes a proximite" << endl << endl;
            }
        }
    }
}