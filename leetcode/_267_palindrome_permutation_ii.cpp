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
// Given a string s, return all the palindromic permutations (without duplicates) of it.
// Return an empty list if no palindromic permutation could be form.
// Created on Oct 15, 2016
// https://leetcode.com/problems/palindrome-permutation-ii/

#include <functional>
#include <unordered_map> // TODO: test map/set faster or unordered_set/unordered_map faster
#include <unordered_set>
//include <map>
//include <set>

class Solution
{
public:
    std::vector<std::string> generatePalindromes(std::string s)
    {
        if (s.size() == 0) return std::vector<std::string> {""};
        if (s.size() == 1) return std::vector<std::string> {s};

        using map_t = std::unordered_map<char, size_t>;
        using set_t = std::unordered_set<char>;
        //using map_t = std::map<char, size_t>;
        //using set_t = std::set<char>;

        set_t odds;
        map_t pairs;

        for (auto c : s)
        {
            if (odds.count(c) > 0)
            {
                odds.erase(c);
                if (pairs.count(c) > 0)
                {
                    pairs[c]++;
                }
                else
                {
                    pairs[c] = 1;
                }
            }
            else
            {
                odds.insert(c);
            }
        }

        if (odds.size() > 1)
        {
            return std::vector<std::string>();
        }

        std::string result_temp = s;
        for (auto c : odds)
        {
            result_temp[result_temp.size() / 2] = c; // only element according to context
            break;
        }

        std::vector<std::string> results;
        auto length = s.size();

        // doing some dfs and add all matches to results
        // cannot use auto on recursive lambda
        std::function<void (int depth)> dfs = [&dfs, &pairs, &result_temp, length, &results](int depth)
        {
            if (depth >= length / 2)
            {
                results.push_back(result_temp); // copy current string to results
                return;
            }
            for (auto& p : pairs)
            {
                auto& c = p.first;
                auto& count = p.second;
                if (count > 0)
                {
                    result_temp[depth] = c;
                    result_temp[length - 1 - depth] = c;
                    count--;
                    dfs(depth + 1);
                    count++;
                }
            }
        };

        dfs(0);
        return results;
    }
};
