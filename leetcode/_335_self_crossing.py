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
Created on March 18, 2016
https://leetcode.com/problems/self-crossing/
@author: Windy Darian (Ruoyu Fan)
'''

# # Why did I write this...
# def step(step_index, length, origin):
#     # type int, int, (int, int) -> (int, int)
#     '''
#     Given the index of the step, length and origin, move the pawn;
#     1st step: north
#     2nd step: west
#     3rd step: south
#     4th step: east
#     '''
#     direction = step_index % 4
#     if direction == 0:
#         return (origin[0], origin[1] + length)
#     elif direction == 1:
#         return (origin[0] - length, origin[1])
#     elif direction == 2:
#         return (origin[0], origin[1] - length)
#     else:
#         return (origin[0] + length, origin[1])


class Solution(object):
    def isSelfCrossing(self, x):
        """
        :type x: List[int]
        :rtype: bool
        """
        # So, step i is only possible to cross step i-3, step i-5 or step i-4
        # and that's it.
        if len(x) < 4:
            return False
        for i in xrange(len(x)):
            if i >= 3 and x[i-1] <= x[i-3] and x[i] >= x[i-2]:
                # Cross with step i-3
                return True
            if (i >= 5 and x[i-2] >= x [i-4] and x[i-3] >= x[i-1] and
                    x[i-1] + x[i-5] >= x[i-3] and x[i] + x[i-4] >= x[i-2]):
                # Cross with step i-4
                return True
            if i >= 4 and x[i-1] == x[i-3] and x[i] + x[i-4] >= x[i-2]:
                # Cross with step i-5
                return True
        return False
