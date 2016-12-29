//==============================================================================
// Copyright 2016 Windy Darian (Ruoyu Fan)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//==============================================================================
//
// Created on Dec 29, 2016
// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <algorithm>

class Solution
{
public:
    int findLongestConsecutiveSequence(TreeNode* root, TreeNode* parent, int parent_max_length)
    {
        if (!root){return 0;}
        int max_length = 1;
        if (parent && parent->val + 1 == root->val)
        {
            max_length += parent_max_length;
        }
        return std::max({max_length, findLongestConsecutiveSequence(root->left, root, max_length), findLongestConsecutiveSequence(root->right, root, max_length)});
    }

    int longestConsecutive(TreeNode* root)
    {
        return findLongestConsecutiveSequence(root, 0, 0);
    }
};

class Solution2
{
public:
    // first: longest with root, longest with or without root
    std::pair<int, int> findLongestConsecutiveSequence(TreeNode* root)
    {
        if (!root) {return std::make_pair(0, 0);}
        auto l_result = findLongestConsecutiveSequence(root->left);
        auto r_result = findLongestConsecutiveSequence(root->right);
        auto longest_with_root = std::max(root->left && root->left->val == root->val+1? l_result.first + 1: 1 ,root->right && root->right->val == root->val + 1? r_result.first + 1: 1);
        auto longest = std::max({longest_with_root, l_result.second, r_result.second});
        return std::make_pair(longest_with_root, longest);
    }

    int longestConsecutive(TreeNode* root)
    {
        return findLongestConsecutiveSequence(root).second;
    }
};
