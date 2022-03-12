/**
 * @file tic_tac_toe_tests_main.cpp 
 * @author xmdf
 * @date 12 March 2022
 * @brief Tests
 */

#include "board.hpp"

#include <gtest/gtest.h>

class TestBoard
    : public ttt::Board
    , public ::testing::Test
{
public:
    TestBoard()
    : ttt::Board{}
    , ::testing::Test{}
    {
    }
};


TEST_F(TestBoard, AsciiBoardUpdate)
{
    for(uint8_t i = 0; i < 9; ++i) {
        this->ascii_board_update(i, "X");
        EXPECT_EQ(this->ascii_board_[this->spot_map_[i]], 'X');
    }
}

TEST_F(TestBoard, CharCompare)
{
    EXPECT_TRUE(Board::char_compare('X', 'X', 'X'));
    EXPECT_FALSE(Board::char_compare('O', 'X', 'X'));
    EXPECT_FALSE(Board::char_compare('X', 'O', 'X'));
    EXPECT_FALSE(Board::char_compare('X', 'X', 'O'));
}

TEST_F(TestBoard, WinnerRowsCheck)
{
    this->init();
    EXPECT_FALSE(this->winner_rows_check());

    this->ascii_board_update(0, "X");
    this->ascii_board_update(1, "X");
    this->ascii_board_update(2, "X");
    EXPECT_TRUE(this->winner_rows_check());

    this->ascii_board_update(1, "O");
    this->ascii_board_update(3, "X");
    this->ascii_board_update(4, "X");
    this->ascii_board_update(5, "X");
    EXPECT_TRUE(this->winner_rows_check());

    this->ascii_board_update(3, "O");
    this->ascii_board_update(6, "X");
    this->ascii_board_update(7, "X");
    this->ascii_board_update(8, "X");
    EXPECT_TRUE(this->winner_rows_check());
}

TEST_F(TestBoard, WinnerColsCheck)
{
    this->init();
    EXPECT_FALSE(this->winner_cols_check());

    this->ascii_board_update(0, "X");
    this->ascii_board_update(3, "X");
    this->ascii_board_update(6, "X");
    EXPECT_TRUE(this->winner_cols_check());

    this->ascii_board_update(3, "O");
    this->ascii_board_update(1, "X");
    this->ascii_board_update(4, "X");
    this->ascii_board_update(7, "X");
    EXPECT_TRUE(this->winner_cols_check());

    this->ascii_board_update(4, "O");
    this->ascii_board_update(2, "X");
    this->ascii_board_update(5, "X");
    this->ascii_board_update(8, "X");
    EXPECT_TRUE(this->winner_cols_check());
}

TEST_F(TestBoard, WinnerDiagCheck)
{
    this->init();
    EXPECT_FALSE(this->winner_diag_check());

    this->ascii_board_update(0, "X");
    this->ascii_board_update(4, "X");
    this->ascii_board_update(8, "X");
    EXPECT_TRUE(this->winner_diag_check());

    this->ascii_board_update(0, "O");
    this->ascii_board_update(2, "X");
    this->ascii_board_update(6, "X");
    EXPECT_TRUE(this->winner_diag_check());
}

TEST_F(TestBoard, BoardFull)
{
    for(uint8_t i = 0; i < 9; ++i) {
        EXPECT_FALSE(this->board_full());
        this->ascii_board_update(i, "X");
    }
    EXPECT_TRUE(this->board_full());

    this->init();
    for(uint8_t i = 0; i < 9; ++i) {
        EXPECT_FALSE(this->board_full());
        this->ascii_board_update(i, "O");
    }
    EXPECT_TRUE(this->board_full());

    this->init();
    for(uint8_t i = 0; i < 9; ++i) {
        EXPECT_FALSE(this->board_full());
        if (i % 2) {
            this->ascii_board_update(i, "X");
        }
        else {
            this->ascii_board_update(i, "O");
        }
    }
    EXPECT_TRUE(this->board_full());
}



int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}