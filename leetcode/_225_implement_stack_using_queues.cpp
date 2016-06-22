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
// https://leetcode.com/problems/implement-stack-using-queues/

class Stack {
private:
    std::queue<int> a;
    std::queue<int> b;
    std::queue<int>& get_current_queue()
    {
        if(a.empty())
        {
            return b;
        }
        return a;
    }
    std::queue<int>& get_empty_queue()
    {
        if(a.empty())
        {
            return a;
        }
        return b;
    }

public:
    // Push element x onto stack.
    void push(int x)
    {
        // push to currently active queue
        get_current_queue().push(x);
    }

    // Removes the element on top of the stack.
    void pop()
    {
        if (this->empty()) return;
        auto& q1 = get_current_queue();
        auto& q2 = get_empty_queue();

        while (!q1.empty())
        {
            int t = q1.front();
            q1.pop();
            // add everything to q2 except stack top
            if (!q1.empty()) q2.push(t);
        }

    }

    // Get the top element.
    int top() {
        if (this->empty()) return a.front();
        auto& q1 = get_current_queue();
        auto& q2 = get_empty_queue();

        int current_top;
        while (!q1.empty())
        {
            current_top = q1.front();
            q1.pop();
            q2.push(current_top);
        }
        return current_top;

    }

    // Return whether the stack is empty.
    bool empty() {
        return (a.empty() && b.empty());
    }
};
