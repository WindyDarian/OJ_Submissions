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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//params:
//    root: input root node
//    ret_biggest: the max value when the root node is robbed
//    ret_biggest_without_root: the max value when the root node is not robbed
//    if root is null, neither reference param is modified
void robsub(const TreeNode* root, int & ret_biggest
    , int & ret_biggest_without_root)
{
    if (!root)
    {
        return;
    }

    // if left tree and right tree are not occupied
    if (!(root->left || root->right))
    {
        ret_biggest = root->val;
        ret_biggest_without_root = 0;
        return;
    }

    // rob left and right children
    int rob_left = 0, rob_left_without_root = 0;
    robsub(root->left, rob_left, rob_left_without_root);
    int rob_right = 0, rob_right_without_root = 0;
    robsub(root->right, rob_right, rob_right_without_root);

    int rob_root = root->val + rob_left_without_root + rob_right_without_root;
    int rob_no_root = rob_left + rob_right;
    if (rob_no_root >= rob_root) rob_root = rob_no_root;

    ret_biggest = rob_root;
    ret_biggest_without_root = rob_no_root;
}

class Solution {
public:
    int rob(TreeNode* root) {
        int biggest = 0, dummy = 0;
        robsub(root, biggest, dummy);
        return biggest;
    }
};
