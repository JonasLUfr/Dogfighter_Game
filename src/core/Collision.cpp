/**
 * @file Collision.cpp
 * @brief Fichier de code source pour la fonctions logiques de détection de collision
 */
#include "Collision.h"

bool Rect::hasIntersection(const My_Rect * A, const My_Rect * B) {
    if (A == nullptr || B == nullptr) {
        return false;
    }

    int A_left = A->x;
    int A_right = A->x + A->w;
    int A_top = A->y;
    int A_bottom = A->y + A->h;

    int B_left = B->x;
    int B_right = B->x + B->w;
    int B_top = B->y;
    int B_bottom = B->y + B->h;

    return !(A_left >= B_right || A_right <= B_left || A_top >= B_bottom || A_bottom <= B_top);
}
