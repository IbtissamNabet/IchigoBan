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
	const Labyrinthe& lab = jeu.getNiveau().getLab();
    Fraise * fraise= jeu.getFraise();
	const Gardien& gard = jeu.getGardien();

	
	win.clear();

    // Affichage des murs 
	Position p;
	for(int x=0;x<lab.getDim().getLargeur();++x){
		p.setPosX(x);
		for(int y=0;y<lab.getDim().getHauteur();++y){	
			p.setPosY(y);
			win.print(x,y,lab.getTypeLab(p));
            // Affichage du Gardien
            win.print(gard.getPositionGardien().getPosX(),gard.getPositionGardien().getPosY(),'G');
            // Affichage de la fraise

			for(int i=0;i<jeu.getNiveau().getNbFraises();i++){
				win.print(fraise[i].getPositionFraise().getPosX(),fraise[i].getPositionFraise().getPosY(),'F');
			}
            

	win.draw();
        }
    }

}
void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	
    WinTXT win (jeu.getNiveau().getLab().getDim().getLargeur(),jeu.getNiveau().getLab().getDim().getHauteur());
	    txtAff(win,jeu);
	
}

