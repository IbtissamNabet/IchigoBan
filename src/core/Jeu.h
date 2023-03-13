#ifndef _JEU_H
#define _JEU_H

#include "Labyrinthe.h"
#include "Fraise.h"
#include "Gardien.h"


class Jeu {

private :

	Labyrinthe lab;
    Gardien gard;
    Fraise fraise;
	  

public :
    Jeu();
    const Labyrinthe & getLab () const;                    
    const Fraise& getFraise () const;                          
    const Gardien& getGardien() const;

};
#endif