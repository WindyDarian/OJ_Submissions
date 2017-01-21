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
// Created on Jan 20, 2017
// https://leetcode.com/problems/perfect-squares/

#include <vector>
#include <limit>

class Solution
{
private:
    std::vector<int> dp = {0, 1, 2, 3};
public:
    int numSquares(int n)
    {
        if (dp.size() <= n)
        {
            dp.reserve(n + 1);
        }
        constexpr auto max_int = std::numeric_limits<int>::max();
        for (int i = dp.size(); i <= n; i++)
        {
            auto min = max_int;
            for (int j=1; j <= i/j; j++)
            {
                min = std::min(dp[i - j*j] + 1, min);
            }
            dp.push_back(min);
        }
        return dp[n];
    }
};
