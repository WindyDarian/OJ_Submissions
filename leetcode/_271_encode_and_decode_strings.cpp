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
// Created on Jan 13, 2017
// https://leetcode.com/problems/encode-and-decode-strings/

#include <string>
#include <vector>

class Codec
{
public:

    // Encodes a list of strings to a single string.
    std::string encode(std::vector<std::string>& strs)
    {
        std::string result;
        for (const auto& str: strs)
        {
            result += std::to_string(str.size());
            result += '#';
            result += str;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    std::vector<std::string> decode(std::string s)
    {
        std::vector<std::string> results;
        std::string current;
        size_t str_l = 0;
        bool str_started = false;
        auto iter = s.cbegin();
        auto end = s.cend();
        while(iter != end)
        {
            auto ch = *iter;
            if (!str_started)
            {
                if (ch >= '0' && ch <= '9')
                {
                    str_l = str_l * 10 + (ch - '0');
                }
                else if (ch == '#')
                {
                    str_started = true;
                }
                iter++;
            }
            else if (str_l > 0)
            {
                str_l--;
                current.push_back(ch);
                iter++;
            }

            if (str_started && str_l == 0)
            {
                results.push_back(current);
                current.clear();
                str_started = false;
            }
        }
        return results;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
