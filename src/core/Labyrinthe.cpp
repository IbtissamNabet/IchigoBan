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
 "#......#...##......#############......#",
 "#####..#....#..#####.....##############",
 "#......##...#......#.................##",
 "#......#....#......#....######..#..####",
 "#..................#..................#",
 "#..................#.....##.....#...**#",
 "#.....#......#.....###...........#..**#",
 "#.....#......#..***#................**#",
 "#######################################"
};

Labyrinthe::Labyrinthe () {
	dimL.setHauteur(20) ;
	dimL.setLargeur(40);
    int dimy=dimL.getHauteur();
	for(int x=0;x<dimL.getHauteur();++x)
		for(int y=0;y<dimL.getLargeur();++y)
		{
			switch(lab1[dimy-1-y][x])
			{
				case '#': tabLab[x][y] = MUR; break;
				case '.': tabLab[x][y] = VIDE; break;
				case '*': tabLab[x][y] = EMPCIBLE; break;
			}
			// m_ter[x][y] = m_terrain1[m_dimy-1-y][x];
		}
}

Labyrinthe::~Labyrinthe(){
	dimL.setHauteur(0);
	dimL.setLargeur(0);
	
}


Dimension  Labyrinthe::getDim() const {
	return dimL ;
}
/*
 void Labyrinthe::setDim(const Dimension & dim ){
	dimL.setHauteur(dim.getHauteur());
	dimL.setHauteur(dim.getHauteur());


 }*/


Labyrinthe::TypeLab Labyrinthe::getTypeLab (const Position & p )const {
	int x=p.getPosX();
	int y=p.getPosY();

	assert(x>=0);
	assert(y>=0);
	assert(x<dimL.getHauteur());
	assert(y<dimL.getLargeur());
	return tabLab[x][y];
}
void Labyrinthe::setTypeLab(Position & p , TypeLab lab ){
	int x=p.getPosX();
	int y=p.getPosY();
	assert(x>=0);
	assert(y>=0);
	assert(x<dimL.getHauteur() );
	assert(y<dimL.getLargeur());
	tabLab[x][y]=lab;
}