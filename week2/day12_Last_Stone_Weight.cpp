class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int x,y;
        while(stones.size() > 1){
            y = stones.back();//get and remove the 2 heaviest stones
            stones.pop_back();
            x = stones.back();
            stones.pop_back();
            if(y != x){//if y heavier than x insert y-x in vector 
                auto it = upper_bound(stones.cbegin(), stones.cend(), y-x);
                stones.insert( it, y-x);//insert remain stone weight sorted
            }
        }
        if(stones.size()) return stones[0];
        return 0;
    }
};
