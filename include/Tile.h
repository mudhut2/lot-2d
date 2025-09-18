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

inline std::map<int, TileDef> tileRegistry = {
    {0, {FLOOR, "floor", "../assets/textures/f2.png", true, ""}},
    {1, {WALL, "mossy_stone", "../assets/textures/mossy_stone.png", false, ""}},
    {2, {WALL, "grey_wall", "../assets/textures/w_grey.jpg", false, ""}},
    {3, {WALL, "green_wall", "../assets/textures/w_green.jpg", false, ""}},
    {4, {START, "note", "../assets/textures/start_sound.jpg", true, ""}},
    {5, {FLOOR, "floor", "../assets/textures/f4.jpg", true, ""}},
    {6, {NOTE, "c_note", "../assets/textures/c-tile.jpg", true, ""}},
{   7, {NOTE, "d_note", "../assets/textures/d-tile.jpg", true, ""}},
    {8, {NOTE, "e_note", "../assets/textures/e-tile.jpg", true, ""}},
    {9, {NOTE, "f_note", "../assets/textures/f-tile.jpg", true, ""}},
    {10, {NOTE, "g_note", "../assets/textures/g-tile.jpg", true, ""}},
    {11, {NOTE, "a_note", "../assets/textures/a-tile.jpg", true, ""}},
    {13, {NOTE, "b_note", "../assets/textures/b-tile.jpg", true, ""}},
};

class Tile {
public:
    int id; // each tile knows its id so it can fetch attributes
    TileType type;
    Vector2 position;
    std::string name;
    bool walkable;
    std::string soundFile;

    Tile(int id, TileType t = FLOOR, Vector2 pos = {0,0},
         std::string n = "", bool w = true, std::string s = "")
        : id(id), type(t), position(pos), name(n), walkable(w), soundFile(s) {}

    void draw(Texture2D& texture) {
        Rectangle src = {0, 0, (float)texture.width, (float)texture.height};
        Rectangle dest = {position.x, position.y, (float)tileSize, (float)tileSize};
        DrawTexturePro(texture, src, dest, {0,0}, 0.0f, WHITE);
    }

    bool isWalkable() { return walkable; }
};

#endif //GAME1_TILE_H
