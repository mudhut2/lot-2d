//
// Created by Harrison groves on 9/3/25.
//

#ifndef GAME1_PLAYER_H
#define GAME1_PLAYER_H
#include <raylib.h>

enum Orientation
{
    UPRIGHT,
    HORIZONTAL,
    VERTICAL
};
class Player {
public:
    Player();
    Vector2 size;
    Vector2 position;
    void update();
    void draw();
    Orientation orientation;
    Texture2D playerTexture;
private:
    void rollLeft();
    void rollRight();
    void rollUp();
    void rollDown();
};


#endif //GAME1_PLAYER_H
