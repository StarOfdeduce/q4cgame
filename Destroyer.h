#ifndef _DESTROYER_H_
#define _DESTROYER_H_
#include "Item.h"
#include "Ship.h"
#include <iostream>
using namespace std;
class Destroyer:public Ship {
public:
    int shotcount2;
    int shotspeed2;
    Destroyer(Game* g, int r, int w,int d);
    void update(int);
    void print();
    void move();
    ~Destroyer();
};
#endif
