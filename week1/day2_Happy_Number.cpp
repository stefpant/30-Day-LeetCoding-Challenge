class Solution {
public:
    bool isHappy(int n) {
        int res = n;
        vector<int> nums = {n};//visited results not equal to 1
        while(res != 1){
            res = 0;
            while(n){
                res += (n%10)*(n%10);
                n /=10;
            }
            for(int i=0;i<nums.size();i++)//check if res already visited,then return false
                if(nums[i] == res) return false;
            nums.push_back(res);
            n = res;
        }
        return true;
    }
};
