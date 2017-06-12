//==============================================================================
// Copyright 2017 Windy Darian (Ruoyu Fan). MIT License.
//==============================================================================
//
// Created on March 21, 2017
// https://leetcode.com/problems/sparse-matrix-multiplication/

#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B)
    {
        auto narow = A.size();
        // TODO: zero handling
        auto nacol = A[0].size();
        auto nbrow = B.size();
        auto nbcol = B[0].size();

        std::vector<std::unordered_map<int, int>> arows(narow);
        for (auto i = 0; i < narow; i++)
        {
            for (auto j = 0; j < nacol; j++)
            {
                if (A[i][j] != 0)
                {
                    arows[i][j] = A[i][j];
                }
            }
        }

        std::vector<std::unordered_map<int, int>> bcols(nbcol);
        for (auto i = 0; i < nbrow; i++)
        {
            for (auto j = 0; j < nbcol; j++)
            {
                if (B[i][j] != 0)
                {
                    bcols[j][i] = B[i][j];
                }
            }
        }


        std::vector<std::vector<int>> result = std::vector<std::vector<int>>(narow, std::vector<int>(nbcol, 0));

        for (auto i = 0; i < narow; i++)
        {
            for (auto j = 0; j < nbcol; j++)
            {
                for (const auto& pr : arows[i])
                {
                    auto pos = pr.first;
                    auto value = pr.second;
                    if (bcols[j].count(pos) > 0)
                    {
                        result[i][j] += value * bcols[j][pos];
                    }
                }
            }
        }

        return result;
    }
};
