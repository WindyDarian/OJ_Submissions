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
// Created on Oct 30, 2016
// https://leetcode.com/problems/find-all-duplicates-in-an-array/

// very important information 1 ≤ a[i] ≤ n
// use the array as a set!!!!
// impossible to use no extra space (at least we need iterator) so I used O(1)
// space

#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> findDuplicates(std::vector<int>& nums)
    {
        std::vector<int> result;
        int i = 0;
        while (i < nums.size())
        {
            // store every v at nums[v - 1]
            // -1 for slots in which elements already appears more than once
            // to avoid duplication
            auto v = nums[i];
            if (i == v - 1 || v == -1 || nums[v - 1] == -1)
            {
                i++;
                continue;
            }
            if (v == nums[v - 1])
            {
                // already exists
                result.push_back(v);
                nums[v - 1] = -1;
                i++;
                continue;
            }
            else
            {
                std::swap(nums[i], nums[v - 1]);
            }
        }

        return result;
    }
};
