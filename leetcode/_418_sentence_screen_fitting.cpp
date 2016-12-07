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
// Created on Oct 15, 2016
// https://leetcode.com/problems/sentence-screen-fitting/

#include <unordered_map>
#include <string>
#include <vector>

class Solution
{
public:
    int wordsTyping(std::vector<std::string>& sentence, int rows, int cols)
    {
        std::unordered_map<int, int> row_start_cache; // stores length if starts with that world
        //TODO: there is a cleverer solution
        size_t current_index = 0;
        int current_row = 0;
        int loops = 0;

        while (current_row < rows)
        {
            if (row_start_cache.count(current_index) == 0)
            {
                int loc = -1;
                size_t wcount = 0;
                auto start_index = current_index;
                while (loc < cols)
                {

                    loc++; // space
                    loc += sentence[current_index].size();
                    if (loc > cols)
                    {
                        break;
                    }

                    // Next word
                    wcount++;
                    current_index ++;
                    if (current_index >= sentence.size())
                    {
                        current_index -= sentence.size();
                        loops++;
                    }
                }
                row_start_cache[start_index] = wcount;
            }
            else
            {
                current_index += row_start_cache[current_index];
                loops += current_index / sentence.size();
                current_index = current_index % sentence.size();
            }

            current_row++;

        }

        return loops;
    }
};
