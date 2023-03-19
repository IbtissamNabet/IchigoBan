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
    Position  pf,pg;
    int pfx,pfy,pgx,pgy;
    for (int i = 0; i < niv.getNbFraises(); i++) {
        pf = fraises[i].getPositionFraise();
        pfx = pf.getPosX(); 
        pfy = pf.getPosY();
        pg = gard.getPositionGardien();
        pgx = pg.getPosX(); 
        pgy = pg.getPosY();

        switch (touche) {
            case 'd':
                if ((pfx-1 == pgx) && (pfy == pgy)) {
                    gard.droite(lab);
                    fraises[i].droite(lab, gard);
                } else {
                    gard.droite(lab);
                }
                break;

            case 'g':
                if ((pfx+1 == pgx) && (pfy == pgy)) {
                    gard.gauche(lab);
                    for (int j = 0; j < niv.getNbFraises(); j++) {
                        if ((fraises[j].getPositionFraise().getPosX() == pgx-1) && (fraises[j].getPositionFraise().getPosY() == pgy)) {
                            fraises[j].gauche(lab, gard);
                        }
                    }
                } else {
                    gard.gauche(lab);
                }
                break;

            case 'h':
                if ((pfx == pgx) && (pfy+1 == pgy)) {
                    gard.haut(lab);
                    fraises[i].haut(lab, gard);
                } else {
                    gard.haut(lab);
                }
                break;

            case 'b':
                if ((pfx == pgx) && (pfy-1 == pgy)) {
                    gard.bas(lab);
                    fraises[i].bas(lab, gard);
                } else {
                    gard.bas(lab);
                }
                break;
        }
    }
}