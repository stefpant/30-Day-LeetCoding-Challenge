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
    TreeNode* constructBST(vector<int>& nums, int& counter, int val, int min, int max){
        if(counter < nums.size()){
            if(val > min && val < max){//if val valid create a node,then it will be root or
                TreeNode* node = new TreeNode(val);//be assigned in left or right kid
                counter++;
                //try to insert next values under node...then whatever happens node is complete
                if(counter < nums.size()) node->left = constructBST(nums, counter, nums[counter], min, val);
                if(counter < nums.size()) node->right = constructBST(nums, counter, nums[counter], val, max);
                return node;
            }
        }
        return NULL;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        int counter=0;
        return constructBST(preorder, counter, preorder[0], INT_MIN, INT_MAX);
    }
};
