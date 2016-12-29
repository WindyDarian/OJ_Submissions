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
// Created on Dec 29, 2016
// https://leetcode.com/problems/missing-ranges/
// just sort and print the range between two adjacents (if there are any range)

#include <algorithm>
#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> findMissingRanges(std::vector<int>& nums, int lower, int upper)
    {
        std::vector<std::string> result;
        std::vector<long> lnums;
        lnums.reserve(nums.size());
        for (auto num : nums)
        {
            lnums.push_back(num);
        }
        lnums.push_back(static_cast<long>(lower) - 1);
        lnums.push_back(static_cast<long>(upper) + 1);
        std::sort(lnums.begin(), lnums.end());
        for (size_t i = 0; i < lnums.size() - 1; i++)
        {
            auto l = lnums[i] + 1;
            auto r = lnums[i + 1] - 1;
            if (l < r)
            {
                result.push_back(std::to_string(l) + "->" + std::to_string(r));
            }
            else if (l == r)
            {
                result.push_back(std::to_string(l));
            }
        }

        return result;
    }
};

class Solution_WithoutOverflowProtection {
public:
    std::vector<std::string> findMissingRanges(std::vector<int>& nums, int lower, int upper)
    {
        std::vector<std::string> result;
        nums.push_back(lower - 1);
        nums.push_back(upper + 1);
        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            auto l = nums[i] + 1;
            auto r = nums[i + 1] - 1;
            if (l < r)
            {
                result.push_back(std::to_string(l) + "->" + std::to_string(r));
            }
            else if (l == r)
            {
                result.push_back(std::to_string(l));
            }
        }

        return result;
    }
};
