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
// Created on Jan 13, 2017
// https://leetcode.com/problems/utf-8-validation/

class Solution {
public:
    bool validUtf8(vector<int>& data)
    {
        int remaining_bytes_for_char = 0;
        for (auto byte: data)
        {
            if (remaining_bytes_for_char == 0)
            {
                if (byte >> 3 == 0b11110)
                {
                    remaining_bytes_for_char = 3;
                }
                else if (byte >> 4 == 0b1110)
                {
                    remaining_bytes_for_char = 2;
                }
                else if (byte >> 5 == 0b110)
                {
                    remaining_bytes_for_char = 1;
                }
                else if (byte >> 7)
                {
                    return false;
                }
            }
            else
            {
                if (byte >> 6 != 0b10)
                {
                    return false;
                }
                remaining_bytes_for_char--;
            }
        }
        return remaining_bytes_for_char == 0;
    }
};
