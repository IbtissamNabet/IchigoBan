#ifndef _JEU_H
#define _JEU_H

#include "Niveau.h"
#include "Fraise.h"
#include "Gardien.h"


class Jeu {

<<<<<<< Updated upstream
	Labyrinthe lab;
=======
private :

    Niveau niv;
>>>>>>> Stashed changes
    Gardien gard;
    Fraise * fraises;
	  

public :
    Jeu();
    Jeu(Niveau N, Gardien G);
    const Niveau& getNiveau () const;                    
 //   const Fraise& getFraise () const;                          
    const Gardien& getGardien() const;

};
#endif