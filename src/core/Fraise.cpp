#include"Fraise.h"
#include"Dimension.h"
#include"Position.h"
#include<cassert>
#include<iostream>
using namespace std;


Fraise::Fraise(){
     pos_Fraise.setPosX(1);
     pos_Fraise.setPosY(1);
}

Position Fraise::getPositionFraise()const{
    return pos_Fraise;
}

void  Fraise::setPositionFraise(const Position & p){
     pos_Fraise.setPosX(p.getPosX());
     pos_Fraise.setPosY(p.getPosY());
}

void Fraise::gauche(const Labyrinthe& l, const Gardien& g){
    int x = pos_Fraise.getPosX();  // position actuelle de la fraise 
    int y = pos_Fraise.getPosY();
    int a = g.getPositionGardien().getPosX();  // position actuelle du gardien
    int b = g.getPositionGardien().getPosY();
    Position p;
    p.setPosX(x - 1);  // position de la case où l'on veut se déplacer
    p.setPosY(y);
    if (l.estPositionValide(p) && a == x && b == y) {
        pos_Fraise.setPosX(x - 1);
    }
    else {
        cerr << "Erreur: Impossible de se déplacer à gauche fraise ." << endl;
    }
}

void  Fraise::droite(const Labyrinthe & l,const Gardien & g ){
    int x=pos_Fraise.getPosX();
    int y=pos_Fraise.getPosY();
    int a=g.getPositionGardien().getPosX();
    int b=g.getPositionGardien().getPosY();
    Position p ;
    p.setPosX(x+1);
    p.setPosY(y);
    if (l.estPositionValide(p) && a == x && b == y) {
    pos_Fraise.setPosX(x + 1);
    }
    else {
    cerr << "Erreur: Impossible de se déplacer à droite fraise." << endl;
    }
}

void Fraise::haut(const Labyrinthe &l, const Gardien &g) {
    int x = pos_Fraise.getPosX();
    int y = pos_Fraise.getPosY();
    int a = g.getPositionGardien().getPosX();
    int b = g.getPositionGardien().getPosY();
    Position p;
    p.setPosX(x);
    p.setPosY(y - 1);
    if (l.estPositionValide(p) && a == x && b == y) {
    pos_Fraise.setPosY(y - 1);
    }
    else {
        cerr << "Erreur: Impossible de se déplacer en haut fraise." << endl;
    }
}

void Fraise::bas(const Labyrinthe &l, const Gardien &g) {
    int x = pos_Fraise.getPosX();
    int y = pos_Fraise.getPosY();
    int a = g.getPositionGardien().getPosX();
    int b = g.getPositionGardien().getPosY();
    Position p;
    p.setPosX(x);
    p.setPosY(y + 1);
    if (l.estPositionValide(p) && a == x && b == y) {
    pos_Fraise.setPosY(y + 1);
    }
    else {
        cerr << "Erreur: Impossible de se déplacer en bas fraise." << endl;
    }
}


void Fraise::testRegression(const Labyrinthe & l){
    Gardien g;
    Fraise f;
    Position p;
    p.setPosX(3);
    p.setPosY(3);
    f.setPositionFraise(p);
    g.setPositionGardien(p);

    f.gauche(l, g);
    assert(f.getPositionFraise().getPosX() == 2);
    assert(f.getPositionFraise().getPosY() == 3);

    g.droite(l);
    assert(f.getPositionFraise().getPosX() == 2);
    assert(f.getPositionFraise().getPosY() == 3);

    f.droite(l, g);
    assert(f.getPositionFraise().getPosX() == 2);
    assert(f.getPositionFraise().getPosY() == 3);
    cout <<"c'est normal" << endl;
    cout <<"fin de test de regression pour Fraise" << endl;
}