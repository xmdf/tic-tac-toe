/**
 * @file board.cpp 
 * @author xmdf
 * @date 12 March 2022
 * @brief
 */

#include "board.hpp"

#include <iostream>

namespace ttt {

    std::string board_ascii_base_get()
    {
        return "     |     |     \n"
               "-----|-----|-----\n"
               "     |     |     \n"
               "-----|-----|-----\n"
               "     |     |     \n";
    }

    //==================================================================================================================
    // Board
    //==================================================================================================================
    Board::Board()
    : ascii_board_{board_ascii_base_get()}
    , spot_map_{2, 8, 14, 38, 44, 50, 74, 80, 86}
    {
    }

    void Board::init()
    {
        this->ascii_board_init();
    }

    void Board::ascii_board_print()
    {
        std::cout << this->ascii_board_ << std::endl << std::endl;
    }

    void Board::ascii_board_init()
    {
        for(uint8_t i = 0; i < static_cast<uint8_t>(this->spot_map_.size()); ++i) {
            this->ascii_board_update(i, std::to_string(i + 1).c_str());
        }
    }

    void Board::ascii_board_update(uint8_t i, const char *c)
    {
        this->ascii_board_.replace(this->spot_map_[i], 1, c);
    }

    bool Board::winner_check()
    {
        return this->winner_rows_check() || this->winner_cols_check() || this->winner_diag_check();
    }

    bool Board::board_full()
    {
        for(uint8_t i = 0; i < static_cast<uint8_t>(this->spot_map_.size()); ++i) {
            if (this->ascii_board_[this->spot_map_[i]] != 'X' &&
                this->ascii_board_[this->spot_map_[i]] != 'O') {
                return false;
            }
        }

        return true;
    }

    bool Board::winner_rows_check()
    {
        return this->spot_map_char_compare(0, 1, 2) ||
               this->spot_map_char_compare(3, 4, 5) ||
               this->spot_map_char_compare(6, 7, 8);
    }

    bool Board::winner_cols_check()
    {
        return this->spot_map_char_compare(0, 3, 6) ||
               this->spot_map_char_compare(1, 4, 7) ||
               this->spot_map_char_compare(2, 5, 8);
    }

    bool Board::winner_diag_check()
    {
        return this->spot_map_char_compare(0, 4, 8) ||
               this->spot_map_char_compare(2, 4, 6);
    }

    bool Board::spot_map_char_compare(uint8_t i1, uint8_t i2, uint8_t i3)
    {
        return Board::char_compare(
            this->ascii_board_[this->spot_map_[i1]],
            this->ascii_board_[this->spot_map_[i2]],
            this->ascii_board_[this->spot_map_[i3]]);
    }

    bool Board::char_compare(const char c1, const char c2, const char c3)
    {
        return (c1 == c2) && (c1 == c3);
    }


} // end namespace ttt