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
// Created on Oct 21, 2016
// https://leetcode.com/problems/count-complete-tree-nodes/

// time complexity: average O(n), best O(log(n)), worst O(n)
// Time Limit Exceeded on LeetCode
// Better way is first know the depth and min/max possible node count,
// and use binary search to guess it. Time complexity O(log(n)^2) : log(n) binary
// search guessing and log(n) verification

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <functional>

class Solution {
public:

    int calcMaxDepth(TreeNode* node, int depth)
    {

        if (!node->left)
        {
            return depth;
        }

        return calcMaxDepth(node->left, depth + 1);
    }

    int countNodes(TreeNode* root)
    {
        if (!root){return 0;}

        int max_depth = calcMaxDepth(root, 1);
        int shift = 0;

        std::function<bool(TreeNode* , int)> find_shift= [max_depth, &shift, &find_shift](TreeNode* node, int depth)->bool
        {
            if (!node)
            {
                shift++;
                return false;
            }

            if (depth == max_depth)
            {
                return true;
            }

            if (find_shift(node->right, depth + 1))
            {
                return true;
            }
            else
            {
                return find_shift(node->left, depth + 1);
            }
        };

        find_shift(root, 1);
        int count = 0;
        int current_layer_count = 1;
        for (int i = 0; i < max_depth;i++)
        {
            count += current_layer_count;
            current_layer_count *= 2;
        }

        count -= shift;
        return count;
    }
};
