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
Created on Nov 13, 2016
https://leetcode.com/problems/validate-binary-search-tree/
@author: Windy Darian (Ruoyu Fan)
'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # let's just do some plain old recursion
        # and each returns min and max values

        def dfs_validate(node):
            # returns (is_bst, min, max)
            if not node:
                return True, None, None
            vmin = vmax = node.val
            if node.left:
                l_valid, l_min, l_max = dfs_validate(node.left)
                if not l_valid:
                    return False, None, None
                if l_max and l_max >= node.val:
                    return False, None, None
                if l_min:
                    vmin = l_min
            if node.right:
                r_valid, r_min, r_max = dfs_validate(node.right)
                if not r_valid:
                    return False, None, None
                if r_min and r_min <= node.val:
                    return False, None, None
                if r_max:
                    vmax = r_max
            return True, vmin, vmax

        return dfs_validate(root)[0]
