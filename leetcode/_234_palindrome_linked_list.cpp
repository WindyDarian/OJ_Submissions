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
// Created on Nov 18, 2016
// https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
private:
    ListNode* reverse(ListNode* head)
    {
        auto current = head->next;
        head->next = nullptr; //LOOK
        while (current)
        {
            auto temp = current->next;
            current->next = head;
            head = current;
            current = temp;
        }
        return head;
    }
public:
    bool isPalindrome(ListNode* head)
    {
        if (!head || !head->next)
        {
            return true;
        }

        // Step 1: use two pointers to find middle
        ListNode* p_slow = head;
        ListNode* p_fast = head;
        while(p_fast->next && p_fast->next->next) //LOOK: this way p_slow is at middle (odd) or one node before right half (even)
        {
            p_slow = p_slow->next;
            p_fast = p_fast->next->next;
        }
        p_slow = p_slow->next; // omit the middle and let point p_slow to start of right half

        // Step 2: reverse and compare
        auto r_head = reverse(p_slow);
        auto l_head = head;
        while(r_head)
        {
            if (l_head->val != r_head->val) return false;
            l_head = l_head->next;
            r_head = r_head->next;
        }

        // FIXME: input linked list was broken, another reverse() will restore it
        return true;
    }
};
