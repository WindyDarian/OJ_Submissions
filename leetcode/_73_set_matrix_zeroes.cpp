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
// Ummmmm I have seen this on Cracking the Coding Interview
// Created on Oct 23, 2016
// https://leetcode.com/problems/set-matrix-zeroes/

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        auto nrow = matrix.size();
        if (nrow == 0)
        {
            return;
        }
        auto ncol = matrix[0].size();
        if (ncol == 0)
        {
            return;
        }

        // using row 0 and col 0 to save which row and col will become zero
        auto col0_zero = false;
        for (auto i = 0; i < nrow; i++)
        {
            if (matrix[i][0] == 0)
            {
                col0_zero = true;
                break;
            }
        }
        auto row0_zero = false;
        for (auto i = 0; i < ncol; i++)
        {
            if (matrix[0][i] == 0)
            {
                row0_zero = true;
                break;
            }
        }

        // mark zero!
        for (auto i = 1; i < nrow; i++)
        {
            for (auto j = 1; j < ncol; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // set zero!
        for (auto i = 0; i < nrow; i++)
        {
            if (matrix[i][0] == 0)
            {
                for (auto j = 1; j < ncol; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (auto i = 0; i < ncol; i++)
        {
            if (matrix[0][i] == 0)
            {
                for (auto j = 1; j < nrow; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }


        if(col0_zero)
        {
            for (auto i = 0; i < nrow; i++)
            {
                matrix[i][0] = 0;
            }
        }
        if (row0_zero)
        {
            for (auto i = 0; i < ncol; i++)
            {
                matrix[0][i] = 0;
            }
        }
    }
};
