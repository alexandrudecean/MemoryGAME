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
    int getRows() const;   
    int getCols() const;    

    const std::vector<std::vector<Card>>& getCards() const;           
    const Card& getCard(int row, int col) const;
    Card& getCard(int row, int col);
    void notifyFrontend(int score);
    void addObserver(Observer* observer);


};

#endif
