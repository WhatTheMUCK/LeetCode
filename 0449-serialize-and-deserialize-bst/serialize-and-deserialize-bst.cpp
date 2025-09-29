/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }

        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    void insert(TreeNode * root, int value) {
        if (value < root->val && root->left == nullptr) {
            root->left = new TreeNode(value);
            return;
        }

        if (value > root->val && root->right == nullptr) {
            root->right = new TreeNode(value);
            return;
        }

        if (value < root->val) {
            insert(root->left, value);
            return;
        }

        if (value > root->val) {
            insert(root->right, value);
            return;
        }

        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        TreeNode * root;
        stringstream input(data);

        int curValue;
        input >> curValue;
        root = new TreeNode(curValue);

        while (input >> curValue) {
            insert(root, curValue);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;