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
// Created on Oct 3, 2016
// https://leetcode.com/problems/longest-palindrome/

#include <unordered_set>
class Solution
{
public:
    int longestPalindrome(string s)
    {
        std::unordered_set<char> chars_with_odd_count = {};
        std::size_t even_pair_count = 0;
        for(auto character : s)
        {
            if (chars_with_odd_count.count(character) > 0)
            {
                even_pair_count++;
                chars_with_odd_count.erase(character);
            }
            else
            {
                chars_with_odd_count.insert(character);
            }
        }

        if (!chars_with_odd_count.empty())
        {
            return even_pair_count * 2 + 1;
        }
        else
        {
            return even_pair_count * 2;
        }
    }
};
