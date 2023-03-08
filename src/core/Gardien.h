/**
 * @file Gardien.h
 
 * @brief Module gérant les fonctionalités relatives à la création d'un personnage(joueur) et controler ses action pour 
 pouvoir pousser les fraises dans leurs emplacements cibles.
   

*/


#ifndef GARD_
#define GARD_
#include"Position.h"
#include"Labyrinthe.h"


class Gardien {
private:
    Position pos_gardien; 
public :

Gardien();
Position  getPositionGardien()const;
void  setPositionGardien(const Position & p);
void gauche(const Labyrinthe & l);
void droite(const Labyrinthe & l );
void haut(const Labyrinthe & l );
void bas(const Labyrinthe &l);






};

#endif
