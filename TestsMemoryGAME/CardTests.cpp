#include "Card.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace BackendTests {
    TEST(CardTests, InitializationSetsCorrectValues) {
        Card card(1, "../images/1.jpg");

        EXPECT_EQ(card.getId(), 1);             
        EXPECT_FALSE(card.isFlipped());         
        EXPECT_EQ(card.getImagePath(), "../images/1.jpg");
    }

    TEST(CardTests, FlipTogglesState) {
        Card card(1, "../images/1.jpg");

        EXPECT_FALSE(card.isFlipped()); 

        card.flip();
        EXPECT_TRUE(card.isFlipped());

        card.flip();
        EXPECT_FALSE(card.isFlipped()); 
    }

    TEST(CardTests, ResetSetsFlippedToFalse) {
        Card card(1, "../images/1.jpg");

        card.flip();
        EXPECT_TRUE(card.isFlipped()); 

        card.reset();
        EXPECT_FALSE(card.isFlipped());
    }

    TEST(CardTests, EqualityOperatorWorksCorrectly) {
        Card card1(1, "../images/1.jpg");
        Card card2(1, "../images/2.jpg"); 
        Card card3(2, "../images/1.jpg"); 

        EXPECT_TRUE(card1 == card2);  
        EXPECT_FALSE(card1 == card3);
    }

    TEST(CardTests, GetImagePathReturnsCorrectValue) {
        Card card(1, "../images/1.jpg");
        EXPECT_EQ(card.getImagePath(), "../images/1.jpg");
    }
}