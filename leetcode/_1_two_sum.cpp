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
// Created on Oct 18, 2016
// https://leetcode.com/problems/two-sum/

#include<vector>
#include<unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        using std::vector;
        using map_t = std::unordered_map<int, int>;

        map_t seen_nums;
        for (int i = 0; i < nums.size(); i++)
        {
            auto desired = target - nums[i];
            if (seen_nums.count(desired) > 0)
            {
                return vector<int>{seen_nums[desired], i};
            }
            seen_nums[nums[i]] = i;
        }

        return vector<int>();
    }
};
