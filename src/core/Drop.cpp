/**
 * @file Drop.cpp
 * @brief Fichier de code source pour la classe Drop
 */
#include "Drop.h"

Drop::Drop(int x, int y, int speed, DropType type)
: x(x), y(y), speed(speed), active(true), width_(20), height_(20), type(type)
{}


int Drop::getX() const {
    return x;
}

int Drop::getY() const {
    return y;
}

void Drop::setX(int setx) {
    x = setx;
}

void Drop::setY(int sety) {
    y = sety;
}

Drop::DropType Drop::getType() const {
    return type;
}

bool Drop::isActive() const {
    return active;
}

void Drop::setActive(bool active) {
    this->active = active;
}

void Drop::update() {
    // 更新补给位置
    y += speed;

    // 如果补给下落到窗口边界外，将其设置为非活动状态
    if (y > 768) {
        active = false;
    }
}

Rect::My_Rect Drop::getCollisionRect() const {
    Rect::My_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width_;
    rect.h = height_;
    return rect;
}
