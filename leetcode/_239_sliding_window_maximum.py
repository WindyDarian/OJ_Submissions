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
Created on June 24, 2016
https://leetcode.com/problems/sliding-window-maximum/
@author: Windy Darian (Ruoyu Fan)
'''

from collections import deque

class SlidingMaxWindow(object):

    def __init__(self):
        self.__max_queue = deque()
        self.__non_max_count = 0
        # or i can just use a ever-increasing index

    def append(self, value):
        '''push a value to the back of the window'''
        empty_count = 0
        while (self.__max_queue and value > self.__max_queue[-1][0]):
            # remove anything smaller than current value, they are useless
            empty_count += self.__max_queue.pop()[1] + 1
        self.__max_queue.append( (value, empty_count) )

    def pop(self):
        '''pop out the left value of the window'''
        if (self.__non_max_count >= self.__max_queue[0][1]):
            self.__max_queue.popleft()
            self.__non_max_count = 0
        else:
            self.__non_max_count += 1

    def max(self):
        return self.__max_queue[0][0]


class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k <= 0: return None

        result = []
        window = SlidingMaxWindow()
        for i in range(k):
            window.append(nums[i])
        result.append(window.max())
        for i in range(k, len(nums)):
            window.append(nums[i])
            window.pop()
            result.append(window.max())
        return result
