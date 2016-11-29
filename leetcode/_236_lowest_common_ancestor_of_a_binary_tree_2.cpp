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
// Created on Nov 28, 2016
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* findOneOrLca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root) {return nullptr;}
        if (root == p || root == q)
        {
            return root;
        }

        auto lfound = findOneOrLca(root->left, p, q);
        auto rfound = findOneOrLca(root->right, p, q);

        if (lfound && rfound)
        {
            return root;
        }

        if (!lfound && rfound)
        {
            return rfound;
        }
        else if (lfound && !rfound)
        {
            return lfound;
        }

        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return findOneOrLca(root, p, q);
    }
};
