/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <unordered_map>

class Solution {
public:
    std::unordered_map<TreeNode *, std::string> mp;
    
    std::string serialize(TreeNode * root) {
        if (!root) {
            return "";
        }

        mp[root] = std::to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
        return mp[root];

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        std::vector<TreeNode *> answer;
        std::unordered_map<std::string, std::vector<TreeNode *>> st;

        for (const auto & [node, serializeStr] : mp) {
            if (!st.contains(serializeStr)) {
                st[serializeStr] = {node};
            } else {
                st[serializeStr].push_back(node);
            }
        }

        for (const auto & [_, vecNodes] : st) {
            if (vecNodes.size() > 1) {
                answer.push_back(vecNodes[0]);
            }
        }

        return answer;
    }
};