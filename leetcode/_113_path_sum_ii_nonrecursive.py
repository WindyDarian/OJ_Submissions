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
Created on Oct 1, 2016
https://leetcode.com/problems/path-sum-ii/
@author: Windy Darian (Ruoyu Fan)
'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class _MoveNode(object):
    "Linked list for the paths we are tracking, to save space"
    def __init__(self, tree_node, parent = None):
        self.tree_node = tree_node
        self.parent = parent
    def get_path(self):
        path = []
        current = self
        while current:
            path.append(current.tree_node.val)
            current = current.parent
        path.reverse()
        return path

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        def successors(parent_move, current_sum):
            parent_node = parent_move.tree_node
            if parent_node.right:
                yield _MoveNode(parent_node.right, parent_move), current_sum + parent_node.right.val
            if parent_node.left:
                yield _MoveNode(parent_node.left, parent_move), current_sum + parent_node.left.val
        if not root: return []
        results = []
        frontier = [(_MoveNode(root), root.val)]
        while frontier:
            current_move, current_sum = frontier.pop()
            prev_stack_len = len(frontier)
            frontier.extend(successors(current_move, current_sum))
            if sum == current_sum and len(frontier) == prev_stack_len:
                results.append(current_move.get_path())
        return results
