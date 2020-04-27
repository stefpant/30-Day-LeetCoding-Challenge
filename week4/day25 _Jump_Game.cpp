class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() < 2) return true;
        int jumps=0, pos;
        for(pos=0; pos < nums.size()-1; pos++){
            jumps = max(jumps-1, nums[pos]);
            if(jumps == 0) return false;
            if(pos+1+jumps >= nums.size()) return true;
        }
        return false;
    }
};
