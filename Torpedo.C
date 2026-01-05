#include "Torpedo.h"
#include "Game.h"

Torpedo::Torpedo(Game* g, int r, int c,int d) 
    : Bullet(g, r, c,d) {
        damage=10;
    }

void Torpedo::update(int c) {
    move();
    print();
}
void Torpedo::move(){
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
void Torpedo::print() {
     game->paintAt(row, col, '=');
}

Torpedo::~Torpedo() {}
