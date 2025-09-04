#include <iostream>
#include <raylib.h>
#include "../include/Player.h"
#include "../include/Tile.h"

int main(){
    const int screenWidth = 1024;
    const int screenHeight = 768;

    Player player;
    Tile testTile(EMPTY, {300, 300}, 32);

    InitWindow(screenWidth, screenHeight, "Raylib Project");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello Raylib!", 200, 200, 20, LIGHTGRAY);
            player.update();
            player.draw();
            testTile.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
