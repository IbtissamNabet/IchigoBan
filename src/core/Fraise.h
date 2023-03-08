#ifndef FRAISE_H
#define FRAISE_H

#include"Labyrinthe.h"
#include"Position.h"
#include"Gardien.h"


class Fraise
{
private:
    Position pos_Fraise ;
public:
    Fraise();

    Position & getPositionFraise();
    void setPositionFraise(const Position & p);
    void gauche(const Labyrinthe & l,const Gardien & g);
    void droite(const Labyrinthe & l,const Gardien & g);
    void haut(const Labyrinthe & l,const Gardien & g);
    void bas(const Labyrinthe &l,const Gardien & g);




};






#endif
