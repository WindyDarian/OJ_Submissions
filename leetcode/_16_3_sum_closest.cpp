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
// https://leetcode.com/problems/3sum-closest/

#include <vector>
#include <algorithm>
#include <cmath>
#include <limit>

class Solution
{
public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
        constexpr auto max_uint = std::numeric_limits<unsigned int>::max();
        // assuming nums.size() > 3
        auto min_diff = max_uint;
        int result = 0;

        auto sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());

        for (size_t i = 0; i < sorted_nums.size() - 2; i++)
        {
            size_t k = sorted_nums.size() - 1;

            for (size_t j = i + 1; j < k; j++)
            {

                while (j < k)
                {
                    auto sum = sorted_nums[i] + sorted_nums[j] + sorted_nums[k];
                    if (sum == target)
                    {
                        return sum;
                    }

                    auto diff = static_cast<unsigned int>(std::abs(sum - target));
                    if (diff < min_diff)
                    {
                        min_diff = diff;
                        result = sum;
                    }

                    if (sum < target)
                    {
                        break;
                    }

                    k--;
                }
            }
        }

        return result;
    }
};
