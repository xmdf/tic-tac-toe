/**
 * @file main.cpp 
 * @author xmdf
 * @date 12 March 2022
 * @brief Tic tac toe
 */


#include "board.hpp"

 
int main()
{
    ttt::Board board{};

    board.ascii_board_print();

    return 0;
}