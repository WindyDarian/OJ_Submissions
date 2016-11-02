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
// Created on Nov 1, 2016
// https://leetcode.com/problems/product-of-array-except-self/

// method 1: forward buffer + backward buffer + combine
// method 2: iterate with one variable

#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        std::vector<int> results(nums.size(), 1);
        int current = 1;
        // forward scan, every thing multiplies product before it
        for (int i = 1; i < nums.size(); i++)
        {
            current *= nums[i - 1];
            results[i] *= current;
        }
        current = 1;
        // backward scan, everything multiplies product after it
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            current *= nums[i + 1];
            results[i] *= current;
        }
        return results;
    }
};
