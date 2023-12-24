/** 
 * \file documentation.h
 * \brief Fichier d'en-tête contenant la documentation Doxygen pour le projet
 */
/** \mainpage Jeu-Vidéo-DogFighter

\section intro Introduction

DogFighter est un jeu-vidéo developpé en c++ en utilisant la SDL/SDL2. Ce projet de developpement à été réalisé dans le cadre de l'UE LIFAP4 <br>
Voir la page du cours :  https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4

Ce dossier contient un makefile permettant d'executer le code du jeu-vidéo.<br>
le Dossier src contient les sous-dossiers /core /sdl2 et /txt qui contiennent les modules spécifiques du jeu. (fichiers .h et .cpp) <br>

Le jeu-vidéo est jouable en version console(version texte) sans interface graphique et en version graphique avec la SDL.

Il peut se compiler sous Linux/ MacOS et Windows (avec WSL notamment) , avec la commande make depuis le dossier source.

## Code et l'organisation des fichiers

Le code est divisé en plusieurs modules répartis entre le coeur (fichiers dans le dossiers /src/core) qui constitue le noyau du programme et entre les modes d'interfaces (fichiers dans le sous-dossier /src/txt) pour la version console(texte) et l'interface graphique (fichiers dans le sous-dossier src/sdl2) pour la version en SDL.
 ## PROJET DogFIghter pour l'UE LIFAP4
 Auteur :<br>
 Zhenshan LI `zhenshan.li@etu.univ-lyon1.fr`     `p2018814`<br>
 Runnian LU `runnian.lu@etu.univ-lyon1.fr`        `p2209010`<br>
La page de Git: https://forge.univ-lyon1.fr/p2209010/lifapa_tp

\section compil Compilation

L'organistion des fichiers est la suivante.

- **bin**   :         Contient les fichiers executable créees avec la commande make depuis le dossier racine , pour éxecuter un fichier il faut executer la commande ./Debug/nom_executable , exemple : ./Debug/Plane
- **bin/Debug**   :  Contient les fichiers exécutables du Makefile
- **data**   :         Contient les fichiers images,audio et fonts du jeu
- **doc**   :         Contient le fichier .doxy permettant d'éditer et générer la documentation doxygen.
- **doc/html/index.html** : La page internet de la documentation généré par doxygen.
- **obj**   :         répertoire comportant les fichiers objets créés lors de la compilation.
- **src**   :         Contient les sous-dossiers /core /sdl2 et /txt
- **src/core**   :         Contient les fichiers source .cpp et .h qui constitue les modules principaux du jeu , les modules noyau.
- **src/sdl2**   :         Contient les fichiers source .cpp et .h qui constitue de les modules principaux pour la version graphique SDL du jeu.
- **src/txt**   :         Contient les fichiers source .cpp et .h qui constitue les modules principaux pour la version txt du jeu.

 
Pour la documentation du code, voir la rubrique "documentation du code" plus bas.

 ## Pour compiler

 ### Sous Linux

 Si vous êtes sous Linux, assurez-vous d'avoir SDL/SDL2 installé sur votre machine.
 - Ouvrez un terminal et exécutez simplement la commande : `sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick`
 - Puis, depuis le dossier racine du jeu, exécutez, depuis votre terminal, la commande : `make`
 - Une fois la compilation terminée, exécutez la commande `./bin/Debug/Plane` pour lancer du jeu

 Si la commande d'installation de la SDL/SDL2 ne fonctionne pas, référez-vous à la commande spécifique pour installer SDL/SDL2 selon votre distribution Linux.

 ### Sous macOS

 Pour compiler sous macOS, assurez-vous d'avoir SDL/SDL2 installé sur votre machine.
 - Installez Homebrew si ce n'est pas déjà fait : `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
 - Installez les bibliothèques SDL2 : `brew install sdl2 sdl2_image sdl2_ttf sdl2_mixer`
 - Puis, depuis le dossier racine du jeu, exécutez la commande : `make`
 - Une fois la compilation terminée, exécutez la commande `./bin/Debug/Plane` pour lancer du jeu

 ### Sous Windows avec Visual Studio

 Pour compiler sous Windows avec Visual Studio, assurez-vous d'avoir SDL/SDL2 installé sur votre machine.
 - Téléchargez les bibliothèques SDL2 (https://www.libsdl.org/download-2.0.php) et décompressez-les
 - Créez un nouveau projet Visual Studio C++ et ajoutez les fichiers sources du jeu
 - Configurez les propriétés du projet pour inclure les répertoires d'en-tête et les bibliothèques de SDL2
 - Compilez le projet et exécutez le jeu depuis Visual Studio

 ### Sous Windows avec Code::Blocks

 Pour compiler sous Windows avec Code::Blocks, assurez-vous d'avoir SDL/SDL2 installé sur votre machine.
 - Téléchargez les bibliothèques SDL2 (https://www.libsdl.org/download-2.0.php) et décompressez-les
 - Créez un nouveau projet Code::Blocks C++ et ajoutez les fichiers sources du jeu
 - Configurez les propriétés du projet pour inclure les répertoires d'en-tête et les bibliothèques de SDL2
 - Compilez le projet (F9) et exécutez le jeu depuis Code::Blocks

### Préambule : si vous voulez un Linux sous Windows, vous pouvez installer WSL !

Voir la page de l'UE : https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4#wsl_pour_faire_tourner_un_linux_ultra_leger_sous_windows

C'est léger, pratique, rapide et suffisant pour de nombreuses applications.
Windows/WSL est exactement comme une machine Linux avec des drivers minimalistes,
donc la gestion de certains périphériques commes la carte son ou l'accélération 3D peut ne pas marcher mais pour ce cours ca peut être suffisant.
Il faut parcontre que vous ayez installé XMing pour pouvoir ouvrir des fenêtres comme expliqué sur la page du cours.
Valgrind marche aussi !


 ### Pour installer SDL2
 Afin d'installer SDL2 sous Linux ou avec WSL/Windows, veuillez suivre les instructions ci-dessous avec soin :<br>
`sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick`

 Veuillez noter que cette commande peut varier en fonction de votre distribution Linux. Consultez la documentation de votre distribution pour connaître la commande appropriée.

 ### Compilation en ligne de commande après l'installation de SDL2 et WSL (si nécessaire)
 Une fois SDL2 et WSL (le cas échéant) correctement installés, veillez à effectuer la compilation en ligne de commande avec prudence :

 - Depuis le répertoire racine du module image, exécutez attentivement la commande `make`.
 - Si la compilation ne s'effectue pas comme prévu, vérifiez minutieusement que les chemins d'inclusion spécifiés dans le fichier Makefile à la racine du projet correspondent à votre installation de SDL2 (par défaut `/usr/include`).
 - Adaptez les chemins d'inclusion si nécessaire, en fonction de votre configuration et de l'emplacement de l'installation SDL2.

\section doc Documentation
 Une documentation détaillée générée grâce à Doxygen est disponible dans le répertoire `doc`. <br>

 Le programme contient 11 classes principales, classées par nom de fichier, et utilise plusieurs librairies.<br>

 Les classes principales sont :
 - `Bomb`
 - `Bullet`
 - `Collision`
 - `Drop`
 - `Enemy`
 - `Map`
 - `Player`
 - `ScoreManager`
 - `Store`
 - `Game`
 - `sdlGame`
 
 Le programme utilise principalement les bibliothèques suivantes :

 ### Bibliothèques C++ :

- `include <vector>`
- `include <cmath>`
- `include <stdlib.h>`


 ### Bibliothèques SDL :

- `include <SDL2/SDL.h>`
- `include <SDL2/SDL_image.h>`
- `include <SDL2/SDL_ttf.h>`
- `include <SDL2/SDL_mixer.h>`
 
 <br>


 ### Classe Bomb
 La classe Bomb représente une bombe dans le jeu. Elle gère les différents états d'une bombe, ainsi que sa position et sa mise à jour.<br>

 #### Types publics:
 
 `enum class BombState { Active, Inactive };`

 #### Fonctions membres publiques:
 - `Bomb(int x, int y)`: Construit un nouvel objet Bombe.
 - `~Bomb()`: Détruit l'objet Bombe.
 - `BombState getState() const`: Récupère l'état de la bombe.
 - `void setState(BombState newState)`: Modifie l'état de la bombe.
 - `int getX() const`: Récupère la coordonnée x de la bombe.
 - `int getY() const`: Récupère la coordonnée y de la bombe.
 - `void setX(int x)`: Modifie la coordonnée x de la bombe.
 - `void setY(int y)`: Modifie la coordonnée y de la bombe.
 - `void reset()`: Réinitialise l'objet bombe.
 - `void update(uint32_t currentTime)`: Met à jour l'objet bombe.
 - `int getCurrentFrame() const`: Récupère le numéro de l'image actuelle.

 #### Attributs privés:
 - `int x`
 - `int y`
 - `int currentFrame`
 - `int maxFrames`
 - `BombState state`
 - `uint32_t lastFrameTime`
 - `const uint32_t frameDuration = 60`
 ### Classe Bullet
 La classe Bullet représente une balle dans le jeu. Elle gère les différents états, trajectoires, vitesses et dégâts d'une balle, ainsi que sa position et sa mise à jour.

 #### Types publics:
  `enum class BulletTrajectory { Weapon1, Weapon2, Weapon3, Weapon4, Weapon5 };`
 `enum class BulletState { Active, Inactive };`

 #### Fonctions membres publiques:
 - `Bullet(int x, int y, int speed, BulletTrajectory trajectory)`: Construit une nouvelle balle.
 - `Bullet()`: Construit une nouvelle balle.
 - `void setX(int x)`: Modifie la coordonnée x de la balle.
 - `void setY(int y)`: Modifie la coordonnée y de la balle.
 - `BulletState getState() const`: Récupère l'état de la balle.
 - `void setState(BulletState newState)`: Modifie l'état de la balle.
 - `int getX() const`: Récupère la coordonnée x de la balle.
 - `int getY() const`: Récupère la coordonnée y de la balle.
 - `int getSpeed() const`: Récupère la vitesse de la balle.
 - `void setSpeed(int speed)`: Modifie la vitesse de la balle.
 - `void reset()`: Réinitialise l'objet balle.
 - `int getDamage() const`: Récupère les dégâts de la balle.
 - `void setDamage(int newDamage)`: Modifie les dégâts de la balle.
 - `int getFireInterval() const`: Récupère l'intervalle de génération de la balle.
 - `void setFireInterval(int newFireInterval)`: Modifie l'intervalle de génération de la balle.
 - `void setTrajectory(BulletTrajectory newTrajectory)`: Modifie la trajectoire de la balle.
 - `void update()`: Met à jour l'objet balle.
 - `void setSpeedX(float speedX)`: Modifie la vitesse horizontale de la balle.
 - `void setSpeedY(float speedY)`: Modifie la vitesse verticale de la balle.
 - `Rect::My_Rect getCollisionRect() const`: Récupère le rectangle de collision de la balle.

 #### Attributs privés:
  - `int x`
 - `int y`
 - `BulletTrajectory trajectory`
 - `float speedX`
 - `float speedY`
 - `int bulletWidth`
 - `int bulletHeight`
 - `int speed`
 - `BulletState state`
 - `int damage`
 - `int fireInterval`
 
 
 ### Classe Drop
 La classe Drop représente un objet qui tombe dans le jeu, tel qu'un bonus ou un boost de vitesse. Elle gère les différents types de bonus, leurs coordonnées, leur état actif et leur mise à jour.

 #### Types publics:
 `enum class DropType { Bonus, SpeedBoost, FireRateBoost };`

 #### Fonctions membres publiques:
 - `Drop(int x, int y, int speed, DropType type)`: Construit un nouvel objet qui tombe.
 - `Drop() = default`: Construit un nouvel objet qui tombe.
 - `int getX() const`: Récupère la coordonnée x de l'objet.
 - `int getY() const`: Récupère la coordonnée y de l'objet.
 - `void setX(int setx)`: Modifie la coordonnée x de l'objet.
 - `void setY(int sety)`: Modifie la coordonnée y de l'objet.
 - `DropType getType() const`: Récupère le type de l'objet qui tombe.
 - `bool isActive() const`: Indique si l'objet est actif.
 - `void setActive(bool active)`: Modifie l'état actif de l'objet.
 - `void update()`: Met à jour l'objet.
 - `Rect::My_Rect getCollisionRect() const`: Récupère le rectangle de collision de l'objet.

 #### Attributs publics:
 - `DropType type`

 #### Attributs privés:
 - `int x`
 - `int y`
 - `int speed`
 - `bool active`
 - `int width_`
 - `int height_`
 
 ### Classe Enemy
 La classe Enemy représente un ennemi dans le jeu. Elle gère les coordonnées, l'état, la vitesse de déplacement et les intervalles de temps entre chaque tir de l'ennemi.

 #### Types publics:
 
 `enum class EnemyState { Active, Inactive };`

 #### Fonctions membres publiques:
 - `Enemy(int x, int y, int interval, int speed)`: Construit un nouvel ennemi.
 - `Enemy()`: Construit un nouvel ennemi.
 - `int getX() const`: Récupère la coordonnée x de l'ennemi.
 - `int getY() const`: Récupère la coordonnée y de l'ennemi.
 - `void setX(int x)`: Modifie la coordonnée x de l'ennemi.
 - `void setY(int y)`: Modifie la coordonnée y de l'ennemi.
 - `EnemyState getState() const`: Récupère l'état de l'ennemi.
 - `void setState(EnemyState newState)`: Modifie l'état de l'ennemi.
 - `int getInterval() const`: Récupère l'intervalle de temps entre chaque tir de l'ennemi.
 - `int getSpeed() const`: Récupère la vitesse de déplacement de l'ennemi.
 - `void setSpeed(int setSpeed)`: Modifie la vitesse de déplacement de l'ennemi.
 - `void update()`: Met à jour l'ennemi.
 - `void reset()`: Réinitialise l'ennemi.
 - `Rect::My_Rect getCollisionRect() const`: Récupère le rectangle de collision de l'ennemi.

 #### Attributs privés:
 - `int x`
 - `int y`
 - `int interval`
 - `int speed`
 - `int enemyWidth`
 - `int enemyHeight`
 - `EnemyState state`
 
 ### Classe Map

 La classe Map gère la carte et la position de la carte dans le jeu.

 #### Fonctions membres publiques:
 - `Map()`: Constructeur d'un nouvel objet Map.
 - `void mapPosition(int scroll_speed)`: Mettre à jour la position de la carte.
 - `int getWidth() const`: Obtenir la largeur de la carte.
 - `int getHeight() const`: Obtenir la hauteur de la carte.
 - `int getMap1PosY() const`: Obtenir la position de la carte1.
 - `int getMap2PosY() const`: Obtenir la position de la carte2.

 #### Attributs privés:
 - `int width_`
 - `int height_`
 - `int map1_posY`
 - `int map2_posY`

 ### Classe Player

 La classe Player représente un joueur dans le jeu et gère ses coordonnées, sa vitesse et sa santé.

 #### Fonctions membres publiques:
 - `Player(int windowWidth, int windowHeight)`: Construit un nouvel objet Player.
 - `void moveLeft()`: Déplacer le joueur vers la gauche.
 - `void moveRight()`: Déplacer le joueur vers la droite.
 - `void moveUp()`: Déplacer le joueur vers le haut.
 - `void moveDown()`: Déplacer le joueur vers le bas.
 - `int getSpeed() const`: Obtient la vitesse du joueur.
 - `void setSpeed(int newSpeed)`: Définit la vitesse du joueur.
 - `int getX() const`: Obtient la coordonnée x du joueur.
 - `int getY() const`: Obtient la coordonnée y du joueur.
 - `void setX(int x)`: Définit la coordonnée x du joueur.
 - `void setY(int y)`: Définit la coordonnée y du joueur.
 - `void reset()`: Réinitialise la position du joueur au centre de la fenêtre.
 - `Rect::My_Rect getCollisionRect() const`: Obtient le rectangle de collision du joueur.
 - `int getHealth() const`: Obtient la santé du joueur.
 - `void setHealth(int newHealth)`: Définit la santé du joueur.

 #### Attributs privés:
 - `int x`
 - `int y`
 - `int speed`
 - `int windowWidth`
 - `int windowHeight`
 - `int playerWidth`
 - `int playerHeight`

 ### Classe Rect

 La classe Rect est utilisée pour la détection de collisions avec des rectangles.

 #### Fonctions membres publiques statiques:
 - `static bool hasIntersection(const My_Rect *A, const My_Rect *B)`: Vérifie si deux rectangles ont une intersection.

 ### Classe ScoreManager

 La classe ScoreManager gère le score du joueur, le meilleur score et le score total.

 #### Fonctions membres publiques:
 - `ScoreManager()`: Construit un nouvel objet ScoreManager.
 - `~ScoreManager()`: Détruit l'objet ScoreManager.
 - `int getPlayerScore() const`: Obtient le score actuel du joueur.
 - `void setPlayerScore(int score)`: Définit le score actuel du joueur.
 - `int getHighScore() const`: Obtient le meilleur score actuel.
 - `void setHighScore(int score)`: Définit le meilleur score actuel.
 - `int getTotalScore()`: Obtient le score total.
 - `void loadScore()`: Charge le score depuis un fichier.
 - `void saveScore()`: Sauvegarde le score dans un fichier.
 - `void updateHighScore(int score)`: Met à jour le meilleur score.

 
 ### Classe Store

 La classe Store représente un magasin dans le jeu. Elle permet de gérer le score du joueur et les achats d'articles.

 #### Types publics:
 `enum class PurchaseState { Success, Failure, UnPurchase, IsPurchased }`<br>
 - L'énumération PurchaseState définit l'état d'achat des articles du magasin.

 #### Fonctions membres publiques:
 - `Store(int initialScore)`: Constructeur de la classe Store.
 - `void setPlayerScore(int newScore)`: Définit le score du joueur.
 - `int getPlayerScore() const`: Renvoie le score actuel du joueur.

 #### Attributs privés:
 - `int playerScore`

 ### Classe Game
 La classe Game est la classe principale du jeu qui gère l'état du jeu, les objets du jeu et les entrées utilisateur.

 #### Types publics:
 - `enum class GameState { MainMenu, Level, ControlMenu, MouseControl, KeyboardControl, Running, Pause, Store, GameOver }`
 - Énumération des différents états du jeu.
 - `enum class ControlType { Keyboard, Mouse }`
 -  Énumération des différents types de contrôles.
 - `enum class LevelSelection { Easy, Normal, Hard }`
 -  Énumération des différents niveaux de difficulté.

 #### Fonctions membres publiques:
 - `GameState getCurrentState() const`: Obtenir l'état actuel du jeu.
 - `bool hasStateChanged() const`: Vérifie si l'état du jeu a changé.
 - `void setCurrentState(GameState state)`: Définir l'état actuel du jeu.
 - `Game()`: Constructeur par défaut de la classe Game.
 - `Game(int windowWidth, int windowHeight)`: Constructeur de la classe Game avec les dimensions de la fenêtre.
 - `void menuInput(const char input)`: Traite les entrées utilisateur dans le menu principal.
 - `void runningInput(const char input)`: Traite les entrées utilisateur dans l'état de jeu en cours.
 - `void controlInput(const char input)`: Traite les entrées utilisateur dans le menu de contrôle.
 - `void levelInput(const char input)`: Traite les entrées utilisateur dans le menu de sélection de niveau.
 - `void storeInput(const char input)`: Traite les entrées utilisateur dans le menu du magasin.
 - `void update()`: Met à jour l'état du jeu et les objets du jeu.
 - `void resetGameObjects()`: Réinitialise les objets du jeu.
 - `void saveScore()`: Enregistre le score du joueur.
 - `int getPlayerScore() const`: Récupère le score actuel du joueur.
 - `void setPlayerScore(int score)`: Définit le score du joueur.
 - `void save()`: Enregistre le score du joueur.
 - `void recordGame(int playerScore, float gameTime)`: Enregistre une partie de jeu avec le score et le temps de jeu.
 - `void setBombSound(bool value)`: Définit si le son de la bombe doit être joué.
 - `bool getBombSound() const`: Récupère l'état du son de la bombe (joué ou non).
 - `ControlType getControlType() const`: Récupère le type de contrôle actuel (clavier ou souris).
 - `void setControlType(ControlType controlType)`: Définit le type de contrôle à utiliser (clavier ou souris).
 - `LevelSelection getCurrentLevel() const`: Récupère le niveau actuel (facile, normal ou difficile).
 - `void setCurrentLevel(LevelSelection level)`: Définit le niveau actuel (facile, normal ou difficile).
 - `void fireBullet(Bullet::BulletTrajectory trajectory)`: Tire une balle avec une trajectoire donnée.
 - `void fireSingleBullet(Bullet::BulletTrajectory trajectory)`: Tire une seule balle avec une trajectoire donnée.
 - `void fireMultipleBullets(Bullet::BulletTrajectory trajectory, int bulletCount)`: Tire plusieurs balles avec une trajectoire donnée.
 - `uint32_t getMyTimer() const`: Récupère le timer actuel.
 - `void updateMyTimer(uint32_t deltaTime)`: Met à jour le timer avec un delta de temps.
 - `Player& getPlayer()`: Récupère l'objet joueur.
 - `std::vector<Bullet>& getBullets()`: Récupère la liste des balles.
 - `std::vector<Enemy>& getEnemies()`: Récupère la liste des ennemis.
 - `Map& getMap()`: Récupère l'objet carte.
 - `std::vector<Bomb>& getBombs()`: Récécupère la liste des bombes.
 - `std::vector<Drop>& getDrops()`: Récupère la liste des objets ramassables.
 - `ScoreManager& getScoreManager()`: Récupère le gestionnaire de score.
 - `Bullet::BulletTrajectory getTrajectory() const`: Récupère la trajectoire actuelle des balles.
 - `Store::PurchaseState getPurchaseState() const`: Récupère l'état d'achat actuel.
 - `double getFireInterval() const`: Récupère l'intervalle de tir actuel.
 - `void setFireInterval(double newFireInterval)`: Définit le nouvel intervalle de tir.
 - `std::vector<Drop::DropType>& getDropType() const`: Récupère la liste des types d'objets ramassables.

 #### Attributs publics:
 - `GameState currentState`: L'état actuel du jeu.<br>
 - `int menuSelection `: La sélection actuelle du menu principal.<br>
 - `int optionsMenuSelection `: La sélection actuelle du menu des options.<br>
 - `int controlSelection `: La sélection actuelle du menu de contrôle.<br>
 - `int controlMenuSelection `: La sélection actuelle du menu de contrôle.<br>
 - `int levelMenuSelection `: La sélection actuelle du menu de sélection de niveau.<br>
 - `int storeMenuSelection `: La sélection actuelle du menu du magasin.<br>
 - `int magazineSize = 100 `: La taille du chargeur de l'arme.<br>
 - `GameState previousState `: L'état précédent du jeu.<br>
 - `bool playSound = false `: Indique si le son doit être joué ou non.<br>
 - `bool useMouseControl `: Indique si les contrôles de la souris sont utilisés.<br>
 - `ControlType currentControlType = ControlType::Keyboard `: Le type de contrôle actuel (clavier ou souris).<br>
 - `uint32_t lastEnemySpawnTime `: Le dernier moment où un ennemi a été généré.<br>
 - `int enemySpawnInterval `: L'intervalle de génération des ennemis.<br>
 - `int maxEnemyCount `: Le nombre maximal d'ennemis.<br>
 - `LevelSelection currentLevel = LevelSelection::Normal `: Le niveau de difficulté actuel.<br>


 #### Fonctions membres privées:
 - `void checkCollisions()`: Vérifie les collisions entre les objets du jeu.
 - `Store::PurchaseState purchaseWeapon(Bullet::BulletTrajectory weapon, int cost, ScoreManager &scoreManager)`: Fonction pour l'achat d'armes dans le jeu.

 #### Attributs privés:
 - `uint32_t myTimer = 0 `: Le timer actuel du jeu.
 - `Map m_map `: La carte du jeu.
 - `int scroll_speed `: La vitesse de défilement de la carte.
 - `Player player `: L'objet joueur.
 - `std::vector<Bullet> bullets `: La liste des balles.
 - `std::vector<Enemy> enemies `: La liste des ennemis.
 - `std::vector<Bomb> bombs `: La liste des bombes.
 - `std::vector<Drop> drops `: La liste des objets ramassables.
 - `ScoreManager scoreManager `: Le gestionnaire de score.
 - `Store store `: Le magasin du jeu.
 - `int weaponPrices[5] `: Les prix des armes.
 - `Bullet::BulletTrajectory currentTrajectory `: La trajectoire actuelle des balles.
 - `bool autoFire = false `: Indique si le tir automatique est activé.
 - `Store::PurchaseState currentPurchaseState `: L'état d'achat actuel.
 - `uint32_t lastFireTime `: Le dernier moment où une balle a été tirée.
 - `int fireInterval = 700 `: L'intervalle de tir.
 - `uint32_t lastDropSpawnTime `: Le dernier moment où un objet ramassable a été généré.
 - `const int dropSpawnInterval = 3000 `: L'intervalle de génération des objets ramassables.


 ### Classe sdlGame

 La classe sdlGame gère l'initialisation, le rendu et la gestion des événements du jeu.

 #### Fonctions membres publiques :
 - `sdlGame()` : Construit un nouvel objet sdlGame.
 - `sdlGame(const std::string &title, int width, int height)` : Construit un nouvel objet sdlGame avec un titre, une largeur et une hauteur spécifiques.
 - `~sdlGame()` : Détruit l'objet sdlGame.
 - `bool initSDL()` : Initialise SDL.
 - `void cleanUpSDL()` : Nettoie SDL.
 - `void run()` : Exécute la boucle principale du jeu.
 - `void updateMusic()` : Met à jour la musique du jeu.
 - `void render()` : Rendu total.
 - `void renderMainMenu()` : Gestion du rendu de menu principale.
 - `void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y)` : Rend la texture spécifiée à la position spécifiée.
 - `void renderGame()` : Gestion du rendu de la partie du jeu.
 - `void renderControlMenu()` : Gestion du rendu des menus du mode de contrôle.
 - `void renderPausedScreen()` : Gestion du rendu de l'écran en pause.
 - `void renderPausedScore()` : Gestion de scores lorsque le rendu est en pause.
 - `void renderScore()` : Gestion de rendu du score.
 - `void renderGameOver()` : Gestion du rendu game over.
 - `void renderLevelMenu()` : Gestion du rendu des menus du mode de level.
 - `void renderStore()` : Gestion du rendu des menus du mode de store.
 - `void handleEvents()` : Gère les événements du jeu.
 - `void handleMainMenuEvents(SDL_Event &event)` : Gère les événements du menu principal.
 - `void handleRunningEvents(SDL_Event &event)` : Gère les événements du jeu en cours.
 - `void handleControlMenuEvents(SDL_Event &event)` : Gère les événements du menu control.
 - `void handlePausedEvents(SDL_Event &event)` : Gère les événements du menu pause.
 - `void handleGameOverEvents(SDL_Event &event, Uint32 gameTime)` : Gère les événements du game over.
 - `void handleLevelMenuEvents(const SDL_Event &event)` : Gère les événements de menu level.
 - `void handleStoreEvents(const SDL_Event &event)` : Gère les événements de menu store.
 - `SDL_Rect MyRect_to_SDLRect(const Rect::My_Rect *rect)` : Convertit un objet My_Rect en SDL_Rect.

 #### Fonctions membres privées :
 - `void playMusic(Mix_Music *music)` : Joue la musique spécifiée.
 - `void stopMusic()`
 - `void pauseMusic()`
 - `void resumeMusic()`
 - `SDL_Texture* renderText(const std::string &text, TTF_Font *font, SDL_Color color)`
*/
