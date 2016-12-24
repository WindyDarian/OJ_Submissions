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
// https://leetcode.com/problems/bomb-enemy/

#include <vector>
#include <utility>

class Solution
{
public:
int maxKilledEnemies(vector<vector<char>>& grid)
{
    using std::vector;
	auto nrow = grid.size();
	if (nrow == 0)
	{
		return 0;
	}
	auto ncol = grid[0].size();

	auto inBound = [nrow, ncol](int i, int j)
	{
		return 0 <= i && i < nrow && 0 <= j && j < ncol;
    };

    vector<vector<std::pair<int, int>>> mem_map(nrow, vector<std::pair<int, int>>(ncol, std::make_pair(-1,-1)));

	auto calcKilledEnemies = [&grid, &mem_map, inBound](size_t i, size_t j)
	{
		if (grid[i][j] != '0') {return 0;}

		int v_count = 0;

        if (mem_map[i][j].first != -1)
        {
            v_count = mem_map[i][j].first;
        }
        else
        {
            int ub = i;
            int db = i;
            for (int up = i; inBound(up, j) && grid[up][j] != 'W'; up--)
            {
                ub = up;
            	if (grid[up][j] == 'E')
            	{
            		v_count++;
            	}
            }

            for (int down = i + 1; inBound(down, j) && grid[down][j] != 'W'; down++ )
            {
                db = down;
            	if (grid[down][j] == 'E')
            	{
            		v_count++;
            	}
            }

            for (int v = ub; v < db; v++)
            {
                mem_map[v][j].first=v_count;
            }

        }

        int h_count = 0;

        if (mem_map[i][j].second != -1)
        {
            h_count = mem_map[i][j].second;
        }
        else
        {
            int lb = j;
            int rb = j;
            for (int left = j; inBound(i  ,left) && grid[i][left] != 'W'; left--)
            {
                lb = left;
            	if (grid[i][left] == 'E')
            	{
            		h_count++;
            	}
            }
            for (int right= j + 1; inBound(i, right) && grid[i][right] != 'W'; right++)
            {
                rb = right;
            	if (grid[i][right] == 'E')
            	{
            		h_count++;
            	}
            }

            for (int h = lb; h < rb; h++)
            {
                mem_map[i][h].second=h_count;
            }
        }

        return v_count + h_count;
	};

	int max_killed = 0;
	for (size_t i = 0; i < nrow; i++)
	{
		for (size_t j = 0; j < ncol; j++)
		{
			max_killed = std::max(calcKilledEnemies(i,j), max_killed);
		}
	}

	return max_killed;
}
};
