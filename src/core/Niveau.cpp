#include "Niveau.h"
#include <cassert>
#include<iostream>


Niveau::Niveau():lab(){
    num=0;
    nbFraises=0;
}

int Niveau::getNum(){
    return num;
}

void Niveau::setNum(int n){
    num=n;
}

int Niveau::getNbFraises(){
    return nbFraises;
}

void Niveau::setNbFraises(int n){
    nbFraises=n;
}

const Labyrinthe& Niveau:: getLab() const{
    return lab;
}

vector<Position> Niveau::getPos_EmpCibles(){
    return pos_EmpCibles;
}

vector<Position> Niveau::getPosInit_Fraises(){
    return posInit_Fraises;
}

void Niveau::ajouterFraise(const Position & p){
    posInit_Fraises.push_back(p);
    nbFraises=posInit_Fraises.size();
}

void Niveau::ajouterEmpCible(const Position & p){
    pos_EmpCibles.push_back(p);
}

void Niveau::modifLab(){
    Position p;
    TypeLab t;
    for (int i=0; i<(int)pos_EmpCibles.size(); i++){
        p=pos_EmpCibles[i]; 
        t=EMPCIBLE;
        lab.setTypeLab(p,t);      
    }
}

void Niveau::testRegression() const {
    Niveau niv;
    assert(niv.getNum()==0);
    assert(niv.getNbFraises()==0);
    assert(niv.getPos_EmpCibles().size()==0);
    assert(niv.getPosInit_Fraises().size()==0);
    Position p1(4,5);
    Position p2(1,2);
    niv.ajouterFraise(p1);
    assert(niv.getNbFraises() == (int)niv.getPosInit_Fraises().size());
    niv.ajouterEmpCible(p2);
    assert(niv.getPos_EmpCibles().size()!=0);
    niv.modifLab();
}