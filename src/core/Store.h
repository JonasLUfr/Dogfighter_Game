/**
 * @file Store.h
 * @brief Fichier d'en-tête pour la classe Store
 */

#ifndef STORE_H
#define STORE_H

#include "Bullet.h"

/**
 * @brief La classe Store représente un magasin de jeu
 */
class Store {
public:
    /**
     * @brief L'énumération PurchaseState définit l'état d'achat des articles du magasin
     */
    enum class PurchaseState {
        Success, /**< L'achat a réussi */
        Failure, /**< L'achat a échoué */
        UnPurchase, /**< L'article n'a pas été acheté */
        IsPurchased /**< L'article a déjà été acheté */
    };

    /**
     * @brief Constructeur de la classe Store
     * @param initialScore Score initial du joueur
     */
    Store(int initialScore) : playerScore(initialScore) {};

    /**
     * @brief Définit le score du joueur
     * @param newScore Le nouveau score du joueur
     */
    void setPlayerScore(int newScore) {
        playerScore = newScore;
    }

    /**
     * @brief Renvoie le score actuel du joueur
     * @return Le score actuel du joueur
     */
    int getPlayerScore() const {
        return playerScore;
    }

private:
    int playerScore; /**< Le score du joueur */
};

#endif