#include "Ship.h"
#include "Game.h"

Ship::Ship(Game* g, int r, int c,int d) 
    : Item(g, r, c) {
        direction=d;
        alive=1;
        shot=0;
        shotcount=0;
        shotspeed=3;
        colrange=0;
        rowrange=0;
        health=5;
        movecount=0;
        movespeed=2;
    }

void Ship::update(int c) {
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

void Ship::print() {
    game->paintAt(row, col, 'S');
}
void Ship::move(){
    if(direction==1) col--;
    if(direction==2) row--;
    if(direction==3) col++;
    if(direction==4) row++;
    if(col<=0) alive=0;
    if(col>100) alive=0;
    if(row<=0) alive=0;
    if(row>24) alive=0;
}
Ship::~Ship() {}
