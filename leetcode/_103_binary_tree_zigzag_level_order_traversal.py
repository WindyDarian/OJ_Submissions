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
Created on Nov 23, 2016
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
@author: Windy Darian (Ruoyu Fan)
'''


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        l_stack = [root]
        r_stack = []
        results = []

        while l_stack or r_stack:
            subresults = []
            while l_stack:
                node = l_stack.pop()
                if node:
                    subresults.append(node.val)
                    r_stack.append(node.left)
                    r_stack.append(node.right)
            if subresults:
                results.append(subresults)
            else:
                break

            subresults = []
            while r_stack:
                node = r_stack.pop()
                if node:
                    subresults.append(node.val)
                    l_stack.append(node.right)
                    l_stack.append(node.left)
            if subresults:
                results.append(subresults)
            else:
                break

        return results
