/**
 * @file sdlGame.h
 * @brief Fichier d'en-tête pour gérer le jeu SDL.
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "../core/Game.h"
#include "../core/Collision.h"

/**
 * @class sdlGame
 * @brief Classe pour gérer le jeu SDL.
 */
class sdlGame {
public:
    // Constructeurs et destructeurs
    /**
     * @brief Construit un nouvel objet sdlGame.
     */
    sdlGame();

    /**
     * @brief Construit un nouvel objet sdlGame avec un titre, une largeur et une hauteur spécifiques.
     * @param title Le titre de la fenêtre.
     * @param width La largeur de la fenêtre.
     * @param height La hauteur de la fenêtre.
     */
    sdlGame(const std::string& title, int width, int height);

    /**
     * @brief Détruit l'objet sdlGame.
     */
    ~sdlGame();

    // Fonctions d'initialisation et de nettoyage
    /**
     * @brief Initialise SDL.
     * @return true si l'initialisation a réussi, false sinon.
     */
    bool initSDL();

    /**
     * @brief Nettoie SDL.
     */
    void cleanUpSDL();

    // Boucle principale du jeu
    /**
     * @brief Exécute la boucle principale du jeu.
     */
    void run();

    // Fonctions de mise à jour
    /**
     * @brief Met à jour la musique du jeu.
     */
    void updateMusic();

    // Fonctions de rendu 
    /**
     * @brief Rendu total
     */
    void render();

    /**
     * @brief Gestion du rendu de menu principale
     */
    void renderMainMenu();

    /**
     * @brief Rend la texture spécifiée à la position spécifiée.
     * @param texture La texture à rendre.
     * @param renderer Le contexte de rendu.
     * @param x La position x sur l'écran.
     * @param y La position y sur l'écran.
     */
    void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y);

    /**
     * @brief Gestion du rendu de la partie du jeu
     */
    void renderGame();

    /**
     * @brief Gestion du rendu des menus du mode de contrôle
     */
    void renderControlMenu();
    /**
     * @brief Gestion du rendu de l'écran en pause
     */
    void renderPausedScreen();
    /**
     * @brief Gestion de scores lorsque le rendu est en pause
     */    
    void renderPausedScore();
    /**
     * @brief Gestion de rendu du score
     */    
    void renderScore();
    /**
     * @brief Gestion du rendu game over
     */    
    void renderGameOver();
    /**
     * @brief Gestion du rendu des menus du mode de level
     */    
    void renderLevelMenu();
    /**
     * @brief Gestion du rendu des menus du mode de store
     */    
    void renderStore();

    // Fonctions de gestion des événements
    /**
     * @brief Gère les événements du jeu.
     */
    void handleEvents();

    // Fonctions de gestion des états de jeu
    /**
     * @brief Gère les événements du menu principal.
     * @param event L'événement SDL à gérer.
     */
    void handleMainMenuEvents(SDL_Event &event);

    /**
     * @brief Gère les événements du jeu en cours.
     */    
    void handleRunningEvents(SDL_Event &event);
    /**
     * @brief Gère les événements du menu control.
     */    
    void handleControlMenuEvents(SDL_Event &event);
    /**
     * @brief Gère les événements du menu pause.
     */    
    void handlePausedEvents(SDL_Event &event);
    /**
     * @brief Gère les événements du game over.
     */    
    void handleGameOverEvents(SDL_Event &event, Uint32 gameTime);
    /**
     * @brief Gère les événements de menu level.
     */    
    void handleLevelMenuEvents(const SDL_Event& event);
    /**
     * @brief Gère les événements de menu store.
     */    
    void handleStoreEvents(const SDL_Event& event);
    
    /**
     * @brief Convertit un objet My_Rect en SDL_Rect.
     * @param rect Un pointeur vers l'objet My_Rect.
     * @return L'objet SDL_Rect correspondant.
     */
    SDL_Rect MyRect_to_SDLRect(const Rect::My_Rect* rect);

private:
    // Variables membres
    SDL_Window *window;
    SDL_Renderer *renderer;
    int windowWidth;
    int windowHeight;
    std::string title;
    bool isRunning;
    Game game;
    
    // Fonctions privées
    /**
     * @brief Joue la musique spécifiée.
     * @param music Un pointeur vers la musique à jouer.
     */
    void playMusic(Mix_Music* music);
    void stopMusic();
    void pauseMusic();
    void resumeMusic();

    //Musique
    Mix_Music *menuMusic = nullptr;
    Mix_Music *gameMusic = nullptr;
    Mix_Chunk *bombSound = nullptr;
    Mix_Music *currentMusic = nullptr;
    bool isMusicPaused;

    //Fonts
    TTF_Font *titleFont;
    TTF_Font *menuFont;
    TTF_Font *pauseFont;
    TTF_Font *scoreFont;
    TTF_Font *gameOverFont;

    //Texture
    SDL_Texture *renderText(const std::string &text, TTF_Font* font, SDL_Color color);
    SDL_Texture *bg_texture1_easy;
    SDL_Texture *bg_texture1_normal;
    SDL_Texture *bg_texture1_hard;
    SDL_Texture *bg_texture2_easy;
    SDL_Texture *bg_texture2_normal;
    SDL_Texture *bg_texture2_hard;
    SDL_Texture *texture;

    SDL_Texture *mainMenuBackgroundTexture;
    SDL_Texture *playerTexture;
    SDL_Texture *bulletTexture1;
    SDL_Texture *bulletTexture2;
    SDL_Texture *bulletTexture3;
    SDL_Texture *bulletTexture4;
    SDL_Texture *bulletTexture5;
    SDL_Texture *enemyTexture;
    SDL_Texture *dropTexture1;
    SDL_Texture *dropTexture2;
    SDL_Texture *dropTexture3;
    std::vector<SDL_Texture*> bombTextures;

    SDL_Texture *titleTexture;
    SDL_Texture *stopTexture;
    SDL_Texture *startGameTexture;
    SDL_Texture *controlsTexture;
    SDL_Texture *levelTexture;
    SDL_Texture *storeTexture;
    SDL_Texture *easyTexture;
    SDL_Texture *normalTexture;
    SDL_Texture *hardTexture;
    SDL_Texture *keyboardTexture;
    SDL_Texture *mouseTexture;




};
