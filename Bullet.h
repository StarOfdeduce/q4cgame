#ifndef _BULLET_H_
#define _BULLET_H_
#include "Item.h"
#include <iostream>
using namespace std;
class Bullet:public Item {
public:
    int damage;
    Bullet(Game* g, int r, int w,int d);
    virtual void update(int);
    virtual void print();
    virtual void move();
    ~Bullet();
};
#endif
