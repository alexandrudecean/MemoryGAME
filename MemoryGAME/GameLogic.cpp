#include "GameLogic.h"

GameLogic::GameLogic(Board& board) : board(board), score(0), firstCardFlipped(false) {}

void GameLogic::flipCard(int row, int col) {
    if (row >= 0 && row < board.getRows() && col >= 0 && col < board.getCols()) {
        if (!firstCardFlipped) {
            // Prima carte întoarsă
            firstCard = { row, col };
            firstCardFlipped = true;

            // Întoarce prima carte și notifică frontend-ul
            board.getCard(row, col).flip(); // Afișează imaginea primei cărți
            board.notifyFrontend(score); // Notifică frontend-ul despre actualizarea tablei
        }
        else {
            // A doua carte întoarsă
            secondCard = { row, col };
            firstCardFlipped = false;

            // Întoarce a doua carte și notifică frontend-ul
            board.getCard(row, col).flip(); // Afișează imaginea celei de-a doua cărți
            board.notifyFrontend(score); // Actualizează frontend-ul cu ambele imagini

            // Verifică dacă există potrivire
            if (areMatches()) {
                // Cărțile se potrivesc, rămân afișate
                score++; // Crește scorul
                board.notifyFrontend(score); // Notifică frontend-ul despre scor
            }
            else {
                // Cărțile nu se potrivesc, se întorc la alb după un delay
                std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Delay de 1 secundă

                // Resetează cărțile la starea inițială
                board.getCard(firstCard.first, firstCard.second).flip(); // Revine la alb prima carte
                board.getCard(secondCard.first, secondCard.second).flip(); // Revine la alb a doua carte
                board.notifyFrontend(score); // Notifică frontend-ul pentru a reseta starea
            }
        }
    }
}





bool GameLogic::areMatches() const {
    const Card& card1 = board.getCard(firstCard.first, firstCard.second);
    const Card& card2 = board.getCard(secondCard.first, secondCard.second);

    return card1.getId() == card2.getId(); // Compară ID-urile cărților
}
