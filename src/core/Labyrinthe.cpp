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
	dimL.setHauteur(0);
	dimL.setLargeur(0);
	tabLab=NULL;

}


Labyrinthe::Labyrinthe (const Dimension & d) {
    int dimy=d.getHauteur();
	int dimx=d.getLargeur();
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
	delete [] tabLab ;
	if(tabLab!=NULL) {
		tabLab=nullptr;
	}
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

void Labyrinthe::testRegression() const {
	 	Labyrinthe lab;
        assert(lab.dimL.getHauteur()==0 );
        assert(lab.dimL.getLargeur()==0 );
		assert(lab.tabLab==nullptr);
		Dimension d ;
		d.setHauteur(150);
		d.setLargeur(200);
        Labyrinthe lab2(d);
        assert(lab2.getDim().getLargeur()==200);
        assert(lab2.getDim().getHauteur()==150);
        assert( lab2.tabLab!=nullptr );
        /*for(int i=0;i<lab2.getDim().getLargeur();i++)
        {
          assert(i<lab2.getDim().getLargeur());
            for( int j=0;j<lab2.getDim().getHauteur();j++)
            {
                assert(j<lab2.getDim().getHauteur());
				int i=j*lab2.getDim().getLargeur()+i;
                switch 
                assert(im2.getPix(64,128).getRouge()==0 );  
                assert(im2.getPix(64,128).getVert()==0 ); 
                assert(im2.getPix(64,128).getBleu()==0 ); 
              
                        // car une image en sortie du constructeur doit être toute noire
            } 
        
  } 
       */
}