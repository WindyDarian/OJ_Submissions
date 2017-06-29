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
// Created on Jun 29, 2017
// https://leetcode.com/problems/excel-sheet-column-number/
// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28

#include <string>

class Solution {
public:
    int titleToNumber(std::string s) 
    {
        int number = 0;
        int currentfactor = 1;
        for (auto iter = s.crbegin(); iter != s.crend(); iter++)
        {
            number += (*iter - 'A' + 1) * currentfactor;
            currentfactor *= 26;
        }
        return number;
    }
};
