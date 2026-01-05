#ifndef _TORPEDO_H_
#define _TORPEDP_H_
#include "Item.h"
#include "Bullet.h"
#include <iostream>
using namespace std;
class Torpedo:public Bullet {
public:
    Torpedo(Game* g, int r, int w,int d);
    void update(int);
    void print();
    void move();
    ~Torpedo();
};
#endif
