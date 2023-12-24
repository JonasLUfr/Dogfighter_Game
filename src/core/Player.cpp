/**
 * @file Player.cpp
 * @brief Fichier de code source pour la classe Player
 */
#include "Player.h"

Player::Player(int windowWidth, int windowHeight)
    : speed(8), windowWidth(windowWidth), windowHeight(windowHeight),
       playerWidth(30), playerHeight(30) {
    x = windowWidth / 2;
    y = windowHeight - 50; // 假设玩家对象的高度约为 50
}

int Player::getSpeed() const {
    return speed;
}

void Player::setSpeed(int newSpeed) {
    speed = newSpeed;
}

void Player::moveLeft() {
    x -= speed;
    if (x < 0) {
        x = 0;
    }
}


void Player::moveRight() {
    x += speed;
    if (x > windowWidth - 50) { // 假设玩家对象的宽度约为 50
        x = windowWidth - 50;
    }
}

void Player::moveUp() {
    y -= speed;
    if (y < 0) {
        y = 0;
    }
}


void Player::moveDown() {
    y += speed;
    if (y > windowHeight - 50) { // 假设玩家对象的高度约为 30
        y = windowHeight - 50;
    }
}

int Player::getX() const {
    return x;
}

int Player::getY() const {
    return y;
}

void Player::setX(int x) {
    this->x = x;
    if (this->x < 0) {
        this->x = 0;
    } else if (this->x > windowWidth - 50) {
        this->x = windowWidth - 50;
    }
}

void Player::setY(int y) {
    this->y = y;
    if (this->y < 0) {
        this->y = 0;
    } else if (this->y > windowHeight - 50) {
        this->y = windowHeight - 50;
    }
}
/*
int Player::getHealth() const {
    return health;
}

void Player::setHealth(int newHealth) {
    health = newHealth;
} 
*/


void Player::reset(){
    x = windowWidth / 2;
    y = windowHeight - 50; 
};




Rect::My_Rect Player::getCollisionRect() const {
    Rect::My_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = playerWidth;
    rect.h = playerHeight;
    return rect;
}
