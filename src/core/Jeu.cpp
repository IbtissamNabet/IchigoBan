#include"Jeu.h"


Jeu::Jeu():niv(), gard(){
    Position p,p1,p2,p3,p4;
    p.setPosX(2);
    p.setPosY(1);
    niv.ajouterFraise(p);
    p1.setPosX(2);
    p1.setPosY(2);
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
