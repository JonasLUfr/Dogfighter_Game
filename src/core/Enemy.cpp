/**
 * @file Enemy.cpp
 * @brief Fichier de code source pour la classe Enemy
 */
#include "Enemy.h"

Enemy::Enemy(int x, int y, int interval, int speed)
    : x(x), y(y), interval(interval), speed(speed),
      enemyWidth(20), enemyHeight(20), state(EnemyState::Active)
{}

Enemy::Enemy()
    : x(0), y(0), interval(0), speed(0), state(EnemyState::Active) {
}


int Enemy::getX() const {
    return x;
}

int Enemy::getY() const {
    return y;
}

void Enemy::setX(int setx) {
    x = setx;
}

void Enemy::setY(int sety) {
    y = sety;
}

Enemy::EnemyState Enemy::getState() const {
    return state;
}

void Enemy::setState(EnemyState newState) {
    state = newState;
}


int Enemy::getInterval() const {
    return interval;
}

int Enemy::getSpeed() const {
    return speed;
}

void Enemy::setSpeed(int setSpeed){
    speed = setSpeed;
}

// 修改Enemy类的update()函数
void Enemy::update() {
    if (state == EnemyState::Inactive) {
        // 如果敌机处于非活动状态，根据一定条件激活敌机
        state = EnemyState::Active;

        // 生成随机高度，范围为100到200像素
        int randomHeight = 100 + rand() % 101;
        y = -randomHeight;
    } else {
        // 更新敌机位置
        y += speed;

        // 如果敌机下落到地图边界外，将状态设置为"Inactive"
        if (y > 768) {
            state = EnemyState::Inactive;
        }
    }
}

void Enemy::reset(){
    state=EnemyState::Inactive;
}

Rect::My_Rect Enemy::getCollisionRect() const {
    Rect::My_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = enemyWidth;
    rect.h = enemyHeight;
    return rect;
}

