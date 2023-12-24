/**
 * @file Game.h
 * @brief Fichier d'en-tête pour la classe Game objet
 */

#pragma once

#include <vector>
#include <cmath>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Bomb.h"
#include "Drop.h"
#include "Collision.h"
#include "ScoreManager.h"
#include "Map.h"
#include "Store.h"

/**
 * @class Game
 * @brief Classe principale du jeu, gère l'état du jeu, les objets du jeu et les entrées utilisateur.
 */
class Game {
public:
    /**
     * @enum GameState
     * @brief Énumération des différents états du jeu.
     */
    enum class GameState {
        MainMenu,        /**< Menu principal. */
        Level,           /**< Sélection du niveau. */
        ControlMenu,     /**< Menu de sélection des contrôles. */
        MouseControl,    /**< Contrôle à la souris. */
        KeyboardControl, /**< Contrôle au clavier. */
        Running,         /**< Jeu en cours. */
        Pause,           /**< Jeu en pause. */
        Store,           /**< Magasin. */
        GameOver         /**< Fin du jeu. */
    };
    // Membres de données
    // ...
    GameState currentState;                 /**< L'état actuel du jeu. */
    int menuSelection;                      /**< La sélection de menu actuelle. */
    int optionsMenuSelection;               /**< La sélection de menu des options actuelle. */
    int controlSelection;                   /**< La sélection de contrôle actuelle. */
    int controlMenuSelection;               /**< La sélection de menu de contrôle actuelle. */
    int levelMenuSelection;                 /**< La sélection de menu de niveau actuelle. */
    int storeMenuSelection;                 /**< La sélection de menu de magasin actuelle. */
    int magazineSize = 100;                 /**< La taille initiale du chargeur. */
    GameState previousState;                /**< L'état précédent du jeu. */

    /**
     * @brief Obtenir l'état actuel du jeu.
     * @return L'état actuel du jeu.
     */
    GameState getCurrentState() const { return currentState; }

    /**
     * @brief Vérifie si l'état du jeu a changé.
     * @return True si l'état du jeu a changé, False sinon.
     */
    bool hasStateChanged() const { return currentState != previousState; }

    /**
     * @brief Définir l'état actuel du jeu.
     * @param state Le nouvel état du jeu.
     */
    void setCurrentState(GameState state) { 
        previousState = currentState;
        currentState = state;
    }

    /**
     * @brief Constructeur par défaut de la classe Game.
     */
    Game();
    
    /**
     * @brief Constructeur de la classe Game avec les dimensions de la fenêtre.
     * @param windowWidth Largeur de la fenêtre de jeu.
     * @param windowHeight Hauteur de la fenêtre de jeu.
     */
    Game(int windowWidth, int windowHeight);
    
    // Fonctions de gestion des entrées
    // ...

    /**
     * @brief Traite les entrées utilisateur dans le menu principal.
     * @param input Caractère d'entrée utilisateur.
     */
    void menuInput(const char input);

    /**
     * @brief Traite les entrées utilisateur dans l'état de jeu en cours.
     * @param input Caractère d'entrée utilisateur.
     */
    void runningInput(const char input);

    /**
     * @brief Traite les entrées utilisateur dans le menu de contrôle.
     * @param input Caractère d'entrée utilisateur.
     */
    void controlInput(const char input);

    /**
     * @brief Traite les entrées utilisateur dans le menu de sélection de niveau.
     * @param input Caractère d'entrée utilisateur.
     */
    void levelInput(const char input);

    /**
     * @brief Traite les entrées utilisateur dans le menu du magasin.
     * @param input Caractère d'entrée utilisateur.
     */
    void storeInput(const char input);

    /**
     * @brief Met à jour l'état du jeu et les objets du jeu.
     */
    void update();

    /**
     * @brief Réinitialise les objets du jeu.
     */
    void resetGameObjects();

    /**
     * @brief Enregistre le score du joueur.
     */
    void saveScore();

    // Fonctions liées au score
    // ...

    /**
     * @brief Récupère le score actuel du joueur.
     * @return Le score actuel du joueur.
     */
    int getPlayerScore() const {
        return scoreManager.getPlayerScore();
    }
    /**
     * @brief Définit le score du joueur.
     * @param score Le nouveau score du joueur.
     */
    void setPlayerScore(int score) {
        scoreManager.setPlayerScore(score);
    }

    /**
     * @brief Enregistre le score du joueur.
     */
    void save() {
        scoreManager.saveScore();
    }
    /**
     * @brief Enregistre une partie de jeu avec le score et le temps de jeu.
     * @param playerScore Score du joueur à enregistrer.
     * @param gameTime Temps de jeu à enregistrer.
     */
    void recordGame(int playerScore, float gameTime) {
        scoreManager.recordGame(playerScore, gameTime);
    }
    // Fonctions liées au son
    // ...

    bool playSound = false;

    /**
     * @brief Définit si le son de la bombe doit être joué.
     * @param value Vrai pour jouer le son, faux sinon.
     */
    void setBombSound(bool value) { playSound = value; }

    /**
     * @brief Récupère l'état du son de la bombe (joué ou non).
     * @return Vrai si le son de la bombe est joué, faux sinon.
     */
    bool getBombSound() const { return playSound; }

    // Fonctions liées au contrôle
    // ...

    /**
     * @brief Énumération des différents types de contrôles.
     */
    enum class ControlType {
        Keyboard, /**< Contrôle au clavier. */
        Mouse     /**< Contrôle à la souris. */
    };
    bool useMouseControl;

    ControlType currentControlType = ControlType::Keyboard;

    /**
     * @brief Récupère le type de contrôle actuel (clavier ou souris).
     * @return Le type de contrôle actuel.
     */
    ControlType getControlType() const { 
        return  currentControlType;
        }
    /**
     * @brief Définit le type de contrôle à utiliser (clavier ou souris).
     * @param controlType Le type de contrôle à utiliser.
     */
    void setControlType(ControlType controlType) { 
        currentControlType = controlType;
        }
    // Fonctions liées à la sélection du niveau
    // ...
    /**
     * @brief Énumération des différents niveaux de difficulté.
     */
    enum class LevelSelection {
        Easy,   /**< Niveau facile. */
        Normal, /**< Niveau normal. */
        Hard    /**< Niveau difficile. */
    };

    uint32_t lastEnemySpawnTime;
    int enemySpawnInterval;
    int maxEnemyCount;
    LevelSelection currentLevel = LevelSelection::Normal;
    /**
     * @brief Récupère le niveau actuel (facile, normal ou difficile).
     * @return Le niveau actuel.
     */
    LevelSelection getCurrentLevel() const {
        return currentLevel;
    }
    /**
     * @brief Définit le niveau actuel (facile, normal ou difficile).
     * @param level Le niveau à définir.
     */
     void setCurrentLevel(LevelSelection level) {
        currentLevel = level;
    }
    // Fonctions liées aux tirs
    // ...

    /**
     * @brief Tire une balle avec une trajectoire donnée.
     * @param trajectory La trajectoire de la balle.
     */
    void fireBullet(Bullet::BulletTrajectory trajectory);

    /**
     * @brief Tire une seule balle avec une trajectoire donnée.
     * @param trajectory La trajectoire de la balle.
     */
    void fireSingleBullet(Bullet::BulletTrajectory trajectory);

    /**
     * @brief Tire plusieurs balles avec une trajectoire donnée.
     * @param trajectory La trajectoire des balles.
     * @param bulletCount Le nombre de balles à tirer.
     */
    void fireMultipleBullets(Bullet::BulletTrajectory trajectory, int bulletCount);

    // Autres fonctions
    // ...

    /**
     * @brief Récupère le timer actuel.
     * @return Le timer actuel.
     */
    uint32_t getMyTimer() const { return myTimer; }

    /**
     * @brief Met à jour le timer avec un delta de temps.
     * @param deltaTime Le delta de temps à ajouter au timer.
     */
    void updateMyTimer(uint32_t deltaTime);

    // Accesseurs
    // ...
     // Player getter
    Player& getPlayer() { return player; }

    // Bullets getter
    std::vector<Bullet>& getBullets() { return bullets; }

    // Enemies getter
    std::vector<Enemy>& getEnemies() { return enemies; }

    // Map getter
    Map& getMap() { return m_map; }

    // Bombs getter
    std::vector<Bomb>& getBombs() { return bombs; }

    // Drops getter
    std::vector<Drop>& getDrops() { return drops; }

    // ScoreManager getter
    ScoreManager& getScoreManager() { return scoreManager; }

    Bullet::BulletTrajectory getTrajectory() const { return currentTrajectory; };
    Store::PurchaseState getPurchaseState() const { return currentPurchaseState;} 

    double getFireInterval() const;
    void setFireInterval(double newFireInterval);

    std::vector<Drop::DropType> &getDropType() const;




private:

    /**
     * @brief Vérifie les collisions entre les objets du jeu.
     */
    void checkCollisions();

    // Membres de données privés
    // ...
    uint32_t myTimer = 0;
    Map m_map;
    int scroll_speed;
    Player player;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    std::vector<Bomb> bombs;
    std::vector<Drop> drops;
    ScoreManager scoreManager;
    Store store;
    int weaponPrices[5];
    Bullet::BulletTrajectory currentTrajectory;
    bool autoFire = false;
    Store::PurchaseState purchaseWeapon(Bullet::BulletTrajectory weapon, int cost, ScoreManager &scoreManager);
    Store::PurchaseState currentPurchaseState;
    uint32_t lastFireTime;
    int fireInterval = 700;
    uint32_t lastDropSpawnTime;
    const int dropSpawnInterval = 3000;

};