#ifndef FRAISE_H
#define FRAISE_H

#include"Labyrinthe.h"
#include"Position.h"


class Fraise
{
private:
    Position pos_Fraise ;
public:
    Fraise(/* args */);
    ~Fraise();
    Position & getPositionFraise();
    void setPositionFraise(const Position & p);
    bool positionValide(const Position & p);
    void gauche(const Labyrinthe & l);
    void droite(const Labyrinthe & l );
    void haut(const Labyrinthe & l );
    void bas(const Labyrinthe &l);



Fraise::Fraise(/* args */)
{
}

Fraise::~Fraise()
{
}



};






#endif
