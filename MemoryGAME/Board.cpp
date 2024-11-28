#include "Board.h"
#include "Observer.h"

Board::Board(int rows, int cols) : rows(rows), cols(cols) {}

void Board::initializeBoard() {
    // Creează setul de cărți
    std::vector<Card> cardSet = {
     Card(1, "../images/wolf.jpg"), Card(1, "../images/wolf.jpg"),
     Card(2, "../images/car.jpg"), Card(2, "../images/car.jpg"),
     Card(3, "../images/flower.jpg"), Card(3, "../images/flower.jpg"),
     Card(4, "../images/dice.jpg"), Card(4, "../images/dice.jpg")
    };


    int index = 0;
    for (int i = 0; i < rows; ++i) {
        std::vector<Card> rowCards;
        for (int j = 0; j < cols; ++j) {
            rowCards.push_back(cardSet[index++]);
        }
        cards.push_back(rowCards);
    }

    // Notifică frontend-ul că tabla a fost creată
    notifyFrontend(0);
}


const Card& Board::getCard(int row, int col) const {
    return cards[row][col];
}

int Board::getRows() const {
    return rows;
}

int Board::getCols() const {
    return cols;
}

const std::vector<std::vector<Card>>& Board::getCards() const {
    return cards;
}

Card& Board::getCard(int row, int col) {
    return cards[row][col];
}

void Board::addObserver(Observer* observer) {
    if (observer) {
        observers.push_back(observer);
    }
}

void Board::notifyFrontend(int score) {
    for (auto observer : observers) {
        if (observer) {
            observer->updateResult(score); // Actualizează scorul în frontend
            observer->displayBoard(getRows(), getCols(), getCards()); // Actualizează tabla de joc
        }
    }
}
