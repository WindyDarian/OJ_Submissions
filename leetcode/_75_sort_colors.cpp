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
// Created on Oct 22, 2016
// https://leetcode.com/problems/sort-colors/
// Don't believe if the elements in limited identical types and it says it is a "sort"

#include <vector>
#include <array>

class Solution
{
public:
    void sortColors(std::vector<int>& nums)
    {
        std::array<size_t, 3> color_nums = {0};
        for (auto num: nums)
        {
            color_nums[num]++;
        }

        size_t p = 0;

        for (int i = 0; i < 3;i++)
        {
            for (size_t j = 0; j < color_nums[i]; j++)
            {
                nums[p] = i;
                p++;
            }
        }
    }
};
