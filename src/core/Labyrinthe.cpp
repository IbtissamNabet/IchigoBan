#include "Labyrinthe.h"
#include <cassert>
#include<iostream>
#include <string>



using namespace std ;

const char lab1[15][40] = {
 "#######################################",
 "#.###....##........###................#",
 "#.#......##...####.#........########..#",
 "#........##................#..........#",
 "#........###....#.................#####",
 "#...#..#....#......#......#####....####",
 "#..................##.................#",
 "#.......#....#......................###",
 "#......##...#......#.................##",
 "#......#....#......#....######..#..####",
 "#..................#..................#",
 "#..................#.....##.....#...**#",
 "#.....#......#...................#..**#",
 "#.....#......#.....#................**#",
 "#######################################"
};

Labyrinthe::Labyrinthe(){
	dimL.setHauteur(0);
	dimL.setLargeur(0);
	tabLab=NULL;
}

/*Labyrinthe::Labyrinthe () {
    int dimy=15;
	int dimx=40;
	assert(dimx>=0);
	assert(dimy>=0);
	dimL.setHauteur(dimy);
	dimL.setLargeur(dimx);
	tabLab=new TypeLab[dimx*dimy];
	for(int x=0;x<dimx;++x)
		for(int y=0;y<dimy;++y)
		{
			int i=y*dimx+x;
			switch(lab1[dimy-1-y][x])
			{
				case '#': tabLab[i] = MUR; break;
				case '.': tabLab[i] = VIDE; break;
				case '*': tabLab[i] = EMPCIBLE; break;
			}
		}
}*/


 Labyrinthe::~Labyrinthe(){
	dimL.setHauteur(0);
	dimL.setLargeur(0);
	if(tabLab!=NULL) {
		delete[]tabLab ;
		tabLab=nullptr;
	}	
 }


Dimension Labyrinthe::getDim() const {
	return dimL ;
}

void Labyrinthe::setDim(int hauteur, int largeur){
	dimL.setLargeur(largeur);
	dimL.setHauteur(hauteur);
}

TypeLab * Labyrinthe::getTabLab() const{
	return tabLab;
}

void Labyrinthe::setTabLab(TypeLab* p){
	tabLab=p;
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
void Labyrinthe::setTypeLab(Position & p , TypeLab lab ){
	int x=p.getPosX();
	int y=p.getPosY();
	int dimx=dimL.getLargeur();
	int dimy=dimL.getHauteur();
	assert(x>=0);
	assert(y>=0);
	assert(y<dimy);
	assert(x<dimx);
	int i=y*dimx+x;
	tabLab[i]=lab;
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
				TypeLab t=MUR;
				lab.setTypeLab(p,t);
			}
		}  
		p=Position(1,1);
		p=Position(0,0);
		assert(lab.getTypeLab(p)==MUR);
		cout<<endl<<"fin de test de regression pour Labyrinthe " <<endl;
} 
