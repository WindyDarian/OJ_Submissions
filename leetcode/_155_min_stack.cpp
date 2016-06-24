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
// https://leetcode.com/problems/implement-stack-using-queues/

#include <stack>
class MinStack
{
public:
    std::stack<int> main_stack;
    std::stack<int> min_stack;

    /** initialize your data structure here. */
    MinStack()
    {

    }

    void push(int x)
    {
        main_stack.push(x);
        if(min_stack.empty() || x <= min_stack.top()) min_stack.push(x);
    }

    void pop()
    {
        auto temp = main_stack.top();
        main_stack.pop();
        if (temp == min_stack.top()) min_stack.pop();
    }

    int top()
    {
        return main_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
