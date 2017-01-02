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
// Created on Jan 1, 2017
// https://leetcode.com/problems/moving-average-from-data-stream/

#include <queue>

class MovingAverage
{
private:
    size_t capacity;
    std::deque<int> q = {};
    long long int sum = 0;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    : capacity(size){}

    double next(int val)
    {
        if (q.size() >= capacity)
        {
            sum -= q.front();
            q.pop_front();
        }

        sum += val;
        q.push_back(val);

        return sum/static_cast<double>(q.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
