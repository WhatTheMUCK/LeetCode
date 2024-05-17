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
    void DFS(TreeNode* root, int target, TreeNode* father, int flag) {
        if (!root)
            return;

        // Удаление узлов на основе условий
        if (!(root->left || root->right) && root->val == target) {
            if (flag == 0) {
                father->left = nullptr;
            } else if (flag == 1) {
                father->right = nullptr;
            }
            return;
        }

        if (root->left) {
            DFS(root->left, target, root, 0);
        }

        if (root->right) {
            DFS(root->right, target, root, 1);
        }

        // Проверка, если текущий узел после удаления его потомков становится листом с целевым значением
        if (!(root->left || root->right) && root->val == target) {
            if (flag == 0) {
                father->left = nullptr;
            } else if (flag == 1) {
                father->right = nullptr;
            }
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* dummyHead = new TreeNode(-1);
        dummyHead->left = root;
        DFS(dummyHead, target, dummyHead, 0);
        TreeNode* result = dummyHead->left;
        delete dummyHead;
        return result;
    }
};
