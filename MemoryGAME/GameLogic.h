#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <thread> 
#include <chrono> 
#include "Board.h"


class GameLogic {
private:
	Board& board;
	int score;
	std::pair<int, int> firstCard;
	std::pair<int, int> secondCard;
	bool firstCardFlipped;

public:
	GameLogic(Board& board);

	void flipCard(int row, int col);
	bool areMatches() const;
	int getScore() const;
	void resetGame();
};

#endif 
