#ifndef PROGRAMMES_H
#define PROGRAMMES_H
enum Couleur
{
    rougeFonceRempli = 68,

    jauneSurRouge = 78,
    noirSurRouge= 64,

    bleu2 = 1,
    vert2 = 2,
    bleuTresClair = 3,
    rougeFonce = 4,
    rose = 5,
    orange = 6,
         
    /** La couleur gris a pour code couleur 7*/
    gris = 7,
    /** La couleur bleu a pour code couleur 9*/
    bleu = 9,
    /** La couleur vert a pour code couleur 10*/
    vert = 10,
    /** La couleur cyan a pour code couleur 11*/
    cyan = 11,
    /** La couleur rouge a pour code couleur 12*/
    rouge = 12,
    /** La couleur violet a pour code couleur 13*/
    violet = 13,
    /** La couleur jaune a pour code couleur 14*/
    jaune = 14,
    /** La couleur blanc a pour code couleur 15*/
    blanc = 15
};

const unsigned int NOMBRE_BOMBES = 30;                            //Nombre de bombes dans le tableau
const unsigned short int LARGEUR = 10;                            //Largeur du tableau
const unsigned short int LONGUEUR = 10;                           //Longueur du tableau
    

void test();


//  FONCTIONNELS
void afficherNombreEnCouleur (double nombre, Couleur couleur);
/*GAMETOOLS : Permet d'afficher un nombre en couleur.*/
void afficherCaractereEnCouleur (char caractere, Couleur couleur);
/*GAMETOOLS : Permet d'afficher un caractère en couleur.*/
int random(int min, int max);
/*GAMETOOLS : Génère un nombre entier aléatoire compris dans un intervalle donné.*/
void effacer();
/*GAMETOOLS : efface la console*/
void afficherLigne(unsigned int nombreCases);
/*Affiche une ligne en fonction du nombreCases de cases */
void bombes(unsigned int emplacementsBombes[], const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR, const unsigned int &NOMBRE_BOMBES);
/*Retourne un tableau de taille LARGEUR et LONGUEUR composé de NOMBRE_BOMBES représentées par le 10.
  Les autres cases représentent le nombre de bombes sur les 8 cases alentours. */


//  TABLEAU - FIXE
void afficheTableauNombres(const short unsigned int tab[][LONGUEUR],const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR);
/*Affiche un tableau composé de nombres*/
void afficheTableauCaracteres(char tab[][LONGUEUR],const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR, unsigned int bombesRestantes);
/*Affiche un tableau composé de caractères*/
void initialisationTableaux(char tabVisible[][LONGUEUR], unsigned short int tabInvisible[][LONGUEUR], unsigned int emplacementsBombes[], const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR, const unsigned int &NOMBRE_BOMBES);
/*Remplit les deux tableaux*/
//void remplissageNombresTableauInvisible(unsigned short int tableau[][LONGUEUR], const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR);
/*Remplit le tableau invisible avec les nombres*/
void saisieVerifTraduction(char &instruction, unsigned short int &ligneCaseCiblee, unsigned short int &colonneCaseCiblee,const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR);
/*Saisie-Verif de l'instruction et renvoit l'instruction ('S' ou 'C'), la ligne et colonne de la case demandée.*/
void ModifCase (char tabVisible[][LONGUEUR], unsigned short int tabInvisible[][LONGUEUR], char instruction, unsigned short int ligneCaseCiblee, unsigned short int colonneCaseCiblee);
/*Saisie des coordonnées sous forme de coordonnées et renvoit le charactère qui va le remplacer*/ 
void remplissageCasesVidesRecursif(unsigned short int tabInvisible[][LONGUEUR], char tabVisible[][LONGUEUR], unsigned short int ligneCaseCiblee, unsigned short int colonneCaseCiblee);
/*Remplit récursivement les cases vides de tabInvisible à partir de coordonnées*/
void remplissageEcranFin(unsigned short int tabInvisible[][LONGUEUR], char tabVisible[][LONGUEUR],const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR);
/*Remplit le tableau visible avec toutes les bombes*/
bool bombeCreusee(unsigned short int tabInvisible[][LONGUEUR], const unsigned short int &ligneCaseCiblee, const unsigned short int &colonneCaseCiblee);
/*Indique si une bombe a été creusée*/

#endif