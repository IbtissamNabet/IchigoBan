#include "winTxt.h"
#include "txtJeu.h"

int main ( int argc, char** argv ) {
    termClear();
	Jeu jeu;
	jeu.setNiveau(0);
	txtBoucle(jeu);
    termClear();
	return 0;
}