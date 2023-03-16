#include "Labyrinthe.h"
#include <cassert>
#include<iostream>
#include <string>


using namespace std ;

const char lab1[15][40] = {
 "#######################################",
 "#.###....##........###.......##########",
 "#.#####..##...####.#........########..#",
 "#........##........#########..........#",
 "#........###....#.................#####",
 "#...#..#....#......#......#####....####",
 "#......#...##......######.............#",
 "#####..#....#..#####...........########",
 "#......##...#......#.................##",
 "#......#....#......#....######..#..####",
 "#..................#..................#",
 "#..................#.....##.....#...**#",
 "#.....#......#.....###...........#..**#",
 "#.....#......#.....#................**#",
 "#######################################"
};


Labyrinthe::Labyrinthe () {
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
	return dimL ;
}
/*
 void Labyrinthe::setDim(const Dimension & dim ){
	dimL.setHauteur(dim.getHauteur());
	dimL.setHauteur(dim.getHauteur());
 }*/


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
bool Labyrinthe::estPositionValide(const Position & p)const{
	int x = p.getPosX();
	int y = p.getPosY();
    return ((x>=0) && (x<dimL.getLargeur()) && (y>=0) && (y<dimL.getHauteur()) && (tabLab[y*dimL.getLargeur()+x]!='#'));


}


void Labyrinthe::testRegression() const {
	 	Labyrinthe lab;
        assert(lab.dimL.getHauteur()==15 );
        assert(lab.dimL.getLargeur()==40 );
        assert(lab.tabLab!=nullptr);   
		Position p;
		p=Position(0,0);
		assert(lab.getTypeLab(p)==MUR);
		lab.setTypeLab(p,VIDE);
		assert(lab.getTypeLab(p)==VIDE);
} 
