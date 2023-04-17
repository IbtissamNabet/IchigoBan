#ifndef _JEU_H
#define _JEU_H

#include "Niveau.h"
#include "Fraise.h"
#include "Gardien.h"


class Jeu {

private :
    
    Fraise * fraises;
	  
public :
    Gardien gard;
    Niveau niv;
    Jeu();
    ~Jeu();
    Jeu(Niveau N, Gardien G);
    const Niveau & getNiveau () const;                    
    Fraise* getFraise () const;                          
    Gardien getGardien() const;
    void setNiveau(int n);
    void toucheClavier(const char touche);
    bool partie_terminee();//renvoie true si toutes les fraises sont placées
    bool placee(Fraise f);//renvoie true si la position de la fraise entrée en parametre correspond à un emplacement cible
};
#endif