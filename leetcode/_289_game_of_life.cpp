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
//
// Created on Dec 21, 2016
// https://leetcode.com/problems/game-of-life/


#include <vector>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board)
    {
        auto nrow = board.size();
        if (nrow == 0) return;
        auto ncol = board[0].size();

        auto isAlive = [nrow, ncol, &board](int i, int j)
        {
            if (i < 0 || i >= nrow || j < 0 || j >= ncol)
            {
                return false;
            }
            else
            {
                return board[i][j] % 2 > 0;
            }
        };

        // using front bits for store neighbors
        // Step 1: calculate neighbor count
        for (int i = 0; i < nrow; i++)
        {
            for (int j = 0; j < ncol; j++)
            {
                int neighbor_count = 0;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        if (!(di == 0 && dj == 0) && isAlive(di+i, dj+j))
                        {
                            neighbor_count++;
                        }
                    }
                }
                board[i][j] |= neighbor_count << 1;
            }
        }

        // Step 2: simulate
        for (size_t i = 0; i < nrow; i++)
        {
            for (size_t j = 0; j < ncol; j++)
            {
                int neighbor_count = board[i][j] >> 1;

                if (board[i][j] % 2)
                {
                    if (neighbor_count < 2 || neighbor_count > 3)
                    {
                        board[i][j] = 0;
                    }
                    else
                    {
                        board[i][j] = 1;
                    }
                }
                else
                {
                    if (neighbor_count == 3)
                    {
                        board[i][j] = 1;
                    }
                    else
                    {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};
