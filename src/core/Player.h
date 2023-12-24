/**
 * @file Player.h
 * @brief Fichier d'en-tête pour la classe Player
 */
#ifndef PLAYER_H
#define PLAYER_H
#include "Collision.h"

/**
 * @class Player
 * @brief Une classe représentant le joueur du jeu.
 */
class Player {
public:
    /**
     * @brief Construit un nouvel objet Player.
     * @param windowWidth La largeur de la fenêtre du jeu.
     * @param windowHeight La hauteur de la fenêtre du jeu.
     */
    Player(int windowWidth, int windowHeight);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    /**
     * @brief Obtient la vitesse du joueur.
     * @return La vitesse du joueur.
     */
    int getSpeed() const;

    /**
     * @brief Définit la vitesse du joueur.
     * @param newSpeed La nouvelle vitesse du joueur.
     */
    void setSpeed(int newSpeed);

    /**
     * @brief Obtient la coordonnée x du joueur.
     * @return La coordonnée x du joueur.
     */
    int getX() const;

    /**
     * @brief Obtient la coordonnée y du joueur.
     * @return La coordonnée y du joueur.
     */
    int getY() const;

    /**
     * @brief Définit la coordonnée x du joueur.
     * @param x La nouvelle coordonnée x du joueur.
     */
    void setX(int x);

    /**
     * @brief Définit la coordonnée y du joueur.
     * @param y La nouvelle coordonnée y du joueur.
     */
    void setY(int y);
    
    /**
     * @brief Réinitialise la position du joueur au centre de la fenêtre.
     */
    void reset();

    /**
     * @brief Obtient le rectangle de collision du joueur.
     * @return Le rectangle de collision du joueur.
     */
    Rect::My_Rect getCollisionRect() const;

     /**
     * @brief Obtient la santé du joueur.
     * @return La santé du joueur.
     */
    int getHealth() const;

    /**
     * @brief Définit la santé du joueur.
     * @param newHealth La nouvelle valeur de santé pour le joueur.
     */
    void setHealth(int newHealth);

private:
    int x;                  /**< La coordonnée x du joueur. */
    int y;                  /**< La coordonnée y du joueur. */
    int speed;              /**< La vitesse du joueur. */
    int windowWidth;        /**< La largeur de la fenêtre du jeu. */
    int windowHeight;       /**< La hauteur de la fenêtre du jeu. */
    int playerWidth;        /**< La largeur du joueur. */
    int playerHeight;       /**< La hauteur du joueur. */
    //int health;           /**< La santé du joueur. */
};

#endif // PLAYER_H