//
// Created by Harrison groves on 9/3/25.
//
#include "../include/Player.h"
#include "../include/Tile.h"

Player::Player(){
    size = { 160.0f, 80.0f };
    position = { 0, 0 };
    orientation = HORIZONTAL;
    playerTexture = LoadTexture("../textures/fingerTex.png");
}

void Player::draw() {
    DrawRectangleV(position, size, BLUE);
    Rectangle source = { 0.0f, 0.0f, (float)playerTexture.width, (float)playerTexture.height };
    Rectangle dest = { position.x, position.y, size.x, size.y };
    Vector2 origin = { 0, 0 }; // top-left corner
    DrawTexturePro(playerTexture, source, dest, origin, 0.0f, WHITE);
}


void Player::update() {
    if (IsKeyPressed(KEY_A)) rollLeft();
    if (IsKeyPressed(KEY_D)) rollRight();
    if (IsKeyPressed(KEY_W)) rollUp();
    if (IsKeyPressed(KEY_S)) rollDown();

    // clamp to window bounds
    if (position.x < 0) position.x = 0;
    if (position.y < 0) position.y = 0;
    if (position.x + size.x > 1024) position.x = 1024 - size.x;
    if (position.y + size.y > 768) position.y = 768 - size.y;
}

void Player::rollLeft() {
    if (orientation == UPRIGHT) {
        position.x -= size.x;
        orientation = HORIZONTAL;
        size = { 2*80.0f, 80.0f };
    } else if (orientation == HORIZONTAL) {
        position.x -= 80.0f;       // move one tile left
        orientation = UPRIGHT;
        size = { 80.0f, 80.0f };
    } else if (orientation == VERTICAL) {
        position.x -= 80.0f;       // slide while vertical
    }
}

void Player::rollRight() {
    if (orientation == UPRIGHT) {
        position.x += size.x;
        orientation = HORIZONTAL;
        size = { 2*80.0f, 80.0f };
    } else if (orientation == HORIZONTAL) {
        position.x += 160.0f;       // advance one tile
        orientation = UPRIGHT;
        size = { 80.0f, 80.0f };
    } else if (orientation == VERTICAL) {
        position.x += 80.0f;
    }
}

void Player::rollUp() {
    if (orientation == UPRIGHT) {
        position.y -= size.y * 2;
        orientation = VERTICAL;
        size = { 80.0f, 2*80.0f };
    } else if (orientation == VERTICAL) {
        position.y -= 80.0f;       // advance one tile
        orientation = UPRIGHT;
        size = { 80.0f, 80.0f };
    } else if (orientation == HORIZONTAL) {
        position.y -= 80.0f;
    }
}

void Player::rollDown() {
    if (orientation == UPRIGHT) {
        position.y += size.y;
        orientation = VERTICAL;
        size = { 80.0f, 2*80.0f };
    } else if (orientation == VERTICAL) {
        position.y += 160.0f;       // advance one tile
        orientation = UPRIGHT;
        size = { 80.0f, 80.0f };
    } else if (orientation == HORIZONTAL) {
        position.y += 80.0f;
    }
}