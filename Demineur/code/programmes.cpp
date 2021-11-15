/*
  Auteur : N. DELAHAIE
  Date de dernière modification : 09/11/2021
*/
#include "programmes.h"

#include <iostream>
#include <windows.h>
#include <random>       // pour la fonction random
#include <chrono>       // pour la fonction now() utilisée dans la fonction random()

using namespace std;


// **************    F O N C T I O N N E L S   ********************

void test()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // you can loop k higher to see more color choices
    for(int k = 1; k < 255; k++)
    {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(hConsole, WORD(k));
    cout << k << " I want to be nice today!" << endl;
    }
}

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

void afficherLigne(unsigned int nombreCases)
{
    cout << endl << "+";
    for (unsigned int i = 0; i < nombreCases; i++)
    {
        cout << "---+";
    }
    cout << endl;    
}





// **************    T A B L E A U  -  F I X E     ********************

void afficheTableauNombres(short unsigned int tab[][LONGUEUR],unsigned short int LARGEUR, unsigned short int LONGUEUR)
{
    Couleur couleurNombre;
    short unsigned int nombre;
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
                    nombre = tab[ligne-1][colonne-1];
                    switch (nombre)
                    {
                    case 0: couleurNombre = blanc; break;
                    case 1: couleurNombre = bleu; break;
                    case 2: couleurNombre = vert; break;         
                    case 3: couleurNombre = rouge; break;
                    case 4: couleurNombre = bleu2; break;
                    case 5: couleurNombre = rougeFonce; break;
                    case 6: couleurNombre = cyan; break;
                    case 9: couleurNombre = rougeFonceRempli; break;
                    default: couleurNombre = violet; break;
                    }

                    cout << " ";
                    afficherNombreEnCouleur(nombre, couleurNombre);
                    cout << " |";
                }
            }
        }
        afficherLigne(LARGEUR+1);
    }
}

void afficheTableauCaracteres(char tab[][LONGUEUR], unsigned short int LARGEUR,  unsigned short int LONGUEUR, unsigned int bombesRestantes)
{
    Couleur couleurCaractere;
    char caractere;
    for (unsigned short int ligne = 0 ; ligne < LONGUEUR +1; ligne++)
    {
        if (ligne == 0) //Pour la première ligne
        {
            afficherLigne(LARGEUR+1);
            //Affichage lettres colorees
            cout << "| ";
            afficherNombreEnCouleur(bombesRestantes, noirSurRouge);
            cout << "|";
            for (unsigned int i = 0 ; i < LARGEUR ; i++)
            {
                cout << " ";
                afficherCaractereEnCouleur (char(65+i), rouge);
                cout << " |";
            }

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
                    cout << " ";
                    caractere = tab[ligne-1][colonne-1];
    
                    switch (caractere)
                    {
                    case char(219): couleurCaractere = gris; break;             //Dalle
                    case char(20): couleurCaractere = jaune; break;             //Drapeau 
                    case char(244): couleurCaractere = jauneSurRouge; break;    //Drapeau erroné
                    case 'N': couleurCaractere = rougeFonceRempli; break;       //Bombe non trouvé
                    case 'X': couleurCaractere = noirSurRouge; break;           //Bombe explosée
                    case '1': couleurCaractere = bleu; break;
                    case '2': couleurCaractere = vert; break;
                    case '3': couleurCaractere = rouge; break;
                    case '4': couleurCaractere = bleu2; break;
                    case '5': couleurCaractere = rougeFonce; break;      
                    case '6': couleurCaractere = cyan; break;   
                       
                    default: couleurCaractere = violet; break;
                    }
                    afficherCaractereEnCouleur(caractere, couleurCaractere);
                    cout << " |";
                }
            }
        }
        afficherLigne(LARGEUR+1);
    }
}

void remplissageTableauInvisible(unsigned short int tab[][LONGUEUR], unsigned short int LARGEUR, unsigned short int LONGUEUR, unsigned short int ligneCaseCiblee, unsigned short int colonneCaseCiblee)
{
    const unsigned int NOMBRE_BOMBES = 30;          //Nombre de bombes dans le tableau
    bool dejaPresent;                               //Indique si emplacementBombe a déjà été selectionné
    unsigned int i;
    unsigned int emplacementsBombes[NOMBRE_BOMBES]; //Liste de tous les emplacements des bombes
    unsigned int emplacementBombe;                  //Emplacement temporaire d'une bombe, verifiée puis stockée dans EmplacementsBombes[] si l'emplacement a pas déjà été selectionné
    unsigned int caseMax;                           //Index de la dernière case du tableau
    caseMax = LONGUEUR*LARGEUR -1;

    while (true)
    {
        // ********************** Création emplacements de bombes ***********************
        i = 0;
        while (i != NOMBRE_BOMBES)
        {
            emplacementBombe = random (0, caseMax);

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
        // **************** Remplissage du tableau Invisible avec bombes ****************
        unsigned short int colonneBombe;                //Colonne d'une bombe de emplacementsBombes
        unsigned short int ligneBombe;                  //Ligne d'une bombe de emplacementsBombes

    
        // -- remplissage cases vides --
        for (unsigned short int ligne = 0 ; ligne < LONGUEUR ; ligne++)
        {
            for (unsigned short int colonne = 0 ; colonne < LARGEUR ; colonne++)
            {
                tab[ligne][colonne] = 0;
            }
        }

        // -- remplissage bombes --
        for (unsigned int n = 0 ; n < NOMBRE_BOMBES ; n++)
        {
            ligneBombe =  static_cast<unsigned short int>(emplacementsBombes[n] / LARGEUR);
            colonneBombe = static_cast<unsigned short int>(emplacementsBombes[n] % LARGEUR);
            //cout << "Ligne " << ligneBombe << "  Colonne " << colonneBombe;
            tab[ligneBombe][colonneBombe] = 9;
            //afficheTableau(tableau, LARGEUR, LONGUEUR);
        }

        // **************** Remplissage du tableau Invisible avec nombres ****************
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
                if (tab[ligne][colonne] != 9)
                {
                    // Encadrement de recherche
                    ymin = static_cast<short int>(ligne -1);
                    ymax = static_cast<short int>(ligne +1);
                    xmin = static_cast<short int>(colonne -1);
                    xmax = static_cast<short int>(colonne +1);

                    if (ligne == 0)                 {ymin = ligne;}
                    else if (ligne == LONGUEUR -1)  {ymax = ligne;}
                    if (colonne == 0)               {xmin = colonne;}
                    else if (colonne == LARGEUR -1) {xmax = colonne;}
                    
                
                    for (y = ymin ; y <= ymax ; y++)
                    {
                        for (x = xmin ; x <= xmax ; x++)
                        {
                            if (tab[y][x] == 9)
                            {
                                tab[ligne][colonne]++;
                            }
                        }
                    }
                }
            }
        }
        if (tab[ligneCaseCiblee][colonneCaseCiblee] == 0)
        {
            break;
        }
    }
}

void remplissageTableauVisible(char tab[][LONGUEUR], unsigned short int LARGEUR, unsigned short int LONGUEUR)
{
    for (unsigned short int ligne = 0; ligne < LONGUEUR; ligne++)
    {
        for (unsigned short int colonne = 0 ; colonne < LARGEUR ; colonne++)
        {
            tab[ligne][colonne] = char(219);
        }
    }   
}

void saisieVerifTraduction(char &instruction, unsigned short int &ligneCaseCiblee, unsigned short int &colonneCaseCiblee, unsigned short int LARGEUR, unsigned short int LONGUEUR)
{
    char lettreColonne;
    unsigned short int nombreLigne;

    //SAISIES-VERIF
    cout << "Instruction (C pour Creuser / S pour Signaler) suivie des coordonnees (lettre puis nombre colles) de la forme 'SA7': "<< endl;
    while(true)
    {
        cout << "Saisie : ";
        cin >> instruction;
        if (instruction != 'C' && instruction != 'S' && instruction != 'R')         {cout << "Mauvaise instruction saisie, recommencez." << endl;}

        if (instruction == 'C' || instruction == 'S')
        {
            cin >> lettreColonne;
            cin >> nombreLigne;

            if ((int(lettreColonne) < 65) || (int(lettreColonne) >= 65+LARGEUR))        {cout << "Mauvaise lettre saisie, recommencez." << endl;}  
            else if ((nombreLigne <= 0) || (nombreLigne > LONGUEUR))                    {cout << "Mauvaise ligne saisie, recommencez." << endl;}                                     
        }
    }

    ligneCaseCiblee = static_cast<unsigned short int>(nombreLigne - 1);
    colonneCaseCiblee = static_cast<unsigned short int>(lettreColonne - 65);
}

void modifCase (unsigned short int tabInvisible[][LONGUEUR], char tabVisible[][LONGUEUR], char instruction, unsigned short int ligneCaseCiblee, unsigned short int colonneCaseCiblee, const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR)
{
    //MODIFICATIONS    
    if (instruction == 'C')
    {
        //Si la case est une bombe
        if (tabInvisible[ligneCaseCiblee][colonneCaseCiblee] == 9)
        {
            tabVisible[ligneCaseCiblee][colonneCaseCiblee] =  'X';
        }
        //Si la case est vide
        else if (tabInvisible[ligneCaseCiblee][colonneCaseCiblee] == 0)        
        {
            remplissageCasesVidesRecursif(tabInvisible, tabVisible, ligneCaseCiblee, colonneCaseCiblee, LARGEUR, LONGUEUR);
        }
        //Si la case est un nombre
        else                              
        {
            tabVisible[ligneCaseCiblee][colonneCaseCiblee] =  char(tabInvisible[ligneCaseCiblee][colonneCaseCiblee] + 48) ;
        }
    }
    else if ((instruction == 'S') && (tabVisible[ligneCaseCiblee][colonneCaseCiblee] = char(219)))
    {
        tabVisible[ligneCaseCiblee][colonneCaseCiblee] = char(20);
    }
}

void remplissageCasesVidesRecursif(unsigned short int tabInvisible[][LONGUEUR], char tabVisible[][LONGUEUR], unsigned short int ligneCaseCiblee, unsigned short int colonneCaseCiblee, unsigned short int LARGEUR, unsigned short int LONGUEUR)
{
    unsigned short int y;
    unsigned short int x;
    short int xmin;                 //Encadrement de recherche de bombes
    short int xmax;                 //
    short int ymin;                 //
    short int ymax;                 //
    
    if (tabInvisible[ligneCaseCiblee][colonneCaseCiblee] == 0)
    {
        tabVisible[ligneCaseCiblee][colonneCaseCiblee] = ' ';

        ymin = static_cast<short int>(ligneCaseCiblee -1);
        ymax = static_cast<short int>(ligneCaseCiblee +1);
        xmin = static_cast<short int>(colonneCaseCiblee -1);
        xmax = static_cast<short int>(colonneCaseCiblee +1);

        //Ne prend pas en compte les cases en dehors du tableau
        if (ligneCaseCiblee == 0)                 {ymin = ligneCaseCiblee;}
        else if (ligneCaseCiblee == LONGUEUR -1)  {ymax = ligneCaseCiblee;}
        if (colonneCaseCiblee == 0)               {xmin = colonneCaseCiblee;}
        else if (colonneCaseCiblee == LARGEUR -1) {xmax = colonneCaseCiblee;}

        for (y = ymin ; y < ymax +1 ; y++)
        {
            for ( x = xmin ; x < xmax +1 ; x++)
            {
                if ( tabVisible[y][x] == char(219))    //Case non découverte
                {
                    //if ( ( (y == ligneCaseCiblee) || (x == colonneCaseCiblee) ) && (tabInvisible[y][x] == 0) )      //
                   
                    remplissageCasesVidesRecursif(tabInvisible, tabVisible, y, x, LARGEUR, LONGUEUR);                 
                }
            }
        }
    }
    else 
    {
        tabVisible[ligneCaseCiblee][colonneCaseCiblee] =  char(tabInvisible[ligneCaseCiblee][colonneCaseCiblee] + 48) ;
    }
}

void remplissageEcranFin(unsigned short int tabInvisible[][LONGUEUR], char tabVisible[][LONGUEUR], unsigned short int LARGEUR, unsigned short int LONGUEUR)
{
    //Parcourt le tableau
    for (unsigned short int ligne = 0 ; ligne < LONGUEUR ; ligne++)
    {
        for (unsigned short int colonne = 0 ; colonne < LARGEUR ; colonne++)
        {
            //Si la case est un signalement faux --> 'X'
            if ((tabVisible[ligne][colonne] == 20) && (tabInvisible[ligne][colonne] != 9))
            {
                tabVisible[ligne][colonne] = char(244);
            }

            //Si la case est une bombe non signalée --> 'O'
            if ((tabInvisible[ligne][colonne] == 9) && (tabVisible[ligne][colonne] != 20) && (tabVisible[ligne][colonne] != 'X'))
            {
                tabVisible[ligne][colonne] = 'N';
            }
        }
    }
}

bool bombeCreusee(unsigned short int tabInvisible[][LONGUEUR], unsigned short int ligneCaseCiblee, unsigned short int colonneCaseCiblee)
{
    if (tabInvisible[ligneCaseCiblee][colonneCaseCiblee] == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

