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
// Created on Jan 19, 2017
// https://leetcode.com/problems/3sum-smaller/

#include <algorithm>
#include <vector>

class Solution
{
public:
    int threeSumSmaller(std::vector<int>& nums, int target)
    {
        if (nums.size() < 3)
        {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int count = 0;
        for (size_t i = 0; i < nums.size() - 2; i++)
        {
            // as j increases, the upper k can only decrease
            size_t k = nums.size() - 1;

            if (nums[i] + nums[i+1] + nums[i+2] >= target)
            {
                break;
            }

            for (size_t j = i + 1; j < k; j++)
            {
                while (j < k && nums[i] + nums[j] + nums[k] >= target)
                {
                    k--;
                }

                count += k - j;
            }
        }

        return count;
    }
};
