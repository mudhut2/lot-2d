#ifndef GAME1_LEVEL_H
#define GAME1_LEVEL_H
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "../include/Tile.h"

class Level {
public:
    int width = 0;
    int height = 0;
    std::vector<std::vector<Tile>> tiles;
    std::vector<Texture2D> tileTextures; // indexed by TileType

    Level() {}

    // load textures for each TileType
    void loadTextures() {
        // order must match TileType enum
        tileTextures.push_back(LoadTexture("../textures/f2.png"));          // 0
        tileTextures.push_back(LoadTexture("../textures/mossy_stone.png")); // 1
        tileTextures.push_back(LoadTexture("../textures/w_grey.jpg"));      // 2
        tileTextures.push_back(LoadTexture("../textures/w_green.jpg"));     // 3
        tileTextures.push_back(LoadTexture("../textures/f4.jpg"));          // 4
        tileTextures.push_back(LoadTexture("../textures/start_sound.jpg")); // 5
        tileTextures.push_back(LoadTexture("../textures/a-tile.jpg"));      // 6
        tileTextures.push_back(LoadTexture("../textures/b-tile.jpg"));      // 7
        tileTextures.push_back(LoadTexture("../textures/c-tile.jpg"));      // 8
        tileTextures.push_back(LoadTexture("../textures/d-tile.jpg"));      // 9
        tileTextures.push_back(LoadTexture("../textures/e-tile.jpg"));      // 10
        tileTextures.push_back(LoadTexture("../textures/f-tile.jpg"));      // 11
        tileTextures.push_back(LoadTexture("../textures/g-tile.jpg"));      // 12

        for (int i = 0; i < tileTextures.size(); i++) {
            if (tileTextures[i].id == 0)
                std::cout << "Failed to load texture for TileType " << i << std::endl;
        }
    }

    void unloadTextures() {
        for (auto& tex : tileTextures) {
            UnloadTexture(tex);
        }
        tileTextures.clear();
    }

    // load CSV and resize level automatically
    void loadFromCSV(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Failed to open CSV: " << filename << std::endl;
            return;
        }
        tiles.clear();
        std::string line;
        int y = 0;

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string cell;
            std::vector<Tile> rowTiles;
            int x = 0;

            while (std::getline(ss, cell, ',')) {
                int tileId = std::stoi(cell);
                rowTiles.push_back(Tile((TileType)tileId, {(float)x * tileSize, (float)y * tileSize}));
                x++;
            }
            tiles.push_back(rowTiles);
            y++;
        }
        height = tiles.size();
        width = tiles.empty() ? 0 : tiles[0].size();
        std::cout << "Loaded CSV: " << width << "x" << height << " tiles" << std::endl;
    }

    void draw() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                Tile& t = tiles[y][x];
                if (t.type >= 0 && t.type < (int)tileTextures.size()) {
                    t.draw(tileTextures[t.type]);
                }
            }
        }
    }

    Tile& getTileAt(int x, int y) {
        return tiles[y][x];
    }

    void setTileType(int x, int y, TileType type) {
        if (x < 0 || x >= width || y < 0 || y >= height) return;
        tiles[y][x].type = type;
    }
};

#endif //GAME1_LEVEL_H
