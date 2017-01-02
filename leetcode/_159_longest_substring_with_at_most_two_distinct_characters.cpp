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
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

#include <string>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(std::string s)
    {
        std::unordered_map<char, size_t> seen_characters;
        auto p_slow = s.cbegin();
        auto p_fast = s.cbegin();
        decltype(s.cend()-s.cbegin()) max_length = 0;
        while (p_fast != s.cend())
        {
            auto ch = *p_fast;
            if (seen_characters.count(ch) == 0)
            {
                seen_characters[ch] = 0;
            }
            seen_characters[ch]++;
            p_fast++;

            while (seen_characters.size() > 2)
            {
                auto slow_ch = *p_slow;
                seen_characters[slow_ch]--;
                if (seen_characters[slow_ch] == 0)
                {
                    seen_characters.erase(slow_ch);
                }
                p_slow++;
            }
            auto length = p_fast - p_slow;
            max_length = std::max(length, max_length);
        }
        return static_cast<int>(max_length);
    }
};
