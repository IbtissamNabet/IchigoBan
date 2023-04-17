#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include"Jeu.h"
#include "winTxt.h"
#include"../core/Position.h"

#include"txtJeu.h"
using namespace std;
void txtAff(WinTXT & win, const Jeu & jeu) {
    const Labyrinthe& lab = jeu.getNiveau().getLab();
    const Fraise* fraises = jeu.getFraise();
    const int nbFraises = jeu.getNiveau().getNbFraises();
    const Gardien& gardien = jeu.getGardien();

    win.clear();

    // Affichage des murs 
    for(int x=0;x<lab.getDim().getLargeur();++x){
        for(int y=0;y<lab.getDim().getHauteur();++y){  
            win.print(x,y,lab.getTypeLab(Position(x, y)));
        }
    }

    // Affichage du Gardien
    win.print(gardien.getPositionGardien().getPosX(),gardien.getPositionGardien().getPosY(),'G');

    // Affichage des fraises
    for(int i=0;i<nbFraises;i++){
        win.print(fraises[i].getPositionFraise().getPosX(),fraises[i].getPositionFraise().getPosY(),'F');
    }

    win.draw();
}


   void txtBoucle (Jeu & jeu) {
    // Creation d'une nouvelle fenetre en mode texte
    // => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getNiveau().getLab().getDim().getLargeur(),jeu.getNiveau().getLab().getDim().getHauteur());

    bool ok = true;
    int c;

    do {
        txtAff(win,jeu);

        // Ajout de lignes pour le débogage
        std::cout << "Attente d'une touche..." << std::endl;
        std::cout << "Dernière touche : " << c << std::endl;

        #ifdef _WIN32
        Sleep(100);
        #else
        usleep(100000);
        #endif // WIN32

        c = win.getCh();

        // Ajout de lignes pour le débogage
        std::cout << "Touche pressée : " << c << std::endl;

        switch (c) {
            case 's':
                std::cout << "Touche G pressée" << std::endl;
                jeu.toucheClavier('g');
                break;
            case 'f':
                std::cout << "Touche D pressée" << std::endl;
                jeu.toucheClavier('d');
                break;
            case 'e':
                std::cout << "Touche H pressée" << std::endl;
                jeu.toucheClavier('h');
                break;
            case 'd':
                std::cout << "Touche B pressée" << std::endl;
                jeu.toucheClavier('b');
                break;
            case 'q':
				std::cout << "Touche Q pressée" << std::endl;
                ok = false;
                break;
        }
        if (jeu.partie_terminee()){
            termClear();
            jeu.setNiveau(jeu.niv.getNum()+1);
            win=WinTXT(jeu.niv.getLab().getDim().getLargeur(),jeu.getNiveau().getLab().getDim().getHauteur());
        }

    } while (ok);
}