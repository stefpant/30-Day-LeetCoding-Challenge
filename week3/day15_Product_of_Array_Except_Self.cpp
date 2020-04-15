class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output = {};
        int temp = 1;
        output.resize(nums.size());
        for(int i=0; i<nums.size(); i++){
            output[i] = temp;//output[i] has nums procuct until pos i
            temp *= nums[i];
        }
        temp = 1;
        for(int i=nums.size()-1; i>=0; i--){
            output[i] *= temp;//mult remaining product without nums[i]
            temp *= nums[i];
        }
        return output;
    }
};
