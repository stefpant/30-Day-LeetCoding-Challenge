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
    int findMaxPathSum(TreeNode* root, int& sum){
        if(root == NULL) return 0;
        int left = findMaxPathSum(root->left, sum);
        int right = findMaxPathSum(root->right, sum);
        if(left < 0) left = 0;
        if(right < 0) right = 0;
        if(left + root->val + right > sum) sum = left + root->val + right;
        
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        findMaxPathSum(root, maxSum);
        return maxSum;
    }
};
