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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<TreeNode*, int>> dict;
        for (vector<int> &description : descriptions){
            TreeNode *parent;
            if (dict.contains(description[0])){
                parent = dict[description[0]].first;
            } else {
                parent = new TreeNode(description[0]);
                dict[description[0]] = {parent, 0};
            }

            TreeNode *child;
            if (dict.contains(description[1])){
                child = dict[description[1]].first;
            } else {
                child = new TreeNode(description[1]);
            }
            dict[description[1]] = {child, 1};

            if (description[2] == 1){
                parent->left = child;
            } else {
                parent->right = child;
            }
            dict[description[0]].first = parent;
        }
        for (pair<int, pair<TreeNode*, int>> elem : dict){
            if (elem.second.second == 0)
                return elem.second.first;
        }
        return nullptr;
    }
};