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
// Created on Oct 22, 2016
// https://leetcode.com/problems/sort-colors/
// Rainbow sort... not really necessary but

#include <vector>
#include <algorithm>

class Solution
{
public:
    void sortColors(std::vector<int>& nums)
    {
        auto p = nums.begin();
        auto h0 = nums.begin();  // position of the next 0
        auto h2 = nums.end() - 1;  // position of the next 2

        while (p <= h2)
        {
            if (*p == 0)
            {
                std::swap(*p, *h0);
                h0++;
                // the new element at p is already verified so we need to also increment this pointer
                p++;
            }
            else if (*p == 1)
            {
                p++;
            }
            else if (*p == 2)
            {
                std::swap(*p, *h2);
                h2--;
                // the new element at p is not verified so we cannot increment this pointer
            }
        }
    }
};
