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
TreeNode* fun(vector<int>& nums, int l, int h) {

        if (l > h) {
            return nullptr;
        }

        int m = l + (h - l) / 2;

        TreeNode* root = new TreeNode(nums[m]);

        root->left = fun(nums, l, m - 1);
        root->right = fun(nums, m + 1, h);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fun(nums, 0, nums.size() - 1);
    }
};