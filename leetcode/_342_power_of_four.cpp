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
// Created on Oct 30, 2016
// https://leetcode.com/problems/power-of-four/

#include <cstdint>

class Solution
{
public:
    bool isPowerOfFour(int32_t num)
    {
        if (num <= 0)
        {
            return false;
        }

        // the priorities of bitwise operators are less than logic operators!
        auto is_power_of_two = (num & (num - 1)) == 0;

        if (is_power_of_two)
        {
            // 0x55555555 == 0b01010101...0101
            return (num & 0x55555555) == num;
        }
        else
        {
            return false;
        }
    }
};
