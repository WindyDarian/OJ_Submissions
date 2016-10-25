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
// Created on Oct 25, 2016
// https://leetcode.com/problems/lru-cache/

// using a double linked list and a hash map as implementation

#include <unordered_map>

// for possible usage in the future
using key_t = int;
using value_t = int;
constexpr value_t fail_value = -1;

class LRUCache{
private:

    // Double linked list
    struct LruNode
    {
        // shared_ptr won't do to much good here
        LruNode* previous = nullptr;
        LruNode* next = nullptr;
        key_t key;
        value_t value;

        LruNode(key_t key, value_t&& value)
        : key(std::move(key))
        , value(std::move(value)){}
    };

    LruNode* head = nullptr;
    LruNode* tail = nullptr;
    std::unordered_map<key_t, LruNode*> hmap;
    size_t count = 0;
    size_t capacity;

    void push_left(LruNode* node)
    {
        auto temp = head;
        head = node;
        head->next = temp;
        if (temp)
        {
            temp->previous = head;
        }
        else
        {
            tail = head;
        }
    }

    key_t delete_right()
    {
        // A optimization strategy is not delete/new nodes when capacity full, instead just break links and use it for next push

        //if (!tail) {return default_key;}

        auto temp = tail;
        tail = temp->previous;

        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }

        auto temp_key = temp->key;

        delete temp;
        return temp_key;
    }

    void move_to_head(LruNode* node)
    {
        if (!node || node == head)
        {
            return;
        }

        auto left = node->previous;
        auto right = node->next;

        if (left)
        {
            left->next = right;
        }

        if (right)
        {
            right->previous = left;
        }
        else
        {
            // tail being deleted
            tail = left;
        }

        node->previous = nullptr;
        node->next = nullptr;

        push_left(node);
    }

public:
    LRUCache(int capacity):capacity(capacity)
    {

    }

    ~LRUCache()
    {
        while(head)
        {
            delete_right();
        }
    }

    value_t get(key_t key)
    {
        if (hmap.count(key) == 0)
        {
            return fail_value;
        }
        auto node = hmap[key];
        move_to_head(node);
        return node->value;
    }

    void set(key_t key, value_t value)
    {
        LruNode* node;
        if (hmap.count(key) == 0)
        {
            node = new LruNode(key, std::move(value));
            hmap[key] = node;
            push_left(node);
            count++;
            if (count > capacity)
            {
                hmap.erase(delete_right());
                count--;
            }
        }
        else
        {
            node = hmap[key];
            node->value = std::move(value);
            move_to_head(node);
        }
    }

    // delete copy and move functions
    LRUCache(const LRUCache&) = delete;
    LRUCache& operator=(const LRUCache&) = delete;
    LRUCache(LRUCache&&) = delete;
    LRUCache& operator=(LRUCache&&) = delete;
};
