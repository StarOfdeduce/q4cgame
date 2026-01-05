#include "Item.h"

Item::Item() : row (0), col (0), last(0) {}
Item::Item(Game* g, int r, int c) 
    : game(g), row (r), col (c), last(0) {}
int Item::getcol(){
    return col;
}
int Item::getrow(){
    return row;
}
int Item::getdirection(){
    return direction;
}
