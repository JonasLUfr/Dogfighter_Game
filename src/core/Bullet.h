/**
 * @file Bullet.h
 * @brief Définition de la classe Bullet représentant une balle.
 */

#ifndef BULLET_H
#define BULLET_H

#include "Collision.h"

/**
 * @class Bullet
 * @brief Classe représentant une balle.
 */
class Bullet {
public:
    /**
     * @brief Énumération des différentes trajectoires de balles.
     */
    enum class BulletTrajectory {
        Weapon1, /**< Trajectoire de l'arme 1. */
        Weapon2, /**< Trajectoire de l'arme 2. */
        Weapon3, /**< Trajectoire de l'arme 3. */
        Weapon4, /**< Trajectoire de l'arme 4. */
        Weapon5  /**< Trajectoire de l'arme 5. */
    };

    /**
     * @brief Construit une nouvelle balle.
     * @param x La coordonnée x de la balle.
     * @param y La coordonnée y de la balle.
     * @param speed La vitesse de la balle.
     * @param trajectory La trajectoire de la balle.
     */
    Bullet(int x, int y, int speed, BulletTrajectory trajectory);

    /**
     * @brief Construit une nouvelle balle.
     */
    Bullet();

    /**
     * @brief Énumération des états possibles des balles.
     */
    enum class BulletState {
        Active,     /**< La balle est active */
        Inactive    /**< La balle est inactive */
    };

    /**
     * @brief Modifie la coordonnée x de la balle.
     * @param x La nouvelle coordonnée x.
     */
    void setX(int x);

    /**
     * @brief Modifie la coordonnée y de la balle.
     * @param y La nouvelle coordonnée y.
     */
    void setY(int y);

    /**
     * @brief Récupère l'état de la balle.
     * @return L'état de la balle.
     */
    BulletState getState() const;

    /**
     * @brief Modifie l'état de la balle.
     * @param newState Le nouvel état.
     */
    void setState(BulletState newState);

    /**
     * @brief Récupère la coordonnée x de la balle.
     * @return La coordonnée x de la balle.
     */
    int getX() const;

    /**
     * @brief Récupère la coordonnée y de la balle.
     * @return La coordonnée y de la balle.
     */
    int getY() const;

    /**
     * @brief Récupère la vitesse de la balle.
     * @return La vitesse de la balle.
     */
    int getSpeed() const;

    /**
     * @brief Modifie la vitesse de la balle.
     * @param speed La nouvelle vitesse.
     */
    void setSpeed(int speed);

    /**
     * @brief Réinitialise l'objet balle.
     */
    void reset();

    /**
     * @brief Récupère les dégâts de la balle.
     * @return Les dégâts de la balle.
     */
    int getDamage() const;

    /**
     * @brief Modifie les dégâts de la balle.
     * @param newDamage Les nouveaux dégâts.
     */
    void setDamage(int newDamage);

    /**
     * @brief Récupère l'intervalle de génération de la balle.
     * @return L'intervalle de génération de la balle.
     */
    int getFireInterval() const;

    /**
     * @brief Modifie l'intervalle de génération de la balle.
     * @param newFireInterval Le nouvel intervalle de génération.
    */
    void setFireInterval(int newFireInterval);

    /**
     * @brief Modifie la trajectoire de la balle.
     * @param newTrajectory La nouvelle trajectoire.
     */
    void setTrajectory(BulletTrajectory newTrajectory);

    /**
     * @brief Met à jour l'objet balle.
     */
    void update();

    /**
     * @brief Modifie la vitesse horizontale de la balle.
     * @param speedX La nouvelle vitesse horizontale.
     */
    void setSpeedX(float speedX);

    /**
     * @brief Modifie la vitesse verticale de la balle.
     * @param speedY La nouvelle vitesse verticale.
     */
    void setSpeedY(float speedY);

    /**
     * @brief Récupère le rectangle de collision de la balle.
     * @return Le rectangle de collision de la balle.
     */
    Rect::My_Rect getCollisionRect() const;
    private:
    int x; /**< La coordonnée x de la balle. */
    int y; /**<La coordonnée y de la balle. */
    BulletTrajectory trajectory; /**< La trajectoire de la balle. */
    float speedX; /**< La vitesse horizontale de la balle. */
    float speedY; /**< La vitesse verticale de la balle. */
    int bulletWidth; /**< La largeur de la balle. */
    int bulletHeight; /**< La hauteur de la balle. */
    int speed; /**< La vitesse de la balle. */
    BulletState state; /**< L'état de la balle. */
    int damage; /**< Les dégâts de la balle. */
    int fireInterval; /**< L'intervalle de génération de la balle. */
    };

    #endif // BULLET_H





