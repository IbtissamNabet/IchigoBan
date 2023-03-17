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

Position Fraise::getPositionFraise(){
    return pos_Fraise;
}

void  Fraise::setPositionFraise(const Position & p){
     pos_Fraise.setPosX(p.getPosX());
     pos_Fraise.setPosY(p.getPosY());
}

void  Fraise::gauche(const Labyrinthe & l,const Gardien &g){
    int x=pos_Fraise.getPosX();//positionx actuelle de la fraise 
    int y=pos_Fraise.getPosY();//positiony actuelle de la fraise 
    int a=g.getPositionGardien().getPosX();//positionx actuelle du gardien
    int b=g.getPositionGardien().getPosY();//positiony actuelle du gardien
    Position p ;
    p.setPosX(x-1); //position de la case ou l'on veut se deplacer 
    p.setPosY(y);
    if ((l.estPositionValide(p))&&(((a==(x+1))&&(b==y))||((a==(x-1))&& (b==y))||((a==x)&&(b==(y-1)))||((a==x+1)&&(b==(y+1)))))pos_Fraise.setPosX(x--);
}

void  Fraise::droite(const Labyrinthe & l,const Gardien & g ){
    int x=pos_Fraise.getPosX();
    int y=pos_Fraise.getPosY();
    int a=g.getPositionGardien().getPosX();
    int b=g.getPositionGardien().getPosY();
    Position p ;
    p.setPosX(x+1);
    p.setPosY(y);
    if ((l.estPositionValide(p)) && (((a==x+1)&&(b==y))||((a==x-1)&& (b==y))||((a==x)&&(b==y-1))||((a==x+1)&&(b==y+1)))) pos_Fraise.setPosX(x++);
}

void  Fraise::haut(const Labyrinthe & l ,const Gardien & g){
    int x=pos_Fraise.getPosX();
    int y=pos_Fraise.getPosY();
    int a=g.getPositionGardien().getPosX();
    int b=g.getPositionGardien().getPosY();
    Position p ;
    p.setPosX(x);
    p.setPosY(y-1);
    if ((l.estPositionValide(p)) && (((a==x+1)&&(b==y))||((a==x-1)&& (b==y))||((a==x)&&(b==y-1))||((a==x+1)&&(b==y+1)))) pos_Fraise.setPosY(y--);
}

void  Fraise::bas(const Labyrinthe &l,const Gardien & g){
    int x=pos_Fraise.getPosX();
    int y=pos_Fraise.getPosY();
    int a=g.getPositionGardien().getPosX();
    int b=g.getPositionGardien().getPosY();
    Position p ;
    p.setPosX(x);
    p.setPosY(y+1);
    if ((l.estPositionValide(p))&& (((a==x+1)&&(b==y))||((a==x-1)&& (b==y))||((a==x)&&(b==y-1))||((a==x+1)&&(b==y+1)))) pos_Fraise.setPosY(y++);
}


void Fraise::testRegression(){
    Gardien g ;
    Labyrinthe l;
    Fraise f;
    Position p;
    p.setPosX(3);
    p.setPosY(3);
    f.setPositionFraise(p);

    f.gauche(l,g);
    assert((f.getPositionFraise().getPosX())==2);
    assert(f.getPositionFraise().getPosX()==3);

    g.droite(l);
    assert((f.getPositionFraise().getPosX())==3);
    assert(f.getPositionFraise().getPosX()==3);
    g.haut(l);
    assert((f.getPositionFraise().getPosX())==3);
    assert((f.getPositionFraise().getPosX())==2); 
    g.bas(l);
    assert((f.getPositionFraise().getPosX())==3);
    assert((f.getPositionFraise().getPosX())==3); 
    
    cout<<endl<<"fin de test de regression pour Fraise " <<endl;

    
    
}