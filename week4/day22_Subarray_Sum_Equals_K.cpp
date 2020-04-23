class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        int sum=0;
        unordered_map<int, int> m{{0,1}};
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
            if(m.count(sum-k) > 0)
                res = res + m[sum-k];
            m[sum]++;
        }
        return res;
    }
};
