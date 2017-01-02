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

#include <string>
#include <vector>

class Solution
{
public:
    std::string decodeString(std::string s)
    {
        std::vector<std::string> str_stack{""};
        std::vector<size_t> str_repeats{1};

        size_t current_repeats = 0;
        for (auto ch : s)
        {
            if (ch == ']')
            {
                auto inner_string = str_stack.back();
                str_stack.pop_back();
                for (size_t i = 0; i < str_repeats.back(); i++)
                {
                    str_stack.back() += inner_string;
                }
                str_repeats.pop_back();
            }
            else if (ch >= '0' && ch <= '9')
            {
                current_repeats = current_repeats * 10 + (ch - '0');
            }
            else if (ch == '[')
            {
                str_stack.emplace_back();
                str_repeats.push_back(current_repeats);
                current_repeats = 0;
            }
            else
            {
                str_stack.back().push_back(ch);
            }
        }

        return str_stack.back();
    }
};
