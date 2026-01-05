#ifndef _ITEM_H_
#define _ITEM_H_

#define MAXROW 30
#define MAXCOL 80
#include <iostream>
using namespace std;
class Game;
class Item {
public:
    int row;
    int col;
    size_t last;
    int direction;
    int health;
    int alive;
    Game* game;
    Item();
    virtual ~Item() {}
    Item(Game* g, int r, int w);
    int getrow();
    int getcol();
    int getdirection();
    virtual void move() =0;
    virtual void update(int) = 0;
    virtual void print() = 0;
};
#endif
