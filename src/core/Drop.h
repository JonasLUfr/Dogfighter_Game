/**
 * @file Drop.h
 * @brief Définition de la classe Drop représentant un objet qui tombe.
 */

#pragma once

#include "Collision.h"

/**
 * @class Drop
 * @brief Classe représentant un objet qui tombe.
 */
class Drop{
private:
    int x;      /**< La coordonnée x de l'objet. */
    int y;      /**< La coordonnée y de l'objet. */
    int speed;  /**< La vitesse de l'objet. */
    
    bool active;    /**< Indique si l'objet est actif. */

    int width_;     /**< La largeur de l'objet. */
    int height_;    /**< La hauteur de l'objet. */
  

public:
    /**
     * @brief Énumération des différents types de bonus.
     */
    enum class DropType {
        Bonus,         /**< Objet avec un effet positif. */
        SpeedBoost,    /**< Augmentation de la vitesse. */
        FireRateBoost  /**< Augmentation de la cadence de tir. */
    };

    DropType type;  /**< Le type de l'objet qui tombe. */

    /**
     * @brief Construit un nouvel objet qui tombe.
     * @param x La coordonnée x de l'objet.
     * @param y La coordonnée y de l'objet.
     * @param speed La vitesse de l'objet.
     * @param type Le type de l'objet qui tombe.
     */
    Drop(int x, int y, int speed, DropType type);

    /**
     * @brief Construit un nouvel objet qui tombe.
     */
    Drop() = default;

    /**
     * @brief Récupère la coordonnée x de l'objet.
     * @return La coordonnée x de l'objet.
     */
    int getX() const;

    /**
     * @brief Récupère la coordonnée y de l'objet.
     * @return La coordonnée y de l'objet.
     */
    int getY() const;

    /**
     * @brief Modifie la coordonnée x de l'objet.
     * @param setx La nouvelle coordonnée x.
     */
    void setX(int setx);

    /**
     * @brief Modifie la coordonnée y de l'objet.
     * @param sety La nouvelle coordonnée y.
     */
    void setY(int sety);

    /**
     * @brief Récupère le type de l'objet qui tombe.
     * @return Le type de l'objet qui tombe.
     */
    DropType getType() const;

    /**
     * @brief Indique si l'objet est actif.
     * @return true si l'objet est actif, false sinon.
     */
    bool isActive() const;

    /**
     * @brief Modifie l'état actif de l'objet.
     * @param active Le nouvel état.
     */
    void setActive(bool active);

    /**
     * @brief Met à jour l'objet.
     */
    void update();

    /**
     * @brief Récupère le rectangle de collision de l'objet.
     * @return Le rectangle de collision de l'objet.
     */
    Rect::My_Rect getCollisionRect() const;
};