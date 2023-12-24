/**
 * @file Enemy.h
 * @brief Définition de la classe Enemy représentant un ennemi.
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "Collision.h"
#include "Bullet.h"
#include "Player.h"
#include <stdlib.h>

/**
 * @class Enemy
 * @brief Classe représentant un ennemi.
 */
class Enemy {
public:
    /**
     * @brief Construit un nouvel ennemi.
     * @param x La coordonnée x de l'ennemi.
     * @param y La coordonnée y de l'ennemi.
     * @param interval L'intervalle de temps entre chaque tir de l'ennemi.
     * @param speed La vitesse de déplacement de l'ennemi.
     */
    Enemy(int x, int y, int interval, int speed);
    /**
     * @brief Construit un nouvel ennemi.
     */
    Enemy();

    /**
     * @brief Énumération des états possibles de l'ennemi.
     */
    enum class EnemyState {
        Active,     /**< L'ennemi est actif */
        Inactive    /**< L'ennemi est inactif */
    };

    /**
     * @brief Récupère la coordonnée x de l'ennemi.
     * @return La coordonnée x de l'ennemi.
     */
    int getX() const;

    /**
     * @brief Récupère la coordonnée y de l'ennemi.
     * @return La coordonnée y de l'ennemi.
     */
    int getY() const;

    /**
     * @brief Modifie la coordonnée x de l'ennemi.
     * @param x La nouvelle coordonnée x.
     */
    void setX(int x);

    /**
     * @brief Modifie la coordonnée y de l'ennemi.
     * @param y La nouvelle coordonnée y.
     */
    void setY(int y);

    /**
     * @brief Récupère l'état de l'ennemi.
     * @return L'état de l'ennemi.
     */
    EnemyState getState() const;

    /**
     * @brief Modifie l'état de l'ennemi.
     * @param newState Le nouvel état.
     */
    void setState(EnemyState newState);

    /**
     * @brief Récupère l'intervalle de temps entre chaque tir de l'ennemi.
     * @return L'intervalle de temps.
     */
    int getInterval() const;

    /**
     * @brief Récupère la vitesse de déplacement de l'ennemi.
     * @return La vitesse de déplacement de l'ennemi.
     */
    int getSpeed() const;

    /**
     * @brief Modifie la vitesse de déplacement de l'ennemi.
     * @param setSpeed La nouvelle vitesse.
     */
    void setSpeed(int setSpeed);

    /**
     * @brief Met à jour l'ennemi.
     */
    void update();

    /**
     * @brief Réinitialise l'ennemi.
     */
    void reset();

    /**
     * @brief Récupère le rectangle de collision de l'ennemi.
     * @return Le rectangle de collision de l'ennemi.
     */
    Rect::My_Rect getCollisionRect() const;

private:
    int x;                      /**< La coordonnée x de l'ennemi. */
    int y;                      /**< La coordonnée y de l'ennemi. */
    int interval;               /**< L'intervalle de temps entre chaque tir de l'ennemi. */
    int speed;                  /**< La vitesse de déplacement de l'ennemi. */
    int enemyWidth;             /**< La largeur de l'ennemi. */
    int enemyHeight;            /**< La hauteur de l'ennemi. */
    EnemyState state;           /**< L'état de l'ennemi. */
};

#endif // ENEMY_H