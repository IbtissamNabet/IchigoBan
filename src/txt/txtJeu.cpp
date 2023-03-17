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
	//const Gardien& gard = jeu.getGardien();

	
	win.clear();

    // Affichage des murs 
	Position p;
	for(int x=0;x<lab.getDim().getLargeur();++x){
		p.setPosX(x);
		for(int y=0;y<lab.getDim().getHauteur();++y){	
			p.setPosY(y);
			win.print(x,y,lab.getTypeLab(p));
            // Affichage du Gardien
            win.print(jeu.getGardien().getPositionGardien().getPosX(),jeu.getGardien().getPositionGardien().getPosY(),'G');
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
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getNiveau().getLab().getDim().getLargeur(),jeu.getNiveau().getLab().getDim().getHauteur());

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		c = win.getCh();
		switch (c) {
			case 's':
				jeu.toucheClavier('g');
				break;
			case 'f':
				jeu.toucheClavier('d');
				break;
			case 'e':
				jeu.toucheClavier('h');
				break;
			case 'd':
				jeu.toucheClavier('b');
				break;
			case 'q':
				ok = false;
				break;
		}

	} while (ok);

}


