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
// Created on Jan 11, 2017
// https://leetcode.com/problems/license-key-formatting/

#include <algorithm>
#include <string>

class Solution {
public:
    std::string licenseKeyFormatting(std::string S, int K)
    {
        std::string output = "";
        output.reserve(S.size() / K * (K+1));

        auto iter = S.crbegin();
        auto end = S.crend();
        int count = 0;
        for (;iter != end; iter++)
        {
            auto ch = *iter;
            if (ch == '-')
            {
                continue;
            }
            if (count == K)
            {
                output.push_back('-');
                count = 0;
            }
            if (ch >= 'a' && ch <= 'z')
            {
                ch -= 'a' - 'A';
            }
            output.push_back(ch);
            count++;
        }
        std::reverse(output.begin(), output.end());
        return output;
    }
};
