#include "Gunboat.h"
#include "Game.h"

Gunboat::Gunboat(Game* g, int r, int c,int d) 
    : Ship(g, r, c , d) {
        shot=0;
        shotcount=0;
        shotspeed=5;
        colrange=0;
        rowrange=0;
        health=1;
        movecount=0;
        movespeed=3;
        score=5;
    }

void Gunboat::update(int c) {
    if(health==0){
        alive=0;
    }
    shotcount++;
    if(shotcount==shotspeed){
        shot=1;
        shotcount=0;
    }
    movecount++;
    if(movecount==movespeed){
        move();
        movecount=0;
    }
    print();
}

void Gunboat::print() {
    game->paintAt(row, col, 'o');
}
void Gunboat::move(){
    if(direction==1) col--;
    if(direction==2) row--;
    if(direction==3) col++;
    if(direction==4) row++;
    if(col<=0) alive=0;
    if(col>100) alive=0;
    if(row<=0) alive=0;
    if(row>24) alive=0;
}
Gunboat::~Gunboat() {}
