#-*- coding:utf-8 -*-
# ==============================================================================
#   Copyright 2016 Windy Darian (Ruoyu Fan)
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.
# ==============================================================================
'''
Created on Oct 18, 2016
https://leetcode.com/problems/add-two-numbers/
@author: Windy Darian (Ruoyu Fan)
'''

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        def get_value_and_next(node):
            if not node:
                return 0, None
            else:
                # in c++ we can just use a reference to pointer to force node point to next
                return node.val, node.next

        result_root = ListNode(None)
        current = result_root
        carry = 0
        while l1 is not None or l2 is not None or carry:
            v1, l1 = get_value_and_next(l1)
            v2, l2 = get_value_and_next(l2)
            carry, new_val = divmod(v1 + v2 + carry, 10)
            current.next = ListNode(new_val)
            current = current.next

        return result_root.next
