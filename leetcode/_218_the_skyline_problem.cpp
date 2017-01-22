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
// https://leetcode.com/problems/the-skyline-problem/


#include <set>
#include <map>
#include <pair>
#include <vector>
#include <int>
#include <algorithm>
#include <limit>


// container req for heights: fast lookup, fast insertion, fast removal,
//   fast max value, multiple instances of the same value, so std::multiset
//   (usually Red-Black Tree)
class Solution
{
public:
    std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>>& buildings)
    {
        std::vector<std::pair<int, int>> result;
        if (buildings.size()==0)
        {
            return result;
        }

        struct SortBuildingsByLeftBound
        {
            bool operator()(const std::vector<int>& b1, const std::vector<int>& b2) const
            {
                return b1[0] < b2[0];
            }
        };

        struct SortBuildingsByRightBound
        {
            bool operator()(const std::vector<int>& b1, const std::vector<int>& b2) const
            {
                return b1[1] < b2[1];
            }
        };

        auto building_enters = buildings;
        std::sort(building_enters.begin(), building_enters.end(), SortBuildingsByLeftBound());
        auto building_exits = buildings;
        std::sort(building_exits.begin(), building_exits.end(), SortBuildingsByRightBound());

        std::multiset<int> heights; // stores heights for current buildings in increasing order

        auto next_enter = building_enters.cbegin();
        auto enter_end = building_enters.cend();
        auto next_exit = building_exits.cbegin();
        auto exit_end = building_exits.cend();

        constexpr auto max_int = std::numeric_limits<int>::max();

        auto changeHeight = [&result](int pos, int new_height)
        {
            if (!result.empty() && result.back().first == pos)
            {
                // multiple height changes at this point
                // we only need the newest one
                result.pop_back();
            }
            if (!result.empty() && result.back().second == new_height)
            {
                // no height change
                return;
            }
            result.emplace_back(pos, new_height);
        };

        while (next_enter != enter_end || next_exit != exit_end)
        {

            auto next_enter_pos = next_enter == enter_end ? max_int : (*next_enter)[0];
            auto next_exit_pos = next_exit == exit_end ? max_int : (*next_exit)[1];

            if (next_exit_pos <= next_enter_pos)
            {
                heights.erase(heights.find((*next_exit)[2]));
                auto new_height = heights.empty()? 0 : *(heights.crbegin());
                changeHeight(next_exit_pos, new_height);
                next_exit++;
            }
            else
            {
                heights.insert((*next_enter)[2]);
                auto new_height = *(heights.crbegin());
                changeHeight(next_enter_pos, new_height);
                next_enter++;
            }
        }

        return result;
    }
};
