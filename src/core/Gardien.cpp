#include"Gardien.h"






Gardien::Gardien(){
    pos_gardien.setPosX(1);
    pos_gardien.setPosY(1);

}
Position Gardien::getPositionGardien()const{
    return pos_gardien ;


}
void  Gardien::setPositionGardien(const Position & p){
    pos_gardien.setPosX(p.getPosX());
    pos_gardien.setPosY(p.getPosY());

}

   
void Gardien::gauche(const Labyrinthe & l){
    int x=pos_gardien.getPosX();
    int y=pos_gardien.getPosY();
    Position p ;
    p.setPosX(x-1);
    p.setPosY(y);

    if (l.estPositionValide(p)) pos_gardien.setPosX(x--) ;
}


void Gardien::droite(const Labyrinthe & l ){
    int x=pos_gardien.getPosX();
    int y=pos_gardien.getPosY();
    Position p ;
    p.setPosX(x+1);
    p.setPosY(y);

    if (l.estPositionValide(p)) pos_gardien.setPosX(x++) ;

}
void Gardien::haut(const Labyrinthe & l ){
    int x=pos_gardien.getPosX();
    int y=pos_gardien.getPosY();
    Position p ;
    p.setPosX(x);
    p.setPosY(y-1);

    if (l.estPositionValide(p)) pos_gardien.setPosX(y--) ;

}
void Gardien::bas(const Labyrinthe &l){

    int x=pos_gardien.getPosX();
    int y=pos_gardien.getPosY();
    Position p ;
    p.setPosX(x);
    p.setPosY(y+1);

    if (l.estPositionValide(p)) pos_gardien.setPosX(y++) ;


}
