/**
 * @brief Module gérant les fonctionalités relatives à la création d'un labyrinthe..
   un labyrinthe est un tableau 2D constitué de Murs(#),des cases vides (.) et des emplacement cibles (*).
@file Labyrinthe.h

*/





#ifndef LABY_H
#define LABY_H 
#include "Dimension.h"
#include <string>
#include "Position.h"




//_______________________________________________________________________________________________________________
/**
   @brief La classe Labyrinthe contient une enumération pour indiqué le type de case figurante dans le labyrinthe , sa dimention et un tableau 2D
   de ses types de cases  .
*/
class Labyrinthe {

    private : 

    enum TypeLab { VIDE = '.' , MUR = '#' ,EMPCIBLE='*' };
    Dimension dimL;

    TypeLab tabLab[200][200];

    public: 
    /**
    @brief <B>Construit</B> un objet Labyrinthe .
    Le constructeur remplit le tableau 2D de types de cases qui le correspond chaque case du tableau 
    */
    Labyrinthe();
    ~Labyrinthe();
    TypeLab getTypeLab (const Position & p )const ;
    void setTypeLab(Position & p , TypeLab lab );
    Dimension  getDim() const ;
   /* void setDim(const Dimension & dim );*/



};

#endif