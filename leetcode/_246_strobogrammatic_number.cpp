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
// Created on Jan 19, 2017
// https://leetcode.com/problems/strobogrammatic-number/

#include <unordered_map>
#include <string>

class Solution {
public:
    bool isStrobogrammatic(std::string num)
    {
        if (num == "")
        {
            return true;
        }

        std::unordered_map<char, char> stros = {{'0', '0'}, {'1','1'}, {'6', '9'}, {'9', '6'}, {'8', '8'}};
        auto l = num.cbegin();
        auto r = num.cend() - 1;
        while (l <= r)
        {
            if (stros.count(*l) == 0 || stros[*l] != *r)
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
