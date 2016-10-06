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
// Created on Oct 5, 2016
// https://leetcode.com/problems/reverse-linked-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        auto current = head;
        decltype(current) last_before_reverse = nullptr;
        int current_pos = 1;

        while (current_pos < m)
        {
            last_before_reverse = current;
            current = current->next;
            current_pos++;
        }

        // start reversing
        auto original_head_of_reversed_part = current;
        decltype(current) head_of_reversed_part = nullptr;
        decltype(current) temp_moving;
        while (current_pos <= n)
        {
            temp_moving = current;
            current = current->next;
            temp_moving->next = head_of_reversed_part;
            head_of_reversed_part = temp_moving;
            current_pos++;
        }

        original_head_of_reversed_part->next = current;

        if (!last_before_reverse)
        {
            return head_of_reversed_part;
        }
        else
        {
            last_before_reverse->next = head_of_reversed_part;
            return head;
        }
    }
};
