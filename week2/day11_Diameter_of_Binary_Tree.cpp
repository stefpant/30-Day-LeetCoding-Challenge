/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findMaxPath(TreeNode* node, int *maxSubPath){
        if(node == NULL) {
            *maxSubPath = 0;
            return -1;
        }
        int maxSubLeft, maxSubRight;
        int maxLeft = 1 + findMaxPath(node->left, &maxSubLeft);
        int maxRight = 1 + findMaxPath(node->right, &maxSubRight);
        if(maxSubLeft > maxSubRight && maxSubLeft > (maxLeft + maxRight)) *maxSubPath = maxSubLeft;
        else if( maxSubRight > (maxLeft + maxRight)) *maxSubPath = maxSubRight;
        else *maxSubPath = (maxLeft + maxRight);
        if(maxLeft < maxRight) return maxRight;
        return maxLeft;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxPath;
        findMaxPath(root, &maxPath);
        return maxPath;
    }
};
