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
// Created on June 23, 2016
// https://leetcode.com/problems/patching-array/

class Solution
{
public:
    int minPatches(vector<int>& nums, int n)
    {
        //  if I already have some numbers between [1, k] and I know they can
        // represent anything between [1, sum]
        // (sum is the sum of all the numbers) I can simply add (sum + 1) to the
        // array so the they can represent [1, 2sum + 1]

        // If I have some numbers between [1, k] and I know they can
        // represent anything between [1, sum] but the next number v is bigger
        // than sum + 1, I know something in between cannot be represented so I
        // add sum + 1 to the array.
        // else sum = sum + v since [1, sum + v] can be safely represented

        unsigned long max_representable = 0;
        int num_pathches = 0;
        for(auto k : nums)
        {
            while (k > max_representable + 1)
            {
                max_representable = max_representable + max_representable + 1;
                num_pathches += 1;
                if (max_representable >= n) return num_pathches;
            }
            max_representable += k;
            if (max_representable >= n) return num_pathches;
        }
        while (max_representable < n)
        {
            max_representable = max_representable + max_representable + 1;
            num_pathches += 1;
        }
        return num_pathches;
    }
};
