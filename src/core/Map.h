/**
 * @file Map.h
 * @brief Définition de la classe Map.
 */

#ifndef MAP_H
#define MAP_H

#include "Bomb.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include <string>

/**
 * @class Map
 * @brief Classe représentant la carte du jeu.
 */
class Map {
public:
    /**
     * @brief Constructeur d'un nouvel objet Map.
     */
    Map();

    /**
     * @brief Mettre à jour la position de la carte.
     * @param scroll_speed La vitesse de défilement.
     */
    void mapPosition(int scroll_speed);

    /**
     * @brief Obtenir la largeur de la carte.
     * @return La largeur de la carte.
     */
    int getWidth() const;

    /**
     * @brief Obtenir la hauteur de la carte.
     * @return La hauteur de la carte.
     */
    int getHeight() const;

    /**
     * @brief Obtenir la position de la carte1.
     * @return La position de la carte1.
     */
    int getMap1PosY() const;

    /**
     * @brief Obtenir la position de la carte2.
     * @return La position de la carte2.
     */
    int getMap2PosY() const;

private:
    int width_;                 /**< La largeur de la carte. */
    int height_;                /**< La hauteur de la carte. */
    int map1_posY;              /**< La position de la carte1. */
    int map2_posY;              /**< La position de la carte2. */
};

#endif // MAP_H
