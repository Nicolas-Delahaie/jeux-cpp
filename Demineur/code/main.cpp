/*
 Programme : Démineur
 Date de dernière modification : 09/11/2021
 Auteur : N. DELAHAIE
*/



/*
Reste à :
    - remplacer remplissageTableauInvisible en fonction pour qu'il dise si le nombre de bombes est torp élevé pour la largeur et la longueur 
    - Gérer le R 
*/


#include <iostream>
#include "programmes.h"

using namespace std;

int main (void)
{   
    
/*
    cout << "Saisie : ";
        cin >> instruction;
        cin >> lettreColonne;
        cin >> nombreLigne;
    
    cout << "lettre : ";
    cin >> nombretest;
    cout << nombretest;*/

    //    ****************      D E C L A R A T I O N S      ***************
    //    T Y P E S  
    //    C O N S T A N T E S   
    
    
    //    V A R I A B L E S  
    string reponseMessageDeFin;                                     //Réponse de l'utilisateur de s'il veut ou non recomencer une partie
    bool jouer;                                                     //Indique si le joueur veut jouer
    char instruction;                                               //Instruction donnée par l'utilisateur. S comme Signaler ou C comme creuser
    
    unsigned short int ligneCase;                                   //Ligne de la case désignée par l'utilisateur
    unsigned short int colonneCase;                                 //Colonne de la case désignée par l'utilisateur
    
    int bombesRestantes;                                            //Nombre de bombes theoriquement restantes
    unsigned int compteurCasesDecouvertes;                          //Compteur du nombre de cases découvertes
    unsigned int nombreDeCasesADecouvrir;                             //Nombre de cases a decouvrir ayant des chiffres
    
    short unsigned int tableauInvisible[LARGEUR][LONGUEUR];         //Tableau Invisible, composé de 9 pour les bombes et d'un nombre représentant le nombre de bombes sur les 8 cases adjacentes
    char tableauVisible[LARGEUR][LONGUEUR];                         //Tableau Visible, composé de dalles, completé au fur-et-à-mesure de la partie par le joueur


    //    *************      I N I T I A L I S A T I O N      *************
    jouer = true;

    
    // -- remplissage du tableau invisible --

    /*CA1
    afficheTableauCaracteres(tableauVisible, LARGEUR, LONGUEUR);
    tableauVisible[2][1] = '5';
    tableauVisible[2][0] = '4';
    tableauVisible[1][1] = '3';
    tableauVisible[1][0] = '2';
    afficheTableauCaracteres(tableauVisible, LARGEUR, LONGUEUR);
    */
    

    //    *************      J O U E R   L A   P A R T I E      ************
    
    while (jouer)
    {
        // -- DEBUT DE PARTIE --
        bombesRestantes = NOMBRE_BOMBES;
        compteurCasesDecouvertes = 0;
        remplissageTableauVisible(tableauVisible, LARGEUR, LONGUEUR);
        afficheTableauCaracteres(tableauVisible, LARGEUR, LONGUEUR, bombesRestantes);

        //Saisie
        saisieVerifTraduction(instruction, ligneCase, colonneCase, LARGEUR, LONGUEUR);

        //Initialisation des tableaux en fonction des emplacements de bombe
        remplissageTableauInvisible(tableauInvisible, LARGEUR, LONGUEUR, ligneCase, colonneCase);
        nombreDeCasesADecouvrir = casesADecouvrir(tableauInvisible, LARGEUR, LONGUEUR);
        modifCase(tableauInvisible, tableauVisible, instruction, ligneCase, colonneCase, LARGEUR, LONGUEUR, bombesRestantes, compteurCasesDecouvertes);
        

        while (true)
        {
            effacer();
            afficheTableauCaracteres(tableauVisible, LARGEUR, LONGUEUR, bombesRestantes);

            if (compteurCasesDecouvertes == nombreDeCasesADecouvrir)
            {
                cout << endl << "FELICITATION, vous avez trouve toutes les cases !" << endl << endl;
                break;
            }
            
        

            //Saisie-Verif-Traduction de l'instruction
            saisieVerifTraduction(instruction, ligneCase, colonneCase, LARGEUR, LONGUEUR);
            
            //Modification adaptée à l'instruction
            modifCase(tableauInvisible, tableauVisible, instruction, ligneCase, colonneCase, LARGEUR, LONGUEUR, bombesRestantes, compteurCasesDecouvertes);
            if ( instruction == 'R')
            {
                break;
            }
            else if (instruction == 'C')
            {
                if (bombeCreusee(tableauInvisible, ligneCase, colonneCase))
                {
                    remplissageEcranFin(tableauInvisible, tableauVisible, LARGEUR, LONGUEUR);
                    effacer();
                    afficheTableauCaracteres(tableauVisible, LARGEUR, LONGUEUR, bombesRestantes);
                    cout << "VOUS AVEZ PERDU !" << endl;
                    break;
                }
            }
        }

        //En fin de partie
        if (instruction != 'R')
        {
            cout << "Recommencer ? oui / non" << endl;
            cin >> reponseMessageDeFin;
            if (reponseMessageDeFin == "non") 
            {
                cout << "Pas de probleme, tchouss" << endl;
                jouer = false;
            }
            effacer();
        } 
        //Si le joueur veut recommencer
        else 
        {
            effacer();
        }
    }
    
    
    
    return 911;
}

