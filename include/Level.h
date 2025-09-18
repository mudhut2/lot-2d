#ifndef GAME1_LEVEL_H
#define GAME1_LEVEL_H
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include "../include/Tile.h"

class Level {
public:
    int width = 0;
    int height = 0;
    std::vector<std::vector<Tile>> tiles;
    std::map<int, Texture2D> textures;

    Level() {}

    void loadTextures() {
        for (auto& [id, def] : tileRegistry) {
            Texture2D tex = LoadTexture(def.texturePath.c_str());
            if (tex.id == 0) {
                std::cout << "Failed to load texture for " << def.name << std::endl;
            }
            textures[id] = tex;
        }
    }

    void unloadTextures() {
        for (auto& [id, tex] : textures) {
            UnloadTexture(tex);
        }
        textures.clear();
    }

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

                auto def = tileRegistry[tileId];
                rowTiles.push_back(Tile(
                    tileId,
                    def.type,
                    {(float)x * tileSize, (float)y * tileSize},
                    def.name,
                    def.walkable,
                    def.soundFile
                ));
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
                int id = (int)t.type; // use type as key into registry
                if (textures.count(t.id)) {
                    t.draw(textures[t.id]);
                }
            }
        }
    }

    Tile& getTileAt(int x, int y) {
        return tiles[y][x];
    }

    void setTile(int x, int y, int registryId) {
        if (x < 0 || x >= width || y < 0 || y >= height) return;
        auto def = tileRegistry[registryId];
        tiles[y][x] = Tile(
            registryId,                        // store the correct CSV/registry ID
            def.type,
            {(float)x * tileSize, (float)y * tileSize},
            def.name,
            def.walkable,
            def.soundFile
        );
    }

};

#endif //GAME1_LEVEL_H
