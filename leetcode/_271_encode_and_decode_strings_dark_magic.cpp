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
// https://leetcode.com/problems/encode-and-decode-strings/

// Attach a fixed size_t before each string indicating the size of current string
// Works only if the memory representation of string and size_t in both sides are the same
#include <string>
#include <vector>

class Codec
{
private:
    using str_size_t = std::string::size_type;
public:
    // Encodes a list of strings to a single string.
    std::string encode(std::vector<std::string>& strs)
    {
        std::string result;
        for (const auto& str: strs)
        {
            str_size_t size = str.size();
            result += std::string(reinterpret_cast<char*>(&size), sizeof(str_size_t));
            result += str;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    std::vector<std::string> decode(std::string s)
    {
        std::vector<std::string> results;
        auto head = s.data();
        auto end = head + s.size();
        while(head < end)
        {
            str_size_t str_l = *reinterpret_cast<const str_size_t*>(head);
            head += sizeof(str_size_t);
            results.emplace_back(head, str_l);
            head += str_l;
        }
        return results;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
