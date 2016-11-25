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
// Created on Nov 24, 2016
// https://leetcode.com/problems/search-a-2d-matrix/

// map 2d to 1d and do one binary search 

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        auto nrow = matrix.size();
        if (nrow == 0) return false;
        auto ncol = matrix[0].size();

        auto one_to_two = [&matrix, ncol](int input)
        {
            return std::make_pair(input/ncol, input%ncol);
        };

        int i, j;
        int start = 0;
        int end = nrow * ncol;
        while (start < end)
        {
            auto mid = (start + end) / 2;
            std::tie(i,j) = one_to_two(mid);
            if (matrix[i][j] == target)
            {
                return true;
            }
            if (matrix[i][j] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return false;
    }
};
