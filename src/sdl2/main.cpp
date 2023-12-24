#include <iostream>

#include "mainSDL.h"

int main(int argc, char* argv[]) {
    
    sdlGame game("Dogfighter", 512, 768);
    game.initSDL();
    game.run();
    game.cleanUpSDL();

    return 0;
}