
enum Couleur
{
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

//  FONCTIONNELS
void afficherNombreEnCouleur (double nombre, Couleur couleur);
/*GAMETOOLS : Permet d'afficher un nombre en couleur.*/
void afficherCaractereEnCouleur (char caractere, Couleur couleur);
/*GAMETOOLS : Permet d'afficher un caractère en couleur.*/
int random(int min, int max);
/*GAMETOOLS : Génère un nombre entier aléatoire compris dans un intervalle donné.*/
void afficherLigne(unsigned int nombreCases);
/*Affiche une ligne en fonction du nombreCases de cases */
void bombes(unsigned int emplacementsBombes[], const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR, const unsigned int &NOMBRE_BOMBES);
/*Retourne un tableau de taille LARGEUR et LONGUEUR composé de NOMBRE_BOMBES représentées par le 10.
  Les autres cases représentent le nombre de bombes sur les 8 cases alentours. */


//  NON - FONCTIONNELS
void afficheTableau(const short unsigned int tableau[][2],const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR);
/*Affiche un tableau*/
void remplissageTableauUtilisateur(char tableau[][2], const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR);
/*Créé un tableau rempli de dalles*/
void remplissageBombesTableauInvisible(unsigned short int tableau[][2], const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR, const unsigned int NOMBRE_BOMBES, const unsigned int emplacementsBombes[]);
/*Remplit le tableau invisible avec les bombes */
void remplissageNombresTableauInvisible(unsigned short int tableau[][2], const unsigned short int &LARGEUR, const unsigned short int &LONGUEUR);
/*Remplit le tableau invisible avec les nombres*/