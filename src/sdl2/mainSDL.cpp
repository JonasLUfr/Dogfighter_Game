/**
 * @file sdlGame.cpp
 * @brief Fichier de code source pour la classe sdlGame
 */
#include "mainSDL.h"
using namespace std;
#include <iostream>
#include <sstream>
#include <iomanip>

sdlGame::sdlGame(const std::string& title, int width, int height)
    : windowWidth(512), windowHeight(768), title("Dogfighter"), isRunning(true)
{
    // Initialize SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    // Create window
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    if(TTF_Init() == -1)
    {
        std::cout << "TTF_init is failed: " << TTF_GetError() << std::endl;
        isRunning = false;
    }
}

sdlGame::~sdlGame() {
    cleanUpSDL();
}

bool sdlGame::initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "SDL initialization failed: " << SDL_GetError() << endl;
        SDL_Quit();
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, windowWidth, windowHeight);
    // 初始化 SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        cout << "SDL_image initialization error: " << IMG_GetError() << endl;
        return false;
    }
    // Load main menu background texture
    SDL_Surface *mainMenuBackgroundSurface = IMG_Load("data/backGroundMenu.jpg");
    mainMenuBackgroundTexture = SDL_CreateTextureFromSurface(renderer, mainMenuBackgroundSurface);
    SDL_FreeSurface(mainMenuBackgroundSurface);

    // charger Jouer image
    SDL_Surface *player_surface = IMG_Load("data/hero.png");
    // charger Jouer texture
    playerTexture = SDL_CreateTextureFromSurface(renderer, player_surface);
    SDL_FreeSurface(player_surface); // 释放已创建纹理的表面
     // charger enenmy image
    enemyTexture = IMG_LoadTexture(renderer, "data/img-plane_3.png");

    // charger tous les texture
    bg_texture1_easy = IMG_LoadTexture(renderer,"data/img_bg_level_1.jpg");
    bg_texture2_easy = IMG_LoadTexture(renderer,"data/img_bg_level_1.jpg");
    bg_texture1_normal = IMG_LoadTexture(renderer,"data/img_bg_level_3.jpg");
    bg_texture2_normal = IMG_LoadTexture(renderer,"data/img_bg_level_3.jpg");
    bg_texture1_hard = IMG_LoadTexture(renderer,"data/img_bg_level_5.jpg");
    bg_texture2_hard = IMG_LoadTexture(renderer,"data/img_bg_level_5.jpg");

    // charger les balles texture
    bulletTexture1 = IMG_LoadTexture(renderer, "data/bullet_1.png");
    bulletTexture2 = IMG_LoadTexture(renderer, "data/bullet_2.png");
    bulletTexture3 = IMG_LoadTexture(renderer, "data/bullet_3.png");
    bulletTexture4 = IMG_LoadTexture(renderer, "data/bullet_4.png");
    bulletTexture5 = IMG_LoadTexture(renderer, "data/bullet_5.png");

    //  charger les Drops texture
    dropTexture1 = IMG_LoadTexture(renderer, "data/dropTexture1.png");
    dropTexture2 = IMG_LoadTexture(renderer, "data/dropTexture2.png");
    dropTexture3 = IMG_LoadTexture(renderer, "data/dropTexture3.png");

    // charger les bomb texture
    for (int i = 1; i <= 7; ++i) {
        std::ostringstream oss;
        oss << "data/bomb-" << i << ".png";
        SDL_Surface* surface = IMG_Load(oss.str().c_str());
        if (!surface) {
         std::cout << "Failed to load bomb-" << i << ".png. Error: " << IMG_GetError() << std::endl;
    } else {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        bombTextures.push_back(texture);
    }
    }
    //font.ttf
    TTF_Init();
    pauseFont = TTF_OpenFont("data/font2.ttf", 64);
    scoreFont = TTF_OpenFont("data/font3.ttf", 24);
    gameOverFont = TTF_OpenFont("data/font2.ttf", 80); // 80 est la taille du texte
    titleFont = TTF_OpenFont("data/fontTitle.ttf", 64);
    menuFont = TTF_OpenFont("data/fontMenu.ttf", 36);
    //BackGroundMusic
    // Handle the error
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
    std::cerr << "Failed to initialize SDL audio: " << SDL_GetError() << std::endl;
    return -1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    std::cerr << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
    return -1;
    }
    menuMusic = Mix_LoadMUS("data/menu_music.mp3");
    gameMusic = Mix_LoadMUS("data/game_play_music.mp3");
    bombSound = Mix_LoadWAV("data/sound.wav");
    isMusicPaused = Mix_PlayingMusic() == 1; //pour le menu_pause
    return true;
}

void sdlGame::cleanUpSDL() {
    // Add clean up code for SDL_image, SDL_ttf, and SDL_mixer here

    SDL_DestroyTexture(bg_texture1_easy);
    SDL_DestroyTexture(bg_texture1_hard);
    SDL_DestroyTexture(bg_texture1_normal);
    SDL_DestroyTexture(bg_texture2_easy);
    SDL_DestroyTexture(bg_texture2_hard);
    SDL_DestroyTexture(bg_texture2_normal);
    SDL_DestroyTexture(bulletTexture1);
    SDL_DestroyTexture(bulletTexture2);
    SDL_DestroyTexture(bulletTexture3);
    SDL_DestroyTexture(enemyTexture);
    SDL_DestroyTexture(startGameTexture);
    SDL_DestroyTexture(controlsTexture);
    SDL_DestroyTexture(levelTexture);
    SDL_DestroyTexture(storeTexture);
    SDL_DestroyTexture(normalTexture);
    SDL_DestroyTexture(easyTexture);
    SDL_DestroyTexture(hardTexture);
    SDL_DestroyTexture(dropTexture1);
    SDL_DestroyTexture(dropTexture2);
    SDL_DestroyTexture(dropTexture3);

    // 释放爆炸特效纹理
    for (auto& texture : bombTextures) {
        if (texture) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }
    }
    bombTextures.clear();

    // Menu
    SDL_DestroyTexture(mainMenuBackgroundTexture);
    SDL_DestroyTexture(texture);

    if (gameOverFont||pauseFont||scoreFont||titleFont||menuFont) {
        TTF_CloseFont(pauseFont);
        TTF_CloseFont(scoreFont);
        TTF_CloseFont(gameOverFont);
        TTF_CloseFont(titleFont);
        TTF_CloseFont(menuFont);
        pauseFont = nullptr;
        scoreFont = nullptr;
        gameOverFont = nullptr;
        titleFont = nullptr;
        menuFont = nullptr;
    };

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    if (menuMusic) {
            Mix_FreeMusic(menuMusic);
            menuMusic = nullptr;
        }

        if (gameMusic) {
            Mix_FreeMusic(gameMusic);
            gameMusic = nullptr;
        }

        if (bombSound) {
            Mix_FreeChunk(bombSound);
            bombSound = nullptr;
        }
    Mix_CloseAudio();


    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

void sdlGame::run() {
    Uint32 lastFrameTime = SDL_GetTicks();

    while (isRunning) {
        handleEvents();
        // 添加用于更新自定义计时器的代码
        Uint32 currentFrameTime = SDL_GetTicks();
        Uint32 deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;
        game.updateMyTimer(deltaTime);
        if (game.currentState==Game::GameState::Running)
        {
            game.update();
        }


        render(); // 在用 render 函数
        updateMusic(); // 在主循环中调用 updateMusic

        SDL_Delay(1000 / 60); // Limit the frame rate to 60 FPS
    }
}


void sdlGame::playMusic(Mix_Music* music) {
    Mix_PlayMusic(music, -1);  // -1 pour la lecture de musique en boucle
};

void sdlGame::stopMusic() {
    Mix_HaltMusic();
}

void sdlGame::pauseMusic() {
    Mix_PauseMusic();
}

void sdlGame::resumeMusic() {
    Mix_ResumeMusic();
}

void sdlGame::updateMusic() {
    Mix_Music* targetMusic = nullptr;

    if (game.currentState == Game::GameState::MainMenu
        ||game.currentState == Game::GameState::Level
        ||game.currentState == Game::GameState::ControlMenu
        ||game.currentState == Game::GameState::Store)
    {
        targetMusic = menuMusic;
    } else if (game.currentState == Game::GameState::Running) {
        targetMusic = gameMusic;
        if(game.getBombSound()==true){
            Mix_PlayChannel(-1, bombSound, 0);
            game.setBombSound(false);
        }
    } else if (game.currentState == Game::GameState::GameOver) {
        targetMusic = menuMusic;
    }

    if (currentMusic != targetMusic) {
        stopMusic();
        playMusic(targetMusic);
        currentMusic = targetMusic;
    }
}

SDL_Texture* sdlGame::renderText(const std::string &text, TTF_Font* font, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void sdlGame::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {

        if (event.type == SDL_QUIT) {
            isRunning = false;
            std::cout << "SDL_QUIT event detected. isRunning set to false.\n";
        }

        switch (game.currentState) {
            case Game::GameState::MainMenu:
                handleMainMenuEvents(event);
                break;

            case Game::GameState::Level:
                handleLevelMenuEvents(event);
                break;

            case Game::GameState::Running:
                handleRunningEvents(event);
                break;

            case Game::GameState::ControlMenu:
                handleControlMenuEvents(event);
                break;

            case Game::GameState::Pause:
                handlePausedEvents(event);
                break;

            case Game::GameState::Store:
                handleStoreEvents(event);
                break;

            case Game::GameState::GameOver: // 添加此 case 以处理 GameOver 状态的事件
                handleGameOverEvents(event, SDL_GetTicks());
                break;

            default:
                break;
        }
    }
}

void sdlGame::handleRunningEvents(SDL_Event &event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE: // 处理 ESC 键事件**Touche ESC pour save le jeu
                game.save();
                game.setCurrentState(Game::GameState::MainMenu);
                break;
            case SDL_SCANCODE_Q: // 处理 Q 键事件**Touche Q pour quitter le jeu
                isRunning = false;
                break;
            default:
                break;
        }
    }
    if (!game.useMouseControl) {
        if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_UP:
                    game.runningInput('w');
                    break;
                case SDL_SCANCODE_LEFT:
                    game.runningInput('a');
                    break;

                case SDL_SCANCODE_DOWN:
                    game.runningInput('s');
                    break;

                case SDL_SCANCODE_RIGHT:
                    game.runningInput('d');
                    break;

                case SDL_SCANCODE_F:
                    game.runningInput('f');
                    break;

                case SDL_SCANCODE_P:
                    game.runningInput('p');
                    break;
                default:
                    break;
            }
        }
    } else if (game.useMouseControl && (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEMOTION)) {
        if (event.button.button == SDL_BUTTON_LEFT || event.type == SDL_MOUSEMOTION) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            game.getPlayer().setX(mouseX - 25);
            game.getPlayer().setY(mouseY - 25);
        }
    }if (event.type == SDL_QUIT) {
        isRunning = false;
    }
}

void sdlGame::handleGameOverEvents(SDL_Event &event, Uint32 gameTime) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                game.save();
                game.recordGame(game.getPlayerScore(), gameTime / 1000.0f);
                game.setCurrentState(Game::GameState::MainMenu);
                game.setPlayerScore(0);
                break;
            case SDLK_RETURN:
                game.save();
                game.recordGame(game.getPlayerScore(), gameTime / 1000.0f);
                game.setCurrentState(Game::GameState::Running);
                game.resetGameObjects();
                break;
            case SDLK_q:
                game.save();
                game.recordGame(game.getPlayerScore(), gameTime / 1000.0f);
                exit(0);
        }
    }
}

void sdlGame::handlePausedEvents(SDL_Event &event) {
    if (isMusicPaused) {
        pauseMusic();
    }
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p) {
        resumeMusic();
        game.setCurrentState(Game::GameState::Running);
    }
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q) {
        game.save();
        game.recordGame(game.getPlayerScore(), SDL_GetTicks() / 1000.0f);
        exit(0);
    }
}

void sdlGame::handleMainMenuEvents(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_UP:
                    game.menuInput('w');
                    break;

                case SDL_SCANCODE_DOWN:
                    game.menuInput('s');
                    break;

                case SDL_SCANCODE_RETURN:
                    game.menuInput('\r');
                    break;
                case SDL_SCANCODE_Q:
                    game.menuInput('q');
                    isRunning=false;
                    break;

                default:
                    break;
    }
}
}

void sdlGame::handleLevelMenuEvents(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_UP:
                game.levelInput('w');
                break;

            case SDL_SCANCODE_DOWN:
                game.levelInput('s');
                break;

            case SDL_SCANCODE_RETURN:
                game.levelInput('\r');
                break;

            case SDL_SCANCODE_ESCAPE:
                game.setCurrentState(Game::GameState::MainMenu);
                break;

            case SDL_SCANCODE_Q:
                isRunning = false;
                break;

            default:
                break;
        }
    }

}

void sdlGame::handleStoreEvents(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_UP:
                game.storeInput('w');
                break;

            case SDL_SCANCODE_DOWN:
                game.storeInput('s');
                break;

            case SDL_SCANCODE_RETURN:
                game.storeInput('\r');
                break;

            case SDL_SCANCODE_ESCAPE:
                game.setCurrentState(Game::GameState::MainMenu);
                break;

            case SDL_SCANCODE_Q:
                isRunning = false;
                break;

            default:
                break;
        }
    }
}

void sdlGame::handleControlMenuEvents(SDL_Event &event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_UP:
                game.controlInput('w');
                break;

            case SDL_SCANCODE_DOWN:
                game.controlInput('s');
                break;

            case SDL_SCANCODE_RETURN:
                game.controlInput('\r');
                break;

            case SDL_SCANCODE_ESCAPE:
                game.setCurrentState(Game::GameState::MainMenu);
                break;

            case SDL_SCANCODE_Q:
                isRunning = false;
                break;

            default:
                break;
        }
    }

}

//render les notes dans le ficher
void sdlGame::renderScore() {
    int playerScore = game.getScoreManager().getPlayerScore();
    int highScore = game.getScoreManager().getHighScore();

    std::stringstream scoreText;
    scoreText << "SCORE: " << playerScore << "    HIGH SCORE: " << highScore<< "\n";;
    scoreText << "ESC-STORE ";

    SDL_Surface* scoreSurface = TTF_RenderText_Solid(scoreFont, scoreText.str().c_str(), {255, 255, 255});
    if (!scoreSurface) {
        std::cerr << "Failed to render score text: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    if (!scoreTexture) {
        std::cerr << "Failed to create score texture: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Rect scoreRect;
    scoreRect.x = 20;
    scoreRect.y = 20;
    SDL_QueryTexture(scoreTexture, NULL, NULL, &scoreRect.w, &scoreRect.h);
    //scoreRect.h = 2 * scoreRect.h;
    SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);

    // 释放资源
    SDL_FreeSurface(scoreSurface);
    SDL_DestroyTexture(scoreTexture);
}

void sdlGame::renderPausedScore() {
    int playerScore = game.getScoreManager().getPlayerScore();

    std::stringstream scoreText;
    scoreText << "SCORE: " << playerScore;

    SDL_Surface* scoreSurface = TTF_RenderText_Solid(scoreFont, scoreText.str().c_str(), {255, 255, 255});
    if (!scoreSurface) {
        std::cerr << "Failed to render score text: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    if (!scoreTexture) {
        std::cerr << "Failed to create score texture: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Rect scoreRect;
    scoreRect.x = (windowWidth - scoreSurface->w) / 2;
    scoreRect.y = (windowHeight - scoreSurface->h) / 2 + 50;
    scoreRect.w = scoreSurface->w;
    scoreRect.h = scoreSurface->h;

    SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);

    // 释放资源
    SDL_FreeSurface(scoreSurface);
    SDL_DestroyTexture(scoreTexture);
}

void sdlGame::renderPausedScreen() {
    // 使用先前渲染的画面作为背景 ** Rendu des images précédentes ici
    SDL_SetRenderTarget(renderer, nullptr);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);

    // 渲染半透明灰色覆盖层 ** Rendu de l'arrière-plan_pause
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 128);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_Rect rect = {0, 0, windowWidth, windowHeight};
    SDL_RenderFillRect(renderer, &rect);

    // 渲染 "PAUSE" 文字
    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Blended(pauseFont, "P-PAUSE & Q-QUIT", textColor);

    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect;
    textRect.x = (windowWidth - textSurface->w) / 2;
    textRect.y = (windowHeight - textSurface->h) / 2;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;

    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

    // 渲染暂停时的分数
    renderPausedScore();

    // 销毁临时创建的资源
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}

void sdlGame::renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y) {
    // 创建目标矩形，用于设置纹理渲染的位置和大小
    //Créer le rectangle cible, sa position et sa taille.
    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
    SDL_QueryTexture(texture, nullptr, nullptr, &dstRect.w, &dstRect.h);

    // 将纹理渲染到目标矩形上
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
}

void sdlGame::renderMainMenu() {
    int windowWidth = 512;
    int windowHeight = 768;
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    // Render main menu background
    SDL_Rect srcRect = {0, 0, windowWidth, windowHeight};
    SDL_Rect destRect = {0, 0, windowWidth, windowHeight};
    SDL_RenderCopy(renderer, mainMenuBackgroundTexture, &srcRect, &destRect);


    // 渲染标题
    SDL_Color whiteColor = {255, 255, 255, 255};
    SDL_Color blackColor = {0, 0, 0, 255};
    SDL_Texture* titleText = renderText("DogFighter", titleFont, whiteColor);
    int titleTextWidth, titleTextHeight;
    SDL_QueryTexture(titleText, nullptr, nullptr, &titleTextWidth, &titleTextHeight);
    renderTexture(titleText, renderer, (windowWidth - titleTextWidth) / 2, windowHeight / 4 - titleTextHeight / 2);
    SDL_DestroyTexture(titleText);


    int positionX = windowWidth / 4 ;
    int positionY = 3 * windowHeight / 4 - 120;

    // 渲染 "Start Game" 菜单项
    startGameTexture = renderText("Start Game", menuFont, game.menuSelection == 0 ? whiteColor : blackColor);
    renderTexture(startGameTexture, renderer, positionX, positionY);



    // 渲染 "Controls" 菜单项
    controlsTexture = renderText("Control", menuFont, game.menuSelection == 1 ? whiteColor : blackColor);
    renderTexture(controlsTexture, renderer, positionX, positionY + 60);


    // 渲染 "Level" 菜单项
    levelTexture = renderText("Level", menuFont, game.menuSelection == 2 ? whiteColor : blackColor);
    renderTexture(levelTexture, renderer, positionX, positionY + 120);


    // 渲染 "Store" 菜单项
    storeTexture = renderText("Store", menuFont, game.menuSelection == 3 ? whiteColor : blackColor);
    renderTexture(storeTexture, renderer, positionX, positionY + 180);

}

void sdlGame::renderLevelMenu(){
    int windowWidth = 512;
    int windowHeight = 768;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

     // Render main menu background
    SDL_Rect srcRect = {0, 0, windowWidth, windowHeight};
    SDL_Rect destRect = {0, 0, windowWidth, windowHeight};
    SDL_RenderCopy(renderer, mainMenuBackgroundTexture, &srcRect, &destRect);

    int positionX = windowWidth / 2 - 100 ;
    int positionY = windowHeight;

    SDL_Color whiteColor = {255, 255, 255, 255};
    SDL_Color blackColor = {0, 0, 0, 255};


// 渲染 "Easy" 菜单项
    easyTexture = renderText("Easy", menuFont, game.levelMenuSelection == 0 ? whiteColor : blackColor);
    renderTexture(easyTexture, renderer, positionX, positionY / 4);


    // 渲染 "Normal" 菜单项
    normalTexture = renderText("Normal", menuFont, game.levelMenuSelection == 1 ? whiteColor : blackColor);
    renderTexture(normalTexture, renderer, positionX, positionY / 2);


    // 渲染 "Hard" 菜单项
    hardTexture = renderText("Hard", menuFont, game.levelMenuSelection == 2 ? whiteColor : blackColor);
    renderTexture(hardTexture, renderer, positionX, 3 * positionY / 4);

};

void sdlGame::renderControlMenu() {

    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

     // Render main menu background
    SDL_Rect srcRect = {0, 0, windowWidth, windowHeight};
    SDL_Rect destRect = {0, 0, windowWidth, windowHeight};
    SDL_RenderCopy(renderer, mainMenuBackgroundTexture, &srcRect, &destRect);

    SDL_Color whiteColor = {255, 255, 255, 255};
    SDL_Color blackColor = {0, 0, 0, 255};

    // 渲染 "Keyboard" 选项
    keyboardTexture = renderText("Keyboard", menuFont, game.controlSelection == 0 ? whiteColor : blackColor);
    renderTexture(keyboardTexture, renderer, 100, 100);


    // 渲染 "Mouse" 选项
    mouseTexture = renderText("Mouse", menuFont, game.controlSelection == 1 ? whiteColor : blackColor);
    renderTexture(mouseTexture, renderer, 100, 200);

    SDL_DestroyTexture(keyboardTexture);
    SDL_DestroyTexture(mouseTexture);
}

void sdlGame::renderStore() {
    int windowWidth = 512;
    int windowHeight = 768;

    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render store background, similar to the main menu background rendering
    SDL_Rect srcRect = {0, 0, windowWidth, windowHeight};
    SDL_Rect destRect = {0, 0, windowWidth, windowHeight};
    SDL_RenderCopy(renderer, mainMenuBackgroundTexture, &srcRect, &destRect);

    // Render store title
    SDL_Color whiteColor = {255, 255, 255, 255};
    SDL_Color blackColor = {0, 0, 0, 255};
    SDL_Texture* storeTitleText = renderText("Store", titleFont, whiteColor);
    int titleWidth, titleHeight;
    SDL_QueryTexture(storeTitleText, nullptr, nullptr, &titleWidth, &titleHeight);
    int titleX = (windowWidth - titleWidth) / 2;
    int titleY = windowHeight / 4 - titleHeight / 2;
    renderTexture(storeTitleText, renderer, titleX, titleY);
    SDL_DestroyTexture(storeTitleText);  // 添加此行以销毁纹理
    std::vector<std::string> weaponNames = {"Weapon_2 $50", "Weapon_3 $100", "Weapon_4 $200", "Weapon_5 $400"};

    int menuItemX = windowWidth / 2;
    int menuItemY = windowHeight / 2;

    for (size_t i = 0; i < weaponNames.size(); ++i) {
        SDL_Color textColor = (i == game.storeMenuSelection) ? whiteColor : blackColor;
        SDL_Texture* menuItemText = renderText(weaponNames[i], menuFont, textColor);

        int itemWidth, itemHeight;
        SDL_QueryTexture(menuItemText, nullptr, nullptr, &itemWidth, &itemHeight);

        int itemY = menuItemY + i * (itemHeight + 10);
        renderTexture(menuItemText, renderer, menuItemX - itemWidth / 2, itemY);
        SDL_DestroyTexture(menuItemText);  // 添加此行以销毁纹理
    }
    std::string scoreText = "Score: " + std::to_string(game.getScoreManager().getPlayerScore());
    SDL_Texture* scoreTexture = renderText(scoreText, menuFont, whiteColor);
    int scoreWidth, scoreHeight;
    SDL_QueryTexture(scoreTexture, nullptr, nullptr, &scoreWidth, &scoreHeight);
    int scoreX = 10;
    int scoreY = windowHeight - scoreHeight - 10;
    renderTexture(scoreTexture, renderer, scoreX, scoreY);
    SDL_DestroyTexture(scoreTexture);  // 添加此行以销毁纹理

}

void sdlGame::renderGameOver() {

    SDL_Color textColor = {255, 255, 255}; // 字体颜色：黑色
    SDL_Surface* textSurface = TTF_RenderText_Blended(gameOverFont, "GAME OVER", textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = {windowWidth / 2 - textSurface->w / 2, windowHeight / 2 - textSurface->h / 2, textSurface->w, textSurface->h};

    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

    SDL_FreeSurface(textSurface);

    // 渲染玩家分数**Rendu les notes
    std::string scoreText = "YOUR SCORES: " + std::to_string(game.getScoreManager().getPlayerScore());
    SDL_Color scoreColor = {255, 255, 255}; // 字体颜色：白色
    SDL_Surface* scoreSurface = TTF_RenderText_Blended(scoreFont, scoreText.c_str(), scoreColor);
    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    SDL_Rect scoreRect;
    scoreRect.x = (windowWidth - scoreSurface->w) / 2;
    scoreRect.y = (windowHeight - scoreSurface->h) / 2 + 100;
    scoreRect.w = scoreSurface->w;
    scoreRect.h = scoreSurface->h;

    SDL_RenderCopy(renderer, scoreTexture, nullptr, &scoreRect);

    SDL_FreeSurface(scoreSurface);

};

SDL_Rect sdlGame::MyRect_to_SDLRect(const Rect::My_Rect* rect) {
    SDL_Rect sdlRect;
    sdlRect.x = rect->x;
    sdlRect.y = rect->y;
    sdlRect.w = rect->w;
    sdlRect.h = rect->h;
    return sdlRect;
}

void sdlGame::render() {
    // 清除屏幕
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    //Rendre l'écran en fonction de l'état du jeu.
    switch (game.getCurrentState()) {
        case Game::GameState::MainMenu:
            renderMainMenu();
            break;
        case Game::GameState::Level:
            renderLevelMenu();
            break;
        case Game::GameState::ControlMenu:
            renderControlMenu();
            break;
        case Game::GameState::Pause:
            renderPausedScreen();
            break;
        case Game::GameState::Running:
            renderGame();
            break;
        case Game::GameState::GameOver:
            renderGameOver();
            break;
        case Game::GameState::Store:
            renderStore();
            break;
        default:
            break;
    }

    // 更新屏幕
    SDL_RenderPresent(renderer);
}

void sdlGame::renderGame() {
    // Rendu des écrans déroulants.
    SDL_Texture* current_bg_texture1;
    SDL_Texture* current_bg_texture2;

    switch (game.currentLevel) {
        //rendu les image difference selon les level du jeu
        case Game::LevelSelection::Easy:
            current_bg_texture1 = bg_texture1_easy;
            current_bg_texture2 = bg_texture2_easy;
            break;
        case Game::LevelSelection::Normal:
            current_bg_texture1 = bg_texture1_normal;
            current_bg_texture2 = bg_texture2_normal;
            break;
        case Game::LevelSelection::Hard:
            current_bg_texture1 = bg_texture1_hard;
            current_bg_texture2 = bg_texture2_hard;
            break;
        default:
            break;
    }

    // Rendu des écrans déroulants.
    SDL_Rect src_rect = {0, 0, windowWidth, windowHeight};
    SDL_Rect dest_rect1 = {0, game.getMap().getMap1PosY(), windowWidth, windowHeight};
    SDL_Rect dest_rect2 = {0, game.getMap().getMap2PosY(), windowWidth, windowHeight};
    SDL_RenderCopy(renderer, current_bg_texture1, &src_rect, &dest_rect1);
    SDL_RenderCopy(renderer, current_bg_texture2, &src_rect, &dest_rect2);

    // Rendu du joueur.
    SDL_Rect playerRect;
    playerRect.x = game.getPlayer().getX();
    playerRect.y = game.getPlayer().getY();
    playerRect.w = 50; // 假设玩家宽度为 50
    playerRect.h = 50; // 假设玩家高度为 50
    SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);

    // 渲染激活状态的子弹**Rendu des balles activées
    for (const Bullet &bullet : game.getBullets()) {
    if (bullet.getState() == Bullet::BulletState::Active) {
        // 使用 bulletTexture 渲染子弹
        SDL_Rect dstRect;
        dstRect.x = bullet.getX();
        dstRect.y = bullet.getY();
        Bullet::BulletTrajectory weaponType = game.getTrajectory(); // Traite les types de balles.
        switch (weaponType)
        {
        case Bullet::BulletTrajectory::Weapon1:
            SDL_QueryTexture(bulletTexture1, nullptr, nullptr, &dstRect.w, &dstRect.h);
            SDL_RenderCopy(renderer, bulletTexture1 , nullptr, &dstRect);
            break;
        case Bullet::BulletTrajectory::Weapon2:
            SDL_QueryTexture(bulletTexture2, nullptr, nullptr, &dstRect.w, &dstRect.h);
            SDL_RenderCopy(renderer, bulletTexture2 , nullptr, &dstRect);
            break;
        case Bullet::BulletTrajectory::Weapon3:
            SDL_QueryTexture(bulletTexture3, nullptr, nullptr, &dstRect.w, &dstRect.h);
            SDL_RenderCopy(renderer, bulletTexture3 , nullptr, &dstRect);
            break;
        case Bullet::BulletTrajectory::Weapon4:
            SDL_QueryTexture(bulletTexture4, nullptr, nullptr, &dstRect.w, &dstRect.h);
            SDL_RenderCopy(renderer, bulletTexture4 , nullptr, &dstRect);
            break;
        case Bullet::BulletTrajectory::Weapon5:
            SDL_QueryTexture(bulletTexture5, nullptr, nullptr, &dstRect.w, &dstRect.h);
            SDL_RenderCopy(renderer, bulletTexture5 , nullptr, &dstRect);
            break;
        default:
            break;
        }


        }
    }

    // Rendu d'un avion ennemi activé.
    for (const auto& enemy : game.getEnemies()) {
        if (enemy.getState() == Enemy::EnemyState::Active) {
            Rect::My_Rect myRect = enemy.getCollisionRect();
            SDL_Rect destRect = MyRect_to_SDLRect(&myRect);

            // Redimensionner les avions ennemis.
            destRect.w *= 2; // 将敌机宽度放大2倍* 2 fois
            destRect.h *= 2; // 将敌机高度放大2倍
            SDL_RenderCopy(renderer, enemyTexture, nullptr, &destRect);
            }
        }
        renderScore();
    // Rendu bomb animation
        for (const auto& bomb : game.getBombs()) {
            if (bomb.getState() == Bomb::BombState::Active) {
                int currentFrame = bomb.getCurrentFrame();
                SDL_Rect srcRect = {0, 0, 86, 68}; // 假设爆炸特效的尺寸为 64x64
                SDL_Rect destRect = {bomb.getX(), bomb.getY(), 64, 64};
                SDL_RenderCopy(renderer, bombTextures[currentFrame], &srcRect, &destRect);
            }
        }

    //Rendu des Drop_BONUS.
    for (const Drop &drop : game.getDrops()) {
        if(drop.isActive()){
            SDL_Rect dstRect;
            dstRect.x = drop.getX();
            dstRect.y = drop.getY();
            dstRect.w = 20;
            dstRect.h = 20;

            SDL_Texture* currentDropTexture;

            if (drop.getType() == Drop::DropType::Bonus) {
                currentDropTexture = dropTexture1;
            } else if (drop.getType() == Drop::DropType::FireRateBoost) {
                currentDropTexture = dropTexture2;
            } else if (drop.getType() == Drop::DropType::SpeedBoost) {
                currentDropTexture = dropTexture3;
            } else {
                continue; //Passer s'il n'y a pas de correspondance target.
            }

            SDL_RenderCopy(renderer, currentDropTexture, nullptr, &dstRect);

    }
    }
}
