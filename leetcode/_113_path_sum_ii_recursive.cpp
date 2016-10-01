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
// https://leetcode.com/problems/path-sum-ii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <memory>
#include <algorithm>

class Solution {
private:
    // use linked lists for solutions to save space
    struct MoveNode// : public std::enable_shared_from_this<MoveNode>
    {
        int move;
        std::shared_ptr<MoveNode> parent = nullptr;
        MoveNode(int move, std::shared_ptr<MoveNode> parent)
        {
            this->move = move;
            this->parent = parent;
        }
        std::vector<int> getPath() const
        {
            std::vector<int> path;
            auto current_node = this;
            while (current_node)
            {
                path.push_back(current_node->move);
                current_node = current_node->parent.get();
            }
            std::reverse(path.begin(), path.end());
            return path;
        }
    };

    void recurse(int current_sum, std::shared_ptr<MoveNode> current_move, TreeNode* node, int target_sum, std::vector<std::vector<int>>& results)
    {
        if (!node) {return;}

        if (!node->left && !node->right)
        {
            if (current_sum == target_sum)
            {
                results.push_back(current_move->getPath());
            }
            return;
        }

        if (node->left)
        {
            auto successor = node->left;
            recurse(current_sum + successor->val, std::make_shared<MoveNode>(successor->val, current_move), successor, target_sum, results);
        }

        if (node->right)
        {
            auto successor = node->right;
            recurse(current_sum + successor->val, std::make_shared<MoveNode>(successor->val, current_move), successor, target_sum, results);
        }
    }

public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum)
    {
        if (!root) return std::vector<std::vector<int>>();
        std::vector<std::vector<int>> result;
        recurse(root->val, std::make_shared<MoveNode>(root->val, nullptr), root, sum, result);
        return result;
    }
};
