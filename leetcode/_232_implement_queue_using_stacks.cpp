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
// Created on June 22, 2016
// https://leetcode.com/problems/implement-queue-using-stacks/

class Queue {
private:
    // or I can use a variable to store current front since only pop may change
    // it if the queue is not empty, but it contradicts the req
    std::stack<int> a, b;
    void back_to_a()
    {
        while(!b.empty())
        {
            a.push(b.top());
            b.pop();
        }
    }
    void revert_to_b()
    {
        while(!a.empty())
        {
            b.push(a.top());
            a.pop();
        }
    }
public:
    // Push element x to the back of queue.
    void push(int x)
    {
        back_to_a();
        a.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void)
    {
        revert_to_b();
        if(!b.empty()) b.pop();
    }

    // Get the front element.
    int peek(void)
    {
        revert_to_b();
        return b.top();
    }

    // Return whether the queue is empty.
    bool empty(void)
    {
        return a.empty() && b.empty();
    }
};
