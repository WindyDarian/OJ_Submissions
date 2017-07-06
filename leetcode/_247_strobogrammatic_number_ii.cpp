//==============================================================================
// Copyright 2016 Windy Darian (Ruoyu Fan)
//
// MIT License
//
//==============================================================================
// Created on Jul 4, 2017
// https://leetcode.com/problems/strobogrammatic-number-ii

// 1-1
// 6-9
// 8-8
// 9-6
// 0-0!
// mid: 0/8/1

#include <vector>
#include <string>
#include <functional>

class Solution {
public:
    std::vector<std::string> findStrobogrammatic(int n)
    {
        std::vector<std::string> results;
        std::string current(n, '0');
        std::function<void(int)> dfs_next = [&current, &results, n, &dfs_next](int pos)
        {
            auto mirror_pos = n - pos - 1;
            if (pos > mirror_pos)
            {
                results.push_back(current);
                return;
            }

            if (pos > 0 || n == 1) //!!!!
            {
                current[pos] = '0';
                current[mirror_pos] = '0';
                dfs_next(pos + 1);
            }

            if (pos != mirror_pos)
            {
                current[pos] = '6';
                current[mirror_pos] = '9';
                dfs_next(pos + 1);

                current[pos] = '9';
                current[mirror_pos] = '6';
                dfs_next(pos + 1);
            }

            current[pos] = '1';
            current[mirror_pos] = '1';
            dfs_next(pos + 1);

            current[pos] = '8';
            current[mirror_pos] = '8';
            dfs_next(pos + 1);
        };

        dfs_next(0);
        return results;
    }
};
