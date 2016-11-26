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
// https://leetcode.com/problems/unique-paths/


#include <vector>

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        std::vector<std::vector<int>> paths(m, std::vector<int>(n, -1));
        for (auto i = 0; i < m; i++)
        {
            paths[i][0] = 1;
        }
        for (auto j = 0; j < n; j++)
        {
            paths[0][j] = 1;
        }
        
        for (auto i = 1; i < m; i++)
        {
            for (auto j = 1; j < n; j++)
            {
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        
        return paths[m-1][n-1];
    }
};