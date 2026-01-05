#ifndef _GUNBOAT_H_
#define _GUNBOAT_H_
#include "Item.h"
#include "Ship.h"
#include <iostream>
using namespace std;
class Gunboat:public Ship {
public:
    Gunboat(Game* g, int r, int w,int d);
    void update(int);
    void print();
    void move();
    ~Gunboat();
};
#endif
