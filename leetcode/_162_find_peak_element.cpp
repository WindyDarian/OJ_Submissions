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
// Created on Nov 27, 2016
// https://leetcode.com/problems/find-peak-element/

#include <vector>

class Solution 
{
public:
    int findPeakElement(std::vector<int>& nums) 
    {
        int l = 0;
        int r = nums.size();
        while (l < r)
        {
            auto mid = (l + r) / 2;
            if ((mid - 1 < 0 || nums[mid-1] < nums[mid]) 
              && (mid + 1 >= nums.size() || nums[mid+1] < nums[mid]))
            {
               return mid;  
            }
            else if (mid - 1 < 0 || nums[mid-1] > nums[mid]) // given num[i] != num[i+1]
            {
                r = mid;    
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};