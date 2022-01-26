
#include "file.h"
#include <iostream>
using namespace std;


void initialiser (File& f)
{
    f.nbElements = 0;
}

void ajouterElement (File& f, UnElement e)
{
    if (f.nbElements >= 20)
    {
        defiler(f);
    }
    enfiler(f, e);
}

void enfiler (File& f, UnElement e)
{
    //Exception : file remplie
    if (f.nbElements >= 20)
    {
        cout << "File pleine : impossible d'enfiler" << endl;
    }
    else
    {
        f.elements[f.nbElements] = e;
        f.nbElements++;
    }
}

void defiler (File& f)
{
    //Exception : file vide
    if (f.nbElements == 0)
    {
        cout << "File vide : impossible de défiler" << endl;
    }
    else
    {
        for (unsigned short int i = 0; i < f.nbElements - 1; i++)
        {
            f.elements[i] = f.elements[i+1];
        }
        f.nbElements--;
    }
}

