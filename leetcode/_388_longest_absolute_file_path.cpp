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
// Created on Dec 1, 2016
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

class Solution {
public:
    int lengthLongestPath(std::string input)
    {
        using std::vector;
        using std::string;

        vector<string> path_stack; // previous level is path_stack.size()
        int current_length = 0;
        int max_length = 0;

        auto iter = input.cbegin();
        auto string_end = input.cend();

        // Helper lambda function to read a line of string
        auto nextLine = [string_end] (decltype(iter) & iter)
        {
            int level = 0;
            bool has_dot = false;
            string line;
            for (;iter < string_end; iter++)
            {
                if (*iter == '\n') {iter++; break;}
                if (*iter == '\t')
                {
                    level++;
                    continue;
                }
                if (*iter == '.')
                {
                    has_dot = true;
                }
                line += *iter;
            }
            return std::make_tuple(line, level, has_dot);
        };

        while (iter < string_end)
        {
            string line;
            int level;
            bool has_dot;
            std::tie(line, level, has_dot) = nextLine(iter);
            while (level < path_stack.size())
            {
                current_length -= path_stack.back().size() + 1; // 1 for '/'
                path_stack.pop_back();
            }
            path_stack.push_back(line);
            current_length += line.size() + 1; //
            if (has_dot)
            {
                max_length = std::max(current_length, max_length);
            }
        }

        if (max_length > 0)
        {
            // Since we counted one more '/'
            max_length = max_length - 1;
        }

        return max_length;
    }
};
