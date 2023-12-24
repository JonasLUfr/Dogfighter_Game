/**
 * @file Bomb.h
 * @brief Définition de la classe Bomb représentant un objet bombe.
 */

#ifndef BOMB_H
#define BOMB_H

#include "Collision.h"
#include <cstdint>

/**
 * @class Bomb
 * @brief Classe représentant un objet bombe.
 */
class Bomb {
public:
    /**
     * @brief Construit un nouvel objet Bombe.
     * @param x La coordonnée x de la bombe.
     * @param y La coordonnée y de la bombe.
     */
    Bomb(int x, int y);

    /**
     * @brief Détruit l'objet Bombe.
     */
    ~Bomb();

    /**
     * @brief Énumération des états possibles de la bombe.
     */
    enum class BombState {
        Active,     /**< La bombe est active */
        Inactive    /**< La bombe est inactive */
    };

    /**
     * @brief Récupère l'état de la bombe.
     * @return L'état de la bombe.
     */
    BombState getState() const;

    /**
     * @brief Modifie l'état de la bombe.
     * @param newState Le nouvel état.
     */
    void setState(BombState newState);

    /**
     * @brief Récupère la coordonnée x de la bombe.
     * @return La coordonnée x de la bombe.
     */
    int getX() const;

    /**
     * @brief Récupère la coordonnée y de la bombe.
     * @return La coordonnée y de la bombe.
     */
    int getY() const;

    /**
     * @brief Modifie la coordonnée x de la bombe.
     * @param x La nouvelle coordonnée x.
     */
    void setX(int x);

    /**
     * @brief Modifie la coordonnée y de la bombe.
     * @param y La nouvelle coordonnée y.
     */
    void setY(int y);

    /**
     * @brief Réinitialise l'objet bombe.
     */
    void reset();

    /**
     * @brief Met à jour l'objet bombe.
     * @param currentTime Le temps actuel.
     */
    void update(uint32_t currentTime);

    /**
     * @brief Récupère le numéro de l'image actuelle.
     * @return Le numéro de l'image actuelle.
     */
    int getCurrentFrame() const;

private:
    int x;                      /**< La coordonnée x de la bombe. */
    int y;                      /**< La coordonnée y de la bombe. */
    int currentFrame;           /**< Le numéro de l'image actuelle. */
    int maxFrames;              /**< Le nombre maximum d'images. */
    BombState state;            /**< L'état de la bombe. */
    uint32_t lastFrameTime;       /**< Le temps de la dernière image. */
    const uint32_t frameDuration = 60; /**< La durée de chaque image. */
};

#endif // BOMB_H