#include "Board.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace BackendTests {
	TEST(BoardTests, InitializeBoardFillsCorrectDimensions) {
		Board board(2, 4);
		board.initializeBoard();

		EXPECT_EQ(board.getRows(), 2);
		EXPECT_EQ(board.getCols(), 4);

		const auto& cards = board.getCards();
		EXPECT_EQ(cards.size(), 2);
		EXPECT_EQ(cards[0].size(), 4);
	}

	TEST(BoardTests, InitializeBoardCreatesUniquePairs) {
		Board board(2, 4);
		board.initializeBoard();

		const auto& cards = board.getCards();
		std::map<int, int> cardCounts;

		for (const auto& row : cards) {
			for (const auto& card : row) {
				cardCounts[card.getId()]++;
			}
		}

		for (const auto& pair : cardCounts) {
			EXPECT_EQ(pair.second, 2);
		}

		EXPECT_EQ(cardCounts.size(), 4);
	}

	TEST(BoardTests, ReinitializeBoardShufflesCards) {
		Board board(2, 4);
		board.initializeBoard();

		auto firstConfig = board.getCards();
		board.initializeBoard();
		auto secondConfig = board.getCards();

		EXPECT_NE(firstConfig, secondConfig);
	}

	TEST(BoardTests, GetCardReturnsCorrectCard) {
		Board board(2, 4);
		board.initializeBoard();

		const Card& card = board.getCard(0, 0);
		EXPECT_TRUE(card.getId() >= 1 && card.getId() <= 4);
	}

	TEST(BoardTests, ModifyCardStateIsReflected) {
		Board board(2, 4);
		board.initializeBoard();

		Card& card = board.getCard(0, 0);
		card.flip();

		EXPECT_TRUE(board.getCard(0, 0).isFlipped());
	}

	TEST(BoardTests, BoardDimensionsAreCorrect) {
		Board board(3, 5);

		EXPECT_EQ(board.getRows(), 3);
		EXPECT_EQ(board.getCols(), 5);
	}

	TEST(BoardTests, AllCardsInitiallyNotFlipped) {
		Board board(2, 4);
		board.initializeBoard();

		const auto& cards = board.getCards();
		for (const auto& row : cards) {
			for (const auto& card : row) {
				EXPECT_FALSE(card.isFlipped());
			}
		}
	}



	// EDGE CASES
	TEST(BoardTests, InvalidDimensions) {
		EXPECT_THROW(Board(-1, 4), std::invalid_argument);
		EXPECT_THROW(Board(4, -1), std::invalid_argument);
		EXPECT_THROW(Board(0, 0), std::invalid_argument);
	}

	TEST(BoardTests, GetCardOutOfBounds) {
		Board board(2, 4);
		board.initializeBoard();

		EXPECT_THROW(board.getCard(-1, 0), std::out_of_range);
		EXPECT_THROW(board.getCard(0, 5), std::out_of_range);
		EXPECT_THROW(board.getCard(2, 0), std::out_of_range);
	}

	TEST(BoardTests, ReinitializeWithDifferentDimensions) {
		Board board(2, 4);
		board.initializeBoard();

		EXPECT_EQ(board.getRows(), 2);
		EXPECT_EQ(board.getCols(), 4);

		board = Board(3, 6);
		board.initializeBoard();

		EXPECT_EQ(board.getRows(), 3);
		EXPECT_EQ(board.getCols(), 6);
	}

	TEST(BoardTests, LargeBoardInitialization) {
		Board board(100, 100);
		EXPECT_NO_THROW(board.initializeBoard());

		const auto& cards = board.getCards();
		EXPECT_EQ(cards.size(), 100);
		EXPECT_EQ(cards[0].size(), 100);
	}

}


