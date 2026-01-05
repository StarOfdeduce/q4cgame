#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(Game* g, int r, int c,int d) 
    : Item(g, r, c) {
        direction=d;
        alive=1;
        damage=1;
    }

void Bullet::update(int c) {
    move();
    print();
}
void Bullet::move(){
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
void Bullet::print() {
    if(direction==1||direction==3)
         game->paintAt(row, col, '-');
    if(direction==2||direction==4)
         game->paintAt(row, col, '|');
}

Bullet::~Bullet() {}
