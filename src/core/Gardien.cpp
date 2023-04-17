#include"Gardien.h"
#include<cassert>
#include<iostream>

using namespace std;




#include "Gardien.h"

Gardien::Gardien() {
    pos_gardien.setPosX(1);
    pos_gardien.setPosY(1);
}

Position Gardien::getPositionGardien() const {
    return pos_gardien;
}

void Gardien::setPositionGardien(const Position & p) {
    pos_gardien = p;
}

void Gardien::gauche(const Labyrinthe & l) {
    Position p(pos_gardien.getPosX() - 1, pos_gardien.getPosY());

    if (l.estPositionValide(p)) {
        pos_gardien = p;
    }
    else {
        cerr << "Erreur: Impossible de se déplacer à gauche gard ." << endl;
    }
}

void Gardien::droite(const Labyrinthe & l) {
    Position p(pos_gardien.getPosX() + 1, pos_gardien.getPosY());

    if (l.estPositionValide(p)) {
        pos_gardien = p;
    }
    else {
        cerr << "Erreur: Impossible de se déplacer à droite gard ." << endl;
    }
}

void Gardien::haut(const Labyrinthe & l) {
    Position p(pos_gardien.getPosX(), pos_gardien.getPosY() - 1);

    if (l.estPositionValide(p)) {
        pos_gardien = p;
    }
    else {
        cerr << "Erreur: Impossible de se déplacer en haut gard ." << endl;
    }
}

void Gardien::bas(const Labyrinthe & l) {
    Position p(pos_gardien.getPosX(), pos_gardien.getPosY() + 1);

    if (l.estPositionValide(p)) {
        pos_gardien = p;
    }
    else {
        cerr << "Erreur: Impossible de se déplacer en bas gard ." << endl;
    }
}

void Gardien::testRegression(const Labyrinthe & l) {
    Gardien g;
    Position p(5,3);
    g.setPositionGardien(p);
    g.gauche(l);
    assert((g.getPositionGardien().getPosX()) == 4);
    assert((g.getPositionGardien().getPosY()) == 3);

    g.droite(l);
    assert((g.getPositionGardien().getPosX()) == 5);
    assert((g.getPositionGardien().getPosY()) == 3);

    g.haut(l);
    assert((g.getPositionGardien().getPosX()) == 5);
    assert((g.getPositionGardien().getPosY()) == 2);

    g.bas(l);
    assert((g.getPositionGardien().getPosX()) == 5);
    assert((g.getPositionGardien().getPosY()) == 3);

    cout << endl << "Fin de test de regression pour Gardien " << endl;
}