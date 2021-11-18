#ifndef PROGRAMMMES_H
#define PROGRAMMMES_H

enum Couleur
{
    bleu2 = 1,
    rougeFonce = 4,
    rougeFonceRempli = 68,
    jauneSurRouge = 70,
    noirSurRouge = 64,
    noirSurBleuClair = 176,

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

const unsigned int NOMBRE_BOMBES = 80;          //Nombre de bombes dans le tableau
const short unsigned int LARGEUR = 10;
const short unsigned int LONGUEUR = 10;

//  FONCTIONNELS
void test();
/*Affiche les couleurs*/
void afficherNombreEnCouleur (double nombre, Couleur couleur);
/*GAMETOOLS : Permet d'afficher un nombre en couleur.*/
void afficherCaractereEnCouleur (char caractere, Couleur couleur);
/*GAMETOOLS : Permet d'afficher un caractère en couleur.*/
int random(int min, int max);
/*GAMETOOLS : Génère un nombre entier aléatoire compris dans un intervalle donné.*/
void effacer();
/*Effacer la console*/
void afficherLigne(unsigned int nombreCases);
/*Affiche une ligne en fonction du nombreCases de cases */


void afficheTableauNombres(unsigned short int tab[][LONGUEUR],unsigned short int LARGEUR, unsigned short int LONGUEUR);
/*Affiche un tableau composé de nombres dans un tableau*/
void afficheTableauCaracteres(char tab[][LONGUEUR], unsigned short int LARGEUR,  unsigned short int LONGUEUR, int bombesRestantes);
/*Affiche un tableau composé de caractères dans un tableau*/
void remplissageTableauInvisible(unsigned short int tab[][LONGUEUR], unsigned short int LARGEUR, unsigned short int LONGUEUR, unsigned short int ligneCaseCiblee, unsigned short int colonneCaseCiblee);
/*Remplit le tableau invisible de nombres et de bombes*/
void remplissageTableauVisible(char tab[][LONGUEUR], unsigned short int LARGEUR, unsigned short int LONGUEUR);
/*Remplit le tableau visible de dalles (219)*/
void saisieVerifTraduction(char &instruction, unsigned short int &ligneCaseCiblee, unsigned short int &colonneCaseCiblee, unsigned short int LARGEUR, unsigned short int LONGUEUR);
/*Saisie l'instructiondu joueur et retourne une ligne, colonne et instruction*/
void modifCase (unsigned short int tabInvisible[][LONGUEUR], char tabVisible[][LONGUEUR], char instruction, unsigned short int ligneCaseCiblee, unsigned short int colonneCaseCiblee, unsigned short int LARGEUR, unsigned short int LONGUEUR, int &bombesRestantes);
/*Modifie une case en fonction des 2 tableaux, de l'instruction et des coordonnées de la case*/
void remplissageCasesVidesRecursif(unsigned short int tabInvisible[][LONGUEUR], char tabVisible[][LONGUEUR], unsigned short int ligneCaseCiblee, unsigned short int colonneCaseCiblee, unsigned short int LARGEUR, unsigned short int LONGUEUR);
/*Remplit récursivement les cases vides dans le tableau visible*/
void remplissageEcranFin(unsigned short int tabInvisible[][LONGUEUR], char tabVisible[][LONGUEUR], unsigned short int LARGEUR, unsigned short int LONGUEUR);
/*Remplit l'écran de fin en monttrant les erreurs du joueur et les bombes qu'il n'a pas trouvés*/
bool bombeCreusee(unsigned short int tabInvisible[][LONGUEUR], unsigned short int ligneCaseCiblee, unsigned short int colonneCaseCiblee);
/*Indique si la case est une bombe*/


#endif