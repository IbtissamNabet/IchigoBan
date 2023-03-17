#ifndef _JEU_H
#define _JEU_H

#include "Niveau.h"
#include "Fraise.h"
#include "Gardien.h"


class Jeu {

private :

    Niveau niv;
    
    Fraise * fraises;
	  

public :
    Gardien gard;
    Jeu();
    ~Jeu();
    Jeu(Niveau N, Gardien G);
    const Niveau & getNiveau () const;                    
    Fraise* getFraise () const;                          
    Gardien getGardien() const;
    void toucheClavier(const char touche);

};
#endif