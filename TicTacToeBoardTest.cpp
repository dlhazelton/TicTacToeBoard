/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Player Switch Test
TEST(TicTacToeBoardTest, switchPlayer)
{
  Piece dummyTurn = turn;
  toggleTurn();
	ASSERT_NE(dummyTurn, turn);
}

TEST(TicTacToeBoardTest, validPlacement)
{
  Piece dummyBad = Invalid;
  Piece dummyGood = placePiece(1,1);
  ASSERT_NE(dummyGood, dummyBad);
}

// This one should fail if working correctly
TEST(TicTacToeBoardTest, occupiedPlacement)
{
  Piece dummyBad = Blank;
  Piece dummyGood = placePiece(1,1);
  ASSERT_EQ(dummyGood, dummyBad);
}

TEST(TicTacToeBoardTest, invalidPlacement)
{
  Piece dummyBad = Invalid;
  Piece dummyGood = placePiece(4,4);
  ASSERT_EQ(dummyGood, dummyBad);
}

// Passes one or the other if intended
TEST(TicTacToeBoardTest, validGet)
{
  placePiece(1,1);
  Piece dummyGet= getPiece(1,1);
  ASSERT_EQ(dummyGet, 'O');
  ASSERT_EQ(dummyGet, 'X');
}

TEST(TicTacToeBoardTest, blankGet)
{
  Piece dummyEmpty = Blank;
  Piece dummyGet= getPiece(1,1);
  ASSERT_EQ(dummyGet, dummyEmpty);
}

TEST(TicTacToeBoardTest, invalidGet)
{
  Piece dummyBad = Invalid;
  Piece dummyGood = getPiece(4,4);
  ASSERT_EQ(dummyGood, dummyBad);
}

// Test getWinner here when done
