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
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <unordered_set>
#include <string>
#include <algorithm>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_set<char> seen_characters;
        auto p_fast = s.cbegin();
        auto p_slow = s.cbegin();
        decltype(p_fast-p_slow) max_length = 0;

        while (p_fast != s.cend())
        {
            auto ch = *p_fast;
            while (seen_characters.count(ch) > 0)
            {
                seen_characters.erase(*p_slow);
                p_slow++;
            }
            seen_characters.insert(ch);
            p_fast++;
            max_length = std::max(p_fast - p_slow, max_length);
        }

        return max_length;
    }
};
