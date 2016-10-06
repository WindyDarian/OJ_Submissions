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
// Created on Oct 5, 2016
// https://leetcode.com/problems/split-array-largest-sum/

#include <algorithm>

class Solution {
public:
    int splitArray(vector<int>& nums, int m)
    {
        // The solution must be between [max_element, sum_all]
        auto max_element = 0L;
        auto sum_all = 0L;
        for (auto num : nums)
        {
            if (num > max_element) {max_element = num;}
            sum_all += num;
        }

        // This lambda function is used to examine if a value is valid as
        // a value equal or greater than min value of maximum of subarrays
        auto calculate_valid_as_max = [&nums, m](decltype(sum_all) desired_max)
        {
            auto current_subarray_sum = 0L;
            auto current_cuts = 0;
            for (auto num : nums)
            {
                current_subarray_sum += num;
                if (current_subarray_sum > desired_max)
                {
                    current_cuts++;
                    if (current_cuts >= m)
                    {
                        return false;
                    }
                    current_subarray_sum = num;
                }
            }
            return true;
        };

        // using binary search
        auto lower_bound = max_element;
        auto upper_bound = sum_all;
        decltype(upper_bound) middle;
        while (lower_bound < upper_bound)
        {
            middle = (lower_bound + upper_bound) / 2;
            if (calculate_valid_as_max(middle))
            {
                upper_bound = middle;
            }
            else
            {
                lower_bound = middle + 1;
            }
        }

        return lower_bound;
    }
};
