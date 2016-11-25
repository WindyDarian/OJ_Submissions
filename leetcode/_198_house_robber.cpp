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
// Created on Nov 24, 2016
// https://leetcode.com/problems/house-robber/

#include <vector>
#include <algorithm>

class Solution
{
public:
    int rob(std::vector<int>& nums)
    {
        if (nums.size() == 0) return 0;
        int max_without_tail = 0; // sice we have non-negative input
        int running_max = 0;

        for(auto iter = nums.cbegin(); iter < nums.cend(); iter++)
        {
            auto temp = running_max;
            running_max = std::max(max_without_tail + *iter, running_max);
            max_without_tail = temp;
        }

        return running_max;
    }
};
