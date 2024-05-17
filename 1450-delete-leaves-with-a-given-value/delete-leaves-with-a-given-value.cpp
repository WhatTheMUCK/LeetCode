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
class Solution {
public:
    void DFS(TreeNode* root, int target, vector<pair<TreeNode*, bool>>& helper, int flag) {
        if (!root)
            return;

        // Удаление узлов на основе условий
        if (!(root->left || root->right) && root->val == target) {
            if (flag == 0) {
                (helper.back().first)->left = nullptr;
            } else if (flag == 1) {
                (helper.back().first)->right = nullptr;
            }
            return;
        }

        if (root->left) {
            helper.push_back({root, 0});
            DFS(root->left, target, helper, 0);
            helper.pop_back();
        }

        if (root->right) {
            helper.push_back({root, 1});
            DFS(root->right, target, helper, 1);
            helper.pop_back();
        }

        // Проверка, если текущий узел после удаления его потомков становится листом с целевым значением
        if (!(root->left || root->right) && root->val == target) {
            if (flag == 0) {
                (helper.back().first)->left = nullptr;
            } else if (flag == 1) {
                (helper.back().first)->right = nullptr;
            }
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* dummyHead = new TreeNode(-1);
        dummyHead->left = root;
        vector<pair<TreeNode*, bool>> helper = {{dummyHead, 0}};
        DFS(dummyHead, target, helper, 0);
        TreeNode* result = dummyHead->left;
        delete dummyHead;
        return result;
    }
};
