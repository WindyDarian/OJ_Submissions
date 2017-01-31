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
// Created on Jan 22, 2017
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <vector>
#include <memory>


struct Node
{
    int value;
    size_t count = 1;
    std::unique_ptr<Node> l = nullptr;
    std::unique_ptr<Node> r = nullptr;

    Node(int value):value(value){}

    void insert(int value)
    {
        if (value >= this->value)
        {
            if (this->r)
            {
                this->r->insert(value);
            }
            else
            {
                this->r = std::unique_ptr<Node>(new Node(value)); //std::make_unique for C++ 14
            }
            count++;
        }
        else
        {
            if (this->l)
            {
                this->l->insert(value);
            }
            else
            {
                this->l = std::unique_ptr<Node>(new Node(value));
            }
            count++;
        }
    }

    size_t lCount()
    {
        if (this->l)
        {
            return this->l->count;
        }
        else
        {
            return 0;
        }
    }

    size_t findLowerCount(int value)
    {
        if (value == this->value)
        {
            return lCount();
        }
        else if (value < this->value)
        {
            if (this->l)
            {return this->l->findLowerCount(value);}
            else {return 0;}
        }
        else
        {
            if (this->r)
            {return lCount() + 1 + this->r->findLowerCount(value);}
            else {return this->count;}
        }
    }
};

class Solution {
public:
    std::vector<int> countSmaller(std::vector<int>& nums)
    {
        std::unique_ptr<Node> root = nullptr;
        std::vector<int> result;
        for (auto iter = nums.crbegin(); iter!= nums.crend(); iter++)
        {
            if (root)
            {
                root->insert(*iter);
            }
            else
            {
                root = std::unique_ptr<Node>(new Node(*iter));
            }
            result.push_back(root->findLowerCount(*iter));
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
