#ifndef LABY_H
#define LABY_H 
#include "Dimension.h"
#include "Position.h"

class Labyrinthe {

    private : 

    enum TypeLab { VIDE = 0 , MUR = 1 ,EMPCIBLE= 2 };
    Dimension dimL;

    TypeLab tabLab[200][200];

    public: 
    Labyrinthe();
    ~Labyrinthe();
    TypeLab getTypeLab (Position & p );
    void setTypeLab(Position & p , TypeLab lab );
    Dimension getDim();
    void setDim(const Dimension & dim );



};

#endif