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
// Created on Jan 1, 2017
// https://leetcode.com/problems/decode-string/

// Doing it deliberately recursively so it also works for linked lists

#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& old_digits)
    {
        auto digits = old_digits; // copy
        std::function<int(size_t)> plusOne = [&digits, &plusOne](size_t current_pos)
        {
            int carry = current_pos < digits.size() - 1 ? plusOne(current_pos + 1) : 1;
            digits[current_pos] += carry;
            carry = digits[current_pos] / 10;
            digits[current_pos] %= 10;
            return carry;
        };

        int carry = plusOne(0);
        if (carry > 0)
        {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
