/**
 * @file ScoreManager.cpp
 * @brief Fichier de code source pour la classe ScoreManager
 */
#include "ScoreManager.h"

ScoreManager::ScoreManager() : playerScore(0), highScore(0), totalScore(0) { // 初始化 totalScore 为 0
    loadScore();
}

ScoreManager::~ScoreManager() {
    saveScore();
}

int ScoreManager::getPlayerScore() const {
    return playerScore;
}

void ScoreManager::setPlayerScore(int score) {
    playerScore = score;
}

int ScoreManager::getHighScore() const {
    return highScore;
}

void ScoreManager::setHighScore(int score) {
    highScore = score;
}

void ScoreManager::loadScore() {
    std::ifstream scoreFile("src/txt/records.txt");

    if (!scoreFile) {
        std::cerr << "Error opening scores.txt for reading_loadScore" << std::endl;
        return;
    }

    scoreFile >> playerScore;
    scoreFile >> highScore;

    scoreFile.close();
}

void ScoreManager::saveScore() {
    std::ofstream scoreFile("src/txt/scores.txt");

    if (!scoreFile) {
        std::cerr << "Error opening scores.txt for saveScore" << std::endl;
        return;
    }

    if (playerScore > highScore) {
        highScore = playerScore;
    }

    scoreFile << playerScore << std::endl;
    scoreFile << "Highest record: "<< highScore << std::endl;

    scoreFile.close();
}

void ScoreManager::recordGame(int score, float gameTime) {
    std::ofstream recordFile("/src/txt/records.txt", std::ios::app);

    if (!recordFile) {
        std::cerr << "Error opening records.txt for recordGame" << std::endl;
        return;
    }

    recordFile << "Score: " << score << ", Time: " << gameTime << "s" << std::endl;
    totalScore += score;
    recordFile << "Total: " << totalScore << std::endl;; // 累加每场游戏的分数到总积分

    recordFile.close();
}

int ScoreManager::getTotalScore() {
    return totalScore;
}
void ScoreManager::updateHighScore(int score) {
    if (score > highScore) {
        highScore = score;
        saveScore();
    }
}
