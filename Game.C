#include "Game.h"
#include <cstdlib>
#include <ctime>
#include "Ship.h"
#include "Bullet.h"
#include "Gunboat.h"
#include "Player.h"
#include "Torpedo.h"
#include "Destroyer.h"
Game::Game() {
    gui.init();
    play=1;
    player = new Player(this,15,40,1);
    ships.push_back(player);
    int r,w,d;
    for(int i=0;i<5;i++){
         r=rand()%20;
         w=rand()%60+10;
         d=rand()%4+1;
         Ship* p = new Destroyer(this,r,w,d);
         ships.push_back(p);
    }
    for(int i=0;i<10;i++){
         r=rand()%20;
         w=rand()%60+10;
         d=rand()%4+1;
         Ship* q = new Gunboat(this,r,w,d);
         ships.push_back(q);
    }
}

void Game::update() {
    gui.clear(); //clear everything on the screen
    int c = gui.get();
    if(c=='q') play=0;
    updateShips(c);
    enemyfire();
    updateBullets(c);
    checkCollision();
    sweep();
     // ========== 关键：手动拼接血量字符串 ==========
    char hpStr[32]; // 定义缓冲区存储拼接后的字符串（足够存"HP:9999"）
    // 1. 用snprintf把"HP:"和player->health拼接成完整字符串
    snprintf(hpStr, sizeof(hpStr), "HP:%d", player->health);
    // 2. 把拼接好的字符串传给printMsg（无需修改printMsg）
    gui.printMsg(0, 0, hpStr);
    
    // （可选）同理显示分数
    char scoreStr[32];
    snprintf(scoreStr, sizeof(scoreStr), "Score:%d", player->score);
    gui.printMsg(0, 7, scoreStr);
    
    char bulletStr[32];
    snprintf(bulletStr,sizeof(bulletStr),"Bullet:%d",player->bulletcount);
    gui.printMsg(0,17,bulletStr);
    gui.redraw(); //draw things
}

void Game::updateShips(int c) {
    list<Ship*>::iterator bi = ships.begin();
    while (bi != ships.end() ) {
        (*bi)->update(c);
        bi++;
    }
}
void Game::updateBullets(int c) {
    list<Bullet*>::iterator pi = bullets.begin();
    while (pi != bullets.end()) {
        (*pi)->update(c);
        pi++;
    }
}
void Game::enemyfire(){
    list<Ship*>::iterator bi = ships.begin();
    while (bi != ships.end() ) {
        if((*bi)->shot==1){//向前发射Bullet
            (*bi)->shot=0;
            Bullet* p = new Bullet(this,(*bi)->row,(*bi)->col,(*bi)->direction);
            (*p).move();
            bullets.push_back(p);
        }
        if((*bi)->shot==2){//向右发射Torpedo
            (*bi)->shot=0;
            Bullet* p = new Torpedo(this,(*bi)->row,(*bi)->col,(*bi)->direction+1);
            (*p).move();
            bullets.push_back(p);
        }
        if((*bi)->shot==3){//向左发射Torpedo
            (*bi)->shot=0;
            Bullet* p = new Torpedo(this,(*bi)->row,(*bi)->col,(*bi)->direction-1);
            (*p).move();
            bullets.push_back(p);
        }
        bi++;
    }
}
void Game::paintAt(int r, int c, char x) {
    gui.paintat(r, c, x);
}
void Game::printMsg(int r, int c, const char* s) {
    gui.printMsg(r, c, s);
}
int Game::ifplay(){
    return play;
}
void Game::sweep(){
    list<Ship*>::iterator bi = ships.begin();
    while (bi != ships.end() ) {
         if((*bi)->alive==0){
             Ship* temp = (*bi);
             bi = ships.erase(bi);
             delete temp;
         }
         else bi++;
    }
    list<Bullet*>::iterator pi = bullets.begin();
    while (pi != bullets.end() ) {
         if((*pi)->alive==0){
             Bullet* temp = (*pi);
             pi = bullets.erase(pi);
             delete temp;
         }
         else pi++;
    }
}
void Game::checkCollision(){
    list<Bullet*>::iterator bulletIt = bullets.begin();
    while (bulletIt != bullets.end()) {
        Bullet* bullet = *bulletIt;
        list<Ship*>::iterator shipIt = ships.begin();
        while (shipIt != ships.end()) {
            Ship* ship = *shipIt;
            if (!ship->alive) {
                shipIt++;
                continue;
            }
            // 碰撞条件：子弹与船的坐标（row/col）
            if ((bullet->row >= ship->row-ship->rowrange && bullet->row <= ship->row+ship->rowrange)&&(bullet->col >= ship->col-ship->colrange && bullet->col <= ship->col+ship->colrange)) {
                bullet->alive = 0;
                ship->health-=bullet->damage;
                player->score+=ship->score;
                break;
            }
            
            shipIt++;
        }
        bulletIt++;
    }
}
Game::~Game() {
    list<Ship*>::iterator bi = ships.begin();
    while (bi != ships.end() ) {
         Ship* temp = (*bi);
         bi = ships.erase(bi);
         delete temp;
    }
    list<Bullet*>::iterator pi = bullets.begin();
    while (pi != bullets.end() ) {
         Bullet* temp = (*pi);
         pi = bullets.erase(pi);
         delete temp;
    }
    gui.end();
}
