#include"Gardien.h"
#include<cassert>
#include<iostream>

using namespace std;




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

    if (l.estPositionValide(p)) {
        pos_gardien.setPosX(y--) ;
    }

}
void Gardien::bas(const Labyrinthe &l){

    int x=pos_gardien.getPosX();
    int y=pos_gardien.getPosY();
    Position p ;
    p.setPosX(x);
    p.setPosY(y+1);

    if (l.estPositionValide(p)) pos_gardien.setPosX(y++) ;


}
void Gardien::testRegression(){
    Gardien g ;
    Labyrinthe l;

    g.gauche(l);
    assert((g.getPositionGardien().getPosX())==1);
    assert((g.getPositionGardien().getPosY())==1);
    g.droite(l);
    assert((g.getPositionGardien().getPosX())==2);
    assert((g.getPositionGardien().getPosY())==1);
    g.haut(l);
     assert((g.getPositionGardien().getPosX())==2);
    assert((g.getPositionGardien().getPosY())==1);
    g.bas(l);
    assert((g.getPositionGardien().getPosX())==2);
    assert((g.getPositionGardien().getPosY())==2);

     cout<<endl<<"fin de test de regression pour Gardien " <<endl;
    
    









}
