#include"Fraise.h"
#include"Dimension.h"
#include"Position.h"



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
