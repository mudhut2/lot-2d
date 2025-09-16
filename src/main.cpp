#include <raylib.h>
#include "../include/main.h"
#include "../include/Level.h"
#include "../include/Player.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tilemap Game");
    SetTargetFPS(64);

    Level level;
    Player player;
    level.loadTextures();
    level.loadFromCSV("../levels/level.csv");

    while (!WindowShouldClose()) {
        player.update();
        BeginDrawing();
        ClearBackground(GRAY);

        level.draw();
        player.draw();

        EndDrawing();
    }
    level.unloadTextures();
    CloseWindow();
    return 0;
}
