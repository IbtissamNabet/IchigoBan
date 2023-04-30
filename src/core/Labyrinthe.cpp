#include "Labyrinthe.h"
#include <cassert>
#include<iostream>
#include <string>

using namespace std ;

Labyrinthe::Labyrinthe(){
	dimL.setHauteur(0);
	dimL.setLargeur(0);
	tabLab=NULL;
}

Labyrinthe::~Labyrinthe(){
	dimL.setHauteur(0);
	dimL.setLargeur(0);
	if(tabLab!=NULL) {
		delete[]tabLab ;
		tabLab=nullptr;
	}	
}


Dimension Labyrinthe::getDim() const {
	return dimL;
}

void Labyrinthe::setDim(int hauteur, int largeur){
	dimL.setLargeur(largeur);
	dimL.setHauteur(hauteur);
}

TypeLab * Labyrinthe::getTabLab() const{
	return tabLab;
}

TypeLab Labyrinthe::getTypeLab (const Position & p )const {
	int x=p.getPosX();
	int y=p.getPosY();
	int dimx=dimL.getLargeur();
	int dimy=dimL.getHauteur();
	assert(x>=0);
	assert(y>=0);
	assert(y<dimy);
	assert(x<dimx);
	return tabLab[y*dimx+x];
}

bool Labyrinthe::estPositionValide(const Position & pos) const {
    int x = pos.getPosX();
    int y = pos.getPosY();
    if (x < 0 || x >= dimL.getLargeur() || y < 0 || y >= dimL.getHauteur()) {
        cout<<"problème dimL"<<endl;
		cout<<dimL.getHauteur()<<endl;
		cout<<dimL.getLargeur()<<endl;
		return false;
    }
    int i = y * dimL.getLargeur() + x;
    return (tabLab[i] != MUR);
}


void Labyrinthe::testRegression() const {
	 	Labyrinthe lab;
        assert(lab.dimL.getHauteur()==0);
        assert(lab.dimL.getLargeur()==0);
        assert(lab.tabLab==NULL); 
		lab.setDim(2,2);
        assert(lab.dimL.getHauteur()==2);
        assert(lab.dimL.getLargeur()==2);
		lab.tabLab=new TypeLab[2*2];
		Position p;
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				p=Position(i,j);
			}
		}  
		cout<<endl<<"fin de test de regression pour Labyrinthe " <<endl;
} 
