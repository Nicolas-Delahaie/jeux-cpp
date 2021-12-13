/**
 * @file Affichage_Tours_Hanoi
 * @author Nicolas DELAHAIE
 * @brief Affiche les tours d'Hanoi
 * @date 2021-12-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */


void afficherToursJoli(const UnePile lesTours[], const unsigned short int &nombreDisques);
// Affiche le contenu des tours dans le tableau passe en parametres en fonction du nombre de disques


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