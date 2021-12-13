#include "pile.h"
#include "hanoi.h"
#include <conio.h>  //Pour getch
#include <iostream> //pour l'usage du type string
using namespace std;

/* ---------- Observateurs -----------*/
bool estDeplacable(const UnePile tourOrigine, const UnePile tourDestination)
{
    //Disque deplaçable
    if (((estVide(tourDestination)) & !(estVide(tourOrigine))) || (sommet(tourOrigine) < sommet(tourDestination)))
    {
        return true;
    }

    //Disque indéplaçable
    else 
    {
        return false;
    }
}

/* ---------- Primitives -----------*/
void deplacerDisque(UnePile &tourOrigine, UnePile &tourDestination, UnePile saves[])
{
    UnElement disque;

    //Deplacement de disque
    depiler(tourOrigine, disque);
    empiler(tourDestination, disque);

    //Ajout aux saves
    saves[0] = tourOrigine;
    saves[1] = tourDestination;
}

void remplirTour(UnePile &tourARemplir, const unsigned int nbDisques)
{
    for (unsigned int i = nbDisques; i > 0; i--)
    {
        empiler(tourARemplir, i);
    }
}

void initialiserPiles(UnePile pile[], unsigned int taille)
{
    for (unsigned int i = 0; i < taille; i++)
    {
        initialiser(pile[i]);
    }
}

/* ---------- Affichage -----------*/
void afficherToursJoli(const UnePile lesTours[], const unsigned short int &nombreDisques)
{
    unsigned short int espaceMilieu;  //Nombre de characteres séparant une bordure du centre
    unsigned short int espaceBordure; //Espace séparant la bordure (|) d'un disque (-)
    unsigned short int largeur;       //Nombre de characteres séparant les 2 bordures (|)
    unsigned short int tailleDisque;  //Nombre de tirets représentant un disque

    UnePile copieTours[3];  //Copie de lesTours qui est modifiable
    UnElement nombreDepile; //Disque (nombre) depilé d'une tour
    unsigned int hauteursPiles[3];

    largeur = 1 + 2 * nombreDisques;
    for (unsigned int i = 0; i < 3; i++)
    {
        copieTours[i] = lesTours[i];
    }

    espaceMilieu = largeur / 2;

    // -- Affichage entête de grille --
    //Premiere ligne
    cout << "|";
    for (unsigned short int i = 0; i < 6; i++)
    {
        for (unsigned short int n = 0; n < espaceMilieu; n++)
        {
            cout << " ";
        }
        if (i % 2 == 0)
        {
            cout << 1 + i / 2;
        }
        else
        {
            cout << "|";
        }
    }

    cout << endl;

    //Deuxieme ligne
    cout << "|";
    for (unsigned short int i = 0; i < 3; i++)
    {
        for (unsigned n = 0; n < largeur; n++)
        {
            cout << "-";
        }
        cout << "|";
    }
    cout << endl;

    //Autres lignes
    for (unsigned short int etage = nombreDisques; etage > 0; etage--)
    {
        cout << "|";
        for (unsigned short int colonne = 0; colonne < 3; colonne++)
        {
            if (taille(copieTours[colonne]) == etage)
            {
                //Depilement
                depiler(copieTours[colonne], nombreDepile);

                //Calculs taille et espacements
                tailleDisque = nombreDepile * 2 - 1;
                espaceBordure = (largeur - tailleDisque) / 2;

                //Affichage disques
                for (unsigned int i = 0; i < espaceBordure; i++)
                {
                    cout << " ";
                }
                for (unsigned int i = 0; i < tailleDisque; i++)
                {
                    cout << "_";
                }
                for (unsigned int i = 0; i < espaceBordure; i++)
                {
                    cout << " ";
                }

                cout << "|";
            }
            else
            {
                //Affiche ligne vide
                for (unsigned int i = 0; i < largeur; i++)
                {
                    cout << " ";
                }
                cout << "|";
            }
        }
        cout << endl;
    }

    //Dernière ligne
    cout << "|";
    for (unsigned short int i = 0; i < 3; i++)
    {
        for (unsigned n = 0; n < largeur; n++)
        {
            cout << "m";
        }
        cout << "|";
    }
}

/* ---------- Outils -----------*/
bool saisieVerifDeplacementDemande(unsigned int &origine, unsigned int &destination)
{
    cout << endl
         << "Appuyez sur 1, 2 ou 3 | ";

    while (true)
    {
        // -- Premiere saisie --
        origine = getch();
        //Traduction/analyse premiere saisie
        if (traductionSaisie(origine))
        {
            cout << char(127);

            // ² pour CTRL-Z
            if (origine == 4)
            {
                return false;
            }
            

            // -- Deuxieme saisie --
            destination = getch();

            //Traduction/analyse deuxieme saisie
            if (traductionSaisie(destination))
            {
                cout << char(127);

                // ² pour CTRL-Z
                if (destination == 4)
                {
                    return false;
                }
                
                //Abandon
                else if ((origine == 3) && (destination == 3))
                {
                    return false;
                }
                
                //Aucun espace
                else if ((origine !=3) & (destination != 3))
                {
                    return true;
                }
            }
            cout << endl;
        }

        cout << "Erreur, WTF MAN" << endl;
    }    
}

bool traductionSaisie(unsigned int &saisie)
{
    switch (saisie)
    {
        //Abandon
        case int(' '): saisie = 3; break;

        //Retour en arrière
        case int('?'): saisie = 4; break;
        case int(','): saisie = 4; break;
        case 253: saisie = 4; break;        //²
        

        //1
        case int('1'): saisie = 0; break;
        case int('&'): saisie = 0; break;
        case int(';'): saisie = 0; break;
        case int('.'): saisie = 0; break;
        
        //2
        case int('2'): saisie = 1; break;
        case int('/'): saisie = 1; break;     
        case 130: saisie = 1;      break;        //é
        case int(':'): saisie = 1; break;
        
        //3
        case int('3'): saisie = 2; break;        
        case int('"'): saisie = 2; break;          
        case int('!'): saisie = 2; break;      
        case 245: saisie = 2;      break;        //§
        default:                   return false;
    }
    return true;
}