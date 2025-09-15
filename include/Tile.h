#ifndef GAME1_TILE_H
#define GAME1_TILE_H
#include <raylib.h>

enum TileType { EMPTY = 0, WALL = 1, WATER = 2 };
static int tileSize = 80;

class Tile {
public:
    TileType type;
    Vector2 position;

    Tile(TileType t = EMPTY, Vector2 pos = {0,0})
        : type(t), position(pos) {}

    void draw(Texture2D& texture) {
        // scale texture to tileSize
        Rectangle src = {0, 0, (float)texture.width, (float)texture.height};
        Rectangle dest = {position.x, position.y, (float)tileSize, (float)tileSize};
        DrawTexturePro(texture, src, dest, {0,0}, 0.0f, WHITE);
    }

    bool isWalkable() {
        return type == EMPTY || type == WATER;
    }
};

#endif //GAME1_TILE_H
