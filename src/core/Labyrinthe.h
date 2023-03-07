#ifndef LABY_H
#define LABY_H 
#include "Dimension.h"
#include <string>
#include "Position.h"

class Labyrinthe {

    private : 

    enum TypeLab { VIDE = '.' , MUR = '#' ,EMPCIBLE='*' };
    Dimension dimL;

    TypeLab tabLab[200][200];

    public: 
    Labyrinthe();
    ~Labyrinthe();
    TypeLab getTypeLab (const Position & p )const ;
    void setTypeLab(Position & p , TypeLab lab );
    Dimension  getDim() const ;
   /* void setDim(const Dimension & dim );*/



};

#endif