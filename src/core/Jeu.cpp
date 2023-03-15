#include"Jeu.h"


Jeu::Jeu():niv(), gard(){
    fraises=NULL;
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

Niveau Jeu::getNiveau () const {
    return niv;
}  

Fraise * Jeu::getFraise ()const{
    return fraises;
}  

Gardien Jeu::getGardien() const{
    return gard;
}
