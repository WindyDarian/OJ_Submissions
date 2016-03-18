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
// Created on March 18, 2016
// https://leetcode.com/problems/increasing-triplet-subsequence/

#include <limits>

class Solution
{
public:
    bool increasingTriplet(vector<int>& nums)
    {
        // if we only need to find a increasing pair, we just need to return
        // when find anything bigger than the min
        auto min = std::numeric_limits<int>::max();
        // but we need to find a increasing triplet.
        // So this problem can be reduced to "find anything bigger than the
        // second of the min increasing pair"
        auto min_second = std::numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < min )
            {
                min = nums[i];
            }
            else if (nums[i] > min)
            {
                if (nums[i] < min_second)
                {
                    min_second = nums[i];
                }
                else if (nums[i] > min_second)
                {
                    return true;
                }
            }
        }

        return false;
    }
};
