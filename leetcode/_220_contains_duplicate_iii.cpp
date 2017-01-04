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
// Created on Jan 3, 2017
// https://leetcode.com/problems/contains-duplicate-iii/


// Given an array of integers, find out whether there are two distinct indices
//   i and j in the array such that the difference between nums[i] and nums[j]
//   is at most t and the difference between i and j is at most k.

#include <vector>
#include <unordered_map>
#include <cmath>


// using buckets of size (t + 1), so if the difference two values are no more than t, they must be in the same bucket or neighbor bucket
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
    {
        if (k < 0)
        {
            return false;
        }
        if (t < 0)
        {
            return false;
        }

        auto bucket_size = t + 1;
        auto findBucketIndexForValue = [bucket_size](int value)
        {
            if (value < 0) {value -= bucket_size - 1;} // make sure the result is floored integer
            return value / bucket_size;
        };

        std::unordered_map<int, size_t> bucket_map; // bucket index to index in nums
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i >= k + 1)
            {
                bucket_map.erase(findBucketIndexForValue(nums[i-k-1]));
            }

            auto num = nums[i];
            auto bucket = findBucketIndexForValue(num);
            if (bucket_map.count(bucket) > 0)
            {
                return true;
            }
            if (bucket_map.count(bucket - 1) > 0
                && std::abs(nums[bucket_map[bucket-1]] - static_cast<long>(num)) <= t) // cast to prevent overflow
            {
                return true;
            }
            if (bucket_map.count(bucket + 1) > 0
                && std::abs(nums[bucket_map[bucket+1]] - static_cast<long>(num)) <= t)
            {
                return true;
            }

            bucket_map[bucket] = i;

        }

        return false;
    }
};
