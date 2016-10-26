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
// Created on Oct 25, 2016
// https://leetcode.com/problems/generate-parentheses/

#include <vector>
#include <string>
#include <functional>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        using std::vector;
        using std::string;

        string current(n * 2, ' ');
        auto current_l = 0;
        auto current_r = 0;
        vector<string> results;

        std::function <void(int)> dfs = [&current, &results, &current_l, &current_r, n, &dfs](int pos)
        {
            if (current_l < current_r)
            {
                return;
            }
            if (pos == n * 2)
            {
                results.push_back(current);
            }

            if (current_l < n)
            {
                current_l++;
                current[pos] = '(';
                dfs(pos + 1);
                current_l--;
            }
            if (current_r < n)
            {
                current_r++;
                current[pos] = ')';
                dfs(pos + 1);
                current_r--;
            }
        };

        dfs(0);

        return results;
    }
};
