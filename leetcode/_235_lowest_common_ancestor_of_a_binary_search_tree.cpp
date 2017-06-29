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
// Created on Jun 29, 2017
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Assumption: p and q exist in the tree
// TODO: there is a better solution using the BST condition

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q)
        {
            return root;
        }
        if (!root)
        {
            return nullptr;
        }

        auto l_found = lowestCommonAncestor(root->left, p, q);
        auto r_found = lowestCommonAncestor(root->right, p, q);

        if (l_found && r_found)
        {
            return root;
        }
        else if (l_found)
        {
            return l_found;
        }
        else if (r_found)
        {
            return r_found;
        }
        else
        {
            return nullptr;
        }
    }
};
