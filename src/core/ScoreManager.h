/**
 * @file ScoreManager.h
 * @brief Définition de la classe ScoreManager représentant un gestionnaire de score.
 */

#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <iostream>
#include <fstream>

/**
 * @class ScoreManager
 * @brief Classe représentant un gestionnaire de score.
 */
class ScoreManager {
private:
    int playerScore;        /**< Le score actuel du joueur. */
    int highScore;          /**< Le meilleur score actuel. */
    int totalScore;         /**< Le score total. */

public:
    // Constructeurs et destructeurs
    /**
     * @brief Construit un nouvel objet ScoreManager.
     */
    ScoreManager();

    /**
     * @brief Détruit l'objet ScoreManager.
     */
    ~ScoreManager();

    // Fonctions getter et setter
    /**
     * @brief Obtient le score actuel du joueur.
     * @return Le score actuel du joueur.
     */
    int getPlayerScore() const;

    /**
     * @brief Définit le score actuel du joueur.
     * @param score Le nouveau score du joueur.
     */
    void setPlayerScore(int score);

    /**
     * @brief Obtient le meilleur score actuel.
     * @return Le meilleur score actuel.
     */
    int getHighScore() const;

    /**
     * @brief Définit le meilleur score actuel.
     * @param score Le nouveau meilleur score.
     */
    void setHighScore(int score);

    /**
     * @brief Obtient le score total.
     * @return Le score total.
     */
    int getTotalScore();

    // Fonctions de chargement et de sauvegarde des scores
    /**
     * @brief Charge le score depuis un fichier.
     */
    void loadScore();

    /**
     * @brief Sauvegarde le score dans un fichier.
     */
    void saveScore();

    // Fonction de mise à jour du meilleur score
    /**
     * @brief Met à jour le meilleur score.
     * @param score Le nouveau score à comparer avec le meilleur score actuel.
     */
    void updateHighScore(int score);

    // Fonction d'enregistrement du score et du temps de jeu
    /**
     * @brief Enregistre le score et le temps de jeu.
     * @param score Le score de la partie.
     * @param gameTime Le temps de jeu.
     */
    void recordGame(int score, float gameTime);   
};

#endif // SCOREMANAGER_H
