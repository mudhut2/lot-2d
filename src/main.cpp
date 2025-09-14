#include <iostream>
#include <raylib.h>
#include "../include/Player.h"
#include "../include/Tile.h"
#include "../include/Level.h"

int main(){
    const int screenWidth = 1024;
    const int screenHeight = 768;

    Player player;
    Level level(20, 15);
    InitWindow(screenWidth, screenHeight, "Raylib Project");
    SetTargetFPS(60);


    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello Raylib!", 200, 200, 20, LIGHTGRAY);
            player.update();
            player.draw();
            level.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
