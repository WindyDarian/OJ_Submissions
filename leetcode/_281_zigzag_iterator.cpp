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
// Created on Dec 29, 2016
// https://leetcode.com/problems/zigzag-iterator/


class ZigzagIterator
{
private:
    std::vector<std::vector<int> *> vs;

    size_t current_x_plus_one = 0; // to allow pointing to before 1st element while preventing underflow for size_t
    size_t current_y;

    size_t max_length;
    size_t y_of_max_length;

public:
    ZigzagIterator(std::vector<int>& v1, std::vector<int>& v2)
        : vs{&v1, &v2}
        , current_y(vs.size() - 1)
    {
        max_length = 0;
        for (size_t i = 0; i < vs.size(); i++)
        {
            if (vs[i]->size() >= max_length)
            {
                y_of_max_length = i;
                max_length = vs[i]->size();
            }
        }
    }

    int next()
    {
        do
        {
            current_y++;
            if (current_y >= vs.size())
            {
                current_y -= vs.size();
                current_x_plus_one++;
            }
        }
        while (current_x_plus_one - 1 >= vs[current_y]->size());

        return (*vs[current_y])[current_x_plus_one - 1];
    }

    bool hasNext()
    {
        return max_length && !(current_x_plus_one == max_length && current_y == y_of_max_length);
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
