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
// Created on Oct 15, 2016
// https://leetcode.com/problems/permutations-ii/

#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>

// Method 2: hash map storing element count and backtrack

class Solution
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
    {
        using std::swap;
        using std::vector;
        std::unordered_map<int, int> hmap;

        vector<vector<int>> result;
        auto length = nums.size();

        for (auto num : nums)
        {
            if (hmap.count(num) <= 0)
            {
                hmap[num] = 1;
            }
            else
            {
                hmap[num] += 1;
            }
        }

        vector<int> result_template = nums;

        std::function<void(int)> dfs = [&dfs, &result_template, &hmap, &result, length] (int depth)
        {
            if (depth >= length)
            {
                result.push_back(result_template);
                return;
            }

            for (auto& p: hmap)
            {
                auto& num = p.first;
                auto& count = p.second;

                if (count > 0)
                {
                    count--;
                    result_template[depth] = num;
                    dfs(depth + 1);
                    count++;
                }
            }
        };

        dfs(0);
        return result;
    }
};
