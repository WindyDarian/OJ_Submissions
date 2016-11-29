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

#include <vector>
#include <algorithm>
#include <functional>

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

    std::vector<const TreeNode*> findPathTo(const TreeNode* from, const TreeNode* to)
    {
        std::vector<const TreeNode*> path = {from};
        std::function<bool (const TreeNode*)> dfs = [&dfs, &path, to](const TreeNode* current) -> bool
        {
            if (current == to)
            {
                return true;
            }
            else if (current == nullptr)
            {
                return false;
            }

            path.push_back(current->left);
            if (dfs(current->left)) return true;
            path.pop_back();

            path.push_back(current->right);
            if (dfs(current->right)) return true;
            path.pop_back();

            return false;
        };

        dfs(from);
        return path;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        auto p1 = findPathTo(root, p);
        auto p2 = findPathTo(root, q);

        auto i = static_cast<int>(std::min(p1.size(), p2.size())) - 1;

        while (i >= 0 && p1[i] != p2[i])
        {
            i--;
        }

        if (i < 0) {return nullptr;}

        return const_cast<TreeNode*>(p1[i]);
    }
};
