#include "GameLogic.h"

GameLogic::GameLogic(Board& board) : board(board), score(0), firstCardFlipped(false) {}

void GameLogic::flipCard(int row, int col) {
	if (row >= 0 && row < board.getRows() && col >= 0 && col < board.getCols()) {
		if (!firstCardFlipped) {
			firstCard = { row, col };
			firstCardFlipped = true;

			board.getCard(row, col).flip();
			board.notifyFrontend(score);
		}
		else if (firstCard != std::make_pair(row, col)) {
			secondCard = { row, col };
			firstCardFlipped = false;

			board.getCard(row, col).flip();
			board.notifyFrontend(score);

			if (areMatches()) {
				score++;
				board.notifyFrontend(score);

				if (score == (board.getRows() * board.getCols()) / 2) {
					board.notifyGameEnded();
				}
			}
			else {
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));

				board.getCard(firstCard.first, firstCard.second).flip();
				board.getCard(secondCard.first, secondCard.second).flip();
				board.notifyFrontend(score);
			}
		}
	}
}

void GameLogic::resetGame() {
	score = 0;
	firstCardFlipped = false;
	board.initializeBoard();
}

bool GameLogic::areMatches() const {
	const Card& card1 = board.getCard(firstCard.first, firstCard.second);
	const Card& card2 = board.getCard(secondCard.first, secondCard.second);

	return card1.getId() == card2.getId();
}

int GameLogic::getScore() const
{
	return score;
}
