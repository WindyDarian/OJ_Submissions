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
// Created on Jan 19, 2017
// https://leetcode.com/problems/3sum/

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <functional>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        using std::vector;
        struct hash_v3
        {
            size_t operator ()(const vector<int>& v) const noexcept
            {
                constexpr auto hashint = hash<int>();
                size_t res = 17;
                res = res * 31 + hashint( v[0] );
                res = res * 31 + hashint( v[1] );
                res = res * 31 + hashint( v[2] );
                return res;
            }
        };

        unordered_set<vector<int>, hash_v3> result_set;

        vector<vector<int>> results;
        if (nums.size() < 3)
        {
            return results;
        }

        auto sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());

        for (size_t i = 0; i < sorted_nums.size() - 2; i++)
        {
            auto k = sorted_nums.size() - 1;

            if (sorted_nums[i] + sorted_nums[i+1] + sorted_nums[i+2] > 0)
            {
                break;
            }

            for (auto j = i + 1; j < k; j++)
            {
                while (j < k)
                {
                    auto sum = sorted_nums[i] + sorted_nums[j] + sorted_nums[k];
                    if (sum == 0)
                    {
                        result_set.insert(vector<int>{sorted_nums[i], sorted_nums[j], sorted_nums[k]});
                    }
                    if (sum <= 0)
                    {
                        break;
                    }
                    k--;
                }
            }
        }

        for (const auto& v: result_set)
        {
            results.push_back(v);
        }

        return results;
    }
};
