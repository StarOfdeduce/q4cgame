#include "Player.h"
#include "Game.h"

Player::Player(Game* g, int r, int c,int d) 
    : Ship(g, r, c , d) {
        colrange=0;
        rowrange=0;
        health=50;
        bulletcount=50;
        score=0;
    }

void Player::update(int c) {
    if(health==0){
        alive=0;
    }
    if(c==' '&&bulletcount!=0){
        shot=1;
        bulletcount--;
    }
    if(c=='w'){
        direction=2;
        colrange=0;
        rowrange=1;
        move();
    }
    if(c=='a'){
        direction=1;
        colrange=1;
        rowrange=0;
        move();
    }
    if(c=='d'){
        direction=3;
        colrange=1;
        rowrange=0;
        move();
    }
    if(c=='s'){
        direction=4;
        colrange=0;
        rowrange=1;
        move();
    }
    print();
}

void Player::print() {
    if(direction==1||direction==3){
         game->paintAt(row, col-1, '<');
         game->paintAt(row, col, '=');
         game->paintAt(row, col+1, '>');
    }
    if(direction==2||direction==4){
         game->paintAt(row-1, col, '^');
         game->paintAt(row, col, '"');
         game->paintAt(row+1, col, 'v');
    }
}
void Player::move(){
    if(direction==1) col--;
    if(direction==2) row--;
    if(direction==3) col++;
    if(direction==4) row++;
    if(col<=0) col++;
    if(col>100) col--;
    if(row<=0) row++;
    if(row>24) row--;
}
Player::~Player() {}
