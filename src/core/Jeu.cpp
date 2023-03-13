#include"Jeu.h"


 Jeu::Jeu():lab(),fraise(),gard(){}
    const Labyrinthe & Jeu::getLab () const {
        return lab;
    }             
    const Fraise& Jeu::getFraise ()const{
        return fraise;
    }   
    const Gardien& Jeu::getGardien() const{
        return gard;
    }
