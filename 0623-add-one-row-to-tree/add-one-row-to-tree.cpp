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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int curdepth = 1, amountOnLVL = 1, newLVL = 0;
        TreeNode* prev = nullptr;
        queue<TreeNode*> tree;
        tree.push(root);
        while (curdepth + 1 < depth){
            newLVL = 0;
            while (amountOnLVL > 0){
                TreeNode* cur = tree.front();
                tree.pop();
                amountOnLVL--;
                //cout << curdepth << " " << cur->val << "\n";
                if (cur->left != nullptr){
                    tree.push(cur->left);
                    newLVL++;
                }
                if (cur->right != nullptr){
                    tree.push(cur->right);
                    newLVL++;
                }
            }
            curdepth++;
            amountOnLVL = newLVL;
        }
        
        if (depth == 1){
            TreeNode* newHead = new TreeNode(val);
            newHead->left = root;
            return newHead; 
        }
        while (!tree.empty()){
            TreeNode* cur = tree.front();
            tree.pop();
            TreeNode *leftt = cur->left, *rightt = cur->right;
            cur->left = new TreeNode(val);
            cur->right = new TreeNode(val);
            cur->left->left = leftt;
            cur->right->right = rightt;
        }
        
        return root;
    }
};