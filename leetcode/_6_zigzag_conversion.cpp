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
// Created on Nov 27, 2016
// https://leetcode.com/problems/zigzag-conversion/

#include <string>
#include <vector>

class Solution 
{
public:
    string convert(std::string s, int numRows) 
    {
        if (numRows <= 1)
        {
            return s;
        }
        
        using std::string;
        using std::vector;
        vector<string> rows(numRows); // optimized from a s.size() * numRows grid
        bool rising = false;
        int r = 0;
        for (auto ch: s)
        {
            rows[r].push_back(ch);
            if (!rising)
            {
                r++;
                if (r == numRows - 1)
                {
                    rising = true;
                }
            }
            else
            {
                r--;
                if (r == 0)
                {
                    rising = false;
                }
            }
        }
        
        string result;
        result.reserve(s.size());
        for (auto& row: rows)
        {
            result += row;
        }
        return result;
    }
};