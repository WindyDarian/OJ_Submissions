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
// Created on Jan 20, 2017
// https://leetcode.com/problems/android-unlock-patterns/

#include <functional>
#include <array>

class Solution {
public:
    int numberOfPatterns(int m, int n)
    {
        // unpotimized
        std::array<bool, 9> visited{false};

        auto isVisited = [&visited](int i, int j)
        {
            if (i >= 3 || i < 0 || j >= 3 || j < 0 || visited[i*3+j])
            {
                return true;
            }
            return false;
        };

        std::function<int (int, int, int)> visitAndCount = [m, n, isVisited, &visited, &visitAndCount](int i, int j, int length)
        {
            if (length + 1 > n || isVisited(i, j))
            {
                return 0;
            }

            visited[i*3+j] = true;

            auto sum = 0;
            if (length + 1 >= m)
            {
                sum += 1;
            }

            // neighbors
            for (auto di = -1; di <= 1; di++)
            {
                for (auto dj = -1; dj <= 1; dj++)
                {
                    if (!(di==0 && dj==0))
                    {
                        if (!isVisited(i+di, j+dj))
                        {
                            sum+=visitAndCount(i+di, j+dj, length+1);
                        }
                        else
                        {
                            sum+=visitAndCount(i+di * 2, j+dj * 2, length+1);
                        }
                    }
                }
            }

            // "knight" jumps
            sum += visitAndCount(i-1, j-2, length+1);
            sum += visitAndCount(i-2, j-1, length+1);
            sum += visitAndCount(i-2, j+1, length+1);
            sum += visitAndCount(i+1, j-2, length+1);
            sum += visitAndCount(i+2, j-1, length+1);
            sum += visitAndCount(i-1, j+2, length+1);
            sum += visitAndCount(i+1, j+2, length+1);
            sum += visitAndCount(i+2, j+1, length+1);

            visited[i*3+j] = false;

            return sum;
        };


        auto count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                count += visitAndCount(i, j, 0);
            }
        }

        return count;
    }
};
