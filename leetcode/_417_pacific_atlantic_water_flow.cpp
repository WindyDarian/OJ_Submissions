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
// Created on Jan 21, 2017
// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <functional>
#include <vector>
#include <limit>
#include <pair>

class Solution {
public:
    std::vector<std::pair<int, int>> pacificAtlantic(std::vector<std::vector<int>>& matrix)
    {
        std::vector<std::pair<int, int>> result;
        auto nrow = matrix.size();
        if (nrow == 0){return result;}
        auto ncol = matrix[0].size();
        if (ncol == 0){return result;}


        constexpr int pacific_mask = 0b1;
        constexpr int atlantic_mask = 0b10;
        constexpr int pa_mask = pacific_mask | atlantic_mask;
        vector<vector<int>> connections(nrow, vector<int>(ncol, 0));
        std::function<void (int, int, int, int)> dfsFlow =
            [&result, &connections, &matrix, nrow, ncol, pacific_mask, atlantic_mask, pa_mask, &dfsFlow]
            (int i, int j, int ocean_mask, int from_value)
        {
            if (i < 0 || i >= nrow || j < 0 || j >= ncol)
            {
                return;
            }

            if (ocean_mask & connections[i][j] || matrix[i][j] < from_value)
            {
                return;
            }

            connections[i][j] |= ocean_mask;
            if (connections[i][j] == pa_mask)
            {
                result.emplace_back(i, j);
            }

            dfsFlow(i+1, j, ocean_mask, matrix[i][j]);
            dfsFlow(i, j+1, ocean_mask, matrix[i][j]);
            dfsFlow(i-1, j, ocean_mask, matrix[i][j]);
            dfsFlow(i, j-1, ocean_mask, matrix[i][j]);
        };


        constexpr auto lowest_int = std::numeric_limits<int>::lowest();
        for (int i = 0; i < nrow; i++)
        {
            dfsFlow(i, 0, pacific_mask, lowest_int);
        }
        for (int j = 1; j < ncol; j++)
        {
            dfsFlow(0, j, pacific_mask, lowest_int);
        }
        for (int i = 0; i < nrow; i++)
        {
            dfsFlow(i, ncol - 1, atlantic_mask, lowest_int);
        }
        for (int j = 0; j < ncol - 1; j++)
        {
            dfsFlow(nrow - 1, j, atlantic_mask, lowest_int);
        }
        return result;
    }
};
