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
// https://leetcode.com/problems/permutations/

#include <functional>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        using std::swap;

        vector<vector<int>> result;
        auto length = nums.size();

        std::function<void(int)> dfs = [&dfs, &nums, &result, length] (int depth)
        {
            for (int i = depth; i < length; i++)
            {
                swap(nums[depth], nums[i]);
                if (i > depth)
                {
                    result.push_back(nums);  // only push when swapping actually happened
                }
                dfs(depth + 1);
                swap(nums[depth], nums[i]);
            }
        };
        result.push_back(nums);
        dfs(0);
        return result;
    }
};
