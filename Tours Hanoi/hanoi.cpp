#include "pile.h"
#include "hanoi.h"
#include <conio.h>  //Pour getch
#include <iostream> //pour l'usage du type string
using namespace std;

/* ---------- Observateurs -----------*/
bool estDeplacable(const UnePile tourOrigine, const UnePile tourDestination)
{

    if (estVide(tourOrigine))
    {
        return false;
    }
    else 
    {
        if (estVide(tourDestination))
        {
            return true;
        }
        else
        {
            if (sommet(tourOrigine) < sommet(tourDestination))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}


/* ---------- Primitives -----------*/
void deplacerDisque(UnePile &tourOrigine, UnePile &tourDestination)
{
    UnElement disque;
    depiler(tourOrigine, disque);
    empiler(tourDestination, disque);
}

void remplirTour(UnePile &tourARemplir , const unsigned int nbDisques)
{
    for (unsigned int i = nbDisques ; i > 0 ; i--)
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
    unsigned short int espaceMilieu;        //Nombre de characteres séparant une bordure du centre
    unsigned short int espaceBordure;       //Espace séparant la bordure (|) d'un disque (-)
    unsigned short int largeur;             //Nombre de characteres séparant les 2 bordures (|)
    unsigned short int tailleDisque;        //Nombre de tirets représentant un disque
    
    UnePile copieTours[3];                  //Copie de lesTours qui est modifiable
    UnElement nombreDepile;                 //Disque (nombre) depilé d'une tour
    unsigned int hauteursPiles[3];



    largeur = 1 + 2 * nombreDisques;
    for (unsigned int i = 0; i < 3; i++)
    {
        copieTours[i] = lesTours[i];
    }
    
    espaceMilieu = largeur/2;

    // -- Affichage entête de grille --
    //Premiere ligne
    cout << "|";
    for (unsigned short int i = 0; i < 6 ; i++)
    {
        for (unsigned short int n = 0; n < espaceMilieu; n++)
        {
            cout << " ";
        }
        if (i%2 == 0)
        {
            cout << 1 + i/2;
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
    for (unsigned short int etage = nombreDisques ; etage > 0 ; etage--)
    {
        cout << "|";
        for (unsigned short int colonne = 0; colonne < 3; colonne++)
        {
            if(taille(copieTours [colonne]) == etage)
            {
                //Depilement
                depiler(copieTours[colonne],nombreDepile);

                //Calculs taille et espacements
                tailleDisque = nombreDepile*2 -1;
                espaceBordure = (largeur - tailleDisque)/2;

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
bool saisieVerifDeplacementDemande(unsigned int& origine, unsigned int& destination)
{
    int premiereSaisie;
    int deuxiemeSaisie;

        cout << endl << "Appuyez sur 1, 2 ou 3 | " ;

        //Pas égaux et egal soit à 1,2 ou 3
        while(true)
        {
            premiereSaisie = getch();
            cout << char(127);
            //cout << premiereSaisie << endl;
            deuxiemeSaisie = getch();
            cout << char(127) << endl;
             

            if (((premiereSaisie > 48) && (premiereSaisie < 52) &&
                 (deuxiemeSaisie > 48) && (deuxiemeSaisie < 52) &&
                 (premiereSaisie != deuxiemeSaisie)) ||
                 (premiereSaisie == 32))
            {
                break;
            }
            cout << "Erreur, WTF MAN" << endl;
        }
        
        //Espace pour recommencer
        if ((premiereSaisie == 32) && (deuxiemeSaisie == 32))
        {
            origine = 10;
            return false;
        }
        // ² pour CTRL-Z
        if (premiereSaisie == 253) 
        {
            origine = 11;
            return false;
        }
        //Bonne saisie
        else
        {
            origine = premiereSaisie - 49;
            destination = deuxiemeSaisie - 49;  
            return true;
        }
}


