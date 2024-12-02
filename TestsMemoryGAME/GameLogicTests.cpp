#include "GameLogic.h"
#include "MockObserver.h"
#include "gtest/gtest.h"

namespace BackendTests {
	TEST(GameLogicTests, InitializationWorksCorrectly) {
		Board board(2, 2);
		GameLogic gameLogic(board);

		EXPECT_EQ(gameLogic.getScore(), 0);
	}

	TEST(GameLogicTests, FlipSingleCardWorksCorrectly) {
		Board board(2, 2);
		board.initializeBoard();
		GameLogic gameLogic(board);

		gameLogic.flipCard(0, 0);

		EXPECT_TRUE(board.getCard(0, 0).isFlipped());
		EXPECT_EQ(gameLogic.getScore(), 0);
	}

	TEST(GameLogicTests, MatchingCardsIncreasesScore) {
		Board board(2, 2);
		board.initializeBoard();

		board.getCard(0, 0) = Card(1, "../images/1.jpg");
		board.getCard(0, 1) = Card(1, "../images/1.jpg");

		GameLogic gameLogic(board);

		gameLogic.flipCard(0, 0);
		gameLogic.flipCard(0, 1);

		EXPECT_EQ(gameLogic.getScore(), 1);
		EXPECT_TRUE(board.getCard(0, 0).isFlipped());
		EXPECT_TRUE(board.getCard(0, 1).isFlipped());
	}

	TEST(GameLogicTests, NonMatchingCardsDoNotIncreaseScore) {
		Board board(2, 2);
		board.initializeBoard();

		board.getCard(0, 0) = Card(1, "../images/1.jpg");
		board.getCard(0, 1) = Card(2, "../images/2.jpg");

		GameLogic gameLogic(board);

		gameLogic.flipCard(0, 0);
		gameLogic.flipCard(0, 1);

		EXPECT_EQ(gameLogic.getScore(), 0);
		//Both cards flip back
		EXPECT_FALSE(board.getCard(0, 0).isFlipped());
		EXPECT_FALSE(board.getCard(0, 1).isFlipped());
	}

	TEST(GameLogicTests, ResetGameResetsState) {
		Board board(2, 2);
		board.initializeBoard();

		GameLogic gameLogic(board);

		gameLogic.flipCard(0, 0);
		gameLogic.resetGame();

		EXPECT_EQ(gameLogic.getScore(), 0);
		EXPECT_FALSE(board.getCard(0, 0).isFlipped());
		EXPECT_FALSE(board.getCard(0, 1).isFlipped());
	}

	//EDGE CASES

	TEST(GameLogicTests, FlippingSameCardTwice) {
		Board board(2, 2);
		board.initializeBoard();

		board.getCard(0, 0) = Card(1, "../images/1.jpg");

		GameLogic gameLogic(board);

		gameLogic.flipCard(0, 0);
		gameLogic.flipCard(0, 0);

		EXPECT_TRUE(board.getCard(0, 0).isFlipped());
		EXPECT_EQ(gameLogic.getScore(), 0);
	}

	TEST(GameLogicTests, FlippingOutOfBoundsDoesNothing) {
		Board board(2, 2);
		board.initializeBoard();

		GameLogic gameLogic(board);

		gameLogic.flipCard(-1, 0);
		gameLogic.flipCard(0, 4);
		gameLogic.flipCard(2, 2);

		EXPECT_EQ(gameLogic.getScore(), 0);
		for (int i = 0; i < board.getRows(); ++i) {
			for (int j = 0; j < board.getCols(); ++j) {
				EXPECT_FALSE(board.getCard(i, j).isFlipped());
			}
		}
	}

	TEST(GameLogicTests, FlippingAfterResetWorksCorrectly) {
		Board board(2, 2);
		board.initializeBoard();

		GameLogic gameLogic(board);

		gameLogic.flipCard(0, 0);
		gameLogic.resetGame();

		EXPECT_EQ(gameLogic.getScore(), 0);
		EXPECT_FALSE(board.getCard(0, 0).isFlipped());

		gameLogic.flipCard(0, 1);
		EXPECT_TRUE(board.getCard(0, 1).isFlipped());
		EXPECT_EQ(gameLogic.getScore(), 0);
	}

	TEST(GameLogicTests, MatchingLastPairEndsGame) {
		Board board(2, 2);
		board.initializeBoard();

		board.getCard(0, 0) = Card(1, "../images/1.jpg");
		board.getCard(0, 1) = Card(1, "../images/1.jpg");
		board.getCard(1, 0) = Card(2, "../images/2.jpg");
		board.getCard(1, 1) = Card(2, "../images/2.jpg");

		MockObserver mockObserver;
		board.addObserver(&mockObserver);

		EXPECT_CALL(mockObserver, gameEnded()).Times(1);

		GameLogic gameLogic(board);

		gameLogic.flipCard(0, 0);
		gameLogic.flipCard(0, 1);
		EXPECT_EQ(gameLogic.getScore(), 1);

		gameLogic.flipCard(1, 0);
		gameLogic.flipCard(1, 1);
		EXPECT_EQ(gameLogic.getScore(), 2);
	}
}
