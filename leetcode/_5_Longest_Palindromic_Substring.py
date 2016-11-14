# wrong
#
# # do some nice dynamic programming for odd and even palindromes separately
# class Solution(object):
#     def longestPalindrome(self, s):
#         """
#         :type s: str
#         :rtype: str
#         """
#         if not s:
#             return s
#
#         longest_start = 0
#         longest_length = 1
#         current_odd_length = 0
#         current_even_length = 0
#         current_odd_mid_point = 0
#         current_even_mid_point = 0
#         for index, _ in enumerate(s):
#             if index == 0:
#                 continue
#
#             iother_odd = 2 * current_odd_mid_point - index
#             if iother_odd < 0 or s[iother_odd] != s[index]:
#                 current_odd_mid_point = index
#                 current_odd_length = 0
#             else:
#                 current_odd_length += 1
#                 if current_odd_length * 2 + 1 > longest_length:
#                     longest_start = iother_odd
#                     longest_length = current_odd_length * 2 + 1
#
#             iother_even = 2 * current_even_mid_point - index + 1
#             if iother_even < 0 or s[iother_even] != s[index]:
#                 current_even_mid_point = index
#                 current_even_length = 0
#             else:
#                 current_even_length += 1
#                 if current_even_length * 2 > longest_length:
#                     longest_start = iother_even
#                     longest_length = current_even_length * 2
#
#         return s[longest_start:longest_start + longest_length]
