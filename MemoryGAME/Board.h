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

    void initializeBoard(); // Creează tabla de joc
    int getRows() const;    // Returnează numărul de rânduri
    int getCols() const;    // Returnează numărul de coloane

    const std::vector<std::vector<Card>>& getCards() const;            // Returnează un Card modificabil
    const Card& getCard(int row, int col) const; // Returnează un Card constant
    Card& getCard(int row, int col);
    void notifyFrontend(int score);// Notifică frontend-ul despre schimbări
    void addObserver(Observer* observer);

};

#endif // BOARD_H
