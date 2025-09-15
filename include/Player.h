//
// Created by Harrison groves on 9/3/25.
//

#ifndef GAME1_PLAYER_H
#define GAME1_PLAYER_H
#include <raylib.h>

class Player {
public:
    Player();
    Vector2 size;
    Vector2 position;
    void update();
    void draw();
    bool isUpright;
private:
};


#endif //GAME1_PLAYER_H
