/**
 * @file Game.cpp
 * @brief Fichier de code source pour la classe Game
 */
#include "Game.h"
#include <algorithm>

Game::Game()
: Game(512, 768) { // la resolution du jeu
}

Game::Game(int windowWidth, int windowHeight)
    : m_map(),
      player(windowWidth, windowHeight), // La taille de la fenêtre entrante.
      bullets(),
      enemies(),
      bombs(),
      drops(),
      store(scoreManager.getPlayerScore())
    {
    // 初始化子弹容器**Initialiser la capacité de la balle.
    bullets.reserve(magazineSize);
    for (int i = 0; i < magazineSize; ++i) {
        bullets.emplace_back(player.getX() + 25, player.getY(), 10, Bullet::BulletTrajectory::Weapon1);
        bullets.back().setState(Bullet::BulletState::Inactive);
    }

    //les valeurs default
    currentState=GameState::MainMenu;
    currentLevel=LevelSelection::Normal;
    currentControlType=ControlType::Keyboard;
    currentTrajectory=Bullet::BulletTrajectory::Weapon1;
    drops.reserve(maxEnemyCount);
    menuSelection=0;
    scroll_speed = 3;
    lastFireTime = 0;
    lastDropSpawnTime = 0;
    useMouseControl = false;  //keyborad par default

    //prix dans le boutique
    weaponPrices[static_cast<int>(Bullet::BulletTrajectory::Weapon2)] = 50;
    weaponPrices[static_cast<int>(Bullet::BulletTrajectory::Weapon3)] = 100;
    weaponPrices[static_cast<int>(Bullet::BulletTrajectory::Weapon4)] = 200;
    weaponPrices[static_cast<int>(Bullet::BulletTrajectory::Weapon5)] = 400;

    // 如果需要默认开启 autoFire，将其设置为 true
    autoFire = true;
    };

void Game::updateMyTimer(uint32_t deltaTime) {
    myTimer += deltaTime;
}

double Game::getFireInterval() const {
    return fireInterval / 1000.0; // Convertir millisecondes en secondes
}

void Game::setFireInterval(double newFireInterval) {
    fireInterval = static_cast<int>(newFireInterval * 1000); // Convertir en millisecondes
}


void Game::menuInput(const char input){
      switch (input) {
        case 'w':
            menuSelection = (menuSelection - 1 + 4) % 4;
            break;
        case 's':
            menuSelection = (menuSelection + 1) % 4;
            break;
        case '\r':
            if (menuSelection == 0) {
                    currentState = GameState::Running;
                } else if (menuSelection == 1) {
                    currentState = GameState::ControlMenu;
                } else if (menuSelection == 2) {
                    currentState = GameState::Level;
                } else if (menuSelection == 3) {
                    currentState = GameState::Store;
                }
                break;
        case 'q':
            saveScore();
      }
};

void Game::saveScore() {
        scoreManager.saveScore();
    }

void Game::runningInput(const char input){
    switch (input){
        case 'w':
            player.moveUp();
            break;
        case 'a':
            player.moveLeft();
            break;
        case 's':
            player.moveDown();
            break;
        case 'd':
            player.moveRight();
            break;
        case 'f':
            fireSingleBullet(Bullet::BulletTrajectory::Weapon1);
            break;
        case 'p':
            saveScore();
            currentState = GameState::Pause;
            break;
        case 'e':
            saveScore();
            currentState = GameState::MainMenu;
            break;

    default:
        break;
    }
};

void Game::controlInput(const char input){
   switch (input) {
        case 'w':
            controlSelection = (controlSelection - 1 + 2) % 2; // 有两个控制选项
            break;
        case 's':
            controlSelection = (controlSelection + 1) % 2;
            break;
        case '\r':
            if (controlSelection == 0) {
                useMouseControl = false;
                setControlType(Game::ControlType::Keyboard);
            } else if (controlSelection == 1) {
                useMouseControl = true;
                setControlType(Game::ControlType::Mouse);
            }
            currentState = GameState::MainMenu;
            break;
}
};

void Game::levelInput(const char input){
    switch (input) {
        case 'w':
            levelMenuSelection = (levelMenuSelection - 1 + 3) % 3;
            break;
        case 's':
            levelMenuSelection = (levelMenuSelection + 1) % 3;
            break;
        case 'd':
        case '\r':
            if (levelMenuSelection == 0) {
                currentLevel = LevelSelection::Easy;
                resetGameObjects();
            } else if (levelMenuSelection == 1) {
                currentLevel = LevelSelection::Normal;
                resetGameObjects();
            } else if (levelMenuSelection == 2) {
                currentLevel = LevelSelection::Hard;
                resetGameObjects();
            }
            currentState = GameState::MainMenu;
            break;
}
};

void Game::storeInput(const char input) {
    switch (input) {
        case 'w':
            storeMenuSelection = (storeMenuSelection - 1 + 4) % 4;
            break;
        case 's':
            storeMenuSelection = (storeMenuSelection + 1) % 4;
            break;
        case 'd':
            break;
        case '\r':
            Bullet::BulletTrajectory selectedWeapon = static_cast<Bullet::BulletTrajectory>(storeMenuSelection + 1);
            int cost = weaponPrices[static_cast<int>(selectedWeapon)];
            Store::PurchaseState purchaseStatus = purchaseWeapon(selectedWeapon, cost, scoreManager);
            if (purchaseStatus == Store::PurchaseState::Success) {
                // 更新当前武器
                currentTrajectory = selectedWeapon;

            }
            currentState = Game::GameState::MainMenu; // 返回商店菜单
            // 可以在这里根据 purchaseStatus 显示购买成功或失败的提示
            break;
    }
}


void Game::checkCollisions() {

    for (auto& enemy : enemies) {
        if (enemy.getState() == Enemy::EnemyState::Active) {
            // 检查子弹与敌机的碰撞**Créer des collisions entre les balles et les avions ennemis
            for (auto& bullet : bullets) {
                if (bullet.getState() == Bullet::BulletState::Active) {
                    Rect::My_Rect bulletRect = bullet.getCollisionRect();
                    Rect::My_Rect enemyRect = enemy.getCollisionRect();
                    if (Rect::hasIntersection(&bulletRect, &enemyRect)) {
                        bullet.setState(Bullet::BulletState::Inactive);
                        enemy.setState(Enemy::EnemyState::Inactive);

                        // Animation bomb
                        Bomb bomb(enemy.getX(), enemy.getY());
                        bomb.setState(Bomb::BombState::Active);
                        bombs.push_back(bomb);

                        // ajouter les notes chaque impact
                        scoreManager.setPlayerScore(scoreManager.getPlayerScore() + 200);

                        //播放音效
                        setBombSound(true);
                    }
                }
            }
        }

        // 检查玩家与敌机的碰撞
        //Vérifier les collisions entre les joueurs et les avions ennemis.
        Rect::My_Rect playerRect = player.getCollisionRect();
        Rect::My_Rect enemyRect = enemy.getCollisionRect();
        if (Rect::hasIntersection(&playerRect, &enemyRect)) {
            enemy.setState(Enemy::EnemyState::Inactive);
            currentState = GameState::GameOver;
        }
    }
    // 检查玩家与补给之间的碰撞
    //Vérifier qu'il n'y a pas de collisions directes entre les joueurs et les bonus_drop.
    for (auto& drop : drops) {

        Rect::My_Rect playerRect = player.getCollisionRect();
        Rect::My_Rect dropRect = drop.getCollisionRect();
        if (Rect::hasIntersection(&playerRect, &dropRect))
        {
            // 处理碰撞效果
            //Moins de points en cas de collision avec un malus.
            switch (drop.getType()) {
            case Drop::DropType::Bonus:
                scoreManager.setPlayerScore(scoreManager.getPlayerScore() - 50);
                break;
            //Augmentation de la vitesse de joueur.
            case Drop::DropType::SpeedBoost:
                if (player.getSpeed() < 15) {
                    player.setSpeed(player.getSpeed() + 10);
                    std::cout << "Speed Boost applied. New speed: " << player.getSpeed() << std::endl; //vitesse Boost
                }
                break;
            //Augmentation de la vitesse de tir.
            case Drop::DropType::FireRateBoost:
                if (getFireInterval() > 0.2) {
                    setFireInterval(getFireInterval() - 0.05);
                    std::cout << "Fire Rate Boost applied. New fire interval: " << getFireInterval() << std::endl;  //balles Boost
                }
                break;

            }

            // mettre drop etat = Inactive
            drop.setActive(false);
        }
}

}
void Game::resetGameObjects() {
    // Réinitialiser les variables du jeu
    player.reset();
    bombs.clear();
    // 重置玩家分数Réinitialiser les notes


    // 重置子弹为非激活状态
    for (Bullet &bullet : bullets) {
        bullet.reset();
    }

    // 重置敌机为非激活状态
    for (Enemy &enemy : enemies) {
        enemy.reset();
    }

}

//Traitement des achats.
Store::PurchaseState Game::purchaseWeapon(Bullet::BulletTrajectory weapon, int cost, ScoreManager &scoreManager) {
    int playerScore = scoreManager.getPlayerScore();
    if (playerScore >= cost) {
        scoreManager.setPlayerScore(playerScore - cost);
        std::cout<<"Buy Success"<<std::endl;
        return Store::PurchaseState::Success;
    }
    return Store::PurchaseState::Failure;
    std::cout<<"Buy Failure! You dont have:"<<cost<<std::endl;
}


void Game::fireBullet(Bullet::BulletTrajectory trajectory) {
    switch (currentTrajectory) {
        case Bullet::BulletTrajectory::Weapon2:
            fireMultipleBullets(trajectory, 2);
            break;
        case Bullet::BulletTrajectory::Weapon3:
            fireMultipleBullets(trajectory, 3);
            break;
        case Bullet::BulletTrajectory::Weapon4:
            fireMultipleBullets(trajectory, 4);
            break;
        case Bullet::BulletTrajectory::Weapon5:
            fireMultipleBullets(trajectory, 6);
            break;
        default:
            fireSingleBullet(trajectory);
            break;
    }
}

void Game::fireSingleBullet(Bullet::BulletTrajectory trajectory) {
    int playerX = player.getX();
    int playerY = player.getY();
    // 查找一个未激活的子弹
    //Rechercher les balles inactives
    Bullet *inactiveBullet = nullptr;
    for (Bullet &bullet : bullets) {
        if (bullet.getState() == Bullet::BulletState::Inactive) {
            inactiveBullet = &bullet;
            break;
        }
    }

    if (inactiveBullet != nullptr) {
        // 飞机对象具有 getX() 和 getY() 方法，返回飞机的位置**Retour à la position de l'avion
        int initialBulletX = playerX + 16;
        int initialBulletY = playerY -25;

        // Modifier la vitesse de la balle
        int bulletSpeed = 10;

        inactiveBullet->setState(Bullet::BulletState::Active);
        inactiveBullet->setX(initialBulletX);
        inactiveBullet->setY(initialBulletY);
        inactiveBullet->setSpeedX(0);
        inactiveBullet->setSpeedY(-bulletSpeed);
        inactiveBullet->setTrajectory(trajectory);
    }
};

void Game::fireMultipleBullets(Bullet::BulletTrajectory trajectory, int bulletCount) {
    int playerX = player.getX();
    int playerY = player.getY();
    float angleIncrement;


    // 寻找未激活的子弹，发射它们**Tirer des balles
    int bulletsFired = 0;
    for (Bullet &bullet : bullets) {
        if (bullet.getState() == Bullet::BulletState::Inactive) {
            bullet.setState(Bullet::BulletState::Active);
            bullet.setSpeed(10);
            bullet.setTrajectory(trajectory);

            // 根据轨迹和子弹数量设置子弹的初始位置
            //Réglage de la trajectoire des balles
            switch (trajectory) {
                case Bullet::BulletTrajectory::Weapon2:
                    if (bulletsFired == 0) {
                        bullet.setX(playerX);
                    } else {
                        bullet.setX(playerX+25);
                    }
                    bullet.setSpeedX(0);
                    bullet.setSpeedY(-10);
                    bullet.setY(playerY-25);
                    break;

                case Bullet::BulletTrajectory::Weapon3:
                    bullet.setX(playerX - 10 + bulletsFired * 25);
                    bullet.setY(playerY-25);
                    bullet.setSpeedX(0);
                    bullet.setSpeedY(-10);
                    break;

                case Bullet::BulletTrajectory::Weapon4:
                {
                    angleIncrement = 24.0 / (bulletCount - 1);
                    float angle1 = -12 + bulletsFired * angleIncrement;
                    bullet.setX(playerX+10);
                    bullet.setY(playerY-25);
                    bullet.setSpeedX(10 * cos((angle1 - 90) * M_PI / 180.0));
                    bullet.setSpeedY(10 * sin((angle1 - 90) * M_PI / 180.0));
                    break;
                }

                case Bullet::BulletTrajectory::Weapon5:
                {
                    angleIncrement = 40.0 / (bulletCount - 1);
                    float angle2 = -20.0 + bulletsFired * angleIncrement;
                    bullet.setX(playerX-25);
                    bullet.setY(playerY-25);
                    bullet.setSpeedX(10 * cos((angle2 - 90) * M_PI / 180.0));
                    bullet.setSpeedY(10 * sin((angle2 - 90) * M_PI / 180.0));
                    break;
                }

                default:
                    break;
            }

            bulletsFired++;
            if (bulletsFired >= bulletCount) {
                break;
            }
        }
    }
};


void Game::update() {

    // game update logic here
    m_map.mapPosition(scroll_speed);
    // update les balles
    for (Bullet &bullet : bullets) {
        if (bullet.getState() == Bullet::BulletState::Active) {
            bullet.update();
            // 检查子弹是否超出窗口边界
            //Surveillance des balles pour les hors-limites
            if (bullet.getY() < 0) {
            bullet.setState(Bullet::BulletState::Inactive);
            }
        }
    }
    if (autoFire) {
        // auto-fire logic here
        if (getMyTimer() - lastFireTime > fireInterval) {
            fireBullet(currentTrajectory); // 使用fireEnhance替换fireBullet
            lastFireTime = getMyTimer();
        }
    }

    uint32_t currentTime = getMyTimer();

    // 更新敌机生成和速度
    //Sélection de la difficulté du jeu
    int speed;
    switch (currentLevel) {
        case LevelSelection::Easy:
            enemySpawnInterval = 2000;
            maxEnemyCount = 10;
            speed = 4;
            break;
        case LevelSelection::Normal:
            enemySpawnInterval = 1500;
            maxEnemyCount = 20;
            speed = 6;
            break;
        case LevelSelection::Hard:
            enemySpawnInterval = 1000;
            maxEnemyCount = 30;
            speed = 8;
            break;
        default:
            break;
    }

    if (currentTime - lastEnemySpawnTime >= enemySpawnInterval && enemies.size() < maxEnemyCount) {
        int randomX = rand() % 512;
        enemies.emplace_back(randomX, 0, enemySpawnInterval, speed);
        lastEnemySpawnTime = currentTime;
    }

    // Mise à jour de la vitesse de l'avion ennemi
    for (auto& enemy : enemies) {
        enemy.setSpeed(speed);
        enemy.update();
    }

    // 生成一个补给**Générer des bonus
    if (currentTime - lastDropSpawnTime >= dropSpawnInterval) {
        int randomX = rand() % 512;
        int randomType = rand() % 3;
        Drop::DropType dropType = static_cast<Drop::DropType>(randomType);
        drops.emplace_back(randomX, 0, 5, dropType);
        lastDropSpawnTime = currentTime;
    }
    //update drops
    for (Drop& drop : drops) {
        drop.update();
    }

    // Remove inactive drops
    drops.erase(std::remove_if(drops.begin(), drops.end(),
                            [](const Drop& drop) { return !drop.isActive(); }),
                drops.end());
    checkCollisions(); // 在update()函数中添加碰撞检测


    // 更新爆炸特效**Mise à jour de l'animation des explosions
    for (auto& bomb : bombs) {
        bomb.update(currentTime);
    }
}
