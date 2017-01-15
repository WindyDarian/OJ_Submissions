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
// Created on Jan 13, 2017
// https://leetcode.com/problems/shortest-distance-from-all-buildings/

#include <vector>
#include <queue>
#include <tuple>
#include <limits>

// method 1: bfs

class Solution
{
public:
    int shortestDistance(std::vector<std::vector<int>>& grid)
    {
        using std::vector;
        using dist_t = int;

        auto nrow = grid.size();
        if (nrow <= 0) {return -1;}
        auto ncol = grid[0].size();

        vector<vector<dist_t>> tile_total_distances(nrow, vector<dist_t>(ncol, 0)); // sum of distances to buildings from loc
        vector<vector<size_t>> tile_reachable_buildings(nrow, vector<size_t>(ncol, 0)); // number of reachable buildings fro loc

        auto bfs = [&grid, &tile_total_distances, &tile_reachable_buildings, nrow, ncol](size_t from_i, size_t from_j, size_t current_building_index)
        {
            std::queue<std::tuple<size_t, size_t, dist_t>> frontier;
            frontier.emplace(from_i, from_j, 0);
            while (!frontier.empty())
            {
                size_t i, j;
                dist_t dist;
                std::tie(i, j, dist) = frontier.front();
                frontier.pop();

                if (i < 0 || i >= nrow || j < 0 || j >= ncol) {continue;}

                bool pos_valid = grid[i][j] == 0 && tile_reachable_buildings[i][j] == current_building_index;
                if (pos_valid)
                {
                    tile_reachable_buildings[i][j]++;
                    tile_total_distances[i][j]+= dist;
                }
                if (pos_valid || (i == from_i && j == from_j))
                {
                    frontier.emplace(i+1, j, dist+1);
                    frontier.emplace(i, j+1, dist+1);
                    frontier.emplace(i-1, j, dist+1);
                    frontier.emplace(i, j-1, dist+1);
                }
            }
        };

        size_t current_building_index = 0;
        for (size_t i = 0; i < nrow; i++)
        {
            for (size_t j = 0; j < ncol; j++)
            {
                if (grid[i][j] == 1)
                {
                    bfs(i, j, current_building_index);
                    current_building_index++;
                }
            }
        }

        if (current_building_index==0)
        {
            return -1;
        }

        dist_t min_dist = -1;
        for (size_t i = 0; i < nrow; i++)
        {
            for (size_t j = 0; j < ncol; j++)
            {
                if (grid[i][j] == 0 && tile_reachable_buildings[i][j] == current_building_index)
                {
                    min_dist = min_dist < 0? tile_total_distances[i][j] : std::min(tile_total_distances[i][j], min_dist);
                }
            }
        }

        return static_cast<int>(min_dist);
    }
};
