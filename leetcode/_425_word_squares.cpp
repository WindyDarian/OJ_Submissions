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
// Created on Jan 10, 2017
// https://leetcode.com/problems/word-squares/

#include <vector>
#include <string>
#include <unordered_map>
#include <functional>

class Solution {
public:
    std::vector<std::vector<std::string>> wordSquares(std::vector<std::string>& words)
    {
        using std::vector;
        using std::string;
        using std::unordered_map;
        int length = words[0].size(); // gurarantees

        // Step 1: pre-process to enable fast lookup using prefixes
        unordered_map<string, vector<string>> prefix_dict;
        for (const auto& word: words)
        {
            for (int i = 0; i < word.size(); i++)
            {
                prefix_dict[word.substr(0, i)].push_back(word);
            }
        }

        // Step 2: fit words into it.
        // TODO?: use a set to prevent the same word appears twice (?) - nvm seems it doesn't require that
        vector<vector<string>> results;
        vector<string> current_square(length, string{length});
        std::function<void (int)> dfsFit = [&results, &current_square, &prefix_dict, &dfsFit, length](int pos)
        {
            if (pos == length)
            {
                results.push_back(current_square);
                return;
            }

            string prefix = "";
            for (int i = 0; i < pos; i++)
            {
                prefix.push_back(current_square[i][pos]);
            }

            for (const auto& word: prefix_dict[prefix])
            {
                current_square[pos] = word;
                dfsFit(pos + 1);
            }
        };

        dfsFit(0);

        return results;
    }
};
