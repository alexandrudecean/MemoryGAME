#ifndef OBSERVER_H
#define OBSERVER_H

#include "Card.h"
#include "Board.h"

class Observer {
public:
    virtual ~Observer() = default;
    virtual void updateResult(int result) = 0; 
    virtual void displayBoard(int rows, int cols, const std::vector<std::vector<Card>>& cards) = 0;
    virtual void gameEnded() = 0;
};

#endif
