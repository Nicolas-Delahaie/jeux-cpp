/**
 * @file Jeux_roulette.cpp
 * @author N. DELAHAIE  
 * @brief Modules pour jouer au jeux de la roulette
 * @version 0.1
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */


/*
    -Améliorer la fonction couleur pour qu'elle affiche aussi en fonction de la selection 
    -faire de ordre une variable globale
    -crééer la file dans l'affichage

*/

#include "Jeux_roulette.h"
#include "game-tools.h"
#include <conio.h>          //pour getch
#include <iostream> 
#include <windows.h>
using namespace std;

const unsigned short int LARGEUR = 14; 
unsigned short int ordre[5][LARGEUR] = {{255,3,6,9,12,15,18,21,24,27,30,33,36,40},
                                        {0,2,5,8,11,14,17,20,23,26,29,32,35,41},
                                        {255,1,4,7,10,13,16,19,22,25,28,31,34,42},
                                        {37,38,39},
                                        {43,44,45,46,47,48}};




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

unsigned short int tirage()
{
    return static_cast<unsigned short int>(random(0,36));
}


// I N D I C A T E U R S
Couleur couleurTirage(unsigned short int numero)
{
    unsigned short int i;

    const unsigned short int NB_NUMEROS_ROUGES = 19;
    unsigned short int listeNumerosRouges[NB_NUMEROS_ROUGES] = {1,3,5,7,9,12,14,16,18,21,23,25,27,28,30,32,34,36,46};
    unsigned short int listeNumerosNoirs[NB_NUMEROS_ROUGES] = {2,4,6,8,10,11,13,15,17,19,20,22,24,26,29,31,33,35,44};
    if (numero == 0)
    {
        return blancSurVert;
    }

    //Recherche de première occurence dans la liste des numeros rouges
    //Initialisations
    i = 0;
    while (true)
    {
        //Boucle parcourue (pas noir)
        if (i >= NB_NUMEROS_ROUGES)
        {
            break;
        }
        //Nombre présent dans le tableau
        if (listeNumerosRouges[i] == numero)
        {
            return blancSurRouge;
        }
        //Element suivant 
        else // ELSE INUTILE ?????????????????????????????????????????
        {
            i ++;
        }
    }

    i = 0;
    while (true)
    {
        //Boucle parcourue (pas noir)
        if (i >= NB_NUMEROS_ROUGES)
        {
            break;
        }
        //Nombre présent dans le tableau
        if (listeNumerosNoirs[i] == numero)
        {
            return blancSurNoir;
        }
        //Element suivant 
        else // ELSE INUTILE ?????????????????????????????????????????
        {
            i ++;
        }
    }

    return wtfMan;
}

bool gagnant (unsigned short int resultat, unsigned short int pari)
{
    if  (( (pari <= 36) && (resultat == pari) ) ||                      

         ( (pari == 37) && (resultat >= 1) && (resultat <= 12) ) ||                        
         ( (pari == 38) && (resultat >= 13) && (resultat <= 24) ) ||    
         ( (pari == 39) && (resultat >= 25) && (resultat <= 36) ) ||

         ( (pari == 40) && (resultat % 3 == 0) && (resultat != 0) ) ||
         ( (pari == 41) && (resultat % 3 == 2) ) ||
         ( (pari == 42) && (resultat % 3 == 1) ) ||

         ( (pari == 43) && (resultat >= 1) && (resultat <= 18) ) ||
         ( (pari == 44) && (resultat % 2 == 0) ) ||
         ( (pari == 45) && (couleurTirage(resultat) == blancSurRouge) ) ||
         ( (pari == 46) && (couleurTirage(resultat) == blancSurNoir) )||
         ( (pari == 47) && (resultat % 2 == 1) )||
         ( (pari == 48) && (resultat >= 19) && (resultat <= 36) ))
    {
        return true;
    }

    else
    {
        return false;
    }
}

string equivalenceEnString (unsigned short int pari)
{
    string mot;
    mot = "PD";

    if (pari <= 36)
    {
        //1 chiffre
        if (pari < 10)
        {
            mot[0] = char (pari + 48);
            mot[1] = ' ';
        }
        // 2 chiffres
        else
        {
            mot[0] = char (static_cast<unsigned int>(pari / 10) + 48);
            mot[1] = char ((pari % 10) + 48);
        }
    }    

    else
    {
        switch (pari)
        {
        case 37: mot = "       Tier 1       "; break;
        case 38: mot = "       Tier 2       "; break;
        case 39: mot = "       Tier 3       "; break;

        case 40: mot = "Ligne 1"; break;
        case 41: mot = "Ligne 2"; break;
        case 42: mot = "Ligne 3"; break;

        case 43: mot = "   1-18  "; break;
        case 44: mot = "   Pair   "; break;
        case 45: mot = "   Rouge  "; break;
        case 46: mot = "  Noir   "; break;
        case 47: mot = "  Impair  "; break;
        case 48: mot = " 19-36   "; break;
        
        default: mot = "erreur : pari depassant 48"; break;
        }
    }


   return mot;
}

/*
unsigned short int equivalenceEnNombre (string pari)
{
    unsigned short int resultat;
    unsigned short int taille;

    
    taille = pari.size();

    if (taille == 1)
    {
        resultat = int(pari[0])-48;
    }
    else if (taille == 2)
    {
        switch (pari)
        {
        case "Tier 1": resultat = 37; break;
        case "Tier 2" : resultat = 38; break;
        case "Tier 3" : resultat = 39; break;

        case "Ligne 1" : resultat = 40; break;
        case "Ligne 2" : resultat = 41; break;
        case "ligne 3" : resultat = 42; break;

        case "Pair" : resultat = 43; break;
        case "Impair" : resultat = 44; break;
        case "Noir" : resultat = 45; break;
        case "Rouge" : resultat = 46; break;
        case "1-18" : resultat = 47; break;
        case "19-36": resultat = 48; break;
        
        default: mot = "erreur : pari depassant 48"; break;
        }
    }
    else
    {
        return 666;
        cout << "WTF MAN" << endl;
    }


    if (pari<= 36)
    {
        //1 chiffre
        if (pari <= 2)
        {
            mot[0] = char (pari + 48);
            mot[1] = ' ';
        }
        // 2 chiffres
        else
        {
            mot[0] = char (static_cast<unsigned int>(pari / 10) + 48);
            mot[1] = char ((pari % 10) + 48);
        }
    }
    else
    {
        
    }


   return mot;
}
*/


// A F F I C H A G E S
void affichageSimple (unsigned short int ligneSelection, unsigned short int colonneSelection, unsigned int mise, bool reglageMise)
{
    unsigned short int element;                 //Element courant du tableau ordre
    string elementAffichable;                   //Chaine de caractère représentent element
    Couleur couleurElement;                     //Couleur de lelement affiche
    unsigned short int selection;

    selection = ordre[ligneSelection][colonneSelection];

    //Ligne 1 : Barre
    afficherTexteEnCouleur("|-----|--------------------------------------------------------------|---------|", blancSurVert);
    cout << endl;
    

    //Lignes 2,3,4 : Numeros et Lignes
    for (unsigned short int i = 0; i < 3; i++)
    {
        for (unsigned short int n = 0; n < LARGEUR; n++)
        {
            element = ordre[i][n];
            elementAffichable = equivalenceEnString(element);

            //Premiere colonne
            if (n==0)
            {
                //Definition couleur
                if (selection == element)
                {
                    couleurElement = blancSurOrange;
                }
                else
                {
                    couleurElement = blancSurVert;
                }

                afficherTexteEnCouleur("|  ", blancSurVert);
                if (element == 0)
                {
                    afficherTexteEnCouleur(elementAffichable, couleurElement);
                }
                else
                {
                    afficherTexteEnCouleur("  ", blancSurVert);
                }

                afficherTexteEnCouleur(" |", blancSurVert);
            }

            //Derniere colonne
            else if (n==LARGEUR-1)
            {
                //Definition couleur
                if (selection == element)
                {
                    couleurElement = blancSurOrange;
                }
                else
                {
                    couleurElement = blancSurVert;
                }

                afficherTexteEnCouleur("  | ", blancSurVert);
                afficherTexteEnCouleur(elementAffichable, couleurElement);
                afficherTexteEnCouleur(" |", blancSurVert);
            }

            //Autres colonnes
            else
            {
                //Definition de la couleur
                
                //Si lelement correspond a la selection
                if (element == selection)
                {
                    couleurElement = blancSurOrange;
                }

                //S il n a rien de particulier
                else
                {
                    couleurElement = couleurTirage(element);
                }

                afficherTexteEnCouleur("   ", blancSurVert);
                afficherTexteEnCouleur(elementAffichable, couleurElement);
            }
        }
        
        cout << endl;
    }
    

    //Ligne 5 : Barre
    afficherTexteEnCouleur("|-----|--------------------------------------------------------------|---------|", blancSurVert);
    cout << endl;


    //Ligne 6 : Tiers
    afficherTexteEnCouleur("      |", blancSurVert);
    for (unsigned short int i = 0; i < 3; i++)
    {
        //Definition couleur
        if (selection == ordre[3][i])
        {
            couleurElement = blancSurOrange;
        }
        else
        {
            couleurElement = blancSurVert;
        }
        afficherTexteEnCouleur(equivalenceEnString(ordre[3][i]), couleurElement); 
        afficherTexteEnCouleur("|", couleurElement);
    }
    afficherTexteEnCouleur("         |", blancSurVert);
    cout << endl;


    //Ligne 7 : Barre + mise
    //Definition couleur mise
    if (reglageMise)
    {
        couleurElement = blancSurViolet;
    }
    else
    {
        couleurElement = blancSurVert;
    }

    if (mise < 10)
    {
        afficherTexteEnCouleur("      |--------------------------------------------------------------|    ", blancSurVert);
        afficherNombreEnCouleur(static_cast<unsigned short int>(mise), couleurElement);
        afficherTexteEnCouleur("    |", blancSurVert);
    }
    else if ( mise < 100)
    {
        afficherTexteEnCouleur("      |--------------------------------------------------------------|    ", blancSurVert);
        afficherNombreEnCouleur(static_cast<unsigned short int>(mise), couleurElement);
        afficherTexteEnCouleur("   |", blancSurVert);
    }
    else if ( mise < 1000)
    {
        afficherTexteEnCouleur("      |--------------------------------------------------------------|   ", blancSurVert);
        afficherNombreEnCouleur(static_cast<unsigned short int>(mise), couleurElement);
        afficherTexteEnCouleur("   |", blancSurVert);
    }
    else if ( mise < 10000)
    {
        afficherTexteEnCouleur("      |--------------------------------------------------------------|  ", blancSurVert);
        afficherNombreEnCouleur(static_cast<unsigned short int>(mise), couleurElement);
        afficherTexteEnCouleur("   |", blancSurVert);
    }
    else if ( mise < 100000)
    {
        afficherTexteEnCouleur("      |--------------------------------------------------------------|  ", blancSurVert);
        afficherNombreEnCouleur(static_cast<unsigned short int>(mise), couleurElement);
        afficherTexteEnCouleur("  |", blancSurVert);
    }
    else
    {
        afficherTexteEnCouleur("      |--------------------------------------------------------------|?>100 000|", blancSurVert);

    }
    cout << endl;


    //Ligne 8 : Autres paris
    afficherTexteEnCouleur("      |", blancSurVert);
    for (unsigned short int i = 0; i < 6; i++)
    {
        element = ordre[4][i];

        //Definition couleur
        if (element == selection)
        {
            couleurElement = blancSurOrange;
        }
        else
        {
            if (element == 45)
            {
                couleurElement = blancSurRouge;
            }
            else if (element == 46)
            {
                couleurElement = blancSurNoir;
            }
            else
            {
                couleurElement = blancSurVert;
            } 
        }
        afficherTexteEnCouleur(equivalenceEnString(ordre[4][i]), couleurElement);
        afficherTexteEnCouleur('|', blancSurVert);
    }
    afficherTexteEnCouleur("         |", blancSurVert);
    cout << endl;


    //Ligne 9 : Barre
    afficherTexteEnCouleur("      |--------------------------------------------------------------|---------|", blancSurVert);
    cout << endl;
}

void retournerAuDebut()
{
    HANDLE idTerminal;
    COORD coordonneesOrigine = {0, 0};
    idTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(idTerminal, coordonneesOrigine);
    if (idTerminal == INVALID_HANDLE_VALUE)
    {
        return;
    }
}


// C A L C U L A T E U R S
unsigned int gain (unsigned short int pari, unsigned int argentMise)
{
    unsigned short int taux;

    //Taux de 36 lorsqu un nombre est mise
    if (pari <= 36) 
    {
        taux = 36;
    }
    //Taux de 3 lorsqu un tier ou une ligne est mise
    else if ( (pari >= 37) && (pari <= 42) )
    {
        taux = 3;
    }
    //Taux de 2 pour toute la ligne du bas
    else if ( (pari >= 43) && (pari <= 48) )
    {
        taux = 2;
    }

    else
    {
        taux = 0;
    }

    

    return argentMise * taux;
}


// S A I S I E
void saisieDeplacement (short int &ligneCaseCourante, short int &colonneCaseCourante, bool &saisie)
{
    unsigned short int largeur[5]={13,13,13,2,5};     //Indices max des cases du tableau par ligne
    int saisie1;
    int saisie2;

    //1ere saisie
    saisie1 = getch();


    //Déplacement
    if (saisie1 == 224)
    {
        saisie = false;

        //2e saisie
        saisie2 = getch();
        saisie2 -= 72;

        if (saisie2 == 0)   //haut
        {
            if (ligneCaseCourante > 0)
            {
                //case 0
                if ( (ligneCaseCourante == 1) && (colonneCaseCourante == 0) )
                {
                    colonneCaseCourante = 1;
                }

                //4e ligne
                else if (ligneCaseCourante == 3)
                {
                    switch (colonneCaseCourante)
                    {
                    case 0: 
                        colonneCaseCourante = 2;
                        break;
                    
                    case 1:
                        colonneCaseCourante = 6;
                        break;
                    case 2:
                        colonneCaseCourante = 10;
                        break;
                    
                    default:
                        break;
                    }
                }

                //5e ligne
                else if (ligneCaseCourante == 4)
                {
                    if (colonneCaseCourante < 2)
                    {
                        colonneCaseCourante = 0;
                    }
                    else if (colonneCaseCourante < 4)
                    {
                        colonneCaseCourante = 1;
                    }
                    else
                    {
                        colonneCaseCourante = 2;
                    }
                }
                              
                ligneCaseCourante--;
            }
        }
        
        else if (saisie2 == 3)    //gauche
        {
            if ( colonneCaseCourante > 0)
            {
                //Si l element est 3 ou 1
                if ( ( (ligneCaseCourante == 0) && (colonneCaseCourante == 1) ) ||
                     ( (ligneCaseCourante == 2) && (colonneCaseCourante == 1) ) )
                {
                    ligneCaseCourante = 1;
                }

                colonneCaseCourante--;
            }
        } 

        else if (saisie2 == 5)    //droite
        {
            if (colonneCaseCourante < largeur[ligneCaseCourante])
            {
                colonneCaseCourante++;
            }
        } 

        else if (saisie2 == 8)  //bas
        {
            if (ligneCaseCourante < 4)
            {
                //case 0
                if ( (ligneCaseCourante == 1) && (colonneCaseCourante == 0) )
                {
                    colonneCaseCourante++;
                }

                //3e ligne
                else if (ligneCaseCourante == 2)
                {
                    if (colonneCaseCourante < 5)
                    {
                        colonneCaseCourante = 0;
                    }
                    else if (colonneCaseCourante < 9)
                    {
                        colonneCaseCourante = 1;
                    }
                    else
                    {
                        colonneCaseCourante = 2;
                    }
                }

                //4e ligne
                else if (ligneCaseCourante == 3)
                {
                    switch (colonneCaseCourante)
                    {
                    case 0: 
                        colonneCaseCourante = 0;
                        break;
                    
                    case 1:
                        colonneCaseCourante = 2;
                        break;
                    case 2:
                        colonneCaseCourante = 4;
                        break;
                    
                    default:
                        break;
                    }
                }
            

                ligneCaseCourante++;
            }
        }
    }

    //Entrer
    else if (saisie1 == 13)
    {
        saisie = true;
    }
}

void ajustementMise (unsigned int &mise, bool &validee)
{
    int saisie;

    //Saisie
    saisie = getch();


    //Fleches ou Nombres (selection mise)
    if ( ( (saisie >= 48) && (saisie <= 55) ) || (saisie == 224) )
    {   
        saisie -= 48;

        switch (saisie)
        {
        case 1: mise++;   break;
        case 2: mise+=5;   break;
        case 3: mise+=10;   break;
        case 4: mise+=50;   break;
        case 5: mise+=100;   break;
        case 6: mise+=500;   break;
        case 7: mise+=1000;   break;
        
        default: cout << "wtf man (ajustement mise)" << endl; break;
        }
    }

    //Entrer (Validation mise)
    else if (saisie == 13)
    {
        validee = true;
    }

    //Effacer (remise à 0)
    else if (saisie == 8)
    {
        mise = 0;
    }


}



