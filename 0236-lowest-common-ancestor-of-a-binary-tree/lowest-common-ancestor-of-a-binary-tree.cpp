/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_map>

class Solution {
public:
    std::unordered_map<TreeNode *, std::string> mp;
    std::string preprocess(TreeNode * root) {
        if (!root) {
            return "";
        }

        if (root->left) {
            mp[root->left] = mp[root] + '/';
            preprocess(root->left);
        }

        if (root->right) {
            mp[root->right] = mp[root] + '\\';
            preprocess(root->right);
        }

        return mp[root]; 
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        preprocess(root);
        std::string pPath = mp[p], qPath = mp[q];
        size_t i = 0;
        for (; i < pPath.size() && i < qPath.size() && pPath[i] == qPath[i]; ++i);
        std::string path = qPath.substr(0, i);
        for (char elem : path) {
            if (elem == '/') {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};