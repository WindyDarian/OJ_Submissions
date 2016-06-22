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
// Created on March 19, 2016
// https://leetcode.com/problems/power-of-three/

// #include <limits>

// int getMaxPowerOfThree()
// {
//     int max_int = std::numeric_limits<int>::max();
//     // not optimized.
//     int result = 1;
//     while(result <= max_int / 3)
//     {
//         result = result * 3;
//     }
//     return result;
// }

class Solution
{
public:
    // int max_power_of_three;

    bool isPowerOfThree(int n)
    {
        //if (!max_power_of_three) max_power_of_three = getMaxPowerOfThree()
        // assuming int32
        const int max_power_of_three = 1162261467;
        if (n <= 0) return false;

        return max_power_of_three % n == 0;
    }
};
