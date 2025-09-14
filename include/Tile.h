//
// Created by Harrison groves on 9/3/25.
//

#ifndef GAME1_TILE_H
#define GAME1_TILE_H
#include <raylib.h>

enum TileType { EMPTY, WALL, WATER };
static int tileSize = 15;

class Tile {
public:
    TileType type;
    Vector2 position;

    Tile(TileType t, Vector2 pos) : type(t), position(pos){}

    void draw(){
        Color color = GRAY;
        switch(type) {
            case EMPTY: color = LIGHTGRAY; break;
            case WALL:  color = DARKGRAY; break;
            case WATER: color = BLUE; break;
        }
        DrawRectangle(position.x, position.y, tileSize, tileSize, color);
    }

    bool isWalkable(){
        return type == EMPTY || type == WATER;
    }
private:

};
#endif //GAME1_TILE_H
