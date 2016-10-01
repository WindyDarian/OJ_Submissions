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
#include <tuple>

class Solution
{
private:
    template<typename random_iterator>
    static bool is_new_row_valid(random_iterator begin, int new_prefix_length)
    {
        auto new_index = new_prefix_length - 1;
        for(int j = 0; j < new_index; j++)
        {
            if (new_index - j == std::abs(begin[new_index] - begin[j]))
            {
                return false;
            }
        }
        return true;
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        using std::vector;
        std::vector<std::vector<std::string>> results;

        vector<std::tuple<vector<int>, int>> frontier;
        auto append_successors = [n, &frontier](const vector<int>& current, int prefex_length)
        {
            for (auto i = prefex_length; i < n; i++)
            {
                auto temp_vector = current;
                std::swap(temp_vector[prefex_length], temp_vector[i]);
                frontier.push_back(std::make_tuple(std::move(temp_vector), prefex_length + 1));
            }
        };

        // k = positions[i] indicates k-th column of i-th row is possessed
        vector<int> positions(n);
        for (int i = 0; i < n; i++) { positions[i] = i; }

        frontier.push_back(make_tuple(positions, 0));
        vector<int> current_positions;
        int current_prefix_length;
        const std::string row_string(n, '.');
        while(frontier.size() > 0)
        {
            std::tie(current_positions, current_prefix_length) = std::move(frontier.back());
            frontier.pop_back();

            if (!is_new_row_valid(current_positions.cbegin(), current_prefix_length))
            {
                continue;
            }

            if (current_prefix_length == n)
            {
                std::vector<string> rows(n, row_string);
                for (int i = 0; i < n; i++)
                {
                    rows[i][current_positions[i]] = 'Q';
                }
                results.push_back(std::move(rows));
            }

            append_successors(current_positions, current_prefix_length);

        }

        return results;
    }
};
