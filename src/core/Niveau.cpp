#include "Niveau.h"
#include <cassert>
#include<iostream>
#include <string>
#include <sstream> 
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

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

int Niveau::getNbFraises() const {
    return nbFraises;
}

void Niveau::setNbFraises(int n){
    nbFraises=n;
}

const Labyrinthe& Niveau:: getLab() const{
    return lab;
}

void Niveau::setLab(int n){
	string nom_fichier = "./data/niveau";
	string m(to_string(n));
	string extension=".txt";
	nom_fichier=nom_fichier.append(m);
	nom_fichier=nom_fichier.append(extension);
	ifstream fichier(nom_fichier);
    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir le fichier" << endl;
    }
    
    int nb_lignes, nb_colonnes;
    fichier>>nb_lignes>>nb_colonnes;
    assert(nb_lignes>=0);
	assert(nb_colonnes>=0);
	lab.setDim(nb_lignes,nb_colonnes);
	char tableau[nb_lignes][nb_colonnes];
	if(lab.tabLab!=NULL){
		delete[]lab.tabLab;
		lab.tabLab=NULL;
	}
	lab.tabLab=new TypeLab[nb_lignes*nb_colonnes];
    while(posInit_Fraises.size()!=0){
        posInit_Fraises.pop_back();
    }
    while(pos_EmpCibles.size()!=0){
        pos_EmpCibles.pop_back();
    }

	for (int x=0; x<nb_lignes; x++) {
        string ligne;
        fichier>>ligne;
        for (int y=0; y<nb_colonnes; y++) {
            tableau[x][y] = ligne[y];
            //cout<<tableau[x][y];
        }
        //cout<<endl;
    }
    
    for (int x=0; x<nb_lignes; x++) {
        for (int y=0; y<nb_colonnes; y++) {
			int i=x*nb_colonnes+y;
            Position p;
			switch(tableau[x][y])
			{
				case '#': lab.tabLab[i] = MUR; break;
				case '.': lab.tabLab[i] = VIDE; break;
				case '*': lab.tabLab[i] = EMPCIBLE; break;
				default : lab.tabLab[i] = VIDE; break;
			}
            if(tableau[x][y]=='G'){
                posInit_Gardien.setPosX(y);
                posInit_Gardien.setPosY(x);
            }
            if(tableau[x][y]=='*'){
                p.setPosX(y);
                p.setPosY(x);
                pos_EmpCibles.push_back(p);
            }
            if(tableau[x][y]=='F'){
                p.setPosX(y);
                p.setPosY(x);
                posInit_Fraises.push_back(p);
            }
        }
    } 
    nbFraises=posInit_Fraises.size(); 
/*    cout<<"position gardien: "<<posInit_Gardien.getPosX()<<","<<posInit_Gardien.getPosY()<<endl;
    for (int i=0;i<nbFraises;i++){
        cout<<"position fraise: "<<posInit_Fraises[i].getPosX()<<","<<posInit_Fraises[i].getPosY()<<endl;
    } */
}

vector<Position> Niveau::getPos_EmpCibles(){
    return pos_EmpCibles;
}

vector<Position> Niveau::getPosInit_Fraises(){
    return posInit_Fraises;
}

Position Niveau::getPosInit_Gardien()const{
    return posInit_Gardien;
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
    niv.setLab(1);
    assert(niv.getNbFraises() == (int)niv.getPosInit_Fraises().size());
    assert(niv.getNbFraises()==2);
    Position p(6,4);
    assert(niv.getPosInit_Gardien().getPosX()==p.getPosX());
    assert(niv.getPosInit_Gardien().getPosY()==p.getPosY());
    cout<<endl<<"fin de test de regression pour Niveau " <<endl;

}