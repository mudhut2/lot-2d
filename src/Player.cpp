//
// Created by Harrison groves on 9/3/25.
//
#include "../include/Player.h"
#include "../include/Tile.h"
#include "../include/main.h"

const int TILE = 86;
const int DOUBLE_TILE  = 172;

Player::Player() {
    size = { DOUBLE_TILE, TILE };  // start horizontal
    position = { 0, 0 };
    orientation = HORIZONTAL;
    playerTexture = LoadTexture("../textures/fingerTex.png");
}

void Player::draw() {
    // Draw background rectangle under the texture
    DrawRectangleV(position, size, BLUE);
    // Draw the texture on top
    Rectangle source = { 0.0f, 0.0f, (float)playerTexture.width, (float)playerTexture.height };
    Rectangle dest   = { position.x, position.y, size.x, size.y };
    Vector2 origin   = { 0, 0 };
    DrawTexturePro(playerTexture, source, dest, origin, 0.0f, WHITE);
}

void Player::update() {
    if (IsKeyPressed(KEY_A)) rollLeft();
    if (IsKeyPressed(KEY_D)) rollRight();
    if (IsKeyPressed(KEY_W)) rollUp();
    if (IsKeyPressed(KEY_S)) rollDown();
}

void Player::rollLeft() {
    float newX = position.x;
    float newY = position.y;
    Vector2 newSize = size;
    Orientation newOrientation = orientation;

    if (orientation == UPRIGHT) {
        newX -= size.x * 2;
        newOrientation = HORIZONTAL;
        newSize = { DOUBLE_TILE, TILE };
    } else if (orientation == HORIZONTAL) {
        newX -= TILE;
        newOrientation = UPRIGHT;
        newSize = { TILE, TILE };
    } else if (orientation == VERTICAL) {
        newX -= TILE;
    }

    if (newX >= 0 && newX + newSize.x <= SCREEN_WIDTH &&
        newY >= 0 && newY + newSize.y <= SCREEN_HEIGHT) {
        position.x = newX;
        position.y = newY;
        size = newSize;
        orientation = newOrientation;
    }
}

void Player::rollRight() {
    float newX = position.x;
    float newY = position.y;
    Vector2 newSize = size;
    Orientation newOrientation = orientation;

    if (orientation == UPRIGHT) {
        newX += size.x;
        newOrientation = HORIZONTAL;
        newSize = { DOUBLE_TILE, TILE };
    } else if (orientation == HORIZONTAL) {
        newX += DOUBLE_TILE;
        newOrientation = UPRIGHT;
        newSize = { TILE, TILE };
    } else if (orientation == VERTICAL) {
        newX += TILE;
    }

    if (newX >= 0 && newX + newSize.x <= SCREEN_WIDTH &&
        newY >= 0 && newY + newSize.y <= SCREEN_HEIGHT) {
        position.x = newX;
        position.y = newY;
        size = newSize;
        orientation = newOrientation;
    }
}

void Player::rollUp() {
    float newX = position.x;
    float newY = position.y;
    Vector2 newSize = size;
    Orientation newOrientation = orientation;

    if (orientation == UPRIGHT) {
        newY -= size.y * 2;
        newOrientation = VERTICAL;
        newSize = { TILE, DOUBLE_TILE };
    } else if (orientation == VERTICAL) {
        newY -= TILE;
        newOrientation = UPRIGHT;
        newSize = { TILE, TILE };
    } else if (orientation == HORIZONTAL) {
        newY -= TILE;
    }

    if (newX >= 0 && newX + newSize.x <= SCREEN_WIDTH &&
        newY >= 0 && newY + newSize.y <= SCREEN_HEIGHT) {
        position.x = newX;
        position.y = newY;
        size = newSize;
        orientation = newOrientation;
    }
}

void Player::rollDown() {
    float newX = position.x;
    float newY = position.y;
    Vector2 newSize = size;
    Orientation newOrientation = orientation;

    if (orientation == UPRIGHT) {
        newY += size.y;
        newOrientation = VERTICAL;
        newSize = { TILE, DOUBLE_TILE };
    } else if (orientation == VERTICAL) {
        newY += DOUBLE_TILE;
        newOrientation = UPRIGHT;
        newSize = { TILE, TILE };
    } else if (orientation == HORIZONTAL) {
        newY += TILE;
    }

    if (newX >= 0 && newX + newSize.x <= SCREEN_WIDTH &&
        newY >= 0 && newY + newSize.y <= SCREEN_HEIGHT) {
        position.x = newX;
        position.y = newY;
        size = newSize;
        orientation = newOrientation;
    }
}
