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
    string dfs(TreeNode *root, string &path, int target) {
    if (root) {
        if (root->val == target) {
            return path;
        }
        path.push_back('L');
        string leftPath = dfs(root->left, path, target);
        if (!leftPath.empty()) {
            return leftPath;
        }
        path.pop_back();
        path.push_back('R');
        string rightPath = dfs(root->right, path, target);
        if (!rightPath.empty()) {
            return rightPath;
        }
        path.pop_back();
    }
    return "";
}

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path = "";
        string pathFromRootToStart = dfs(root, path, startValue);
        path = "";
        string pathFromRootToDest = dfs(root, path, destValue);
        int i = 0, n = pathFromRootToStart.size(), m = pathFromRootToDest.size();
        while (i < min(n, m) && pathFromRootToStart[i] == pathFromRootToDest[i]){
            i++;
        }
        pathFromRootToStart = pathFromRootToStart.substr(i);
        pathFromRootToDest = pathFromRootToDest.substr(i);
        n = pathFromRootToStart.size();
        for (int j = 0; j < n; j++){
            pathFromRootToStart[j] = 'U';
        }
        return pathFromRootToStart + pathFromRootToDest;
    }
};