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
// https://leetcode.com/problems/counting-bits/


class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> bits(num + 1);
        // when the number reaches 2^n, the number of 1 resets to 1
        // and the number of 1s before the next 2^n is previous + 1
        int current_reset = 1;
        int next_reset = 2;
        for (int i = 0; i <= num; i++)
        {
            if (i == 0) bits[i] = 0;
            else if (i == 1) bits[i] = 1;
            else if (i < next_reset)
            {
                bits[i] = bits[i - current_reset] + 1;
            }
            else
            {
                // so the current number is 2^n
                current_reset = next_reset;
                next_reset = current_reset * 2;
                bits[i] = 1;
            }
        }
        return bits;
    }
};
