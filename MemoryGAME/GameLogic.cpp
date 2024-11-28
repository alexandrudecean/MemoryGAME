#include "GameLogic.h"

GameLogic::GameLogic(Board& board) : board(board), score(0), firstCardFlipped(false) {}

void GameLogic::flipCard(int row, int col) {
    if (row >= 0 && row < board.getRows() && col >= 0 && col < board.getCols()) {
        if (!firstCardFlipped) {
            // Prima carte întoarsă
            firstCard = { row, col };
            firstCardFlipped = true;

            // Întoarce prima carte și notifică frontend-ul
            board.getCard(row, col).flip();
            board.notifyFrontend(score); // Transmite scorul către frontend
        }
        else {
            // A doua carte întoarsă
            secondCard = { row, col };
            firstCardFlipped = false;

            // Întoarce a doua carte și notifică frontend-ul
            board.getCard(row, col).flip();
            board.notifyFrontend(score);

            // Verifică dacă există potrivire
            if (areMatches()) {
                score++; // Crește scorul
                board.notifyFrontend(score); // Transmite scorul actualizat
            }
            else {
                // Dacă nu există potrivire, resetează starea cărților
                board.getCard(firstCard.first, firstCard.second).flip();
                board.getCard(secondCard.first, secondCard.second).flip();
                board.notifyFrontend(score); // Transmite scorul fără modificări
            }
        }
    }
}



bool GameLogic::areMatches() const {
    const Card& card1 = board.getCard(firstCard.first, firstCard.second);
    const Card& card2 = board.getCard(secondCard.first, secondCard.second);

    return card1.getId() == card2.getId(); // Compară ID-urile cărților
}
