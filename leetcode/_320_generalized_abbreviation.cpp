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
// Created on Jan 21, 2017
// https://leetcode.com/problems/walls-and-gates/

#include <functional>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector<std::string> generateAbbreviations(std::string word)
    {
        std::vector<std::string> results;
        using str_size_t = std::string::size_type;
        std::function<void (const std::string&, str_size_t, str_size_t)> dfs = [&results, word, &dfs](const std::string& prefix, str_size_t pos, str_size_t count)
        {
            auto new_pref = count > 0? prefix + std::to_string(count) : prefix;
            results.push_back(new_pref + word.substr(pos));

            if (pos >= word.size())
            {
                return;
            }
            // Take character at pos
            dfs(prefix, pos+1, count+1);

            // Don't take character at pos
            for (auto i = pos + 1; i < word.size(); i++)
            {
                dfs(new_pref+word.substr(pos, i - pos), i+1, 1);
            }
        };

        dfs("", 0, 0);
        return results;
    }
};
