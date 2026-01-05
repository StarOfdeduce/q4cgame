#ifndef _SHIP_H_
#define _SHIP_H_
#include "Item.h"
#include <iostream>
using namespace std;
class Ship:public Item {
public:
    int shot;
    int shotcount;
    int shotspeed;
    int health;
    int colrange,rowrange;
    int movespeed;
    int movecount;
    int score;
    int bulletcount;
    Ship(Game* g, int r, int w,int d);
    virtual void update(int);
    virtual void print();
    virtual void move();
    ~Ship();
};
#endif
