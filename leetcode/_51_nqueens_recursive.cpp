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
// Created on Oct 1, 2016
// https://leetcode.com/problems/n-queens/

#include <vector>
#include <string>
#include <cmath>
#include <functional>

class Solution
{
public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        using std::vector;
        std::vector<std::vector<std::string>> results;
        const std::vector<string> template_result(n, std::string(n, '.'));
        // k = positions[i] indicates k-th column of i-th row is possessed
        vector<int> positions(n);

        for (int i = 0; i < n; i++) { positions[i] = i; }

        auto is_new_row_valid = [&positions](int prefex_length)
        {
            auto new_index = prefex_length - 1;
            for(int j = 0; j < new_index; j++)
            {
                if (new_index - j == std::abs(positions[new_index] - positions[j]))
                {
                    return false;
                }
            }
            return true;
        };

        std::function<void(int)> recursive_solve = [n, &positions, &results, &template_result, &recursive_solve, is_new_row_valid](int prefix_length)
        {
            if (!is_new_row_valid(prefix_length)) return;
            if (prefix_length == n)
            {
                results.push_back(template_result);
                auto& new_result = results.back();
                for (int i = 0; i < n; i++)
                {
                    new_result[i][positions[i]] = 'Q';
                }
                return;
            }
            for (auto i = prefix_length; i < n; i++)
            {
                std::swap(positions[prefix_length], positions[i]);
                recursive_solve(prefix_length + 1);
                std::swap(positions[prefix_length], positions[i]);
            }
        };

        recursive_solve(0);

        return results;
    }
};
