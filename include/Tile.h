#ifndef GAME1_TILE_H
#define GAME1_TILE_H
#include <raylib.h>
#include <string>
#include <map>

enum TileType {
    FLOOR = 0,
    WALL = 1,
    START = 2,
    NOTE = 3
};

const int tileSize = 86;

struct TileDef {
    TileType type;
    std::string name;
    std::string texturePath;
    bool walkable;
    std::string soundFile;
};

static std::map<int, TileDef> tileRegistry = {
    {0, {FLOOR, "floor", "../textures/f2.png", true, ""}},
    {1, {WALL, "mossy_stone", "../textures/mossy_stone.png", false, "../sounds/stone_bump.wav"}},
    {2, {WALL, "grey_wall", "../textures/w_grey.jpg", false, "../sounds/stone_bump.wav"}},
    {3, {WALL, "green_wall", "../textures/w_green.jpg", false, "../sounds/stone_bump.wav"}},
    {4, {NOTE, "note", "../textures/start_sound.jpg", true, "../sounds/paper.wav"}},
    {5, {START, "start", "../textures/f4.jpg", true, ""}}

};

class Tile {
public:
    TileType type;
    Vector2 position;
    std::string name;
    bool walkable;
    std::string soundFile;

    Tile(TileType t = FLOOR, Vector2 pos = {0,0},
         std::string n = "", bool w = true, std::string s = "")
        : type(t), position(pos), name(n), walkable(w), soundFile(s) {}

    void draw(Texture2D& texture) {
        Rectangle src = {0, 0, (float)texture.width, (float)texture.height};
        Rectangle dest = {position.x, position.y, (float)tileSize, (float)tileSize};
        DrawTexturePro(texture, src, dest, {0,0}, 0.0f, WHITE);
    }

    bool isWalkable() { return walkable; }
};

#endif //GAME1_TILE_H
