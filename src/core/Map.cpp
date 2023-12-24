/**
 * @file Map.cpp
 * @brief Fichier de code source pour la classe Map
 */
#include "Map.h"

Map::Map()
    : width_(512), height_(768), map1_posY(-768), map2_posY(0) {
}

void Map::mapPosition(int scroll_speed) {
    map1_posY += scroll_speed;
    if (map1_posY >= 768) {
        map1_posY = -768 + scroll_speed;
    }

    map2_posY += scroll_speed;
    if (map2_posY >= 768) {
        map2_posY = -768 + scroll_speed;
    }
}

int Map::getWidth() const {
    return width_;
}

int Map::getHeight() const {
    return height_;
}


int Map::getMap1PosY() const {
    return map1_posY;
}

int Map::getMap2PosY() const {
    return map2_posY;
}
