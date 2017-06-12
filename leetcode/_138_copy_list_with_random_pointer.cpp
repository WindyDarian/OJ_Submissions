//==============================================================================
// Copyright 2017 Windy Darian (Ruoyu Fan). MIT License.
//==============================================================================
//
// Created on June 12, 2017
// https://leetcode.com/problems/copy-list-with-random-pointer

#include <functional>

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        // NOT THREAD SAFE
        // temp structure old1->new1->old2->new2->...->oldn->newn
        decltype(head) new_head = nullptr;
        auto* next_to_copy = head;

        // Step 1: copy all nodes, and link
        while (next_to_copy)
        {
            auto* temp = next_to_copy;
            next_to_copy = next_to_copy->next;
            auto* new_node = new RandomListNode(temp->label);
            temp->next = new_node;
            new_node->random = temp->random;
            new_node->next = next_to_copy;
            if (!new_head)
            {
                new_head = new_node;
            }
        }

        // Step 2: write random attribute
        {
            auto* iter = head;
            while(iter)
            {
                if (iter->random)
                {
                    iter->next->random = iter->random->next; // iter->next is the correspounding new node
                }
                iter = iter->next->next;
            }
        }

        // Step 3: break the big list back into two lists
        {
            auto* iter = head;
            while(iter)
            {
                auto* temp = iter->next;
                iter->next = temp->next;
                if (iter->next)
                {
                    temp->next = iter->next->next;
                }
                iter = iter->next;
            }
        }

        return new_head;
    }
};
