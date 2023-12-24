/**
 * @file Collision.h
 * @brief Définition de la classe Rect pour la détection de collisions.
 */

#ifndef COLLISION_H
#define COLLISION_H

/**
 * @class Rect
 * @brief Classe pour la détection de collisions avec des rectangles.
 */
class Rect {
public:
    /**
     * @brief Structure représentant un rectangle.
     */
    typedef struct {
        int x;  /**< La coordonnée x du coin supérieur gauche du rectangle. */
        int y;  /**< La coordonnée y du coin supérieur gauche du rectangle. */
        int w;  /**< La largeur du rectangle. */
        int h;  /**< La hauteur du rectangle. */
    } My_Rect;

    /**
     * @brief Vérifie si deux rectangles ont une intersection.
     * @param A Le premier rectangle.
     * @param B Le deuxième rectangle.
     * @return true si les deux rectangles ont une intersection, false sinon.
     */
    static bool hasIntersection(const My_Rect * A, const My_Rect * B);
};

#endif // COLLISION_H