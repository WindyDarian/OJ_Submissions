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
// Created on March 18, 2016
// https://leetcode.com/problems/largest-bst-subtree/
// Given a binary tree, find the largest subtree which is a Binary Search
// Tree (BST), where largest means subtree with largest number of nodes in it.


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

 //params:
 //    root: input root node
 //    ret_count: the node count of the largest BST in this tree, if itself is
 //               a BST
 //    ret_min: the largest number in this BST, unmodified if this is not
 //                 a BST
 //    ret_max: the smallest number in this BST, unmodified if this is not
 //                 a BST
 //    return: true when the tree is a BST or null
 //    if root is null, neither reference param is modified
bool bstCompute(const TreeNode* root, int & ret_count
    , int & ret_min, int & ret_max)
{
    if (!root)
        return true;

    if (!root->left && !root->right)
    {
        ret_count = 1;
        ret_min = root->val;
        ret_max = root->val;
        return true;
    }

    int left_count = 0, left_min = root->val, left_max = root->val;
    auto left_bst = bstCompute(root->left, left_count, left_min, left_max);

    int right_count = 0, right_min = root->val, right_max = root->val;
    auto right_bst = bstCompute(root->right, right_count, right_min, right_max);

    // when this is a BST itself
    if (left_bst && right_bst
        && (root->val > left_max || !root->left)
        && (root->val < right_min|| !root->right))
    {
        ret_max = right_max;
        ret_min = left_min;
        ret_count = left_count + right_count + 1;
        return true;
    }

    // when this is not a BST return the node count of largest BST in children
    ret_count = std::max(left_count, right_count);
    return false;
}

class Solution
{
public:
    int largestBSTSubtree(TreeNode* root)
    {
        int count = 0, dummy1 = 0, dummy2 = 0;
        bstCompute(root, count, dummy1, dummy2);
        return count;
    }
};
