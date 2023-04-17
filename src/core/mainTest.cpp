#include"Fraise.h"
#include"Dimension.h"
#include"Position.h"
#include"Labyrinthe.h"
#include"Gardien.h"
#include"Niveau.h"
#include"Jeu.h"
#include<cassert>
#include<iostream>

using namespace std;


int main (){
    Fraise f;
    Gardien g;
    Niveau n;
    n.setLab(0);
    g.testRegression(n.getLab());
    f.testRegression(n.getLab());
    n.getLab().testRegression();
    n.testRegression();
}
