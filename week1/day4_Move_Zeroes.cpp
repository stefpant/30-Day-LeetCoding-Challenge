class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int counterNonZero = 0;
        //iterate nums vector and if element!=0 save it in same array
        //at the beggining using counterNonZero
        for(int i=0; i<nums.size(); i++)
            if( nums[i] ) nums[counterNonZero++] = nums[i];
        //then fill vector with zeros from counterNonZero till the end
        for(int i = counterNonZero; i<nums.size(); i++)
            nums[i] = 0;
    }
};
