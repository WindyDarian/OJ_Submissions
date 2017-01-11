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
// Created on Jan 10, 2017
// https://leetcode.com/problems/range-sum-query-2d-mutable/

// Problem:
//------------------------------------------------------------------------------
// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]
//
// sumRegion(2, 1, 4, 3) -> 8
// update(3, 2, 2)
// sumRegion(2, 1, 4, 3) -> 10
// Note:
// The matrix is only modifiable by the update function.
// You may assume the number of calls to update and sumRegion function is
//   distributed evenly.
// You may assume that row1 ≤ row2 and col1 ≤ col2.
//------------------------------------------------------------------------------


#include <vector>

// Since "You may assume the number of calls to update and sumRegion
// function is distributed evenly." , I did balance the complexity
// of update() and sumRegion()

class NumMatrix
{
private:
    size_t nrow;
    size_t ncol;
    std::vector<std::vector<int>> row_sum_mat;
    std::vector<std::vector<int>> values;
    using sum_t = int;

public:
    NumMatrix(vector<vector<int>> &matrix)
    : values(matrix)
    {
        nrow = values.size();
        if (nrow > 0)
        {
            ncol = values[0].size();
        }

        for (size_t i = 0; i < nrow; i++)
        {
            row_sum_mat.emplace_back(ncol);
            sum_t row_sum = 0;
            for (size_t j = 0; j < ncol; j++)
            {
                row_sum += values[i][j];
                row_sum_mat[i][j] = row_sum;
            }
        }
    }

    void update(int row, int col, int val)
    {
        // Update the values matrix
        auto diff = val - values[row][col];
        values[row][col] = val;

        // Update the row_sum_mat in O(ncol) time
        for (size_t j = col; j < ncol; j++)
        {
            row_sum_mat[row][j] += diff;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        // Find the sum in O(row2-row1) time
        sum_t sum = 0;
        for (size_t i = row1; i <= row2; i++)
        {
            sum += (col1 == 0)? row_sum_mat[i][col2] : row_sum_mat[i][col2] - row_sum_mat[i][col1 - 1];
        }
        return static_cast<int>(sum);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
