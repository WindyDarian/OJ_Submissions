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
// Given a string, determine if a permutation of the string could form a palindrome.
// Created on Oct 15, 2016
// https://leetcode.com/problems/palindrome-permutation/

#include <array>

class Solution {
public:
    bool canPermutePalindrome(string s) {
        using std::array;
        array<bool, 256> odds = {false};
        int odd_count = 0;
        for (auto c : s)
        {
            if (odds[c])
            {
                odd_count -= 1;
            }
            else
            {
                odd_count += 1;
            }
            odds[c] = !odds[c];
        }

        if (odd_count > 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
