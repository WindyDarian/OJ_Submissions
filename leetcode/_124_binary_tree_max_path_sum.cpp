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
// Created on Sep 30, 2016
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
private:
    /**
     * The return value is the max value that will end at the root
     * and modifies the global maximum
     */
    int findSubTreeMathPathSum(TreeNode* node, int& global_maximum)
    {
        if (!node) {return 0;}
        auto left_max_ends_at_root = std::max(findSubTreeMathPathSum(node->left, global_maximum), 0);
        auto right_max_ends_at_root = std::max(findSubTreeMathPathSum(node->right, global_maximum), 0);

        auto max_ends_at_root = std::max(left_max_ends_at_root + node->val, right_max_ends_at_root + node->val);
        global_maximum = std::max(global_maximum, left_max_ends_at_root + right_max_ends_at_root + node->val);

        return max_ends_at_root;

        // parallel optimization option: return two values, max path that ends at root with max path that got through root
    }

public:
    int maxPathSum(TreeNode* root)
    {
        if (!root) return 0;
        int global_max = root->val;

        findSubTreeMathPathSum(root, global_max);
        return global_max;
    }
};
