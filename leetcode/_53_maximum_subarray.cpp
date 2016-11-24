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
// Created on Nov 23, 2016
// https://leetcode.com/problems/maximum-subarray/

#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        auto iter = nums.cbegin();
        auto running_sum = *iter;
        auto running_max = running_sum;
        iter++;
        for (;iter < nums.end();iter++)
        {
            if (running_sum < 0)
            {
                running_sum = *iter;
            }
            else
            {
                running_sum += *iter;
            }
            running_max = std::max(running_sum, running_max);
        }
        return running_max;
    }
};
