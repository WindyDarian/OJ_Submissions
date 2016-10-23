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
// Created on Oct 22, 2016
// https://leetcode.com/problems/number-of-islands/

#include <vector>
#include <functional>

class Solution
{
public:
    int numIslands(const std::vector<std::vector<char>>& grid)
    {
        using std::vector;

        // 233 for visited land
        constexpr char VISITED = 233;

        auto nrow = grid.size();
        if (nrow == 0)
        {
            return 0;
        }
        auto ncol = grid[0].size();
        if (ncol == 0)
        {
            return 0;
        }

        vector<vector<char>> map = grid;
        std::function<bool(int, int)> dfs_visit = [&map, &dfs_visit, nrow, ncol](int r, int c) -> bool
        {
            // Out of bound
            if (!(r >= 0 && r < nrow && c >= 0 && c < ncol))
            {
                return false;
            }
            // Water or visited
            if (map[r][c] != '1')
            {
                return false;
            }

            // Land
            map[r][c] = VISITED;
            dfs_visit(r+1, c);
            dfs_visit(r-1, c);
            dfs_visit(r, c+1);
            dfs_visit(r, c-1);
            return true;
        };

        int count = 0;
        for (auto i = 0; i < nrow; i++)
        {
            for (auto j = 0; j < ncol; j++)
            {
                if (dfs_visit(i, j))
                {
                    count ++;
                }
            }
        }

        return count;
    }
};
