/**
 * @file tic_tac_toe.cpp 
 * @author xmdf
 * @date 12 March 2022
 * @brief
 */

#include "tic_tac_toe.hpp"

#include <iostream>

namespace ttt {

    TicTacToe::TicTacToe()
    : board_{}
    , turn_flag_{false}
    {

    }

    void TicTacToe::play()
    {
        this->board_.init();
        // while there is no winner and the board is not full
        while (!(this->board_.winner_check() || this->board_.board_full())) {
            this->board_.ascii_board_print();
            uint16_t spot;
            if (turn_flag_) {
                std::cout << "Player 2 move: ";
                std::cin >> spot;
                std::cout << std::endl;
                this->board_.ascii_board_update(static_cast<uint8_t>(spot)-1, "O");
                this->turn_flag_ = false;
            }
            else {
                std::cout << "Player 1 move: ";
                std::cin >> spot;
                std::cout << std::endl;
                this->board_.ascii_board_update(static_cast<uint8_t>(spot)-1, "X");
                this->turn_flag_ = true;
            }
        }
        this->board_.ascii_board_print();
        if (this->board_.winner_check()) {
            if (turn_flag_) {
                std::cout << "Player 1 wins!" << std::endl;
            }
            else {
                std::cout << "Player 2 wins!" << std::endl;
            }
        }
        else {
            std::cout << "Nobody wins..." << std::endl;
        }
    }

} // end namespace ttt