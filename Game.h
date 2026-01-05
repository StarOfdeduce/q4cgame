#ifndef _GAME_H_
#define _GAME_H_
#include <list>
#include "Gui.h"
#include "Item.h"
using namespace std;
class Ship;
class Bullet;
class Player;
class Game {
    Gui gui;
    int play;
    list <Ship*> ships;
    list <Bullet*> bullets;
    Ship* player;
public:
    Game() ;
    ~Game();
    void paintAt(int r, int c, char x);
    void printMsg(int r, int c, const char* s);
    void update();
    void updateShips(int c);
    void updateBullets(int c);
    void enemyfire();
    void sweep();
    void checkCollision();
    int ifplay();
};
#endif
