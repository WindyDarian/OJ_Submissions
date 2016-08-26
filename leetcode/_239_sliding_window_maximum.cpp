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
// Created on June 24, 2016
// https://leetcode.com/problems/sliding-window-maximum/

#include <deque>

class SlidingMaxWindow
{
private:
    typedef std::pair<int, std::size_t> WPair;
    std::deque<WPair> max_queue;
    std::size_t current_back_index = 0;
    std::size_t current_front_index = 0;
public:

    SlidingMaxWindow() {}

    void append(int value)
    {
        while (!max_queue.empty() && max_queue.back().first < value)
        {
            max_queue.pop_back();
        }
        max_queue.push_back(WPair(value, current_back_index));
        current_back_index ++;
    }

    void pop()
    {
        if (current_front_index == max_queue.front().second)
        {
            max_queue.pop_front();
        }
        current_front_index ++;
    }

    int max()
    {
        return max_queue.front().first;
    }

};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        SlidingMaxWindow a = SlidingMaxWindow();
        std::vector<int> result;
        for (int i = 0; i < k; i++)
        {
            a.append(nums[i]);
        }
        if (k > 0) result.push_back(a.max());
        auto length = nums.size();
        for (int i = k; i < length; i++)
        {
            a.append(nums[i]);
            a.pop();
            result.push_back(a.max());
        }

        return result;
    }
};
