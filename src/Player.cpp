//
// Created by Harrison groves on 9/3/25.
//
#include "../include/Player.h"
#include "../include/Tile.h"

Player::Player(){
    size = { 160.0f, 80.0f };
    position = { 0, 0 };
    isUpright = true;
}

void Player::draw() {
    DrawRectangleV(position, size, GREEN);
}

void Player::update() {
    if (IsKeyPressed(KEY_A)) position.x -= tileSize;
    if (IsKeyPressed(KEY_D)) position.x += tileSize;
    if (IsKeyPressed(KEY_W)) position.y -= tileSize;
    if (IsKeyPressed(KEY_S)) position.y += tileSize;
}
