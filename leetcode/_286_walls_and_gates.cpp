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
// https://leetcode.com/problems/walls-and-gates/


#include <vector>
#include <queue>
#include <tuple>

class Solution {
public:
    void wallsAndGates(std::vector<std::vector<int>>& rooms)
    {
        auto nrow = rooms.size();
        if (nrow == 0){return;}
        auto ncol = rooms[0].size();

        // first, second: row&col from node, third: step taken
        using entry_t = std::tuple<size_t, size_t, int>;
        std::queue<entry_t> frontier = {};
        for (size_t i = 0; i < nrow; i++)
        {
            for (size_t j = 0; j < ncol; j++)
            {
                if (rooms[i][j] == 0)
                {
                    frontier.emplace(i, j, 0);
                }
            }
        }

        while (!frontier.empty())
        {
            size_t i, j;
            int steps;
            std::tie(i, j, steps) = frontier.front();
            frontier.pop();

            if (steps > 0 && rooms[i][j] <= steps)
            {
                continue;
            }
            rooms[i][j] = steps;
            if (i > 0) {frontier.emplace(i-1, j, steps + 1);}
            if (j > 0) {frontier.emplace(i, j - 1 , steps + 1);}
            if (i + 1 < nrow) {frontier.emplace(i+1, j, steps + 1);}
            if (j + 1 < ncol) {frontier.emplace(i, j+1, steps + 1);}
        }
    }
};
