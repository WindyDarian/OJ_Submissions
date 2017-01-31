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
// Created on Jan 22, 2017
// https://leetcode.com/problems/trapping-rain-water/

#include <limit>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int trap(std::vector<int>& height)
    {
        if (height.empty()) {return 0;}

        // since max only grows larger, we can fill either curent left or right each time
        // without the need of other vector
        constexpr auto min_int = std::numeric_limits<int>::lowest();

        std::vector<int>::size_type left = 0;
        auto right = height.size() - 1;
        auto left_max = height.front();
        auto right_max = height.back();

        int water = 0;

        while (left <= right)
        {
            if (left_max <= right_max)
            {
                water += left_max - height[left];

                if (left >= right) break;
                left++;
                left_max = std::max(height[left], left_max);
            }
            else
            {
                water += right_max - height[right];

                if (left >= right) break;
                right--;
                right_max = std::max(height[right], right_max);
            }
        }

        return water;
    }

    int trap_without_opt(std::vector<int>& height)
    {
        using std::vector;

        constexpr auto min_int = std::numeric_limits<int>::lowest();

        vector<int> left_hi(height.size());
        auto max_height = min_int;
        for (size_t i = 0; i < height.size(); i++)
        {
            max_height = std::max(height[i], max_height);
            left_hi[i] = max_height;
        }

        vector<int> right_hi(height.size());
        max_height = min_int;
        for (size_t i = 0; i < height.size(); i++)
        {
            auto index = height.size() - 1 - i;
            max_height = std::max(height[index], max_height);
            right_hi[index] = max_height;
        }

        int water = 0;
        for (size_t i = 0; i < height.size(); i++)
        {
            water += std::min(left_hi[i], right_hi[i]) - height[i];
        }

        return water;
    }
};
