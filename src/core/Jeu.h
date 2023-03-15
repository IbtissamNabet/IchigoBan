#ifndef _JEU_H
#define _JEU_H

#include "Niveau.h"
#include "Fraise.h"
#include "Gardien.h"


class Jeu {

private :

    Niveau niv;
    Gardien gard;
    Fraise * fraises;
	  

public :
    Jeu();
    Jeu(Niveau N, Gardien G);
    Niveau getNiveau () const;                    
    Fraise * getFraise () const;                          
    Gardien getGardien() const;

};
#endif