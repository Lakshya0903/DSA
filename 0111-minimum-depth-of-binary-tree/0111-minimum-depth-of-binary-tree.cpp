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
    int minDepth(TreeNode* root) {
        
        if (root == nullptr) {
            return 0;
        }

     
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int left = INT_MAX;
        int right = INT_MAX;

        if (root->left != nullptr) {
            left = minDepth(root->left);
        }

        if (root->right != nullptr) {
            right = minDepth(root->right);
        }

        return 1 + min(left, right);
    }
};