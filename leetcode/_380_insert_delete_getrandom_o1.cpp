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
// Created on Feb 5, 2017
// https://leetcode.com/problems/insert-delete-getrandom-o1/

#include <unordered_map>
#include <vector>
#include <cstdlib>


class RandomizedSet
{
private:
    std::vector<int> vals;
    std::unordered_map<int, size_t> map;
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (map.count(val) <= 0)
        {
            map[val] = vals.size();
            vals.push_back(val);
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (map.count(val) > 0)
        {
            map[vals.back()] = map[val];
            vals[map[val]] = vals.back();
            vals.pop_back();
            map.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() // TODO: const if I could change definition
    {
        return vals[std::rand() % vals.size()]; // TODO: use <random>, when outside of this online judge
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
