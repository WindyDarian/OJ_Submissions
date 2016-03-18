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
Created on March 17, 2016
https://leetcode.com/problems/palindrome-pairs/
@author: Windy Darian (Ruoyu Fan)
'''

# #tried to use a trie, result was "memory limit exceed"
# class PalinNode:
#     "The trie node for the question used to search the potential matches"
#     def __init__(self):
#         self.index = None
#         self.children = dict.fromkeys
#
#     def add_word(self, word, index):
#         # type (str, int) -> None
#         """ Add a word to the TrieNode. """
#         current_node = self
#         for char in word:
#             if char not in current_node.children:
#                 temp = PalinNode()
#                 current_node.children[char] = temp
#             else:
#                 temp = current_node.children[char]
#             current_node = temp
#         current_node.index = index
#
#     def find_word(self, word):
#         # type (str) -> list[int]/None
#         """
#         find a word in the trie.
#         If found, return index; else return None.
#         """
#         current_node = self
#         for char in word:
#             if char in current_node.children:
#                 current_node = current_node.children[char]
#             else:
#                 return None
#         return current_node.index
#
# def find_potential_pairs(word, index, root):
#     # type (str, int, PalinNode) -> list[list[int, int]]
#     """find potential palindrome pairs for an input string"""
#     result = []
#
#     for i in range(len(word)):
#         # split the word by position i, if one of the left and right is a
#         # palindrome, then try to find the reversed counterpart of the
#         # other side
#         left = word[:i]
#         right = word[i:]
#         if left == left[::-1]:
#             temp = root.find_word(right[::-1])
#             if (temp is not None) and temp != index:
#                 result.append([temp, index])
#         if right == right[::-1]:
#             temp = root.find_word(left[::-1])
#             if (temp is not None) and temp != index:
#                 result.append([index, temp])
#
#     # the for loop will unable to attach a "" to the left if the word is a
#     # palindrome. So...
#     if word == word[::-1]:
#         temp = root.find_word("")
#         if (temp is not None) and temp != index:
#             result.append([temp, index])
#
#     return result

def find_potential_pairs(word, index, words_dict):
    # type (str, int, PalinNode) -> list[list[int, int]]
    """find potential palindrome pairs for an input string"""
    result = []

    for i in range(len(word)):
        # split the word by position i, if one of the left and right is a
        # palindrome, then try to find the reversed counterpart of the
        # other side
        left = word[:i]
        right = word[i:]
        if left == left[::-1]:
            #temp = root.find_word(right[::-1])
            temp = words_dict.get(right[::-1])
            if (temp is not None) and temp != index:
                result.append([temp, index])
        if right == right[::-1]:
            #temp = root.find_word(left[::-1])
            temp = words_dict.get(left[::-1])
            if (temp is not None) and temp != index:
                result.append([index, temp])

    # the for loop will unable to attach a "" to the left if the word is a
    # palindrome. So...
    if word == word[::-1]:
        #temp = root.find_word("")
        temp = words_dict.get("")
        if (temp is not None) and temp != index:
            result.append([temp, index])

    return result

class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        result = []

        # # tried to use a trie, got "memory limit exceed" when encountered a
        # # long string as input
        # root = PalinNode()
        words_dict = {}

        for index, word in enumerate(words):
            #root.add_word(word, index)
            words_dict[word] = index

        for index, word in enumerate(words):
            #result.extend(find_potential_pairs(word, index, root))
            result.extend(find_potential_pairs(word, index, words_dict))

        return result
