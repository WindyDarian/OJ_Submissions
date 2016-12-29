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
Created on Dec 28, 2016
https://leetcode.com/problems/search-a-2d-matrix-ii/
@author: Windy Darian (Ruoyu Fan)
'''

class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        nrow = len(matrix)
        if not nrow:
            return False
        ncol = len(matrix[0])
        if not ncol:
            return False

        def dfs_find(minx, miny, maxx, maxy):
            if minx >= maxx or miny >= maxy:
                return False
            if target < matrix[minx][miny] or target > matrix[maxx - 1][maxy - 1]:
                return False
            middle = ((minx + maxx) / 2, (miny + maxy) / 2)
            val = matrix[middle[0]][middle[1]]
            if val == target:
                return (middle[0], middle[1])
            elif val > target:
                return dfs_find(minx, miny, maxx, middle[1]) or dfs_find( middle[0], miny, maxx, middle[1]) or dfs_find(minx, middle[1], middle[0], maxy)
            else:
                return dfs_find(middle[0] + 1, miny, maxx, middle[1] + 1) or dfs_find(minx, middle[1] + 1, middle[0] + 1, maxy) or dfs_find(middle[0] + 1, middle[1] + 1, maxx, maxy)

        return bool(dfs_find(0, 0, nrow, ncol))
