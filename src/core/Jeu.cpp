#include"Jeu.h"

#include<iostream>
#include<math.h>
using namespace  std;

Jeu::Jeu():niv(), gard(){
    Position p,p1,p2,p3,p4;
    p.setPosX(2);
    p.setPosY(6);
    niv.ajouterFraise(p);
    p1.setPosX(6);
    p1.setPosY(3);
    niv.ajouterFraise(p1);
    p2.setPosX(3);
    p2.setPosY(1);
    niv.ajouterFraise(p2);
    p3.setPosX(3);
    p3.setPosY(2);
    niv.ajouterFraise(p3);
    p4.setPosX(5);
    p4.setPosY(4);
    niv.ajouterFraise(p4);
    Fraise f;
    fraises=new Fraise[niv.getNbFraises()];
    for (int i=0; i<niv.getNbFraises();i++){
        f.setPositionFraise(niv.getPosInit_Fraises()[i]);
        fraises[i]=f;
    }
}

Jeu::~Jeu(){
    if(fraises!=NULL) {
		delete[]fraises ;
		fraises=nullptr;
    }
}

Jeu::Jeu(Niveau N, Gardien G){
    niv=N;
    gard=G;
    Fraise f;
    fraises=new Fraise[N.getNbFraises()];
    for (int i=0; i<N.getNbFraises(); i++){
        f.setPositionFraise(N.getPosInit_Fraises()[i]);
        fraises[i]=f;
    }
}

const Niveau &Jeu::getNiveau () const {
    return niv;
}  

Fraise * Jeu::getFraise ()const{
    return fraises;
}  

Gardien Jeu::getGardien() const{
    return gard;
   
}

void Jeu::toucheClavier (const char touche) {
    Labyrinthe lab;
    Position  pf,pg,p;
    int pfx,pfy,pgx,pgy;
    pg = gard.getPositionGardien();
    pgx = pg.getPosX(); 
    pgy = pg.getPosY();
    int j=-1;
    int k=-1;
    switch (touche)
    {
        case 'd':
            for (int i = 0; i < niv.getNbFraises(); i++) {
            pf = fraises[i].getPositionFraise();
            pfx = pf.getPosX(); 
            pfy = pf.getPosY();
                if ((pfx == pgx+1) && (pfy == pgy)) {
                    j=i;
                }
                if ((pfx == pgx+2) && (pfy == pgy)) {
                    k=i;
                }            
            }
            p.setPosX(pgx+2);
            p.setPosY(pgy);
            if ((j!=-1)&&(k==-1)&&lab.estPositionValide(p)){
                gard.droite(lab);
                fraises[j].droite(lab, gard);
            }
            else if(j==-1){
                    gard.droite(lab);
            }
            break;

        case 'g':
            for (int i = 0; i < niv.getNbFraises(); i++) {
            pf = fraises[i].getPositionFraise();
            pfx = pf.getPosX(); 
            pfy = pf.getPosY();
                if ((pfx == pgx-1) && (pfy == pgy)) {
                    j=i;
                }
                if ((pfx == pgx-2) && (pfy == pgy)) {
                    k=i;
                }            
            }
            p.setPosX(pgx-2);
            p.setPosY(pgy);
            if ((j!=-1)&&(k==-1)&&lab.estPositionValide(p)){
                gard.gauche(lab);
                fraises[j].gauche(lab, gard);
            }
            else if(j==-1){
                    gard.gauche(lab);
            }
            break;

        case 'h':
            for (int i = 0; i < niv.getNbFraises(); i++) {
            pf = fraises[i].getPositionFraise();
            pfx = pf.getPosX(); 
            pfy = pf.getPosY();
                if ((pfx == pgx) && (pfy == pgy-1)) {
                    j=i;
                }
                if ((pfx == pgx) && (pfy == pgy-2)) {
                    k=i;
                }            
            }
            p.setPosX(pgx);
            p.setPosY(pgy-2);
            if ((j!=-1)&&(k==-1)&&lab.estPositionValide(p)){
                gard.haut(lab);
                fraises[j].haut(lab, gard);
            }
            else if(j==-1){
                    gard.haut(lab);
            }
            break;

        case 'b':
            for (int i = 0; i < niv.getNbFraises(); i++) {
            pf = fraises[i].getPositionFraise();
            pfx = pf.getPosX(); 
            pfy = pf.getPosY();
                if ((pfx == pgx) && (pfy == pgy+1)) {
                    j=i;
                }
                if ((pfx == pgx) && (pfy == pgy+2)) {
                    k=i;
                }            
            }
            p.setPosX(pgx);
            p.setPosY(pgy+2);
            if ((j!=-1)&&(k==-1)&&lab.estPositionValide(p)){
                gard.bas(lab);
                fraises[j].bas(lab, gard);
            }
            else if(j==-1){
                    gard.bas(lab);
            }
            break;        
        default:
            break;
    } 
}
