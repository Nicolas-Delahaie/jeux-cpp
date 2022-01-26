#ifndef FILE_H
#define FILE_H

using namespace std;

const unsigned short int tailleFile = 20;

typedef unsigned short int UnElement;
struct File     //File contenant 20 elements dans un tableau ainsi qu'une propriété indiquant le nombres d'élements actuels
{
    UnElement elements[tailleFile];
    unsigned short int nbElements;
};


/**
 * @brief Intitialise nbElements à 0
 * 
 * @param f 
 */
void initialiser (File& f);
/**
 * @brief Ajoute un élement, quitte à défiler si la file est pleine
 * 
 * @param f 
 */
void ajouterElement (File& f, UnElement e);
/**
 * @brief Enfile e dans f si elle n est pas pleine
 * 
 * @param f 
 * @param e 
 */
void enfiler (File& f, UnElement e);
/**
 * @brief Déplie f si elle est pas vide
 * 
 * @param f 
 */
void defiler (File& f);



#endif