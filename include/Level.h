//
// Created by Harrison groves on 9/3/25.
//

#ifndef GAME1_LEVEL_H
#define GAME1_LEVEL_H
#include <vector>
#include "../include/Tile.h"

class Level{
public:
    int width, height;
    std::vector<std::vector<Tile>> tiles;

    Level(int w, int h) :
        width(w), height(h){
        tiles.resize(height, std::vector<Tile>(width,Tile(EMPTY, {0,0})));
        for(int y = 0; y < height; y++) {
            for(int x = 0; x < width; x++){
                tiles[y][x] = Tile(EMPTY, {(float)x * tileSize,(float)y * tileSize});
            }
        }
    }
    void draw(){
        for(int y = 0; y < height; y++){
            for(int x = 0 ; x < width; x++){
                tiles[y][x].draw();
            }
        }
    }
    Tile& getTileAt(int x, int y){
        return tiles[y][x];
    }
    void setTileType(int x, int y, TileType type){
        if(x < 0 || x >= width || y < 0 || y >= height) return;
        tiles[y][x].type = type;

    }
private:

};
#endif //GAME1_LEVEL_H
