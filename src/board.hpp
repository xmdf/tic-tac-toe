/**
 * @file board.hpp 
 * @author xmdf
 * @date 12 March 2022
 * @brief
 */

#pragma once

#include <array>
#include <string>

namespace ttt {

    class Board
    {
    public:
        Board();

        void init();

        bool winner_check();

        bool board_full();

        void ascii_board_print();

        void ascii_board_update(uint8_t i, const char *c);

        ~Board() = default;

    protected:
        void ascii_board_init();

        bool winner_rows_check();

        bool winner_cols_check();

        bool winner_diag_check();

        bool spot_map_char_compare(uint8_t i1, uint8_t i2, uint8_t i3);

        static bool char_compare(char c1, char c2, char c3);

    protected:
        std::string ascii_board_;
        std::array<uint8_t, 9> spot_map_;
    };

} // end namespace ttt