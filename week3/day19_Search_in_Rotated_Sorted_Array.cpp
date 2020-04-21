class Solution {
public:
    int myBinSearch(vector<int>& nums, int start, int end, int target){
        int m=(start+end)/2;
        if(nums[m]==target) return m;
        if(start>=end) return -1;
        if(nums[start]>target){
            int res1 = myBinSearch(nums, m+1, end,target);
            int res2 = myBinSearch(nums, start, m-1, target);
            if(res1==-1) return res2;
            else return res1;
        }
        if(nums[start]<nums[m]){
            if(nums[start]<target && nums[m]<target)
            return myBinSearch(nums, m+1,end, target);
            else return myBinSearch(nums, start, m-1, target);
        }
        else{
            int res1 = myBinSearch(nums, start, m-1, target);
            int res2 = myBinSearch(nums, m+1, end, target);
            if(res1==-1) return res2;
            else return res1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        //binary search with little more checks
        return myBinSearch(nums, 0, nums.size()-1, target);
    }
};
