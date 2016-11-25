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
Created on Nov 24, 2016
https://leetcode.com/problems/longest-palindromic-substring/
@author: Windy Darian (Ruoyu Fan)
'''

# TODO: solve this in O(n)

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """

        def palin_length(mid1, mid2):
            if mid1 == mid2:
                length = -1
            else:
                length = 0
            while  0 <= mid1 <= mid2 < len(s):
                if s[mid1] == s[mid2]:
                    length += 2
                    mid1 -= 1
                    mid2 += 1
                else:
                    break
            return length, mid1, mid2

        max_length = 0;
        max_str = '';
        for i in xrange(len(s)):
            length, start, end = palin_length(i, i)
            if length > max_length:
                max_length = length
                max_str = s[start:end]

            length, start, end = palin_length(i, i + 1)
            if length > max_length:
                max_length = length
                max_str = s[start:end]
        return max_str
