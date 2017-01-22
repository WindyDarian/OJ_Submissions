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
// https://leetcode.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<Interval> merge(std::vector<Interval>& intervals)
    {
        if (intervals.size() == 0) {return std::vector<Interval>();}

        auto sorted = intervals;
        constexpr auto SortByStart = [](const Interval& l, const Interval& r)
        {
            return l.start < r.start;
        };
        std::sort(sorted.begin(), sorted.end(), SortByStart);

        auto iter = sorted.cbegin();
        auto end = sorted.cend();

        std::vector<Interval> results = {*iter};
        iter++;

        for (;iter != end; iter++)
        {
            auto& current = *iter;
            if (current.start > results.back().end)
            {
                results.push_back(current);
            }
            else
            {
                results.back().end = std::max(current.end, results.back().end);
            }
        }
        return results;
    }
};
