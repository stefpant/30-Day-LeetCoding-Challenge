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
    bool isValidSequenceHelper(TreeNode* node, vector<int>& arr, int index){
        if(node == NULL) return false;
        if(node->val != arr[index]) return false;
        if(arr.size() == index+1) return (node->left == NULL && node->right == NULL);
        return (isValidSequenceHelper(node->left,arr,index+1) || isValidSequenceHelper(node->right,arr,index+1));
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return isValidSequenceHelper(root, arr, 0);
    }
};
