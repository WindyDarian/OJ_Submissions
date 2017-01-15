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
// Created on Jan 13, 2017
// https://leetcode.com/problems/wiggle-sort/

#include <algorithm>

class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        for (size_t i = 1; i < nums.size(); i+=2)
        {
            auto has_next = i+1 < nums.size();
            if (nums[i] < nums[i-1] || (has_next && nums [i] < nums[i+1]))
            {
                if (has_next && nums[i+1] > nums[i-1])
                {
                    std::swap(nums[i+1], nums[i]);
                }
                else
                {
                    std::swap(nums[i-1], nums[i]);
                }
            }
        }
    }
};
