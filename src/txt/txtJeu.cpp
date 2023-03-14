#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"
#include"../core/Position.h"
#include"Jeu.h"
#include"txtJeu.h"


void txtAff(WinTXT & win, const Jeu & jeu) {
	const Labyrinthe& lab = jeu.getLab();
    //sconst Fraise& fraise= jeu.getFraise();
	const Gardien& gard = jeu.getGardien();


	
	win.clear();

    // Affichage des murs 
	Position p;
	for(int x=0;x<lab.getDim().getHauteur();++x){
		p.setPosX(x);
		for(int y=0;y<lab.getDim().getLargeur();++y){	
			p.setPosY(y);
			win.print(x,y,lab.getTypeLab(p));
            // Affichage du Gardien
            win.print(gard.getPositionGardien().getPosX(),gard.getPositionGardien().getPosY(),'G');
              // Affichage de la fraise
            //win.print(fraise.getPositionFraise().getPosX(),fraise.getPositionFraise().getPosY(),'F'); 

	win.draw();
        }
    }
}
