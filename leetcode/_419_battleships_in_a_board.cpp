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
// Created on Oct 30, 2016
// https://leetcode.com/problems/battleships-in-a-board/

// if up or left of an 'X' is 'X' then the tile just sits in a ship already counted

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        auto n_row = board.size();
        if (n_row == 0)
        {
            return 0;
        }
        auto n_col = board[0].size();

        int ship_count = 0;

        for (int i = 0; i < n_row; i++)
        {
            for (int j = 0; j < n_col; j++)
            {
                if (board[i][j] == 'X')
                {
                    // check up
                    if (i > 0 && board[i-1][j] == 'X')
                    {
                        continue;
                    }
                    // check left
                    if (j > 0 && board[i][j-1] == 'X')
                    {
                        continue;
                    }

                    ship_count++;
                }
            }
        }

        return ship_count;
    }
};
