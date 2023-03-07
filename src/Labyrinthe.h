#ifndef LABY_H
#define LABY_H 
#include "Dimension.h"

class Labyrinthe {

    private : 

    enum TypeLab { VIDE = 0 , MUR = 1 ,EMPCIBLE= 2 };
    Dimension dimL;
    TypeLab tabLab[200][200];


};

#endif