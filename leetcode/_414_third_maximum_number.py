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
https://leetcode.com/problems/third-maximum-number/
@author: Windy Darian (Ruoyu Fan)
'''

class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        first = second = third = None
        for v in nums:
            if first is None:
                first = v
                continue
            if v > first:
                third = second
                second = first
                first = v
                continue
            if v == first:
                continue
            if second is None:
                second = v
                continue
            if v > second:
                third = second
                second = v
                continue
            if v == second:
                continue
            if third is None:
                third = v
                continue
            if v > third:
                third = v
                continue
        if third is None:
            return first
        else:
            return third
