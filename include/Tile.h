//
// Created by Harrison groves on 9/3/25.
//

#ifndef GAME1_TILE_H
#define GAME1_TILE_H
#include <raylib.h>

enum TileType { EMPTY, WALL, WATER };

class Tile {
public:
    TileType type;
    Vector2 position;
    int size;

    Tile(TileType t, Vector2 pos, int s) : type(t), position(pos), size(s) {}

    void draw(){
        Color color = GRAY;
        switch(type) {
            case EMPTY: color = LIGHTGRAY; break;
            case WALL:  color = DARKGRAY; break;
            case WATER: color = BLUE; break;
        }
        DrawRectangle(position.x, position.y, size,size, color);
    }

    bool isWalkable(){
        return type == EMPTY || type == WATER;
    }
};
#endif //GAME1_TILE_H
