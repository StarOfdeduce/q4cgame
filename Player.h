#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Item.h"
#include "Ship.h"
#include <iostream>
using namespace std;
class Player:public Ship {
public:
    int bulletcount;
    Player(Game* g, int r, int w,int d);
    void update(int);
    void print();
    void move();
    ~Player();
};
#endif
