#include"Jeu.h"

#include<iostream>
#include<math.h>
using namespace  std;

/*Jeu::Jeu():niv(), gard(){
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
}*/

Jeu::Jeu():gard(),niv(){
    fraises=NULL;
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

void Jeu::setNiveau(int n){
    niv.setNum(n);
    niv.setLab(n);
    if (fraises!=NULL){
        delete[]fraises;
        fraises=NULL;
    }
    fraises=new Fraise[niv.getNbFraises()];
    Fraise f;
    for (int i=0; i<niv.getNbFraises(); i++){
        f.setPositionFraise(niv.getPosInit_Fraises()[i]);
        fraises[i]=f;
    }  
    gard.setPositionGardien(niv.getPosInit_Gardien());  
}

void Jeu::toucheClavier (const char touche) {
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
            if ((j!=-1)&&(k==-1)&&niv.getLab().estPositionValide(p)){
                gard.droite(niv.getLab());
                fraises[j].droite(niv.getLab(), gard);
            }
            else if(j==-1){
                    gard.droite(niv.getLab());
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
            if ((j!=-1)&&(k==-1)&&niv.getLab().estPositionValide(p)){
                gard.gauche(niv.getLab());
                fraises[j].gauche(niv.getLab(), gard);
            }
            else if(j==-1){
                    gard.gauche(niv.getLab());
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
            if ((j!=-1)&&(k==-1)&&niv.getLab().estPositionValide(p)){
                gard.haut(niv.getLab());
                fraises[j].haut(niv.getLab(), gard);
            }
            else if(j==-1){
                    gard.haut(niv.getLab());
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
            if ((j!=-1)&&(k==-1)&&niv.getLab().estPositionValide(p)){
                gard.bas(niv.getLab());
                fraises[j].bas(niv.getLab(), gard);
            }
            else if(j==-1){
                    gard.bas(niv.getLab());
            }
            break;        
        default:
            break;
    } 
}

bool Jeu::partie_terminee(){
    bool fin=true;
    for (int i = 0; i < niv.getNbFraises(); i++){
        if(!placee(fraises[i])){
            fin=false;
        }
    }
    return(fin==true);
}

bool Jeu::placee(Fraise f){
    int i=-1;
    int pfx=f.getPositionFraise().getPosX();
    int pfy=f.getPositionFraise().getPosY();
    int pcx;
    int pcy;
    for (int j=0;j<niv.getNbFraises();j++){
        pcx=niv.getPos_EmpCibles()[j].getPosX();
        pcy=niv.getPos_EmpCibles()[j].getPosY();
        if ((pfx==pcx)&&(pfy==pcy)){
            i=0;
        }
    }
    return(i==0);
}
void Jeu::rejouer_partie(){
    gard.setPositionGardien(niv.getPosInit_Gardien());
    Fraise f ;
    for(int i=0 ;i< niv.getNbFraises();i++){
        f.setPositionFraise(niv.getPosInit_Fraises()[i]);
        fraises[i]=f;
    }
}