#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Card.h"
#include "Subject.h"
#include <iostream>

class Board : public Subject {
private:
    int rows;
    int cols;
    std::vector<std::vector<Card>> cards;

public:
    Board(int rows, int cols);

    void initializeBoard();
    void resetBoard();
    void incrementScore(); // Incrementează scorul
    int getScore() const;  // Obține scorul curent
    int getMaxScore() const; // Obține scorul maxim
    int score;    // Scorul curent
    int maxScore; // Scorul maxim pentru rundă
    void setScore(int newScore);


    int getRows() const;
    int getCols() const;
    const std::vector<std::vector<Card>>& getCards() const;
    const Card& getCard(int row, int col) const;
    Card& getCard(int row, int col);

    void notifyFrontend(int score);
    void addObserver(Observer* observer);
    void scoreUpdated(int newScore);
};

#endif // BOARD_H
