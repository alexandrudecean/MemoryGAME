#include "Board.h"
#include "Observer.h"
#include <algorithm>
#include <random>
#include <stdexcept>


Board::Board(int rows, int cols) : rows(rows), cols(cols) {
	if (rows <= 0 || cols <= 0) {
		throw std::invalid_argument("Rows and columns must be positive integers.");
	}
}

void Board::initializeBoard() {
    cards.clear();

    int totalCards = rows * cols;
    if (totalCards % 2 != 0) {
        throw std::logic_error("Board must have an even number of cells to create pairs.");
    }

    std::vector<std::string> imagePaths = {
        "../images/1.jpg",
        "../images/2.jpg",
        "../images/3.jpg",
        "../images/4.jpg"
    };

    std::vector<Card> cardSet;
    int pairCount = totalCards / 2;
    for (int i = 0; i < pairCount; ++i) {
        int imageIndex = i % imagePaths.size();
        cardSet.emplace_back(i + 1, imagePaths[imageIndex]);
        cardSet.emplace_back(i + 1, imagePaths[imageIndex]);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cardSet.begin(), cardSet.end(), g);

    int index = 0;
    for (int i = 0; i < rows; ++i) {
        std::vector<Card> rowCards;
        for (int j = 0; j < cols; ++j) {
            rowCards.push_back(cardSet[index++]);
        }
        cards.push_back(rowCards);
    }

	notifyFrontend(0);
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
	if (row < 0 || row >= rows || col < 0 || col >= cols) {
		throw std::out_of_range("Card position out of range.");
	}
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
			observer->updateResult(score);
			observer->displayBoard(getRows(), getCols(), getCards());
		}
	}
}