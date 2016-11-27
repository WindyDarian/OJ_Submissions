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
// Created on Nov 26, 2016
// https://leetcode.com/problems/unique-paths-ii/


#include <vector>

class Solution 
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) 
    {
        using std::vector;
        
        int nrow = obstacleGrid.size();
        if (nrow == 0) return 0;
        int ncol = obstacleGrid[0].size();
        
        vector<vector<int>> paths (nrow, vector<int>(ncol, 0) );
        
        for (auto i = 0; i < nrow; i++)
        {
            if (obstacleGrid[i][0]) break;
            paths[i][0] = 1;
        }
        
        for (auto j = 0; j < ncol; j++)
        {
            if (obstacleGrid[0][j]) break;
            paths[0][j] = 1;
        }
        
        for (auto i = 1; i < nrow; i++)
        {
            for (auto j = 1; j < ncol; j++)
            {
                if (obstacleGrid[i][j]) {continue;} // 0 not changed
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        
        return paths[nrow - 1][ncol - 1];
    }
};