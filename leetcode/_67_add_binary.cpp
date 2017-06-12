//==============================================================================
// Copyright 2017 Windy Darian (Ruoyu Fan). MIT License.
//==============================================================================
//
// Created on March 21, 2017
// https://leetcode.com/problems/add-binary

#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b)
    {
        std::string c;
        auto iter_a = a.crbegin();
        auto iter_b = b.crbegin();
        bool carry = false;

        while (iter_a != a.crend() || iter_b != b.crend())
        {
            char ca, cb;
            if (iter_a != a.crend())
            {
                ca = *iter_a;
                iter_a++;
            }
            else
            {
                ca = '0';
            }

            if (iter_b != b.crend())
            {
                cb = *iter_b;
                iter_b++;
            }
            else
            {
                cb = '0';
            }

            if (ca != cb)
            {
                if (carry)
                {
                    c.push_back('0');
                }
                else
                {
                    c.push_back('1');
                }
            }
            else
            {
                if (carry)
                {
                    c.push_back('1');
                }
                else
                {
                    c.push_back('0');
                }

                if (ca == '1')
                {
                    carry = true;
                }
                else
                {
                    carry = false;
                }
            }
        }
        if (carry)
        {
            c.push_back('1');
        }

        std::reverse(c.begin(), c.end());
        return c;
    }
};
