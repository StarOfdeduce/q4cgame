#include "Destroyer.h"
#include "Game.h"

Destroyer::Destroyer(Game* g, int r, int c,int d) 
    : Ship(g, r, c , d) {
        shot=0;
        shotcount=0;
        shotspeed=5;
        shotcount2=0;
        shotspeed2=9;
        colrange=0;
        rowrange=0;
        health=10;
        movecount=0;
        movespeed=3;
        score=10;
    }

void Destroyer::update(int c) {
    if(health==0){
        alive=0;
    }
    shotcount++;
    if(shotcount==shotspeed){
        shot=1;
        shotcount=0;
    }
    shotcount2++;
    if(shotcount2==shotspeed2){
        int r=rand()%2;
        if(r==1) shot=2;
        else shot=3;
        shotcount2=0;
    }
    movecount++;
    if(movecount==movespeed){
        move();
        movecount=0;
    }
    print();
}

void Destroyer::print() {
    game->paintAt(row, col, 'O');
}
void Destroyer::move(){
    int r=rand()%10;
    if(r<3){
       direction+=r; 
    }
    if(direction>4) direction-=4;
    if(direction<1) direction+=4;
    if(direction==1) col--;
    if(direction==2) row--;
    if(direction==3) col++;
    if(direction==4) row++;
    if(col<=0) alive=0;
    if(col>100) alive=0;
    if(row<=0) alive=0;
    if(row>24) alive=0;
}
Destroyer::~Destroyer() {}
