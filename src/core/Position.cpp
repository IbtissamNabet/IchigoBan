#ifndef DIM_H
#define DIM_H
#include "Position.h"

    Position::Position(){
        x=y=0;
    }
    int Position::getPosX() const{
        return x ;
    }
    int Position::getPosY() const{
        return y;
    }
    void Position::setPosX( int a ){
        x=a;

    }
    void Position::setPosY( int b){
        y=b;
    }
#endif
