class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = 0;
        for( int i=0; i < nums.size(); i++){
            curSum += nums[i];//while current sum > 0 continue adding numbers
            if( maxSum < curSum )//and keep the maximum
                maxSum = curSum;
            if( curSum < 0)//if sum becomes less than 0 start again from 0
                curSum = 0;
        }
        return maxSum;
    }
};
