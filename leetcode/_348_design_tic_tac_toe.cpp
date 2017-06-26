//==============================================================================
// Copyright 2016 Windy Darian (Ruoyu Fan)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//==============================================================================
// Created on Jun 25, 2017
// https://leetcode.com/problems/design-tic-tac-toe/

#include <vector>

struct PlayerState
{
    std::vector<int> row_counts;
    std::vector<int> column_counts;
    int diagonal_one_count = 0;  // x == y
    int diagonal_two_count = 0;  // x + y == n - 1

    PlayerState(int n)
        : row_counts(n, 0)
        , column_counts(n, 0)
    {}

    bool move(int row, int col)
    {
        auto n = row_counts.size();
        row_counts[row]++;
        if (row_counts[row] == n) {return true;}
        column_counts[col]++;
        if (column_counts[col] == n) {return true;}
        if (row == col)
        {
            diagonal_one_count++;
            if (diagonal_one_count == n) {return true;}
        }
        if (row + col + 1 == n)
        {
            diagonal_two_count++;
            if (diagonal_two_count == n) {return true;}
        }
        return false;
    }
};

class TicTacToe {
private:
    PlayerState p1state;
    PlayerState p2state;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
        : p1state(n)
        , p2state(n)
    {}

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player)
    {
        if (player == 1)
        {
            if (p1state.move(row, col))
            {
                return 1;
            }
        }
        if (player == 2)
        {
            if (p2state.move(row, col))
            {
                return 2;
            }
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
