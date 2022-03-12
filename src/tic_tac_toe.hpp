/**
 * @file tic_tac_toe.hpp 
 * @author xmdf
 * @date 12 March 2022
 * @brief
 */

#pragma once

#include "board.hpp"


namespace ttt {

    class TicTacToe
    {
    public:
        TicTacToe();

        void play();

        ~TicTacToe() = default;

    protected:
        Board board_;
        bool turn_flag_;
    };

} // end namespace ttt