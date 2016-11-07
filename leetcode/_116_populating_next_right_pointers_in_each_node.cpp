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
// Created on Nov 7, 2016
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root)
    {
        if (!root) return;

        TreeLinkNode* left_most = root;
        TreeLinkNode* current = nullptr;
        while (left_most->left)
        {
            current = left_most;
            while (current)
            {
                current->left->next = current->right;
                if (current->next)
                {
                    current->right->next = current->next->left;
                }
                current = current->next;
            }
            left_most = left_most->left;
        }
    }
};
