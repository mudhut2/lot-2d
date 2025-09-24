// Created by Harrison Groves on 9/3/25.
//
#include "../include/Player.h"
#include "../include/Tile.h"
#include "../include/main.h"

const int TILE = 86;
const int DOUBLE_TILE = 172;

Player::Player() {
    size = { DOUBLE_TILE, TILE };
    position = { 0, 0 };
    orientation = HORIZONTAL;
    playerTexture = LoadTexture("../assets/textures/fingerTex.png");
    level = nullptr;
}

void Player::draw() {
    DrawRectangleV(position, size, BLUE);
    Rectangle source = { 0.0f, 0.0f, (float)playerTexture.width, (float)playerTexture.height };
    Rectangle dest   = { position.x, position.y, size.x, size.y };
    Vector2 origin   = { 0, 0 };
    DrawTexturePro(playerTexture, source, dest, origin, 0.0f, WHITE);
}

void Player::update() {
    Vector2 oldPos = position;
    if (IsKeyPressed(KEY_A)) rollLeft();
    if (IsKeyPressed(KEY_D)) rollRight();
    if (IsKeyPressed(KEY_W)) rollUp();
    if (IsKeyPressed(KEY_S)) rollDown();

    if (position.x != oldPos.x || position.y != oldPos.y) {
        if (isOnNote()) {
            std::cout << "Player rolled onto a NOTE tile!" << std::endl;
        }
    }
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
        newY >= 0 && newY + newSize.y <= SCREEN_HEIGHT &&
        !wouldCollide(newX, newY, newSize))
    {
        position = { newX, newY };
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
        newY >= 0 && newY + newSize.y <= SCREEN_HEIGHT &&
        !wouldCollide(newX, newY, newSize))
    {
        position = { newX, newY };
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
        newY >= 0 && newY + newSize.y <= SCREEN_HEIGHT &&
        !wouldCollide(newX, newY, newSize))
    {
        position = { newX, newY };
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
        newY >= 0 && newY + newSize.y <= SCREEN_HEIGHT &&
        !wouldCollide(newX, newY, newSize))
    {
        position = { newX, newY };
        size = newSize;
        orientation = newOrientation;
    }
}

bool Player::wouldCollide(float newX, float newY, Vector2 newSize) {
    if (!level) return false;

    int startX = newX / tileSize;
    int startY = newY / tileSize;
    int endX = (newX + newSize.x - 1) / tileSize;
    int endY = (newY + newSize.y - 1) / tileSize;

    for (int y = startY; y <= endY; ++y) {
        for (int x = startX; x <= endX; ++x) {
            if (x < 0 || x >= level->width || y < 0 || y >= level->height) continue;
            if (!level->getTileAt(x, y).isWalkable()) return true;
        }
    }
    return false;
}

bool Player::isOnNote() {
    if (!level) return false;

    int startX = position.x / tileSize;
    int startY = position.y / tileSize;
    int endX   = (position.x + size.x - 1) / tileSize;
    int endY   = (position.y + size.y - 1) / tileSize;

    for (int y = startY; y <= endY; ++y) {
        for (int x = startX; x <= endX; ++x) {
            if (x < 0 || x >= level->width || y < 0 || y >= level->height) continue;
            Tile& t = level->getTileAt(x, y);
            if (t.type == NOTE) {
                std::cout << "Player is on NOTE tile at ("
                          << x << ", " << y << ") name=" << t.name << std::endl;
                return true;
            }
        }
    }
    return false;
}


