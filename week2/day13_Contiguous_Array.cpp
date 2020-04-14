class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hm;
        int maxLen = 0;
        int sum = 0;
        int size = nums.size();
        
        for(int i=0; i<size; i++){
            if(nums[i])//having a sum to know where subarrays have equal 0's and 1's
                sum += 1;
            else
                sum -= 1;
            if(sum == 0) maxLen = i+1;//if sum==0, array with equal 0,1's starts from pos 0 to 'i'
            //if found same sum != 0, in 2 diferent positions, then
            //subarray from pos1 to pos2 has equal 0's and 1's
            //to achieve that:
            //use a hashmap to keep unique sums and its first pos that appears
            //then if sum appears again check length of subarray to get the maximum of them
            if(hm.find(sum + size) != hm.end()){
                if(i-hm[sum+size] > maxLen) maxLen = i - hm[sum + size];
            }
            else
               hm[sum + size] = i;
        }
        return maxLen;
    }
};
