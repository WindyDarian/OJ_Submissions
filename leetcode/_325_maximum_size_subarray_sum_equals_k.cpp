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
// Created on Feb 16, 2017
// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

#include <unordered_map>
#include <vector>

class Solution {
public:
    int maxSubArrayLen(std::vector<int>& nums, int k)
    {
        using Size_t = std::vector<int>::size_type;
        std::unordered_map<int, Size_t> scan_sum_to_index;
        int current_sum = 0;
        Size_t max_length = 0;
        scan_sum_to_index[0] = -1;

        for (Size_t i = 0; i < nums.size(); i++)
        {
            current_sum = current_sum + nums[i];

            if (scan_sum_to_index.count(current_sum) == 0)
            {
                scan_sum_to_index[current_sum] = i;
            }

            if (scan_sum_to_index.count(current_sum-k)>0)
            {
                max_length = std::max(i - scan_sum_to_index[current_sum - k], max_length);
            }


        }

        return max_length;
    }
};

// class Solution {
// public:
//     int maxSubArrayLen(vector<int>& nums, int k)
//     {
//         vector<int> scan_sum(nums.size() + 1);
//         scan_sum[0] = 0;
//         using Size_t = vector<int>::size_type;
//         for (Size_t i = 0; i < nums.size(); i++)
//         {
//             scan_sum[i+1] = scan_sum[i] + nums[i];
//         }

//         size_t max_length = 0;
//         for (Size_t i = 0; i < nums.size(); i++)
//         {
//             for (Size_t j = i; j < nums.size(); j++)
//             {
//                 if (scan_sum[j+1] - scan_sum[i] == k)
//                 {
//                     max_length = std::max(max_length, j + 1 - i);
//                 }
//             }
//         }

//         return max_length;
//     }
// };
