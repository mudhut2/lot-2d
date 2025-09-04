//
// Created by Harrison groves on 9/3/25.
//
#include "../include/Player.h"

Player::Player(){
    size = { 60.0f, 40.0f };
    position = { 400, 300 };
    velocity = 1.1f;
}

void Player::draw() {
    DrawRectangleV(position, size, GREEN);
}

void Player::update() {
    if (IsKeyDown(KEY_A))  position.x -= velocity;
    if (IsKeyDown(KEY_D))  position.x += velocity;
    if (IsKeyDown(KEY_W))  position.y -= velocity;
    if (IsKeyDown(KEY_S))  position.y += velocity;
}
