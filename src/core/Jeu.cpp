#include"Jeu.h"
#include<iostream>
#include<math.h>

using namespace  std;

Jeu::Jeu():gard(),niv(){
    fraises=NULL;
}

Jeu::~Jeu(){
    if(fraises!=NULL) {
		delete[]fraises ;
		fraises=nullptr;
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

void Jeu::setNiveau(int n) {
   
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