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
// Created on Jan 22, 2017
// https://leetcode.com/problems/evaluate-division/

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <pair>
#include <string>
#include <stack>

class Solution {
public:
    std::vector<double> calcEquation(std::vector<std::pair<std::string, std::string>> equations, std::vector<double>& values, std::vector<std::pair<std::string, std::string>> queries)
    {
        std::unordered_map<std::string, std::unordered_set<size_t>> related_equations;
        std::unordered_set<size_t> unsolved_equations;

        std::unordered_map<std::string, double> v;
        std::unordered_map<std::string, size_t> v_group;

        for (size_t i = 0; i < equations.size(); i++)
        {
            unsolved_equations.insert(i);
            related_equations[equations[i].first].insert(i);
            related_equations[equations[i].second].insert(i);
        }

        size_t group_count = 0;
        while (!unsolved_equations.empty())
        {
            std::stack<std::size_t> to_solve;
            to_solve.push(*(unsolved_equations.begin()));

            auto current_group_id = group_count++;

            while (!to_solve.empty())
            {
                auto equ = to_solve.top();
                to_solve.pop();

                auto v1_str = equations[equ].first;
                auto v2_str = equations[equ].second;
                auto v1_solved = v.count(v1_str)>0;
                auto v2_solved = v.count(v2_str)>0;
                if (!v1_solved && !v2_solved)
                {
                    v[v2_str] = 1.0;
                    v[v1_str] = values[equ];
                }
                else if (!v1_solved)
                {
                    v[v1_str] = v[v2_str] * values[equ];
                }
                else if (!v2_solved)
                {
                    v[v2_str] = v[v1_str] / values[equ];
                }

                if (!v1_solved)
                {
                    v_group[v1_str] = current_group_id;
                    related_equations[v1_str].erase(equ);
                    for (auto new_equ : related_equations[v1_str])
                    {
                        to_solve.push(new_equ);
                    }
                    related_equations[v1_str].clear();
                }
                if (!v2_solved)
                {
                    v_group[v2_str] = current_group_id;
                    related_equations[v2_str].erase(equ);
                    for (auto new_equ : related_equations[v2_str])
                    {
                        to_solve.push(new_equ);
                    }
                    related_equations[v2_str].clear();
                }
                unsolved_equations.erase(equ);
            }
        }

        std::vector<double> results;

        for (const auto& pr: queries)
        {
            auto v1_str = pr.first;
            auto v2_str = pr.second;
            auto v1_solved = v.count(v1_str)>0;
            auto v2_solved = v.count(v2_str)>0;
            if (v1_solved && v2_solved && v_group[v1_str] == v_group[v2_str])
            {
                results.push_back(v[v1_str]/v[v2_str]);
            }
            else
            {
                results.push_back(-1.0);
            }
        }

        return results;

    }
};
