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
// https://leetcode.com/problems/perfect-rectangle/

#include <pair>
#include <unordered_map>
#include <functional>
#include <limit>
#include <vector>
#include <algorithm>

// cond1: sum of all rectangles is sum of big "rectangle"
// cond2: no overlapping (or, all corners except 4 corners of the large rect appear 2 or 4 times)
// satisify when cond1&&cond2 are met (to be verified)
class Solution {
public:
    bool isRectangleCover(std::vector<std::vector<int>>& rectangles)
    {
        if (rectangles.size()==0){return true;}
        using point_t = std::pair<int, int>;

        struct PointHash
        {
            size_t operator()(const point_t& pair) const noexcept
            {
                constexpr std::hash<int> int_hash;
                auto hash_second = int_hash(pair.second);
                return (int_hash(pair.first) + 0x9e3779b9 + hash_second << 6 + hash_second >> 2) ^ hash_second;
            }
        };

        std::unordered_map<point_t, int, PointHash> corners_count;

        auto addCorner = [&corners_count](point_t point)
        {
            if (corners_count.count(point) == 0)
            {
                corners_count[point] = 1;
            }
            else
            {
                corners_count[point]++;
            }
            return corners_count[point] <= 4;
        };

        constexpr auto lowest_int = std::numeric_limits<int>::lowest();
        constexpr auto max_int = std::numeric_limits<int>::max();
        point_t min = {max_int, max_int};
        point_t max = {lowest_int, lowest_int};

        unsigned long area_sum = 0;


        for (const auto& rect: rectangles)
        {
            if (!(  addCorner(point_t{rect[0], rect[1]}) &&
                    addCorner(point_t{rect[0], rect[3]}) &&
                    addCorner(point_t{rect[2], rect[1]}) &&
                    addCorner(point_t{rect[2], rect[3]})
                )
            )
            {
                return false;
            }

            area_sum += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            min.first = std::min(rect[0], min.first);
            min.second = std::min(rect[1], min.second);
            max.first = std::max(rect[2], max.first);
            max.second = std::max(rect[3], max.second);
        }

        if (area_sum != static_cast<unsigned long>(max.second - min.second) * (max.first - min.first))
        {
            return false;
        }

        point_t cor_a = {min.first, max.second};
        point_t cor_b = {max.first, min.second};
        for (const auto& pr: corners_count)
        {
            auto& point = pr.first;
            auto count = pr.second;

            if (point == max || point == min || point == cor_a || point == cor_b)
            {
                if (count > 1)
                {
                    return false;
                }
            }
            else if (count != 2 && count != 4)
            {
                return false;
            }
        }

        return true;

    }
};
