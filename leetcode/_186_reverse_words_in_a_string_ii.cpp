//==============================================================================
// Copyright 2017 Windy Darian (Ruoyu Fan)
//
// MIT License
//
//==============================================================================
// Created on Jul 4, 2017
// https://leetcode.com/problems/reverse-words-in-a-string-ii/

#include <string>

class Solution {
public:
    void reverseWords(string &s)
    {
        if (s.size() == 0)
        {
            return;
        }

        // or std::reverse
        auto reverse_between = [&s](std::string::size_type begin, std::string::size_type end)
        {
            end--;
            while (begin < end)
            {
                auto temp = s[begin];
                s[begin] = s[end];
                s[end] = temp;
                begin++;
                end--;
            }
        };

        reverse_between(0, s.size());

        std::string::size_type slow = 0;
        std::string::size_type fast = 0;

        while (fast < s.size())
        {
            while (fast < s.size() && s[fast] == ' ')
            {
                fast++;
            }
            slow = fast;
            while (fast < s.size() && s[fast] != ' ')
            {
                fast++;
            }
            reverse_between(slow, fast);
        }
    }
};
