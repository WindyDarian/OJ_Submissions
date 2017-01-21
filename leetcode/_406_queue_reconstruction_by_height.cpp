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
// Created on Jan 20, 2017
// https://leetcode.com/problems/queue-reconstruction-by-height/

#include <pair>
#include <algorithm>

class Solution {
public:
    vector<std::pair<int, int>> reconstructQueue(vector<std::pair<int, int>>& people)
    {
        auto people_cpy = people;
        using data_t = pair<int, int>;
        struct SortHelper
        {
            bool operator()(const data_t& p1, const data_t& p2) const noexcept
            {
                // sort height by decreasing order
                // while sorting k in increasing order
                if (p1.first > p2.first) {return true;}
                else if (p1.first == p2.first) {return p1.second < p2.second;}
                else {return false;}
            }
        };

        std::sort(people_cpy.begin(), people_cpy.end(), SortHelper());
        for (size_t i = 0; i < people_cpy.size(); i++)
        {
            auto k = people_cpy[i].second;
            auto pos = i;
            while (pos > k)
            {
                std::swap(people_cpy[pos], people_cpy[pos-1]);
                pos--;
            }
        }

        return people_cpy;
    }
};
