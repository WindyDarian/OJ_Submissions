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
// Created on March 19, 2016
// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        // A '#' consumes one opening, and a valid node adds one opening if
        //  there is opening left.
        // If no openings left for a node or the final opening is not zero,
        //  it is not a valid serialization

        int openings = 1;
        for (int i = 0; i < preorder.length();i++)
        {

            if (preorder[i] == '#')
            {
                if (openings <= 0) return false;
                openings -= 1;
                if (openings < 0) return false;
            }

            // if this section is any valid input other than #
            else if (i == 0 || preorder[i-1]==',')
            {
                if (openings <= 0) return false;
                openings += 1;
            }
        }

        if (opening == 0)
            return true;
        else return false;
    }
};
