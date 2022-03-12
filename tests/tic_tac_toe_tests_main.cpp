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


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}