class FirstUnique {
    int firstUniquePos;
    int firstUnique;
    vector<int> q;
    unordered_map<int, int> map;
public:
    FirstUnique(vector<int>& nums) {
        firstUnique = -1;
        firstUniquePos = nums.size()-1;
        q = nums;
        map = {};
        for(int i=0; i<nums.size(); i++) map[nums[i]]++;
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]] == 1){
                firstUnique = nums[i];
                firstUniquePos = i;
                break;
            }
        }
    }
    
    int showFirstUnique() {
        return firstUnique;
    }
    
    void add(int value) {
        q.push_back(value);
        map[value]++;
        if(value == firstUnique){//then search for next unique in (pos,end]
            int i;
            for(i=firstUniquePos+1; i<q.size(); i++){
                if(map[q[i]] == 1){
                    firstUnique = q[i];
                    firstUniquePos = i;
                    break;
                }
            }
            if(i == q.size()){
                firstUnique = -1;
                firstUniquePos = i-1;
            }
        }
        else if(firstUnique == -1 && map[-1] != 1 && map[value] == 1){
            firstUnique = value;
            firstUniquePos = q.size()-1;
        }
    }
};
